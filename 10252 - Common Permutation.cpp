#include<bits/stdc++.h>


/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;


int main()
{
    string a, b;
    while(getline(cin,a) && getline(cin,b))
    {
        map<char,int>ma;
        map<char,int>mb;
        for(int i=0;i<a.size();i++)
        {
            ma[a[i]]++;
        }
        for(int j=0;j<b.size();j++)
        {
            mb[b[j]]++;
        }
        char c='a';
        for(c;c<='z';c++)
        {
            if(ma[c]>0&&mb[c]>0)
            {
                int count=min(ma[c],mb[c]);
                for(int j=0;j<count;j++)
                {
                    cout<<c;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
