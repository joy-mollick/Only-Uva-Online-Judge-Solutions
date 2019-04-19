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

long long int catalan[30];

void ctalan()
{
   long long int i=0;
   catalan[0]=1;
   while(i<26)
   {
       catalan[i+1]=(catalan[i]*(4*i+2))/(i+2);
       i++;
   }
}


int main()
{
    ctalan();
    long long int d;
    while(scanf("%lld",&d)==1)
    {
        if(d==1)
        {
            printf("1\n");
        }
        else{
        for(int j=0;j<26;j++)
        {
            if(catalan[j]==d)
            {
                printf("%d\n",j);
                break;
            }
        }
        }
    }
    return 0;
}
