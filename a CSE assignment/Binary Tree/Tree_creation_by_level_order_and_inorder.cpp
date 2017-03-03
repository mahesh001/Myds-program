#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

struct btnode
{
	int x;
	btnode *lchild;
	char data;
	btnode *rchild;
};

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

/*level wise printing of binary tree*/
void levelwise(btnode *B)
{
	double i=0,k=1;
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
		{
		  cout<<endl;
		  i=0;
	    }
		else
		{
		  cout<<T->data<<" ";
		  if(T->lchild!=NULL)
		  Q.enqueue(T->lchild);
		  if(T->rchild!=NULL)
		  Q.enqueue(T->rchild);
		  i=i+2;
		  if(i==pow(2,k)){
		  	k=k+1;
		  	Q.enqueue(T1);
		  }
	    }
	}
}

int Find(char *str,char k,int s,int e)
{
	int i;
	for(i=s;i<=e;i++)
	{
		if(k==str[i])
		break;
	}
	if(i<=e)
	return i;
	else
	return -1;
}

btnode* create_tree(char *In,char *L,int is,int ie,int ls,int le)
{
	int i,index;
	char ch;
	btnode *Root=new btnode;
	btnode *left=NULL,*right=NULL;
	for(i=ls;i<=le;i++)
	{
		ch=L[i];
		index=Find(In,ch,is,ie);
		if(index!=-1)
		break;
	}
	Root->data=In[index];
	if(is<index)
	left=create_tree(In,L,is,index-1,ls+1,le);
	if(index<ie)
	right=create_tree(In,L,index+1,ie,ls+1,le);
	Root->lchild=left;
	Root->rchild=right;
	return Root;
}

int main()
{
	btnode *B;
	int size;
	char level[20],inorder[20];
	cout<<"Enter the level order\n";
	cin>>level;
	cout<<"Enter the inorder\n";
	cin>>inorder;
	
	size=strlen(inorder);
	B=create_tree(inorder,level,0,size-1,0,size-1);
	
	cout<<"The binary tree is :\n";
	levelwise(B);
}
