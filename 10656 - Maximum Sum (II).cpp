#include<bits/stdc++.h>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;

#define maxi  100000001

typedef unsigned long long ll;


int main() {
	int n;

	while (scanf("%d",&n),n) {
		vector<int> v;

		for(int i=0;i<n;i++){
			int m;
			scanf("%d",&m);
			if(m>0) v.push_back(m);
		}

		int sze = v.size();
		if(sze==0) printf("0\n");
		else{
			for(int i=0;i<sze;i++){
				printf("%d",v[i]);
				if(i!=sze-1) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}

