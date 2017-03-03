#include<iostream>
using namespace std;

void swap(int a[],int c,int d)
{
	int t=a[c];
	a[c]=a[d];
	a[d]=t;
}

void quick_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int l=low+1,h=high,p=a[low];
		
		while(l<=h)
		{
			while(a[l]<p && l<=high)
			l++;
			while(a[h]>p && h>low)
			h--;
			swap(a,l,h);
		}
		cout<<"h="<<h<<endl;
		swap(a,h,low);
		
		quick_sort(a,low,h-1);
		quick_sort(a,h+1,high);
	}
}

int main()
{
	int i,j,a[10];
	cout<<"Enter 10 value\n";
	for(i=0;i<10;i++)
	cin>>a[i];
	
	quick_sort(a,0,9);
	
	cout<<"Sort array is \n";
	for(i=0;i<10;i++)
	cout<<a[i]<<" ";
}
