#include<bits/stdc++.h>


/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

bool isprime(long long int n)
{
    long long int range=sqrt(n),i;
    for(i=2;i<=range;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long int n;
    while(scanf("%lld",&n)&&n!=0)
    {
        bool a=isprime(n);
        bool b=isprime((1LL<<n)-1LL);
        if(a&&b)
        {
            printf("Perfect: %lld!\n", (1LL<<(n-1))*((1LL<<n)-1));
        }
        else if(a&&!b)
        {
            printf("Given number is prime. But, NO perfect number is available.\n");
        }
        else{
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
    }
}
