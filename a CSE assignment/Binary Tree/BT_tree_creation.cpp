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
/*set x corr. of each node in the tree*/
void getx(btnode *B,int &t)
{
	if(B!=NULL)
	{
		getx(B->lchild,t);
		B->x=t++;
		getx(B->rchild,t);
	}
}
/*find depth of tree*/
void getdepth(btnode *B,int &max,int &tmax)
{
	if(B!=NULL)
	{
		tmax++;
		getdepth(B->lchild,max,tmax);
		getdepth(B->rchild,max,tmax);
		if(B->lchild==NULL&&B->rchild)
		{
			if(tmax>max)
			max=tmax;
		}
		tmax--;
	}
}

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

/*show the values in stack*/
void showstack(stack S)
{
	btnode* T=S.pop();
	if(!S.isEmpty())
	{
		showstack(S);
	}
	cout<<T->data<<" ";
}
/*show the path of all leaf nodes*/
void showpath(btnode *B,stack &S)
{
	if(B!=NULL)
	{
		S.push(B);
		showpath(B->lchild,S);
		showpath(B->rchild,S);
		if(B->lchild==NULL&&B->rchild==NULL)
		{
		  showstack(S);
		  cout<<endl;
	    }
	    S.pop();
	}
}
/*print as space as value of n*/
void prints(int n)
{
	for(int i=0;i<n;i++)
	cout<<"*";
}
/*print tree in tree shape*/
void printtree(btnode *B)
{
	if(B==NULL)
	{
		cout<<"Tree is empty\n";
		return;
	}
	btnode *T,*T1;
	T1=new btnode;
	T1->data='*';
	Queue Q,Q1;
	Q.enqueue(B);
	Q.enqueue(T1);
	int xcorr=0,par_count=0;
	while(!Q.isempty())
	{
		//cout<<"inside while loop";
		T=Q.dequeue();
		if(T->data=='*')
		{
			cout<<endl;
			int l=0;
			while(!Q1.isempty())
			{
				//cout<<"in / for";
				btnode *temp;
				temp=Q1.dequeue();
				for(l;l<temp->x-2;l++)
				cout<<" ";
				l=l+3;
				if(temp->lchild!=NULL)
				cout<<"/";
				else
				cout<<" ";
				if(temp->rchild!=NULL)
				cout<<" \\";
				else
				cout<<"  ";
			}
			cout<<endl;
			if(!Q.isempty())
			{
				Q.enqueue(T1);
			}
			par_count=0;
			xcorr=0;
		}
		else
		{
			Q1.enqueue(T);
			for(xcorr;xcorr<(T->x-1);xcorr++)
			cout<<" ";
			xcorr++;
			cout<<T->data;
			if(T->lchild!=NULL)
			{
				Q.enqueue(T->lchild);
				par_count++;
			}
			if(T->rchild!=NULL)
			{
				Q.enqueue(T->rchild);
				par_count++;
			}
		}
	}
}

int size(btnode *B)
{
	if(B!=NULL)
	{
		return 1+size(B->lchild)+size(B->rchild);
	}
	else
	return 0;
}

int comp(btnode *B,btnode *B1)
{
	if(B!=NULL&&B1!=NULL)
	{
		return (B->data==B1->data)&&comp(B->lchild,B1->lchild)&&comp(B->rchild,B1->rchild);
	}
	else if(B==NULL&&B1==NULL)
	return 1;
	else
	return 0;
}

void deletetree(btnode* &B)
{
	if(B!=NULL)
	{
		deletetree(B->lchild);
		deletetree(B->rchild);
		delete B;
	}
}

void IntoMirror(btnode* &B)
{
	if(B!=NULL)
	{
		IntoMirror(B->lchild);
		IntoMirror(B->rchild);
		btnode *temp;
		temp=B->lchild;
		B->lchild=B->rchild;
		B->rchild=temp;
	}
}

int find_in_inorder(char *inorder,char root)
{
	int i,len=strlen(inorder);
	for(i=0;i<len;i++)
	{
		if(root==inorder[i])
		return i;
	}
	if(i>len)
	return -1;
}

void createtree(btnode* &T,char *pre,char *in,int &index,int start,int end)
{
	char root=pre[index++];
    T=new btnode;
    T->data=root;
    T->lchild=NULL;
    T->rchild=NULL;
	int inorder_index=find_in_inorder(in,root);
	if(start<inorder_index)
	createtree(T->lchild,pre,in,index,start,inorder_index-1);
	if(inorder_index<end)
	createtree(T->rchild,pre,in,index,inorder_index+1,end);
}

int main()
{
	stack S;
	btnode *B=NULL;
	btnode *B1=NULL;
	cout<<"Enter the root of First binary tree\n";
	/*create(B);
	cout<<"Enter the root of Second binary tree\n";
	create(B1);
	if(comp(B,B1))
	cout<<"Both tree are same\n";
	else
	cout<<"Both tree are Differt\n";
	cout<<"The binary tree is :\n";
	levelwise(B);
	cout<<"\nThe path of all leaf nodes is \n";
	showpath(B,S);
	cout<<"The FRIST in it tree shape is:\n";
	int t=5;
	getx(B,t);
	//getdepth();
	printtree(B);*/
	/*cout<<"The SECOND in it tree shape is:\n";
	t=5;
	getx(B1,t);
	//getdepth();
	printtree(B1);*/
	/*cout<<"DELETING TREE\n";
	deletetree(B);
	deletetree(B1);*/
	//cout<<"Converting into Mirror\n";
	//IntoMirror(B);
	char pre[20],in[20];
	cout<<"Enter the preorder\n";
	cin>>pre;
	cout<<"Enter the inorder\n";
	cin>>in;
	btnode *T=NULL;
	int index=0;
	createtree(T,pre,in,index,0,strlen(pre));
	cout<<"Now your tree is :\n";
	int t=5;
	getx(T,t);
	printtree(T);
	/*cout<<"Now your tree is :\n";
	t=5;
	getx(B1,t);
	printtree(B1);*/
	cout<<"The size of tree is :"<<size(T);
}
