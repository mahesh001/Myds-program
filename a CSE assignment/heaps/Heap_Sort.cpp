#include<iostream>
using namespace std;
/*display array*/
void show(int h[],int size)
{
	for(int i=1;i<=size;i++)
	cout<<h[i]<<" ";
	cout<<endl;
}
/*swaping two element in the array*/
void swap(int h[],int i,int j)
{
	int temp=h[i];
	h[i]=h[j];
	h[j]=temp;
}
/*heapfy fucntion*/
void heapfy(int h[],int index)
{
	while(index>1)
	{
		if(h[index]<h[index/2])
		{
			swap(h,index,index/2);
		}
		index=index/2;
	}
}
/*inserting values in heap*/
void insert(int h[],int &index,int k)
{
	h[++index]=k;
	heapfy(h,index);
}
/*heapsort function*/
void heapsort(int h[],int &index)
{
	while(index>=1)
	{
		cout<<h[1]<<" ";
		h[1]=h[index--];
		for(int i=index;i>1;i--)//heapfy all elements
		heapfy(h,i);
	}
}
int main()
{
	int index=0;//index of array
	int h[20];
	char ans;//for knowing responce of user
	do
	{
		int k;//key
		cout<<"Enter the no\n";
		cin>>k;
		insert(h,index,k);
		cout<<"do want to enter more y or n\n";
	    cin>>ans;
	}while(ans=='y');
	cout<<"The array is :";
	show(h,index);
	cout<<"The element in sorted order are :\n";
	heapsort(h,index);
}
