#include<iostream>
using namespace std;


class heap
{
	public :
		heap(){
			index=0;
		}
		void Insert(int a);   //insert a into the heap
		int min();            //delete and return min element in the heap
		void print();
	private :
		int index;  //no of vertics
		int A[20];
};

void heap::print()
{
	for(int i=1;i<=index;i++)
	cout<<A[i]<<" ";
	cout<<endl;
}

void heap::Insert(int a)
{
	index++;
	
	int i=index;
	
	while(i>1 && a<A[i/2])
	{
		A[i]=A[i/2];
		i=i/2;
	}
	A[i]=a;
}

int heap::min()
{
	int mini=A[1],temp=A[index];
	index--;
	
	int i=1;
	while(i<=index/2)
	{
		if(A[2*i]<A[2*i+1])
		{
			if(temp<A[2*i])
			break;
			else
			{
				A[i]=A[2*i];
				i=2*i;
			}
		}
		else
		{
			if(temp<A[2*i+1])
			break;
			else
			{
				A[i]=A[2*i+1];
				i=2*i+1;
			}
		}
	}
	
	A[i]=temp;
	return mini;
}

int main()
{
	heap H;
	
	int temp,size=0;
	cout<<"Enter element -1 to stop\n";
	cin>>temp;
	while(temp!=-1)
	{
		H.Insert(temp);
		size++;
		cin>>temp;
	}
	
	cout<<"The element are \n";
	while(size>0)
	{
		cout<<H.min()<<" ";
		size--;
	}
	cout<<endl;
}
