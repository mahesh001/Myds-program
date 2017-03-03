#include<iostream>
using namespace std;
int main()
{
	int i,j,n,k;
	int a[20];
	cout<<"enter size";
	cin>>n;
	cout<<"enter elements";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int temp=n;
	for(i=0;i<temp;i++)
	{
		for(j=0;j<temp;j++)
		{
			if(a[i]=a[j])
			{
				for(k=j;k<temp;k++)
				{
					a[k]=a[k+1];
				}
				temp=n-1;
			}
			
			
		}
	}
	cout<<"corrected array is";
	for(i=0;i<temp;i++)
	{
		cout<<a[i];
	}
return 0;
}
