#include<iostream>
#include<string>
using namespace std;

class stack{
	public:
		int a[20];
		int top;
	public:
		stack(){
			top=-1;
		}
		int isEmpty(){
			if(top==-1)
			return 1;
			else
			return 0;
		}
		int isFull(){
			if(top==19)
			return 1;
			else
			return 0;
		}
		void push(int k){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=k;
		}
		int pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};

/*queue class*/

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

/*printing fucntion for queue*/

void printqueue(Queue Q)
{
	cout<<"Your Queue is:\n";
	while(!Q.isempty())
	  cout<<Q.dequeue()<<" ";
	  cout<<endl;
}

/*printing function for stack*/

void printstack(stack S)
{
	cout<<"Your stack is;\n";
	while(!S.isEmpty())
	  cout<<S.pop()<<" ";
	  cout<<endl;
}

int main()
{
	Queue Q;
	stack S;
	int tag,size,i,k;
	cout<<"Enter tag (1 for stack and 2 for queue)\n";
	cin>>tag;
	
	if(tag==1)
	{
		cout<<"Enter the no of element for stack\n";
		cin>>size;
		cout<<"Enter the elements\n";
		for(i=0;i<size;i++)
		{
			cin>>k;
			S.push(k);
		}
		/*filling queue with stack*/
		for(i=0;i<size;i++)
		{
			k=S.pop();
			Q.enqueue(k);
		}
		/*printing the queue*/
		printqueue(Q);
	}
	else if(tag==2)
	{
		cout<<"Enter the no of element for queue\n";
		cin>>size;
		cout<<"Enter the elements\n";
		for(i=0;i<size;i++)
		{
			cin>>k;
			Q.enqueue(k);
		}
		/*filling stack with queue*/
		for(i=0;i<size;i++)
		{
			k=Q.dequeue();
			S.push(k);
		}
		/*printing the stack*/
		printstack(S);
	}
}
