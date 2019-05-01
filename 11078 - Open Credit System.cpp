#include<bits/stdc++.h>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

#define maxi -2147483647

typedef unsigned long long ll;


int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
        int x,mn,mx;
        scanf("%d",&x);
        vector<int>v(x);
        for(int j=0;j<x;j++)
        {
            scanf("%d",&v[j]);
        }
        mn=mx=v[0];
        int mx_so_far=maxi;
        for(int r=1;r<x;r++)
        {
            mx_so_far=max(mx_so_far,max(mx-v[r],mn-v[r]));
            mn=min(mn,v[r]);
            mx=max(mx,v[r]);
        }
        printf("%d\n",mx_so_far);
    }
}

