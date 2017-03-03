#include<iostream>
#include<cmath>
using namespace std;
/*struct for binary search tree*/
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
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
/*Queue class*/
class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=6;
	}
	private:
		int front;
		int rear;
		int size;
		bstnode* element[6];
		
	public:
		int isfull();
		int isempty();
		void enqueue(bstnode* k);
		bstnode* dequeue();
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

void Queue::enqueue(bstnode* k)
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

bstnode* Queue::dequeue()
{
	bstnode* t;
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
void levelwise(bstnode *B)
{
	double i=0,k=1;
	bstnode *T=B,*T1;
	T1=new bstnode;
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

void insert(bstnode* &B,int k)
{
	if(B==NULL)
	{
		B=new bstnode;
		B->data=k;
		B->lchild=NULL;
		B->rchild=NULL;
	}
	else if(k<B->data)
	  insert(B->lchild,k);
	else
	  insert(B->rchild,k);
}

int search(bstnode *T,int k)
{
	if(T!=NULL)
	{
		if(T->data==k)
		return 1;
		else if(k<T->data)
		return search(T->lchild,k);
		else
		return search(T->rchild,k);
	}
	else
	return 0;
}
/*leftmost of right*/
int leftmost_of_right(bstnode *T)
{
	if(T->rchild!=NULL)
	{
		T=T->rchild;
		while(T->lchild!=NULL)
		{
		  T=T->lchild;
	    }
		return T->data;
	}
}
/*rightmost of left*/
int rightmost_of_left(bstnode *T)
{
	if(T->lchild!=NULL)
	{
	  T=T->lchild;
	  while(T->rchild!=NULL)
	  {
	    T=T->rchild;
      }
 	  return T->data;
    }
}
/*delete function*/
void del(bstnode* &B,int k)
{
   if(B->data==k)
   {
   	  if(B->lchild==NULL&&B->rchild==NULL)
   	  B=NULL;
   	  else if(B->lchild==NULL&&B->rchild!=NULL)
	  {
	  	int lm=leftmost_of_right(B);
	  	del(B,lm);
	  	B->data=lm;
   	  }
   	  else
	  {
	  	int rm=rightmost_of_left(B);
	  	del(B,rm);
	  	B->data=rm;
   	  }
   }
   else if(k<B->data)
   del(B->lchild,k);
   else
   del(B->rchild,k);
}

int leftmost_of_left(bstnode *T)
{
	if(T!=NULL)
	{
		if(T->lchild==NULL)
		return T->data;
		else
		return leftmost_of_left(T->lchild);
	}
	else
	cout<<"Tree is empty\n";
}

int findmin(bstnode *T)
{
	while(T->lchild!=NULL)
	T=T->lchild;
	return T->data;
}

int findmax(bstnode *T)
{
	while(T->rchild!=NULL)
	T=T->rchild;
	return T->data;
}
int rightmost_of_right(bstnode *T)
{
	if(T!=NULL)
	{
		if(T->rchild==NULL)
		return T->data;
		else
		return rightmost_of_right(T->rchild);
	}
	else
	cout<<"Tree is empty\n";
}

void inorder(bstnode *T)
{
	if(T!=NULL)
	{
		inorder(T->lchild);
		cout<<T->data<<" ";
		inorder(T->rchild);
	}
}

void postorder(bstnode *T)
{
	if(T!=NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout<<T->data<<" ";
	}
}

void change(bstnode *B)
{
	if(B!=NULL)
	{
		change(B->lchild);
		change(B->rchild);
		bstnode *T=new bstnode;
		T->lchild=T->rchild=NULL;
		T->data=B->data;
		T->lchild=B->lchild;
		B->lchild=T;
	}
}

bstnode* Pre(bstnode *T)
{
	if(T->lchild==NULL)
	return NULL;
	else
	{
		T=T->lchild;
		while(T->rchild!=NULL)
		T=T->rchild;
		return T;
	}
}

bstnode* Suc(bstnode *T)
{
	if(T->rchild==NULL)
	return NULL;
	else
	{
		T=T->rchild;
		while(T->lchild!=NULL)
		T=T->lchild;
		return T;
	}
}

void TreeToList(bstnode *T)
{
	if(T!=NULL && (T->lchild!=NULL || T->rchild!=NULL))
	{
		TreeToList(T->lchild);
		TreeToList(T->rchild);
		bstnode *P,*S;
		P=Pre(T);
		S=Suc(T);
		if(P==NULL)
		{
			T->rchild=S;
			S->lchild=T;
		}
		else if(S==NULL)
		{
			P->rchild=T;
			T->lchild=P;
		}
		else
		{
			T->rchild=S;
			T->lchild=P;
			S->lchild=T;
			P->rchild=T;
		}
	}
}

void print_list(bstnode *T)
{
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->rchild;
	}
	cout<<endl;
}

int main()
{
	bstnode *B=NULL;
	int k;
	
	while(1)
	{
		cout<<"Enter the elment to be inserted in binary search tree\n"
		    <<"Enter -1 to end\n";
		cin>>k;
		if(k==-1)
		 break;
		insert(B,k);
	}
	cout<<"The level wise printing is:\n";
	levelwise(B);
	/*cout<<"\nlmr and rml\n";
    cout<<leftmost_of_right(B);
	cout<<rightmost_of_left(B);*/
	/*cout<<"\nchanging\n";
	change(B);*/
	TreeToList(B);
	bstnode *head=B;
	while(head->lchild!=NULL)
	head=head->lchild;
	print_list(head);
	/*cout<<"The level wise printing is:\n";
	levelwise(B);*/
	/*cout<<"Enter the element you want to delete\n";
	cin>>k;
	del(B,k);
	cout<<"The level wise printing is:\n";
	levelwise(B);*/
	cout<<"Enter the element you want to search\n";
	cin>>k;
	if(search(B,k))
	cout<<"Element found\n";
	else
	cout<<"Not found\n";
	/*to find min in tree*/
	/*cout<<"The min by recursion is: ";
	cout<<leftmost_of_left(B)<<endl;
	cout<<"The min by iteration is: ";
	cout<<findmin(B)<<endl;*/
	/*to find max in tree*/
	/*cout<<"The max by recursion is: ";
	cout<<rightmost_of_right(B)<<endl;
	cout<<"The max by iteration is :";
	cout<<findmax(B)<<endl;*/
	//cout<<"Enter the element you want to delete\n";
	//cin>>k;
	//del(B,k);
	//cout<<"The level wise printing is\n";
	//Q.enqueue(B->data);
	//Q.enqueue(-1);
	//printlevel(B,Q);
	//cout<<"The tree in preorder is:\n";
	//preorder(B);
	//cout<<endl;
	//cout<<"The tree in inorder is:\n";
	//inorder(B);
	//cout<<endl;
	//cout<<"The tree in postorder is:\n";
	//postorder(B);
	//cout<<endl;
	//cout<<"The level wise printing is:\n";
	//levelwise(B);
	cout<<" \nthe tree in preorder is\n";
	stack S;
	S.push(B);
	bstnode* T;
	while(!S.isEmpty())
	{
		T=S.pop();
		cout<<T->data<<" ";
		if(T->rchild!=NULL)
		 S.push(T->rchild);
		if(T->lchild!=NULL)
		 S.push(T->lchild);
	}
	cout<<"\nthe tree in inorder\n";
	T=B;
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
	cout<<"\nThe tree in postorder is :\n";
	stack s1,s2;
	s1.push(B);
	while(!s1.isEmpty())
	{
		T=s1.pop();
		s2.push(T);
		if(T->lchild!=NULL)
		s1.push(T->lchild);
		if(T->rchild!=NULL)
		s1.push(T->rchild);
	}
	while(!s2.isEmpty())
	{
		cout<<s2.pop()->data<<" ";
	}
}
