#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+500;

//typedef pair<double,double> pi;

//typedef pair< double,pi> pii;
//int dx[]= {1,-1,0,0,1,-1,-1,1};
//int dy[]= {0,0,1,-1,1,-1,1,-1};
map<int,vector<int> >adj;
map<int,int>level;
map<int,bool>vis;

void bfs(int src)
{
   queue<int>q;
   level[src]=0;
   q.push(src);
   vis[src]=1;
   while(!q.empty())
   {
       int u=q.front();
       q.pop();
       for(int it=0;it<adj[u].size();it++)
       {
           if(vis[adj[u][it]]==0)
           {
               vis[adj[u][it]]=1;
               level[adj[u][it]]=level[u]+1;
               q.push(adj[u][it]);
           }
       }
   }
}

int main()

{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int tc;
    int cases=1;
    int u,v,x,y;
    while(cin>>tc&&tc!=0)
    {
         adj.clear();
        level.clear();
        vis.clear();
        while(tc--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
        while(cin>>x>>y&&(x!=0||y!=0))
        {
           level.clear();
           vis.clear();
            bfs(x);
            map<int,int>::iterator it;
            int cont=0;
            for(it=level.begin();it!=level.end();it++)
            {
                if((it->second)>y) cont++;
                //cout<<(it->first)<<" "<<(it->second)<<endl;
            }
            cont+=(adj.size()-level.size());// for disconnected components
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases,cont,x,y);
            cases++;
        }
    }
    return 0;
}
