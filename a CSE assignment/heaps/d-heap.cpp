#include<iostream>
using namespace std;

void swap(int h[],int i,int j)
{
	int temp=h[i];
	h[i]=h[j];
	h[j]=temp;
}
void heapfy(int h[],int d,int index)
{
	while(index>0)
	{
		if(h[index/d]>h[index])
		swap(h,index,index/d);
		index=index/d;
	}
}
void insert(int h[],int k,int d,int &index)
{
	h[++index]=k;
	heapfy(h,d,index);
}
void heapsort(int h[],int d,int &index)
{
	while(index>0)
	{
	  cout<<h[0]<<" ";
	  h[0]=h[index];
	  index--;
	  for(int i=index;i>0;i--)
	  heapfy(h,d,i);
	}
	cout<<h[0]<<endl;
}
int main()
{
	int d=3;
	int h[50];
	int index=-1;
	int k;
	do
	{
		cout<<"Enter the value -1 for stop\n";
		cin>>k;
		if(k==-1)
		break;
		insert(h,k,d,index);
	}while(k!=-1);
	cout<<"Element in sort form are\n";
	heapsort(h,d,index);
}
