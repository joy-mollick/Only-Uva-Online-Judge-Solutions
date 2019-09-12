#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+500;

typedef long long ll;

int oil[101][101];

//typedef pair< int,pair<int,int> > pii;
int dx[]= {1,-1,0,0,1,-1,-1,1};
int dy[]= {0,0,1,-1,1,-1,1,-1};
int n,m;

void dfs(int i,int j)
{
  if(i<0||i>=n||j<0||j>=m||oil[i][j]==0) return;
  oil[i][j]=0;
  for(int k=0;k<8;k++)
  {
      int ii=i+dx[k];
      int jj=j+dy[k];
      dfs(ii,jj);
  }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c;
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>c;
                if(c=='*')
                oil[i][j]=0;
                else
                    oil[i][j]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(oil[i][j])
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
