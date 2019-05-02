#include<bits/stdc++.h>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

// normal dp problem
typedef unsigned long long ll;

 ll longest_pal(string str)
{
   ll n =str.size();
   ll i, j, k;
   ll dp[n][n];  // Create a table to store results of subproblems
    memset(dp,0,sizeof(dp));

   // Strings of length 1 are palindrome of lentgh 1
   for (i = 0; i < n; i++)
      dp[i][i] = 1;

    for (int i=2; i<=n; i++)
    {
        for (int j=0; j<n-i+1; j++)
        {
            int k = i+j-1;
             if (str[j] == str[k])
               dp[j][k] = dp[j+1][k-1] + 2;
            else
               dp[j][k] = max(dp[j][k-1], dp[j+1][k]);
        }
    }

    return dp[0][n-1];
}


int main() {
	string s;
	int n;
	scanf("%d",&n);
	cin.ignore();
	while(n--)
    {
        getline(cin,s);
        if(s=="")
        {
            cout<<"0"<<endl;
            continue;
        }
        cout<<longest_pal(s)<<endl;
    }
    return 0;
}

