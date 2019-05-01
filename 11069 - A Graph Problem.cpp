
   // Just precalculate the answer

   #include<bits/stdc++.h>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */


#define maxi  100000001
 #define MAX 46400

typedef unsigned long long ll;


using namespace std;


    int main()
    {
        int arr[77];

        arr[1]=1;
        arr[2]=2;
        arr[3]=2;
        for(int i=4;i<=76;i++)
        {
            arr[i]=arr[i-2]+arr[i-3];
        }
        int n;

        while(scanf("%d",&n)!=EOF){
        printf("%d\n",arr[n]);
        }
        return 0;
    }
