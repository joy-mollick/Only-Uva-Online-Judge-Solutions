#include<bits/stdc++.h>

using namespace std;

const int mx=200001;

typedef pair<int,int> pi;

map<string,vector<string> >adj;
map<string,int>level;
map<string,int>vis;
map<string,string>parent;
int n;

void bfs(string src,string dest)
{
   queue<string>pq;
   level[src]=0;
   pq.push(src);
   vis[src]=1;
   while(!pq.empty())
   {
       string s=pq.front();
       pq.pop();
       if(s==dest) {return;}
       for(int it=0;it<adj[s].size();it++)
       {
           if(vis[adj[s][it]]==0)
           {
               vis[adj[s][it]]=1;
               level[adj[s][it]]=level[s]+1;
               parent[adj[s][it]]=s;
               pq.push(adj[s][it]);
           }
       }
   }
}
void print(string s,string d)
{
     if(s==d){return;}
  print(parent[s],d);
  cout<<parent[s]<<" "<<s<<endl;
}

int main()

{
   // ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    bool dhuk=false;
    int m;
    string s,s1;
    while(scanf("%d",&m)!=EOF)
    {
        level.clear();
        adj.clear();
        vis.clear();
        parent.clear();
        while(m--)
        {
            cin>>s>>s1;
            adj[s].push_back(s1);
            adj[s1].push_back(s);
        }
        cin>>s>>s1;
        if(dhuk) printf ("\n"); dhuk = true;
        bfs(s,s1);
        if(vis[s1]){
        print(s1,s);
        }
        else
        {
            printf("No route\n");
        }
    }
    return 0;
}
