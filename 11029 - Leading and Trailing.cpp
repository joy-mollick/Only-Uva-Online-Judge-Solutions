#include<bits/stdc++.h>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

/*
 Last three digits finding is easy , when we have to know the last digit then we mod number by 10 (%10),Here last three digits So,mod by 1000.Simple
Now the complex thing is finding first three digits we have to use of log property
here think about   log10(n^k)

                 =>k.log10(n)=log value of power used.

here our log value is obviously some form like 10^p * (some fraction number) =log value

just take a look here 100000 * 1.23456 = 123456 (our log value ) [when n=123456 and k=1]

So,if we find out the fractional part then we will get 1.23456 from where by multiplying 100 we will get first 3 digits :)

so when we will get  log value of 123456^1,then the value will be exactly in the form of 5.0915122

Here we notice the integral part 5 is log10 value of 100000 and 0.0915122 is log10 value of 1.23456

then if we slice only fractional part separately then we get from 5.0915122, (.0915122)

Now , if u clever u will find the power of pow(10,0.0915122) which will convert you to 1.23456 which is wanted .Now just multiply this 100 and take integral so first 3 digits

Don't see this code , just use this logic manually
*/

typedef unsigned long long ll;



// Constraints are only 20 , So U can produce these values by using next_permutation then store these into res array.

ll power(ll x, ll y,ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1) {
            res = (res*x) % p;
            }

        // y must be even now
        y = y/2; // y = y/2
        x = (x*x) % p;
    }
    return res;
}




int main() {
	ll n,np,k;
	int test;
	scanf("%d",&test);
	while(test--){
	scanf("%llu %llu",&n,&k);
    double x=k*(log10(n));
        x=x-(int)x;
       // cout<<"diff "<<x<<endl;
        double ans=pow(10, x);
        // cout<<ans<<endl;
        ans=ans*100;
        cout<<(int)ans<<"...";
    printf("%03d\n", power(n, k, 1000));
    }
}

