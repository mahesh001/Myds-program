#include<iostream>
using namespace std;

int main()
{
	int t,k;
	scanf("%d %d",&t,&k);
	
	int count=0,no;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&no);
		if(no%k==0)
		count++;
	}
	cout<<count;
}
