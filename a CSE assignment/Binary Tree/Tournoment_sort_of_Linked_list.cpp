#include<iostream>
using namespace std;

struct tnode
{
	tnode *lchild;
	int data;
	tnode *rchild;
	tnode *next;
};
/*Queue of tnode pointers*/
class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=20;
	}
	private:
		int front;
		int rear;
		int size;
		tnode* element[20];
		
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
/*create function for creating tree*/
void create(tnode* &T,Queue &Q)
{
	tnode *T1,*T2,*T3;
	while(!Q.isempty())
	{
		T1=Q.dequeue();
		if(!Q.isempty())
		{
			T2=Q.dequeue();
			T3=new tnode;
			T3->lchild=T1;
			T3->rchild=T2;
			T3->data=-1;
			Q.enqueue(T3);
		}
	}
	T=T1;
}
/*compare function*/
int comp(int a,int b)
{
	if(a==-1&&b==-1)
	return -1;
	else if(a==-1)
	return b;
	else if(b==-1)
	return a;
	else if(a>b)
	return b;
	else
	return a;
}
/*evalueating function*/
int eva(tnode* &T)
{
	if(T!=NULL)
	{
		if(T->data==-1)
		{
			return comp(eva(T->lchild),eva(T->rchild));
		}
		else
		{
			int t;
			t=T->data;
			T=T->next;
			return t;
		}
	}
	else
	return -1;
}
/*intialising function*/
void inti(tnode *T)
{
	if(T!=NULL)
	{
		if(T->lchild!=NULL)
		{
		  T->data=-1;
		  inti(T->lchild);
		  inti(T->rchild);
	    }
	}
}
/*after taking value out set that to -1*/
void remove(tnode *T,int k)
{
	if(T!=NULL)
	{
		if(T->data==k)
		T->data=-1;
		else
		{
		  remove(T->lchild,k);
		  remove(T->rchild,k);
	    }
	}
}
void addend(tnode* &L,int k)
{
	if(L==NULL)
	{
		L=new tnode;
		L->lchild=NULL;
		L->rchild=NULL;
		L->next=NULL;
		L->data=k;
	}
	else
    {
    	while(L->next!=NULL)
    	L=L->next;
    	tnode *T;
    	T=new tnode;
    	T->lchild=NULL;
		T->rchild=NULL;
		T->next=NULL;
		T->data=k;
		L->next=T;
	}
}
int main()
{
	/*tnode objects*/
	tnode *T;
	Queue Q;
	int k,size=0;
	char ch;
	cout<<"Enter the element you want to enter\n";
	do
	{
		cout<<" do you want to enter linked list y for yes and n for no\n";
		cin>>ch;
		if(ch=='y')
		{
		   tnode *L=NULL;//temp node for Linked List
		   do
		   {
			  cout<<"Enter the values\n";
			  cin>>k;
			  if(k!=-1)
			  {
			  	size++;
			  	addend(L,k);
			  }
			  else
			  {
			  	Q.enqueue(L);
			  }
		   }while(k!=-1);
		}
	}while(ch=='y');
	/*creating tree by Queue*/
	create(T,Q);
	/*taking sorted no by evaluating function*/
	cout<<"The sorted no are :\n";
	tnode *head=T;
	for(int i=0;i<size;i++)
	{
		T=head;
		k=eva(T);
		cout<<k<<" ";
		inti(T);//initailise node other then leaf node to -1
		//remove(T,k);
	}
}
