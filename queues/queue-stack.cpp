#include<iostream>
using namespace std;

class stack
{
	public:
		int a[20]={0};
		int top;
		stack()
		{top=-1;
		}
		int isfull(){
			if(top==19)
			return 1;
			else 
			return 0;
		}
		
		int isempty(){
			if(top==-1)
			return 1;
			else 
			return 0;
		}
		void push(char x){
			if(isfull())
			cout<<"stack overflow";
			else
			a[++top]=x;
			
		}
		
		
		int pop(){
			if(isempty())
			cout<<"stack underflow";
			else{
				
				return a[top--];
				
				}
		}
		};
		
class queue{
	public:
	int front;
	int rear;
	int size;
	int ele[50];
	queue(){
		rear=-1;
		front=-1;
		size=50;
	}
int isfull(queue Q){
	if(((rear+1)%(size))==(front)){
		return 1;
	}
	else{
	return 0;
	}
}
int isempty(queue Q){
	if(front==-1 && rear==-1){
		return 1;
	}
	else{
		return 0;
	}
}
void enqueue(queue &Q,int k){
	if(isfull(Q)==1){
		cout<<"Queue is full";
	}
	else{
		if(front==-1 && rear==-1){
			front=0;
			rear=0;
		}
		else{
			rear=(rear+1)%size;
		}
		ele[rear]=k;
	}
}
int dequeue(queue &Q){
	int t;
	if(isempty(Q)==1){
		cout<<"Queue is empty ";
		return -1;
	}
	else{
		if(front==rear){
			t=ele[front];
			front=-1;
			rear=-1;
		}
		else{
			t=ele[front];
			front=(front+1)%size;
		}
	return t;
	}
}
};

int main()
{
	queue q;
	stack s;
	int i,j,k;
	int c,x;
	cout<<"enter the operation to be performed"
		<<"1.fill queue with stack\n"
		<<"2.fill stack with a queue\n";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"enter stack elements(-1 to stop)\n";
			while(1)
			{
				cout<<"enter an element";
				cin>>k;
				if(k==-1) break;
				
				else  s.push(k);
			}
			//filling of queue
			
			while(!s.isempty())
			{
				x=s.pop();
				q.enqueue(q,x);
				cout<<q.dequeue(q);
			}
			
			break;
			
			case 2:
				cout<<"enter queue elements(-1 to stop)\n";
				while(1)
				{
					cout<<"enter an element";
					cin>>k;	
					if(k==-1) break;
					else q.enqueue(q,k);
					cout<<q.dequeue(q);
				}
				//filling stack
				
				while(!q.isempty(q))
				{
					x=q.dequeue(q);
					s.push(x);
				}
				
			}
			
			//print
		while(!s.isempty())
		cout<<s.pop()<<" ";
		cout<<endl;
		while(!q.isempty(q))
		cout<<q.dequeue(q)<<" ";	
			
			
			return 0;
			
			
			
			
			
			
			
	}	
		
	
	
	
	





