#include<bits/stdc++.h>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

typedef unsigned long long ll;

// For time limit , You have to use binary search and I have used lower_bound and upper_bound function properly which takes also o(nlogn) time


int main() {
	int N,nq,a;
	scanf("%d",&N);
	vector<int>v(N);
	for(int i=0;i<N;i++)
    {
        scanf("%d",&v[i]);
    }
    scanf("%d",&nq);
    for(int j=0;j<nq;j++)
    {
        scanf("%d",&a);
        vector<int>::iterator iter=lower_bound(v.begin(),v.end(),a);
        if(iter!=v.end())
        {
            if(iter==v.begin())
            {
                cout<<"X ";
            }
            else{
                iter--;
                cout<<(*iter)<<" ";
            }
        }
        else{
            iter--;
            if((*iter)<a)
            {
                cout<<(*iter)<<" ";
            }
            else{
                cout<<"X ";
            }
        }
        vector<int>::iterator it=upper_bound(v.begin(),v.end(),a);
        if(it==v.end())
        {
            cout<<"X";
        }
        else{
            cout<<(*it);
        }
        cout<<endl;
    }
    return 0;
}

