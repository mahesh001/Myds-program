#include<iostream>
using namespace std;
const int d=1;

struct bdnode
{
	bdnode()
	{
		c=0;
		for(int i=0;i<2*d+2;i++)
		ptr[i]=NULL;
	}
	int data[2*d+1];
	bdnode* ptr[2*d+2];
	int c;
};

class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=200;
	}
	private:
		int front;
		int rear;
		int size;
		bdnode* element[200];
		
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
	T1->data[0]=-1;
	Q.enqueue(B);
	Q.enqueue(T1);
	
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data[0]==-1)
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(T1);
		}
		else
		{
			int i;
			cout<<"|";
			for(i=0;i<T->c;i++)
			cout<<T->data[i]<<" ";
			for(i;i<2*d;i++)
			cout<<"* ";
			cout<<"|  ";
			
			for(i=0;i<=T->c;i++)
			{
			   if(T->ptr[i]!=NULL)
			   Q.enqueue(T->ptr[i]);
			}
		}
	}
}

void Sort(int a[],int size)
{
	int i=0,j=0,temp;
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1);j++)
		{
		   if(a[j]>a[j+1])
		   {
			  temp=a[j];
			  a[j]=a[j+1];
			  a[j+1]=temp;
		   }
		}
	}
}

void Insert_and_Sort(bdnode *B,int k)
{
	int i,j;
	B->data[B->c++]=k;
	int t,size=B->c;
	bdnode* tptr;
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1);j++)
		{
			if(B->data[j]>B->data[j+1])
			{
				t=B->data[j];
				B->data[j]=B->data[j+1];
				B->data[j+1]=t;
				tptr=B->ptr[j+1];
				B->ptr[j+1]=B->ptr[j+2];
				B->ptr[j+2]=tptr;
			}
		}
	}
}

int check_leafnode(bdnode *B)
{
	if(B->ptr[0]==NULL)
	return 1;
	else
	return 0;
}

void Node_splite(bdnode *T,bdnode* &N,int &median)
{
	int i;
	median=T->data[d];
	for(i=d+1;i<2*d+1;i++)    //copying data and pointers into new node
	{
		N->ptr[N->c]=T->ptr[i];
		N->data[N->c++]=T->data[i];
	}
	N->ptr[N->c]=T->ptr[i];
	T->c=d;    //Now no of element are d
}

void Overflow(bdnode *B,int added_into)
{
	bdnode *N=new bdnode;
	bdnode *T=B->ptr[added_into];
	int median;
	if(check_leafnode(B->ptr[added_into]))
	{
		Node_splite(T,N,median);
		Insert_and_Sort(N,median);
		B->ptr[B->c+1]=N;
		Insert_and_Sort(B,median);
	}
	else
	{
		Node_splite(T,N,median);  //splting node N is new node median is separator
		B->ptr[B->c+1]=N;
		Insert_and_Sort(B,median);
	}
}

void Add(bdnode* &B,int k)
{
	int i;
	if(B==NULL)
	{
		B=new bdnode;
		B->data[B->c++]=k;
		return;
	}
	if(check_leafnode(B))
	{
		B->data[B->c++]=k;  //Simply insert and sort into leafnode
		Sort(B->data,B->c);
	}
	else
	{	
		int added_into=0;
		for(i=0;i<B->c;i++)
		{
			if(k<B->data[i])
			{
			    added_into=i;
				Add(B->ptr[i],k);
				break;
			}
		}
		if(i==B->c)
		{
			added_into=B->c;
			Add(B->ptr[B->c],k);
		}
		if(B->ptr[added_into]->c>2*d)   //checking for Overflow
		{
			Overflow(B,added_into);
		}
	}
}

int main()
{
	bdnode *B=NULL;
	int k;
	cout<<"Enter data for the tree\n";
	//for(int i=1;i<=100;i++)
	do
	{
	   cout<<"Enter -1 to stop\n";
	   cin>>k;
	   if(k==-1)
	   break;
	   Add(B,k);
	   if(B->c>2*d)
	   {
	   	  bdnode *N=new bdnode;
	   	  int median;
	   	  Node_splite(B,N,median);
	   	  if(check_leafnode(N))
	   	  Insert_and_Sort(N,median);
	   	  bdnode *P=new bdnode;
	   	  P->ptr[0]=B;
	   	  P->data[P->c++]=median;
	   	  P->ptr[P->c]=N;
	   	  B=P;
	   }
	   Level_order(B);
	}while(k!=-1);
}
