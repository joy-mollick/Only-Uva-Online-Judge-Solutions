#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstring>
#include<vector>

/*
Nayeem Mollick Joy , Electrical & Electronic Engineering , University of Rajshahi.
Passionate Contest Programmer , Coder , Android Developer */

using namespace std;



int main()
{
  double a,b,c;
  while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
  {
      double perimeter=(a+b+c)/(2.0);
      double r=sqrt(((perimeter-a)*(perimeter-b)*(perimeter-c))/(perimeter));
      if(a == 0 || b == 0 || c == 0)
      {
          r=0;
      }
      printf("The radius of the round table is: %0.3lf\n",r);
  }
  return 0;
}
