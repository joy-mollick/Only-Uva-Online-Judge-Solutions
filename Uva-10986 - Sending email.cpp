#include<bits/stdc++.h>

using namespace std;

const int mx=200001;

typedef pair<int,int> pi;

vector<pi>adj[mx];

int n;

void djkstra(int src,int dest)
{
   priority_queue<pi,vector<pi>,greater<pi> > pq;
   int dist[n];
   bool vis[n];
   for(int i=0;i<n;i++) {dist[i]=1000000000;vis[i]=false;}
   pq.push(make_pair(0,src));
   dist[src]=0;
   while(!pq.empty())
   {
       int u=pq.top().second;
       pq.pop();
       if(vis[u]) continue;
       else vis[u]=true;
       vector<pi>::iterator it;
       for( it=adj[u].begin();it!=adj[u].end();it++)
       {
           int v=(*it).first;
            int weight=((*it).second);
           if(dist[v]>dist[u]+weight)
           {
               dist[v]=dist[u]+weight;
               pq.push(make_pair(dist[v],v));
           }
       }
   }
   if(dist[dest]==1000000000){
    cout<<"unreachable"<<endl;}
    else {cout<<dist[dest]<<endl;}
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int j=1;j<=tc;j++){
    int m,u,v,c,s,t;
    cin>>n>>m>>s>>t;
    for(int i=0;i<n;i++)
    {
        adj[i].clear();
    }
    while(m--)
    {
        cin>>u>>v>>c;
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }
    cout << "Case #" <<j<< ": ";
    djkstra(s,t);
    }
}
