#include<iostream>
using namespace std;

struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};

struct lnode
{
	int data;
	bstnode *bstptr;
	lnode *next;
};

class stack{
	public:
		bstnode* a[20];
		int top;
	public:
		stack(){
			top=-1;
		}
		int isEmpty(){
			if(top==-1)
			return 1;
			else
			return 0;
		}
		int isFull(){
			if(top==19)
			return 1;
			else
			return 0;
		}
		void push(bstnode* ch){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=ch;
		}
		bstnode* pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};

void addend(lnode* &L,int k)
{
	lnode *T=new lnode;
	T->data=k;
	T->bstptr=NULL;
	T->next=NULL;
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

void insert_in_tree(bstnode* &B,int k)
{
	if(B==NULL)
	{
		B=new bstnode;
		B->data=k;
		B->lchild=NULL;
		B->rchild=NULL;
	}
	else
	{
		if(k<B->data)
		insert_in_tree(B->lchild,k);
		else
		insert_in_tree(B->rchild,k);
	}
}

void insert(lnode *L,int k)
{
	lnode *pre=L;
	while(L!=NULL&&k>L->data)
	{
		pre=L;
		L=L->next;
	}
	L=pre;
	insert_in_tree(L->bstptr,k);
}

int search(lnode *L,int k)
{
	lnode *pre=L;
	while(L!=NULL&&k>L->data)
	{
		pre=L;
		L=L->next;
	}
	L=pre;
	bstnode *T=L->bstptr;
	while(T!=NULL)
	{
		if(T->data==k)
		return 1;
		else if(k<T->data)
		T=T->lchild;
		else
		T=T->rchild;
	}
	if(T==NULL)
	return 0;
}

void print(lnode *L)
{
	 stack S;
     for(L;L!=NULL;L=L->next)
	{
		cout<<L->data<<"-";
		if(L->next!=NULL)
		cout<<L->next->data<<" : ";
		else
		cout<<" -- : ";
		bstnode *T=L->bstptr;
	    while(1)
	    {
	    	if(T!=NULL)
		   {
			 S.push(T);
			 T=T->lchild;
		   } 
		   else if(!S.isEmpty())
		   {
			 T=S.pop();
			 cout<<T->data<<" ";
			 T=T->rchild;
		   }
		   else
		   break;
	    }
		cout<<endl;
	}
}

int main()
{
	lnode *L=NULL;
	int k;
	cout<<"Enter the data for linked list\n";
	while(1)
	{
		cout<<"Enter value -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		addend(L,k);
	}
	
	cout<<"Enter the value for binary tree\n";
	while(1)
	{
		cout<<"Enter value -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		insert(L,k);
	}
	cout<<"Enter the element you want to search\n";
	cin>>k;
	if(search(L,k))
	cout<<"\nFOUND\n";
	else
	cout<<"\nNOT FOUND\n";
	cout<<"Printing :\n";
	print(L);
}
