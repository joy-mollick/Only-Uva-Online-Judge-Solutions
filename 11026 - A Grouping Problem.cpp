
#include<bits/stdc++.h>

// Clasical dp problem , U have to find out in which way U have to precalculate the result %m.

using namespace std;

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

long long product[1005][1005];// all elements initially zero(0)

int main()
{
    int n, m, A[1005], i, k;
    while(scanf("%d %d", &n, &m) == 2) {
        if(n== 0&&m==0)
            break;
        for(i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        product[0][0] = 1;// no element selected so sum is zero
        // product[i][k] means the summation of product upto i index when group size is k
        for(i = 1; i <= n; i++) {
            product[i][0] = 1;// element upto index i but k(0) element so sum is zero(0)
            for(k = 1; k <= i; k++) {
                product[i][k] = product[i-1][k] + product[i-1][k-1]*A[i];
                if(product[i][k] >= m){
                    product[i][k] %= m;
                }
            }
        }
        long long ans = 0;
        for(i = 1; i <= n; i++)
            ans = max(product[n][i], ans);
        printf("%lld\n", ans);
    }
    return 0;
}
