#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+500;

typedef pair<double,double> pi;

vector<pi>adj;

//typedef pair< double,pi> pii;
//int dx[]= {1,-1,0,0,1,-1,-1,1};
//int dy[]= {0,0,1,-1,1,-1,1,-1};
int n;
double res=0.0;
//pi vis[2501];
void djkstra()
{
    double dist[101];
    bool vis[101];
    for(int j=0;j<100;j++) {dist[j]=1000000.0;vis[j]=false;}
    pi k,k1;
    dist[0]=0.0;
    int v=0;
    double dst=0.0,sum=0.0;
    while(!vis[v])
    {
        vis[v]=true;
        sum+=dist[v];
        k=adj[v];
        for(int i=0;i<n;i++)
        {
            //cout<<dst<<endl;
            if(!vis[i])
            {
                k1=adj[i];
                double x=k.first;
                double y=k.second;
                //cout<<x<<" "<<y<<endl;
                double xx=k1.first;
                double yy=k1.second;
                dst=sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
                if(dist[i]>dst)
                {
                    dist[i]=dst;
                }
            }
        }
        v=0;
        double mn=1000000.0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dist[i]<mn)
                {
                    mn=dist[i];
                    v=i;
                }
            }
        }
    }
    res=sum;
}

int main()

{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int tc;
    scanf("%d",&tc);
    for(int i=0;i<tc;i++)
    {

        double x,y;
        scanf("%d",&n);
        adj.clear();
        for(int j=0;j<n;j++){
        scanf("%lf%lf",&x,&y);
        pi p=make_pair(x,y);
        adj.push_back(p);
        }
        djkstra();
        printf("%.2lf\n",res);
         if(i!=tc-1)
        printf("\n");
    }
    return 0;
}
