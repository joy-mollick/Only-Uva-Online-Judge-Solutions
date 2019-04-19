#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstring>
#include<vector>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;


char s[177737];
  char s1[163763];

vector<string>v1;
vector<string>v2;
 int dp[10001][10001];

void fillup()
{
    string w="";
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i])||(s[i]>='0'&&s[i]<='9'))
        {
            w=w+s[i];
        }
        else if(w!="")
        {
            v1.push_back(w);
            w="";
        }
    }
    if(w!="")
    {
        v1.push_back(w);
    }
     w="";
    for(int j=0;j<strlen(s1);j++)
    {
        if(isalpha(s1[j])||(s1[j]>='0'&&s1[j]<='9'))
        {
            w=w+s1[j];
        }
        else if(w!="")
        {
            v2.push_back(w);
            w="";
        }
    }
     if(w!="")
    {
        v2.push_back(w);
    }
}
int ld()
{
        int N=(int)(v1.size());
    int m=(int)(v2.size());
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0){
                dp[i][j]=0;
                continue;
            }
            if(v1[i-1]==v2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            if(v1[i-1]!=v2[j-1])
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[N][m];
}
int main()
{
    int n=1;
  while(gets(s))
  {
      gets(s1);
      v1.clear();
      v2.clear();
      fillup();

      int ans=ld();
      if(ans!=0){
      printf("%2d. Length of longest match: %d\n",n,ans);
      }
      else{
        printf("%2d. Blank!\n",n);
      }
      n++;
  }
  return 0;
}
