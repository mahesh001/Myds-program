#include<iostream>
using namespace std;

class Queue
{
	public:
	int front;
	int rear;
	int size;
	int ele[20];
	Queue()
	{
		rear=-1;
		front=-1;
		size=20;
	}

	int isfull()
	{
		if(((rear+1)%(size))==(front))
			{
				return 1;
			}
			else
			{
			return 0;
			}
	}
	int isempty()
	{
		if(front==-1 && rear==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void enque(int k)
	{
		if(isfull()==1)
		{
			cout<<"Queue is full";
		}
		else
		{
			if(front==-1 && rear==-1)
			{
				front=0;
				rear=0;
			}
			else
			{
				rear=(rear+1)%size;
			}
			ele[rear]=k;
		}		
	}
	int deque()
	{
		int t;
		if(isempty()==1)
		{
			cout<<"Queue is empty ";
			return -1;
		}
		else{
			if(front==rear)
			{
				t=ele[front];
				front=-1;
				rear=-1;
			}
			else
			{
				t=ele[front];
				front=(front+1)%size;
			}
		return t;
		}
	}
};

int main(){
	int n,i,j,t;
	Queue Q;
	
	cout<<"Enter the total no. of elements \n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the no. \n";
		cin>>j;
		Q.enque(j);
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(Q.ele[Q.front+j]>Q.ele[Q.front+j+1])
			{
				t=Q.ele[Q.front+j];
				Q.ele[Q.front+j]=Q.ele[Q.front+1+j];
				Q.ele[Q.front+1+j]=t;
			}
		}
	}
	cout<<"the sorted queue is:\n";
	for(i=0;i<n;i++)
	{	
		cout<<Q.deque()<<"  ";
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
