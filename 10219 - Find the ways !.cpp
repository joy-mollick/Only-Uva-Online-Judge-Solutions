#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<cstring>
#include<vector>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */
using namespace std;


int main()
{
    long long int n,k,i;
    while(scanf("%lld%lld",&n,&k)==2)
    {
        long double ans=0;
        for(i=n-k+1;i<=n;i++){
        ans=(log10(i))+ans;}
        for(i=1;i<=k;i++)
        {
            ans=ans-(log10(i));
        }
        printf("%d\n",(int)(floor)(ans)+1);
    }
    return 0;
}
