#include<iostream>
using namespace std;

struct lnode
{
	lnode(){
		data=-1;
		next=NULL;
	}
	int data;
	lnode *next;
};

struct tnode
{
	tnode(){
		data=-1;
		lchild=rchild=NULL;
	}
	tnode *lchild;
	int data;
	tnode *rchild;
	lnode *lptr;
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
	tnode* element[100];
		
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

void addend(lnode* &L,int k)
{
	lnode *T=new lnode;
	T->data=k;
	if(L==NULL)
	{
		L=T;
	}
	else
	{
		lnode *temp=L;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=T;
	}
}

void remove_front(lnode* &L)
{
	if(L==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	else
	L=L->next;
}

void create(tnode* &T,Queue &Q)
{
	tnode *temp,*L,*R;
	while(!Q.isempty())
	{
		L=Q.dequeue();
		if(!Q.isempty())
		{
			R=Q.dequeue();
			temp=new tnode;
			temp->lchild=L;
			temp->rchild=R;
			Q.enqueue(temp);
		}
	}
	T=L;
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

int T_sort(tnode *T)
{
	if(T->lchild==NULL&&T->rchild==NULL)
	{
		if(T->lptr!=NULL)
		return T->lptr->data;
		else
		return -1;
	}
	else
	{
		int l,r;
		l=T_sort(T->lchild);
		r=T_sort(T->rchild);
		T->data=min(l,r);
		return T->data;
	}
}

void remove(tnode *T,int k)
{
	if(T->lchild==NULL&&T->rchild==NULL)
	{
		remove_front(T->lptr);
	}
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
	int i,t;
	for(i=0;i<size;i++)
	{
		t=T_sort(T);
		remove(T,t);
        cout<<t<<" ";
	}
}

int main()
{
	tnode *T=NULL;  //tournament tree
	tnode *temp;
	lnode *L=NULL;
	Queue Q;
	int i=0,size=0,k;
	char ans;
	cout<<"Enter data\n";
	do
	{
		cout<<"Enter data for "<<i+1<<"linked list \n";
		while(1)
		{
			cout<<"Enter -1 to stop\n";
			cin>>k;
			if(k==-1)
			break;
			addend(L,k);  //create new lnode and add at the end of linked list
			size++;
		}
		temp=new tnode;
		temp->lptr=L;
		Q.enqueue(temp);
		L=NULL; //To store another linked list
		cout<<"Want to Enter more y for yes n for no\n";
		cin>>ans;
		i++;  //count of no of linked list
	}while(ans=='y');
	create(T,Q);  //create tournoment tree from linked list in Queue
	Print_sorted(T,size);
}
