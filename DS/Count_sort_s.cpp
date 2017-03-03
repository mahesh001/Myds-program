#include<iostream>
using namespace std;

int findmax(int a[],int n)
{
    int max=a[0];
    int i;
    for(i=0;i<n;i++)
    {
                    if(a[i]>max)
                    max=a[i];
    }
return max;
}

void count_sort(int a[],int n,int b[])
{
     int k;
     k=findmax(a,n);
     int c[k];
     int i,j;
     for(i=1;i<k;i++)
     c[i]=0;
     for(j=0;j<n;j++)
     c[a[j]]+=1;
     for(i=1;i<=k;i++)
     c[i]+=c[i-1];
     for(j=n-1;j>=0;j--)
     {
                        b[c[a[j]]]=a[j];
                        c[a[j]]-=1;
     }
}
 
 int main()
 {
     int a[100],b[100],n,i;
     cout<<"Enter size\n";
     cin>>n;
     cout<<"Enter elements\n";
     for(i=0;i<n;i++)
     cin>>a[i];
     count_sort(a,n,b);
     cout<<"Sorted\n";
     for(i=0;i<n;i++)
     cout<<b[i];
     
     return 0;
 }                 
