#include<iostream>
using namespace std;

struct tnode
{
	tnode(){
		data=-1;
		lchild=rchild=NULL;
	}
	tnode *lchild;
	int data;
	tnode *rchild;
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
/*return minimum */
int min(int a,int b)
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
int T_sort(tnode *T)
{
	if(T->lchild==NULL&&T->rchild==NULL)
	{
	   return T->data;
	}
	else
	{
	   int a,b;
	   a=T_sort(T->lchild);
	   b=T_sort(T->rchild);
	   T->data=min(a,b);
	   return T->data;
	}
}

void remove(tnode *T,int k)
{
	if(T->lchild==NULL&&T->rchild==NULL)
	T->data=-1;
	else
	{
	   if(T->lchild->data==k)
	   remove(T->lchild,k);
	   else
	   remove(T->rchild,k);
	}
	
}

void Print_sorted(tnode *T,int size)
{
	for(int i=0;i<size;i++)
	{
		int temp=T_sort(T);
		remove(T,temp);
		cout<<temp<<" ";
	}
	cout<<endl;
}

int main()
{
	/*tnode objects*/
	tnode *T;
	Queue Q;
	int size=0,k;
	cout<<"Enter the element you want to enter\n";
	do
	{
		cout<<"Enter the value enter -1 to stop\n";
		tnode *temp;//temp node for input
		cin>>k;
		if(k!=-1)
		{
			temp=new tnode;
			temp->data=k;
			Q.enqueue(temp);
			size++;//for no of elements
		}
	}while(k!=-1);
	/*creating tree by Queue*/
	create(T,Q);
	/*print element in their sorted order*/
	Print_sorted(T,size);
}
