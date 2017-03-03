#include<iostream>
#include<cmath>
using namespace std;
int height(int a)
{	
	int i=0;
	while((pow(2,i))<a)
		i++;
	return i;
}
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int main()
{	int n;
	cout<<"Enter no of elements:";
	cin>>n;
	int h=height(n);
	cout<<h;
	int  z=pow(2,(h+1))-2;
	cout<<z;
	int *a;
	a=new int[z];
	for(int i=0;i<=z;i++)
		a[i]=-1;
	int s=pow(2,h)-1;
	cout<<"enter elements:";
	int x;
	int i=0;
	while(i<n)
		{
			cin>>x;
			a[s++]=x;
			i++;
		}
	cout<<endl;
	int c=1;
	i=0;
	cout<<"sorted order:";
while(i<n)
	{ 

		int l=z;
		while(l>=2)
		{
			a[(l-2)/2]=max(a[l],a[l-1]);
			l=l-2;
		}
		if(a[0]!=-1)
			cout<<a[0]<<endl;
		for(int k=1;k<=z;k++)
			if(a[k]==a[0])
				a[k]=-1;
			i--;
	}
return 0;
}
