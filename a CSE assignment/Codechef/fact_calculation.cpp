#include<iostream>
using namespace std;

void convert(int no[],int n)
{
	int i=-1;
	while(n>0)
	{
		no[++i]=n%10;
		n=n/10;
	}
	int j,temp;
	for(j=0;j<i/2;i++)
	{
		temp=no[j];
		no[j]=no[i-j];
		no[i-j]=temp;
    }
}

void multi(int ans[],int no[])
{
	int temp[20];
}

int main()
{
	int t,n;
	int ans[20],no[10];
	
	for(int i=0;i<t;i++)
	{
		cin>>n;
		while(n>1)
		{
			convert(no,n);
			multi(ans,no);
			n--;
		}
		print(ans);
	}
}
