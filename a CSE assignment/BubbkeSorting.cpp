#include<iostream>
using namespace std;

void sorting(int a[],int size)
{
	int i=0,j=0,temp;
	for(i=0;i<(size);i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	
}
int main(){
	int a[5],i;
	cout<<"Enter the 5 integers\n";
	for(i=0;i<5;i++){
		cin>>a[i];
	}
	sorting(a,5);
	cout<<"The sorted no are\n";
	for(i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
	
}
