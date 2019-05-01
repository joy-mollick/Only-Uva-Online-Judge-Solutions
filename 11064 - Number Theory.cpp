
   // U have to find out for which number gcd(m,n)!=1 && gcd(m,n)!=m...........So, find numbers for gcd(m,n)=1 and divisors numbers


   #include<bits/stdc++.h>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */


#define maxi  100000001
 #define MAX 46400

typedef unsigned long long ll;


using namespace std;

vector<int>prime;

bool check[MAX];

int phi_value;

    void sieve()
    {
        int i,j,k;

        k = sqrt(MAX);

        prime.push_back(2);

        for(i=3; i<=k; i+=2)
        {
            if(check[i]==0)
            {
                for(j=i*i; j<MAX; j+=i+i)
                {
                    check[j]=1;
                }
            }
        }

        for(i=3;i<MAX;i+=2)
        {
            if(!check[i])
                prime.push_back(i);
        }
    }

    int countDivisor(int n)
    {
        int cnt=0,divisor = 1;

        int i,len = prime.size();

        for(i=0; i<len && prime[i]*prime[i]<=n; i++)
        {
            cnt = 0;

            if(n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    n/=prime[i];

                    cnt++;
                }

                phi_value-=(phi_value/prime[i]);

                divisor*=(cnt+1);
            }
        }

        if(n>1)
        {
            phi_value-=(phi_value/n);

            divisor*=2;// divisors=divisors*(1+1)
        }

        return divisor;
    }

    int main()
    {
        sieve();// prime generation

        int n,divisors;

        while(scanf("%d",&n)==1)
        {
            phi_value = n;

            divisors = countDivisor(n);

            // cout<<divisors<<" "<<phi_value<<endl;

            printf("%d\n",n-phi_value-divisors+1);
        }

        return 0;
    }
