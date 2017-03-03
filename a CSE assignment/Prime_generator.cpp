#include<iostream>
using namespace std;

void printPrime(int a,int b)
{
   int  i,j;
   if(a==1)
   a++;
   for(i=a;i<=b;i++)
   {
      for(j=2;j<=(i-1);j++)
      {
         if(i%j==0)
         break;
      }
      if(j==i)
      cout<<i<<" ";
   }
   cout<<endl;
}

int main()
{
   int t;
   cin>>t;
   int no[t][2];
   for(int i=0;i<t;i++)
   {
      cin>>no[i][0];
      cin>>no[i][1];
   }
   for(int i=0;i<t;i++)
   {
      printPrime(no[i][0],no[i][1]);
   }
}
