#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;

class stack{
	public:
		char *a[20];
		int top;
		stack()
		{top=-1;
		}
		int isfull(){
			if(top==19)
			return 1;
			else 
			return 0;
		}
		
		int isempty(){
			if(top==-1)
			return 1;
			else 
			return 0;
		}
		void push(char* x){
			if(isfull())
			cout<<"stack overflow";
			else
			a[++top]=x;
			
		}
		
		
		char pop(){
			if(isempty())
			cout<<"stack underflow";
			else{
				
				return *a[top--];
				
				}
		}
	};
class dnode{
	public:
	int data;
	dnode *right;
	dnode *left;
	
	dnode()
	{
		left=NULL;
		right=NULL;
	}
	
	void add_aft(dnode *L,int x,int k)
	{
		dnode *T;
		while(L->data!=x)
		L=L->right;
		T=new dnode;
		
		T->data=k;
		T->right=L->right;
		T->left=L;
		L->right=T;
		
	}
	void add_end(dnode *L,int x)
	{	dnode *T;
		T=new dnode;
		while(L->right!=NULL)
			L=L->right;
		T->data=x;
		T->right=L->right;
		T->left=L;
		L->right=T;
	}
	
	void add_bef(dnode *L,int x,int k)
	{
		dnode *T;
		T=new dnode;
		while(L->right->data!=x)
			L=L->right;
		T->data=k;
		T->right=L->left->right;
		L->left->right=T;
		T->left=L->left;
		L->left=T;
		
	}
	void del_node(dnode *L,int x)
	{	dnode *T;
		T =new dnode;
		while(L->data!=x)
			{
				L=L->right;
			}
		T=L;
				L->left->right=L->right;
				L->right->left=L->left;
	}
	int search(dnode *L,int x)
	{	int i=1;
		while(L->data!=x)
			{
				L=L->right;
				i++;
			}
		return i;
	}
	void print(dnode *L)
	{
			dnode *pre;
			pre=new dnode;
		while(L->right!=NULL)
			{
			cout<<L->data<<"->";
			pre=L;
			L=L->right;
			}
			cout<<pre->right->data<<endl;
	}
	void add_fro(dnode* &L,int k,int i)
	{
		dnode *T;
		T=new dnode;
		T->right=L;
		T->data=k;
		L=T;
		if(i==6)
		L->print(L);	
	}
	};
class queue{
	public:
	int front;
	int rear;
	int size;
	float elements[50];
	queue(){
		rear=-1;
		front=-1;
		size=50;
	}

int Qisfull(){
	if(((rear+1)%(size))==(front)){
		return 1;
	}
	else{
	return 0;
	}
}
int Qisempty(){
	if(front==-1 && rear==-1){
		return 1;
	}
	else{
		return 0;
	}
}
void enque(int k){
	if(Qisfull()==1){
		cout<<"Queue is full";
	}
	else{
		if(front==-1 && rear==-1){
			front=0;
			rear=0;
		}
		else{
			rear=(rear+1)%size;
		}
		elements[rear]=k;
	}
}
int deque(){
	int t;
	if(Qisempty()==1){
		cout<<"Queue is empty ";
		return -1;
	}
	else{
		if(front==rear){
			t=elements[front];
			front=-1;
			rear=-1;
		}
		else{
			t=elements[front];
			front=(front+1)%size;
		}
	return t;
	}
}
};

struct gnode{
	int data;
	stack *S;
	queue *Q;
	dnode *D;
	dnode *next;
	
	
	
};
int check(char *str)
{
	if(isalpha(str[0]))
	return 2;
	
	int l=strlen(str);
	for(int i=1;i<l;i++)
	{
		if(str[i]=='.')
		return 3;
	}
	return 1;
}

int main()	
{	int n,i,j,t,x;
	char str[20];
	//queue *Q=new queue;
	//dnode *D=new dnode;
	gnode *G=new gnode;
	G->Q=new queue;
	G->S=new stack;
	G->D=new dnode;	
	cout<<"how mant elements\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter an element(-1 to stop)";
		cin>>str;
		cout<<"string"<<str;
		t=check(str);
		cout<<"t="<<t;
		
		switch(t)
		{
			case 1:
				x=atoi(str);
				G->D->add_end(G->D,x);
				break;
				
			case 2:
				G->S->push(str);
				break;
				
			case 3:
				float f=atof(str);
				G->Q->enque(f);
				break;		
		}
	}
	
	
	
	
	
	
	
}
