#include<iostream>
using namespace std;

struct btnode
{
	int level;
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
		size=100;
	}
	int front;
	int rear;
	int size;
	btnode* element[100];
		
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

void create(btnode* &B)
{
	char ch;
	if(B==NULL)
	{
		cout<<"Enter / for end\n";
		cin>>ch;
		if(ch=='/')
		return;
		B=new btnode;
		B->data=ch;
		B->lchild=NULL;
		B->rchild=NULL;
	}
	cout<<"Enter the lchild value of "<<B->data<<" ";
	create(B->lchild);
	cout<<"Enter the rchild value of "<<B->data<<" ";
	create(B->rchild);
}

/*void printspiral(btnode* &B)
{
	Queue Q;
	int l=0;
	Q.enqueue(B);
	btnode *T;
	btnode *T1=new btnode;
	T1->data='*';
	Q.enqueue(T1);
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data=='*')
		{
			cout<<endl;
			l=(l+1)%2;
			if(!Q.isempty())
			Q.enqueue(T1);
		}
		else
		{
			cout<<T->data<<" ";
			if(l==0)
			{
				if(T->lchild!=NULL)
				Q.enqueue(T->lchild);
				if(T->rchild!=NULL)
				Q.enqueue(T->rchild);
			}
			else
			{
				if(T->rchild!=NULL)
				Q.enqueue(T->rchild);
				if(T->lchild!=NULL)
				Q.enqueue(T->lchild);
			}
		}
	}
}*/

void getlevel(btnode *B,int l)
{
	if(B!=NULL)
	{
		B->level=l;
		getlevel(B->lchild,l+1);
		getlevel(B->rchild,l+1);
	}
}

int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}

int height(btnode *B)
{
	if(B==NULL)
	return -1;
	else
	{
		return 1+max(height(B->lchild),height(B->rchild));
	}
}

void printlevel(btnode *B,int l,int level)
{
	if(B!=NULL)
	{
		if(B->level==level)
		cout<<B->data<<" ";
		else
		{
			if(l)
			{
				printlevel(B->rchild,l,level);
				printlevel(B->lchild,l,level);
			}
			else
			{
				printlevel(B->lchild,l,level);
				printlevel(B->rchild,l,level);
			}
		}
	}
}

void printspiral(btnode *B)
{
	int l=0;
	int h=height(B);
	for(int i=0;i<=h;i++)
	{
		printlevel(B,l,i);
		cout<<endl;
		l=(l+1)%2;
    }
}

int main()
{
	btnode *B=NULL;
	cout<<"Enter the root node\n";
	create(B);
	cout<<"Getting level\n";
	getlevel(B,0);
	cout<<"Print spiral\n";
	printspiral(B);
}
