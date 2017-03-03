#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;

/*stack of string*/

class stack{
	public:
		string a[20];
		int top;
	public:
		stack()
		{
			top=-1;
		}
		int isEmpty()
		{
			if(top==-1)
			return 1;
			else
			return 0;
		}
		int isFull()
		{
			if(top==19)
			return 1;
			else
			return 0;
		}
		void push(string str)
		{
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=str;
		}
		string pop()
		{
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};

/*queue of floats*/

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
		float element[6];
		
	public:
		int isfull();
		int isempty();
		void enqueue(float k);
		float dequeue();
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

void Queue::enqueue(float k)
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

float Queue::dequeue()
{
	float t;
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

/*douobly linked list of integers*/

struct dnode
{
	dnode *left;
	int data;
	dnode *right;
};

void addend(dnode *D,int k)
{
	dnode *T;
	T=new dnode;
	T->right=NULL;
	T->data=k;
	while(D->right!=NULL)
	   D=D->right;
	D->right=T;
	T->left=D;
}

/*union for dnode,stack and queue*/

union u
{
	dnode *D;
	Queue *Q;
	stack *S;
};

/*Generic structure*/

struct gnode
{
	int tag;
	u u1;
	gnode *next;
};

/*check function*/

int check(char *input)
{
	char ch;
	int l=strlen(input);
	for(int i=0;i<l;i++)
	{
		ch=input[i];
		if(isalpha(ch))
		  return 1;
		else if(ch=='.')
	      return 2;
	}
	return 3;
}

/*function to print doubly linked list*/

void printList(dnode *D)
{
	while(D!=NULL)
	{
	   cout<<D->data<<" ";
	   D=D->right;	
	}
	cout<<endl;
}

/*print method for generic linked list*/

void print(gnode *G)
{
	while(G!=NULL)
	{
		if(G->tag==1)
		{
			cout<<"Stack of string is:\n";
			while(!G->u1.S->isEmpty())
			  cout<<G->u1.S->pop()<<" ";
			  cout<<endl;
		}
		else if(G->tag==2)
		{
			cout<<"Your queue of float is:\n";
			while(!G->u1.Q->isempty())
			  cout<<G->u1.Q->dequeue()<<" ";
			  cout<<endl;
		}
		else if(G->tag==3)
		{
			cout<<"Your doubly lniked list of integer is:\n";
			printList(G->u1.D);
		}
		G=G->next;
	}
}

int main()
{
	int i,empty=1;
	char ch1='y';
	
	char input[20];
	gnode *G,*T;
	G=new gnode;
	G->tag=1;
	G->u1.S=new stack;
	T=G;
	G->next=new gnode;
	G=G->next;
	G->tag=2;
	G->u1.Q=new Queue;
	G->next=new gnode;
	G=G->next;
	G->tag=3;
	G->u1.D=new dnode;
	G->u1.D->right=NULL;
	G->next=NULL;
	G=T;
	while(ch1=='y')
	{
		cout<<"Enter the value\n";
		cin>>input;
		
		switch(check(input))
		{
			case 1:
				G->u1.S->push(input);
				break;
			case 2:
				T=G;
			    G=G->next;
			    G->u1.Q->enqueue(atof(input));
			    G=T;
			    break;
			case 3:
				T=G;
				for(i=0;i<2;i++)
				G=G->next;
				if(empty==1)
				{
				  G->u1.D->data=atoi(input);
				  empty=0;
			    }
			    else
			    addend(G->u1.D,atoi(input));
			    G=T;
		}
		
		cout<<"want to enter more y for yes and n for no\n";
		cin>>ch1;
	}
	
	cout<<"Your Generic lniked list is:\n";
	print(G);
}
