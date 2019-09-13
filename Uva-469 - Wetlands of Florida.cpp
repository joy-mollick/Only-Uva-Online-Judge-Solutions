#include<bits/stdc++.h>

using namespace std;

const int mx=101;

typedef pair<int,int> pi;

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={1,0,-1,1,-1,1,0,-1};

int grid[mx][mx];
bool vis[mx][mx];

int n,m;
int ans=0;
int destx,desty;
void dfs(int x,int y)
{
    if(grid[x][y]==1 && x>=0 && x<n && y>=0 && y<m && vis[x][y]==false)
    {
        vis[x][y]=true;
        ans++;
        for(int k=0;k<8;k++)
        {
            int xx=x+dx[k];
            int yy=y+dy[k];
            dfs(xx,yy);
        }
    }
}

int main()

{
   ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string>mp;
    string s;
    int tc;
    cin>>tc;
    getline(cin,s);
    getline(cin,s);
    for(int cases=1;cases<=tc;cases++)
    {
        mp.clear();
        memset(grid,0,sizeof(grid));
        while(1)
        {
            getline(cin,s);
            if(s[0]!='W' && s[0]!='L') break;
            else{
            mp.push_back(s);}
        }
        n=mp.size();
        m=mp[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='W')
                {
                    grid[i][j]=1;
                }
                else
                {
                    grid[i][j]=0;
                }
            }
        }
        int x,y;
        while(true)
        {
            istringstream iss(s);
            iss>>x;
            iss>>y;
            memset(vis,false,sizeof(vis));
            ans=0;
            dfs(x-1,y-1);
            cout<<ans<<endl;
            if (cin.eof())
            {
                break;
            }
            getline(cin, s);
            if (s == "")
            {
                break;
            }
        }
        if(cases!=tc) cout<<endl;
    }
}
