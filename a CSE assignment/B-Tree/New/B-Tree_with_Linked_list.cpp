#include<iostream>
using namespace std;
const int d=1;

struct bdnode
{
	bdnode(){
		data=0;
		ptr=right=left=NULL;
	}
	int data;
	bdnode *ptr;
	bdnode *left;
	bdnode *right;
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
		bdnode* element[20];
		
	public:
		int isfull();
		int isempty();
		void enqueue(bdnode* k);
		bdnode* dequeue();
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

void Queue::enqueue(bdnode* k)
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

bdnode* Queue::dequeue()
{
	bdnode* t;
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

void Level_order(bdnode *B)
{
	if(B==NULL)
	{
		cout<<"TREE IS EMPTY\n";
		return;
	}
	Queue Q;
	bdnode *T,*T1;
	T1=new bdnode;
	T1->data=-1;
	Q.enqueue(B);
	Q.enqueue(T1);
	
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data==-1)
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(T1);
		}
		else
		{
			int i=0;
			cout<<"|";
			if(T->ptr!=NULL)
			Q.enqueue(T->ptr);
			while(T->right!=NULL)
			{
				T=T->right;
				cout<<T->data<<" ";
				if(T->ptr!=NULL)
			    Q.enqueue(T->ptr);
				i++;
			}
			for(i;i<2*d;i++)
			cout<<"* ";
			cout<<"|  ";
		}
	}
}

void swap_data(bdnode *x,bdnode *y)  //swaping two nodes data
{
	int tdata=x->data;
	bdnode *tptr=x->ptr;
	x->data=y->data;
	x->ptr=y->ptr;
	y->data=tdata;
	y->ptr=tptr;
}

int check_leafnode(bdnode *B)
{
	if(B->ptr==NULL)
	return 1;
	else
	return 0;
}

void Insert_and_Sort(bdnode *B,int k,bdnode *N)
{
	bdnode *head=B;
	B->data++;  //count is increased
	while(B->right!=NULL)
	B=B->right;
	B->right=new bdnode;
	B->right->left=B;
	B=B->right;
	B->data=k;
	B->ptr=N;
	//inserting at appropreate location
	bdnode *newnode=B;
	B=head;
	int count=B->data;
	while(newnode->data<newnode->left->data && count>1)  
	{
		swap_data(newnode,newnode->left);
		newnode=newnode->left;
		count--;
	}
}

void Node_splite(bdnode *B,bdnode* &N,int &median)
{
	bdnode *head=B;
	B->data=d;     //after node splitting node has d data values
	for(int i=0;i<d;i++)
	B=B->right;
	bdnode *temp=B->right;
	temp->left=NULL;
	B->right=NULL;
	median=temp->data;
	N->ptr=temp->ptr;
	N->right=temp->right;
	N->data=d;   //after node splitting newnode has d data values
	N->right->left=N;
	temp->right=temp->left=temp->ptr=NULL;
	delete temp;
}

void Overflow(bdnode *B,int added_into)
{
	bdnode *temp=B;
	bdnode *N=new bdnode;
	int median;
	for(int i=0;i<added_into;i++)
	temp=temp->right;
	Node_splite(temp->ptr,N,median);
	
	Insert_and_Sort(B,median,N);
}

void Add(bdnode* &B,int k)
{
	bdnode *head=B;
	if(B==NULL)
	{
		B=new bdnode;
		Insert_and_Sort(B,k,NULL);
		return;
	}
	if(check_leafnode(B))
	{
		Insert_and_Sort(B,k,NULL);
	}
	else
	{
		int i=0,added_into=0;
		bdnode *temp=B;
		while(temp->right!=NULL && k>temp->right->data)
		{
			temp=temp->right;
			added_into++;
		}
		Add(temp->ptr,k);
		if(temp->ptr->data>2*d)
		{
			Overflow(B,added_into);
		}
	}
}

int main()
{
	bdnode *B=NULL;
	int k;
	do
	{
	   cout<<"Enter -1 to stop\n";
	   cin>>k;
	   if(k==-1)
	   break;
	   Add(B,k);
	   if(B->data>2*d)
	   {
	   	  int median;
	   	  bdnode *N=new bdnode;
	   	  Node_splite(B,N,median);
	   	  bdnode *P=new bdnode;
	   	  P->ptr=B;
	   	  Insert_and_Sort(P,median,N);
	   	  B=P;
	   }
	   cout<<"Level_order\n";
	   Level_order(B);
	}while(k!=-1);
}
