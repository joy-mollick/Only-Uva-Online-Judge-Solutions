#include<bits/stdc++.h>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

// Mainly You Have to find out the number of palindrmic subsequence ,this is the key idea .Nothing else
typedef unsigned long long ll;

long long int countways(string str)
{
    int N = str.length();
    long long int dp[N+1][N+1];
    memset(dp, 0 ,sizeof(dp));

    dp[0][0]=1;
    // length of one is alawys a palindrom itself
    for (int i=0; i<N; i++)
        dp[i][i] = 1;

    // dp[i][j] states that from index i(0) how many subsequences of length j(N) are available.
    for (int L=2; L<=N; L++)
    {
        for (int i=0; i<N; i++)
        {
            int k = L+i-1;
   // cout<<i<<" "<<k<<endl;
            if (str[i] == str[k])
                dp[i][k] = dp[i][k-1] + dp[i+1][k] + 1;
            else
                dp[i][k] = dp[i][k-1] +dp[i+1][k] -dp[i+1][k-1];
        }
    }

    // return total palindromic subsequence from index 0 to length of N;
    return dp[0][N-1];
}


int main() {
	string s;
	int n;
	scanf("%d",&n);
	while(n--)
    {
        cin>>s;
        cout<<countways(s)<<endl;
    }
    return 0;
}

