#include<bits/stdc++.h>

using namespace std;

//typedef pair<double,double> pi;

//typedef pair< double,pi> pii;
int dy[] ={1,0,-1,0};
int dx[] ={0,1,0,-1};

const int mx=30001;

vector<int>adj[mx];
bool vis[mx];
int cont=0;

void dfs(int u)
{
   vis[u]=true;
   cont++;
   for(int i=0;i<adj[u].size();i++)
   {
       if(!vis[adj[u][i]]) dfs(adj[u][i]);
   }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc,u,v,n,m;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(int i=0;i<=n;i++)
        {
            adj[i].clear();
           // vis[i]=false;
        }
        while(m--)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,false,sizeof(vis));
            cont=0;
            dfs(i);
            mx=max(mx,cont);
        }
        cout<<mx<<'\n';
    }
    return 0;
}
