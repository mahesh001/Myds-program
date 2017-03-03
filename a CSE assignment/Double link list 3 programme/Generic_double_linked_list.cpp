#include<iostream>
using namespace std;

class stack{
	public:
		int a[20];
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
		void push(int ch){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=ch;
		}
		int pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};

struct lnode{
	int data;
	lnode *next;
};

struct dnode{
	dnode *left;
	int data;
	dnode *right;
};

union uni{
	stack *s;
	lnode *l;
	dnode *dl;
};

struct gnode{
	int tag;
	gnode *left;
	uni u;
	gnode *right;
};

void addend(lnode* L,int k)
{
	lnode* T;
	T=new lnode;
	T->data=k;
	T->next=NULL;
	while(L->next!=NULL)
	  L=L->next;
	L->next=T;
}

void addend(dnode *D,int k)
{
	dnode *T;
	T=new dnode;
	T->right=NULL;
	T->data=k;
	while(D->right!=NULL)
	   D=D->right;
	D->right=T;
	T->left=D;
}

void addafter(dnode *D,int x,int k)
{
	dnode *T;
	T=new dnode;
	T->data=k;
	while(D!=NULL)
	{
	   if(D->data==x&&D->right!=NULL)
	   {
	   	  T->right=D->right;
	   	  T->left=D;
	   	  D->right->left=T;
	   	  D->right=T;
	   }
	   else if(D->data==x)
	   {
	   	T->right=NULL;
	   	D->right=T;
	   	T->left=D;
	   }
	   D=D->right;
	}
}

void addbefor(dnode *D,int x,int k)
{
	dnode *T;
	T=new dnode;
	T->data=k;
	while(D!=NULL)
	{
		if(D->data==x)
		{
			D->left->right=T;
			T->right=D;
			T->left=D->left;
			D->left=T;
		}
		D=D->right;
	}
}

void addend(gnode *G)
{
	gnode *T;
	T=new gnode;
	T->right=NULL;
	while(G->right!=NULL)
	  G=G->right;
	G->right=T;
	T->left=G;
	
	int i,k,no,tag;
	
   cout<<"Enter the tag for the element you want to enter\n";
   cout<<"(0 for stack, 1 for linked list and 2 for double linked list)\n";
   
   cin>>tag;
   
   if(tag==0)
   {
   	  T->tag=0;
   	  T->u.s=new stack;
   	  cout<<"Enter the element you want to have in stack\n";
   	  cin>>k;
   	  cout<<"Enter the element\n";
   	  for(i=0;i<k;i++)
      {
      	 cin>>no;
      	 T->u.s->push(no);
   	  }
   }
   else if(tag==1)
   {
   	  T->tag=1;
   	  T->u.l=new lnode;
   	  T->u.l->next=NULL;
   	  cout<<"Enter the no of element you want to have in Linked List\n";
   	  cin>>k;
   	  cout<<"Enter the nos\n";
   	  cin>>no;
   	  T->u.l->data=no;
   	  for(i=1;i<k;i++)
	  {
	  	 cin>>no;
	  	 addend(T->u.l,no);
   	  }
   }
   else if(tag==2)
   {
   	  T->tag=2;
   	  T->u.dl=new dnode;
   	  T->u.dl->left=NULL;
   	  T->u.dl->right=NULL;
   	  cout<<"Enter the no of element you want to have in Linked List\n";
   	  cin>>k;
   	  cout<<"Enter the nos\n";
   	  cin>>no;
   	  T->u.dl->data=no;
   	  for(i=1;i<k;i++)
      {
      	cin>>no;
      	addend(T->u.dl,no);
   	  }
   }
}

void addafter(lnode *L,int x,int k)
{
	lnode *T;
	T=new lnode;
	while(L->data!=x)
		L=L->next;
	T->data=k;
	T->next=L->next;
	L->next=T;
}
void addbefor(lnode *L,int x,int k)
{
   lnode *T;
   T=new lnode;
   T->data=k;
   if(L->data==x)
   {
   	 T->next=L;
   	 L=T;
   }
   else
   {
     while(L->next->data!=x)
   	   L=L->next;
     T->next=L->next;
     L->next=T;
   }
}

void printList(lnode *L)
{
	while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
	cout<<endl;
}

void printList(dnode *D)
{
	while(D!=NULL)
	{
	   cout<<D->data<<" ";
	   D=D->right;	
	}
	cout<<endl;
}

