#include<iostream>
#include<cmath>
using namespace std;

struct btnode
{
	btnode *lchild;
	char data;
	btnode *rchild;
};

/*Queue class*/
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
		btnode* element[6];
		
	public:
		int isfull();
		int isempty();
		void enqueue(btnode* k);
		btnode* dequeue();
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

void Queue::enqueue(btnode* k)
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

btnode* Queue::dequeue()
{
	btnode* t;
	if(isempty())
	  return NULL;
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
/*level wise printing of binary tree*/
void levelwise(btnode *B)
{
	double i=1.0,k=0;
	btnode *T=B,*T1;
	T1=new btnode;
	T1->data='*';
	Queue Q;
	Q.enqueue(T);
	Q.enqueue(T1);
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data=='*')
		cout<<endl;
		cout<<T->data<<" ";
		if(T->lchild!=NULL)
		Q.enqueue(T->lchild);
		if(T->rchild!=NULL)
		Q.enqueue(T->rchild);
		i=i*2;
		k=k+1;
		if(i==pow(2,k))
		Q.enqueue(T1);
	}
}

void create(btnode* &T)
{
	char ch;
	if(T==NULL)
	{
		cout<<"Enter / for end\n";
		cin>>ch;
		if(ch=='/')
		return;
		T=new btnode;
		T->data=ch;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	cout<<"Enter the lchild value of "<<T->data<<" ";
	create(T->lchild);
	cout<<"Enter the rchild value of "<<T->data<<" ";
	create(T->rchild);
}

int main()
{
	btnode *B=NULL;
	cout<<"Enter the root of binary tree\n";
	create(B);
	cout<<"The binary tree is :\n";
	levelwise(B);
}
