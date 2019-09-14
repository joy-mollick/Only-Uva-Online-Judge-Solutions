#include<bits/stdc++.h>

using namespace std;

const int mx=101;

typedef pair<int,int> pi;

vector<string>adj;
map<string,int>level;

void bfs(string src,string dest)
{
    map<string,int>vis;
    queue<string>q;
    q.push(src);
    level[src]=0;
    while(!q.empty()&&vis[dest]==0)
    {
        string u=q.front();
        q.pop();
        for(int i=0;i<adj.size();i++)
        {
                string w=u;
                string x=adj[i];
                if(w.size()==x.size()&&vis[x]==0)
                {
                    int nteql=0;
                    for(int i=0;i<w.size();i++)
                    {
                        if(w[i]!=x[i]) {nteql++;}
                    }
                    if(nteql==1)
                    {
                        level[x]=level[w]+1;
                        vis[x]=1;
                        q.push(x);
                    }
                }
        }
    }
    cout<<src<<" "<<dest<<" "<<level[dest]<<endl;
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    string s,src,dest;
    while(tc--)
    {
        adj.clear();
        level.clear();
        while(cin>>s&&s!="*")
        {
            adj.push_back(s);
        }
        cin.ignore();
        while(getline(cin,s)&&s!="")
        {
            istringstream iss(s);
            iss>>src>>dest;
            level.clear();
            bfs(src,dest);
            if(cin.eof()) {break;}
        }
        if(tc) {cout<<endl;}
    }
    return 0;
}
