#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+500;

typedef long long ll;

vector<int>adj[2501];

//typedef pair< int,pair<int,int> > pii;
//int dx[]= {1,-1,0,0,1,-1,-1,1};
//int dy[]= {0,0,1,-1,1,-1,1,-1};
int n;
bool vis[2501];
int level[2501];

void bfs(int src)
{
  vis[src]=true;
  queue<int>q;
  level[src]=0;
  q.push(src);
  while(!q.empty())
  {
      int u=q.front();
      q.pop();
      for(int it=0;it<adj[u].size();it++)
      {
          if(!vis[adj[u][it]])
          {
              vis[adj[u][it]]=true;
              if(level[adj[u][it]]>level[u]+1){
              level[adj[u][it]]=level[u]+1;
              q.push(adj[u][it]);}
          }
      }
  }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q,u,v,t,s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q;
        while(q--)
        {
            cin>>u;
            adj[i].push_back(u);
        }
    }
    cin>>t;
    while(t--)
    {
        memset(vis,false,sizeof(vis));
        for(int l=0;l<n;l++) level[l]=INT_MAX;
        cin>>s;
        bfs(s);
        int lev=0,day=0;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            if(level[i]!=INT_MAX&&(i!=s))
            m[level[i]]++;
        }
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            if(lev<(it->second))
            {
                lev=(it->second);
                day=(it->first);
            }
        }
        if(lev==0&&day==0) cout<<"0"<<endl;
        else
      cout<<lev<<" "<<day<<endl;
    }

}
