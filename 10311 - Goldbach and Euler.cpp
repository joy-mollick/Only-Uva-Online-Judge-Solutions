#include<bits/stdc++.h>


/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

#define maxi  100000005
bool prime[maxi] ;

void  Sieve()
{
 prime[0] = prime[1] =true ;
    prime[2] = false ;
    int i,j ;
    for(i=3 ; i<=sqrt(maxi) ; i+=2)
    {
        if(prime[i]==false)
        {
            for(j=i*i ; j<=maxi ; j+=(2*i))
            {
                prime[j] = true ;
            }
        }
    }
}

int main()
{
    int n ,i,k;
    Sieve() ;
    while(scanf("%d",&n)==1)
    {
        int f =0 ;
        if(n%2)
        {
            k = n-2 ;
            if(k>2 && prime[k]==false)
                printf("%d is the sum of %d and %d.\n",n,2,k) ;
            else
                printf("%d is not the sum of two primes!\n",n) ;
        }
        else
        {
            for(i= n/2+1 ; i<n ; i++)
            {
                if(prime[i]==false && prime[n-i]==false && (n-i)%2!=0)
                {
                    printf("%d is the sum of %d and %d.\n",n,n-i,i) ;
                    f =1 ;
                    break ;
                }

            }
            if(!f)
            {
                printf("%d is not the sum of two primes!\n",n) ;
            }
        }
    }
    return 0;
}
