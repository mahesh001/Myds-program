#include<iostream>
using namespace std;
struct gtnode
{
	gtnode *c[3];
	int data;
	gtnode()
	{
		c[3]={NULL};
	}
};
struct lnode
{
	int data;
	lnode *next;
};
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
		gtnode* element[20];
		
	public:
		int isfull();
		int isempty();
		void enqueue(gtnode* k);
		gtnode* dequeue();
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

void Queue::enqueue(gtnode* k)
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

gtnode* Queue::dequeue()
{
	gtnode* t;
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

void addend(lnode* &L,int k)
{
	if(L==NULL)
	{
		lnode *L=new lnode;
		L->data=k;
		L->next=NULL;
	}
	else
	{
	   lnode *T;
	   T=new lnode;
	   while(L->next!=NULL)
		 L=L->next;
	   T->data=k;
	   T->next=NULL;
	   L->next=T;
	}
}	

gtnode* create(lnode *&L,Queue &Q)
{
    gtnode* T;	
	while(!Q.isempty())
	{
	   T=Q.dequeue();
	   for(int i=0;i<3&&L!=NULL;i++)
	   {
	      T->c[i]=new gtnode;
		  T->c[i]->data=L->data;
		  L=L->next;
	      Q.enqueue(T->c[i]);
	   }
    }
    return T;
}
void preorder(gtnode *T)
{      
    if(T!=NULL)
    {	
		for(int i=0;i<3;i++)
		{ 	
           preorder(T->c[i]);
        }
        cout<<T->data<<" ";
    }	
}
/*preorder printing*/
/*void preorder(gtnode *T)
{
	if(T!=NULL)
	{
		for(int i=0;i<3;i++)
		preorder(T->c[i]);
		
		cout<<T->data<<" ";
	}
}*/
int main()
{	
    Queue Q;
	lnode *L=NULL;
	int k;
	cout<<"Enter the element enter -1 to stop\n";
	while(1)
	{
		cin>>k;
		if(k==-1)
		break;
		addend(L,k);
	}	
	gtnode *T=new gtnode;
	T->data=L->data;
	L=L->next;
	Q.enqueue(T);
	T=create(L,Q);
	cout<<"The preorder of tree is\n";
	preorder(T);
    return 0;
}
