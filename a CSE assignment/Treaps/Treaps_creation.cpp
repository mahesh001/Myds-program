#include<iostream>
using namespace std;

struct tnode
{
	tnode *lchild;
	char data;
	int prio;
	tnode *rchild;
};

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
		tnode* element[6];
		
	public:
		int isfull();
		int isempty();
		void enqueue(tnode* k);
		tnode* dequeue();
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

void Queue::enqueue(tnode* k)
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

tnode* Queue::dequeue()
{
	tnode* t;
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

void single_right_rotation(tnode* &T)
{
	cout<<"in si_right\n";
	tnode* N;
	N=T->lchild;
	T->lchild=N->rchild;
	N->rchild=T;
	T=N;
}

void single_left_rotation(tnode* &T)
{
	cout<<"in si_left\n";
	tnode *N;
	N=T->rchild;
	T->rchild=N->lchild;
	N->lchild=T;
	T=N;
}

void Insert(tnode* &T,char data,int prio)
{
	if(T==NULL)
	{
	   T=new tnode;
	   T->data=data;
	   T->prio=prio;
	   T->lchild=NULL;
	   T->rchild=NULL;
	}
	else if(data<T->data)
	{
	   Insert(T->lchild,data,prio);
	   if(T->lchild->prio<T->prio)
	   single_right_rotation(T);
	}
	else
	{
	   Insert(T->rchild,data,prio);
	   if(T->rchild->prio<T->prio)
	   single_left_rotation(T);
	}
}

void Level_order(tnode *H)
{
	Queue Q;
	tnode *T;
	tnode *T1=new tnode;
	T1->data='*';
	Q.enqueue(H);
	Q.enqueue(T1);
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data=='*')
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(T1);
		}
		else
		{
			cout<<T->data<<" "<<T->prio<<"\t";
			if(T->lchild!=NULL)
			Q.enqueue(T->lchild);
			if(T->rchild!=NULL)
			Q.enqueue(T->rchild);
		}
	}
}

int main()
{
	tnode *T=NULL;
	char data;
	int prio;
	
	cout<<"Enter the elment to be inserted in binary search tree\n";
	while(1)
	{
	    cout<<"Enter -1 to end\n";
	    cin>>data;
	    if(data=='/')
		break;
		cin>>prio;
		Insert(T,data,prio);
		cout<<"Level_order :\n";
		Level_order(T);
	}
}
