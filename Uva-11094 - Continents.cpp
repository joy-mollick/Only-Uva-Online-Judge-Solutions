#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+500;

//typedef pair<double,double> pi;

//typedef pair< double,pi> pii;
int dy[] ={1,0,-1,0};
int dx[] ={0,1,0,-1};

char grid[22][22];
int sum=0;
bool vis[22][22];
char land;
int n,m;

bool valid(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return false;
    else return true;
}
void dfs(int x,int y)
{
    sum++;
    vis[x][y]=true;
   for(int k=0;k<4;k++)
   {
       int xx=x+dx[k];
       int yy=y+dy[k];
       if(valid(xx,yy)&&!vis[xx][yy]&&grid[xx][yy]==land)
       {
           dfs(xx,yy);
       }
   }
   if(y==0&&!vis[x][m-1]&&grid[x][m-1]==land) dfs(x,m-1);
   else if(y==m-1&&!vis[x][0]&&grid[x][0]==land) dfs(x,0);
}

int main()

{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int tc;
    int u,v,x,y;
    while(cin>>n>>m){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int xx,yy;
    cin>>xx>>yy;
    land=grid[xx][yy];
    dfs(xx,yy);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&grid[i][j]==land)
            {
                sum=0;
                dfs(i,j);
                ans=max(sum,ans);
            }
        }
    }
    cout<<ans<<endl;
    }
}
