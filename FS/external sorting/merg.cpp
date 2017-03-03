#include<iostream>
using namespace std;
void merg(int a,int low,int high)
{
	
}
void mergsort(int *a,int low,int high)
{
	int mid;
	mid=(low+high)/2;
	if(low<high)
	mergsort(a,low,mid);
	mergsort(a,mid+1,high);
	merg(a,low,high);
}
int main()
{
	int a[100],n,i,low=0,high;
	cout<<"enter the size of array";
	cin>>n;
	cout<<"enter the element of array \n";
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<"the unsorted arrray is \n";
	for(i=0;i<n;i++)
	cout<<"\t"<<a[i];
	cout<<endl;
	cout<<"sorted merged array is \n";
	high=n;
	mergsort(a,low,high);
	return 0;
}
