#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

typedef pair<int,int> pi;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int level[mx][mx];
int grid[mx][mx];
bool vis[mx][mx];

int n,m;
int destx,desty;
void bfs(int x,int y)
{
   level[x][y]=0;
   vis[x][y]=true;
   queue<pi>pq;
   pq.push(make_pair(x,y));
   while(!pq.empty())
   {
       pi p=pq.front();
       pq.pop();
       for(int it=0;it<4;it++)
       {
           int xx=p.first+dx[it];
           int yy=p.second+dy[it];
           if(xx>=0&&xx<n&&yy>=0&&yy<m&&grid[xx][yy]==0){
           if(vis[xx][yy]==false)
           {
               vis[xx][yy]=true;
               level[xx][yy]=level[p.first][p.second]+1;
               if(xx==destx&&yy==desty) {return;}
               pq.push(make_pair(xx,yy));
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
    while(cin>>n>>m && n!=0 &&m!=0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                grid[i][j]=0;
                level[i][j]=0;
                vis[i][j]=false;
            }
        }
        int r;
        cin>>r;
        while(r--)
        {
            int x,y,c;
            cin>>x>>y;
            for(int i=0;i<y;i++)
            {
                cin>>c;
                grid[x][c]=-1;
            }
        }
        int sx,sy;
        cin>>sx>>sy;
        cin>>destx>>desty;
         bfs(sx,sy);
        cout<<level[destx][desty]<<endl;
    }

}
