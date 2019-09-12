#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+500;

typedef long long ll;

int dist[1004][1004];
int ans[1004][1004];
bool vis[1004][1004];

typedef pair< int,pair<int,int> > pii;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int n,m;

void djkstra()
{
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    memset(vis,true,sizeof(vis));
   // memset(ans,100000,sizeof(ans));
    pair<int,int> p;
    p=make_pair(0,0);
    pq.push(make_pair(dist[0][0],p));
    ans[0][0]=dist[0][0];
    while(!pq.empty())
    {
        pii top=pq.top();
        pq.pop();
        p=top.second;
        int x=p.first;
        int y=p.second;
        if(vis[x][y]) vis[x][y]=false;
        else continue;
        for(int k=0;k<4;k++)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=0&&xx<n&&yy>=0&&yy<m)
            {
                if(ans[xx][yy]>ans[x][y]+dist[xx][yy])
                {
                    int cost=ans[x][y]+dist[xx][yy];
                    ans[xx][yy]=cost;
                    p=make_pair(xx,yy);
                    pq.push(make_pair(cost,p));
                }
            }
        }
    }

}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
   cin>>n;
   cin>>m;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           ans[i][j]=100000000;
       }
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin>>dist[i][j];
       }
   }
   djkstra();
   cout<<ans[n-1][m-1]<<endl;
    }
    return 0;
}
