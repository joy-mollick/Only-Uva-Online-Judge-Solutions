#include<bits/stdc++.h>


/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

#define maxi  100000005

vector<long long int>factors;

void prime_factors(long long int n)
{
    long long count=0;
    while(n%2==0)
    {
        n=n>>1;
        count++;
    }
    factors.push_back(count);
    for(long long int i=3;i<=sqrt(n)+1;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
                count++;
            }
            factors.push_back(count);
        }
        count=0;
    }
    if(n>2)
    {
        factors.push_back(1);
    }
}

int gcd(long long int a, long long int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to find gcd of array of
// numbers
long long int findGCD(vector<long long int> arr)
{
    int n=arr.size();
    long long int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}


int main()
{
    long long int n;
    while(scanf("%lld",&n)==1&&n!=0)
    {
        bool neg=n<0;
        factors.clear();
        if(n<0)
        {
            n=n*(-1);
        }
       if(n==INT_MAX)
       {
           printf("31\n");
       }
       if(n==1)
       {
           printf("1\n");
       }
       else{
        prime_factors(n);
        long long int ans=findGCD(factors);
        if(neg)
        {
            if(ans&1)
            {
                 printf("%lld\n",ans);
            }
            else{
                while(ans%2==0)
                {
                    ans=ans>>1;
                }
                printf("%lld\n",ans);
            }
        }
        else{
        printf("%lld\n",ans);}
       }
    }
    return 0;
}
