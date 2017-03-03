#include<iostream>
#include<cmath>
using namespace std;

struct btnode
{
	int x;
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

class stack{
	public:
		btnode* a[20];
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
		void push(btnode* ch){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=ch;
		}
		btnode* pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};

void create(btnode* &T)
{
	char ch;
	if(T==NULL)
	{
		cout<<"Enter / for end\n";
		cin>>ch;
		if(ch=='/')
		return;
		T=new btnode;
		T->data=ch;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	cout<<"Enter the lchild value of "<<T->data<<" ";
	create(T->lchild);
	cout<<"Enter the rchild value of "<<T->data<<" ";
	create(T->rchild);
}

void postorder(btnode *B)
{
	stack S1,S2;
	S1.push(B);
	btnode *T;
	while(!S1.isEmpty())
	{
		T=S1.pop();
		if(T->lchild!=NULL)
		S1.push(T->lchild);
		if(T->rchild!=NULL)
		S1.push(T->rchild);
		S2.push(T);
	}
	while(!S2.isEmpty())
	{
		cout<<S2.pop()->data<<" ";
	}
	cout<<endl;
}

void preorder(btnode *B)
{
	stack S;
	S.push(B);
	btnode *T;
	while(!S.isEmpty())
	{
		T=S.pop();
		cout<<T->data<<" ";
		if(T->rchild!=NULL)
		S.push(T->rchild);
		if(T->lchild!=NULL)
		S.push(T->lchild);
	}
	cout<<endl;
}

void inorder(btnode *B)
{
	stack S;
	btnode *T=B;
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

int main()
{
	btnode *B=NULL;
	cout<<"Enter the root of binary tree\n";
	create(B);
	cout<<"The inorder traversal is :\n";
	inorder(B);
	cout<<"The preorder traversals is :\n";
	preorder(B);
	cout<<"The postorder traversals is :\n";
	postorder(B);
}