void printstack(stack *S)
{
	while(!S->isEmpty())
	{
		cout<<S->pop()<<" ";
	}
	cout<<endl;
}
void printGlist(gnode *G)
{
	while(G!=NULL)
	{
		if(G->tag==0)
		{
			cout<<"stack element are:\n";
			printstack(G->u.s);
		}
		else if(G->tag==1)
		{
			cout<<"linked list is:\n";
			printList(G->u.l);
		}
			else if(G->tag==2)
		{
			cout<<"double linked is:\n";
			printList(G->u.dl);
		}
		G=G->right;
	}
}


int main()
{
   int i,j,k,size,no,tag,op,key,x;
   gnode *G;
   G=new gnode;
   G->left=NULL;
   G->right=NULL;
   
   cout<<"Enter the no of element you want to have in Generic stack\n";
   cin>>size;
   cout<<"Enter the tag for the element you want to enter\n";
   cout<<"(0 for stack, 1 for linked list and 2 for double linked list)\n";
   
   cin>>tag;
   
   if(tag==0)
   {
   	  G->tag=0;
   	  G->u.s=new stack;
   	  cout<<"Enter the element you want to have in stack\n";
   	  cin>>k;
   	  cout<<"Enter the element\n";
   	  for(i=0;i<k;i++)
      {
      	 cin>>no;
      	 G->u.s->push(no);
   	  }
   }
   else if(tag==1)
   {
   	  G->tag=1;
   	  G->u.l=new lnode;
   	  G->u.l->next=NULL;
   	  cout<<"Enter the no of element you want to have in Linked List\n";
   	  cin>>k;
   	  cout<<"Enter the nos\n";
   	  cin>>no;
   	  G->u.l->data=no;
   	  for(i=1;i<k;i++)
	  {
	  	 cin>>no;
	  	 addend(G->u.l,no);
   	  }
   }
   else if(tag=2)
   {
   	  G->tag=2;
   	  G->u.dl=new dnode;
   	  G->u.dl->left=NULL;
   	  G->u.dl->right=NULL;
   	  cout<<"Enter the no of element you want to have in Linked List\n";
   	  cin>>k;
   	  cout<<"Enter the nos\n";
   	  cin>>no;
   	  G->u.dl->data=no;
   	  for(i=1;i<k;i++)
      {
      	cin>>no;
      	addend(G->u.dl,no);
   	  }
   }
   
   for(i=1;i<size;i++)
   {
   	 addend(G);
   }
   
   /*oeration on stack linked ilst and doubly linked list*/
   cout<<"Enter code of opration\n";
   cin>>tag;
   
   switch(tag)
   {
   	  case 1:
	  	cout<<"Enter the code for opration\n";
	  	cin>>op;
   	  if(op==1)
      {
      	cout<<"Enter the element to be pushed in stack\n";
      	cin>>key;
      	G->u.s->push(key);
   	  }
   	  else if(op==2)
	  {
	  	cout<<"Element poped out of stack: ";
	  	cout<<G->u.s->pop()<<endl;
   	  }
   	  break;
   	  case 2:
   	  	G=G->right;
   	  	cout<<"Enter opration(1 for addend and 2 for addafter)\n";
   	  	cin>>op;
   	  	switch(op)
		{
			case 1:
				cout<<"Enter the key\n";
				cin>>key;
				addend(G->u.l,key);
			break;
			case 2:
				cout<<"Enter the element after you want to add element\n";
				cin>>x;
				cout<<"Enter the element\n";
				cin>>key;
				addafter(G->u.l,x,k);
   	  	}
   	  break;
   	  case 3:
   	  	G->right;
   	  	G->right;
   	  	cout<<"Enter opration(1 for addend and 2 for addafter and 3 for addbefor)\n";
   	  	cin>>op;
   	  	switch(op)
		{
			case 1:
				cout<<"Enter the element to be addend at the end\n";
				cin>>key;
				addend(G->u.dl,key);
				break;
			case 2:
				cout<<"Enter the element after you want to add element\n";
				cin>>x;
				cout<<"Enter the element\n";
				cin>>key;
				addafter(G->u.dl,key);
				break;
			case 3:
				cout<<"Enter the element befor which you want to add element\n";
				cin>>x;
				cout<<"Enter the element\n";
				cin>>key;
				addbefor(G->u.dl,x,key);
				break;
     	}
   }
   /*showing the generic linked list*/
   cout<<"Generic double linked list is:\n";
   printGlist(G);
   return 0;
}
