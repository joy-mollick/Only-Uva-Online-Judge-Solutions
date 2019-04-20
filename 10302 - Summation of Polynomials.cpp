#include<bits/stdc++.h>


/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

#define maxi  100000005

int main()
{
    unsigned long long int n,ans;
    while(scanf("%llu",&n)!=EOF)
    {
        ans=((n*(n+1))>>1)*((n*(n+1))>>1);
        printf("%llu\n",ans);
    }
    return 0;
}
