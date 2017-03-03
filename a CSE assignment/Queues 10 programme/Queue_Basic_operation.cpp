#include<iostream>
using namespace std;

class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=6;
	}
	private:
		int front;
		int rear;
		int size;
		int element[6];
		
	public:
		int isfull();
		int isempty();
		void enqueue(int k);
		int dequeue();
};

int Queue::isfull()
{
	if((rear+1)%size==front)
	 return 1;
	else
	 return 0;
}

int Queue::isempty()
{
	if(front==-1)
	 return 1;
	else
	 return 0;
}

void Queue::enqueue(int k)
{
	if(isfull())
	  cout<<"Queue is full\n";
	else if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear=(rear+1)%size;
	}
	element[rear]=k;
}

int Queue::dequeue()
{
	int t;
	if(isempty())
	  return -1;
	else
	{
		if(front==rear)
		{
		  t=element[front];
		  front=-1;
		  rear=-1;	
		}
		else
		{
			t=element[front];
			front=(front+1)%size;
		}
		return t;
	}
}

int main()
{
	Queue Q;
	int i,size,k;
	cout<<"Enter no of the element for Queue\n";
	cin>>size;
	cout<<"Enter nos\n";
	for(i=0;i<size;i++)
	{
		cin>>k;
		Q.enqueue(k);
	}
	cout<<"Your Queue is\n";
	while(!Q.isempty())
	{
		cout<<Q.dequeue()<<" ";
	}
	/*for(i=0;i<size;i++)
	{
	   cout<<Q.dequeue()<<" ";
    }
    return 0;
    */
}
