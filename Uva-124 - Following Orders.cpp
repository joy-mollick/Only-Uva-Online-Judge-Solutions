#include<bits/stdc++.h>

using namespace std;

const int mx=101;

bool order[26][26];
bool vis[26];
bool use_alpha[26];
char res[26];

void dfs(int indx,int sz)
{
   if(indx==sz)
   {
       res[indx]='\0';
       cout<<res<<endl;
       return ;
   }
   int i,j;
   for( i=0;i<26;i++)
   {
       if(!vis[i]&&use_alpha[i])
       {
           for( j=0;j<26;j++){

               if(order[i][j]&&vis[j])
                {
                    return;
                }
                    }

                   vis[i]=true;
                   char c=(i+'a');
                   res[indx]=c;
                   dfs(indx+1,sz);
                   vis[i]=false;
       }
   }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stringstream ln;
    string s;
    char c,d;
    bool frst=false;
    while(getline(cin,s))
    {
        memset(vis,false,sizeof(vis));
        memset(order,false,sizeof(order));
        memset(use_alpha,false,sizeof(use_alpha));
        if(frst){
            cout<<endl;}
        frst=true;
        ln.clear();
        ln<<s;
        while(ln>>c)
        {
            use_alpha[c-'a']=true;
        }
        int sz=0;
        for(int i=0;i<26;i++)
        {
            if(use_alpha[i])
            {
                sz++;
            }
        }
        getline(cin,s);
        ln.clear();
        ln<<s;
        while(ln>>c>>d)
        {
            order[c-'a'][d-'a']=true;
        }
        dfs(0,sz);
    }
    return 0;
}
