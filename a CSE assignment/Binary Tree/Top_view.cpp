#include<iostream>
#include<cmath>
using namespace std;
/*struct for binary search tree*/
struct bstnode
{
	int tag;
	int level;
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
struct lnode
{
	int tag;
	int level;
	int data;
	lnode* next;
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
void insert(bstnode* &B,int k,int l)
{
	if(B==NULL)
	{
		B=new bstnode;
		B->data=k;
		B->lchild=NULL;
		B->rchild=NULL;
		B->level=l;
	}
	else if(k<B->data)
	  insert(B->lchild,k,l+1);
	else
	  insert(B->rchild,k,l+1);
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
void del(bstnode* &T,int k)
{
	int temp;
	if(search(T,k))
	{
		if(T->lchild==NULL && T->rchild==NULL)
		{
			T=NULL;
			cout<<"\nDELETED\n";
		}
		else if(T->data==k)
		{
			if(T->lchild==NULL)
			{
			  temp=leftmost_of_right(T);
			  del(T,temp);
			  T->data=temp;
			}
			else
			{
			  temp=rightmost_of_left(T);
			  del(T,temp);
			  T->data=temp;
		    }
		}
		else if(k<T->data)
		{
			del(T->lchild,k);
		}
		else if(k>T->data)
		{
			del(T->rchild,k);
		}
	}
}
/*inorder printing*/
void inorder(bstnode *T)
{
	if(T!=NULL)
	{
		inorder(T->lchild);
		cout<<T->data<<"t="<<T->tag<<"_l="<<T->level<<endl;
		inorder(T->rchild);
	}
}
/*it assign tag value to each node*/
void initi(bstnode *B)
{
	B->tag=0;
	stack S;
	S.push(B);
	while(!S.isEmpty())
	{
		//cout<<"inside 1 while";
		B=S.pop();
		if(B->lchild!=NULL)
		{
			//cout<<"inside 2 while";
			B->lchild->tag=B->tag+1;
			S.push(B->lchild);
		}
		if(B->rchild!=NULL)
	    {
			B->rchild->tag=B->tag-1;
			S.push(B->rchild);
		}
	}
}
/*it create linked list of top view node of tree*/
void add_end(lnode* &L,int tag,int level,int data)
{
	lnode *head=L;
	cout<<" inside add_end ";
	lnode *T;
	T=new lnode;
	T->tag=tag;
	T->level=level;
	T->data=data;
	T->next=NULL;
	if(L==NULL)
	{
		L=T;
	}
	else
	{
	   lnode *pre=NULL;
	   lnode *temp;
	   while(tag<L->tag)
	   {
	   	cout<<" inside while ";
	   	  pre=L;
	   	  L=L->next;
	   	  if(L==NULL)
	   	  break;
	   }
	   if(L==NULL)
	   {
	   	  pre->next=T;
	   	  L=head;
	   }
	   else if(pre==NULL)
	   {
	   	cout<<"inside pre==NULL\n";
	   	cout<<"L->data="<<L->data<<endl;
	   	cout<<"T->data="<<T->data<<endl;
	   	  T->next=L;
	   	  L=T;
	   	  cout<<"now L->data="<<L->data<<endl;
	   }
	   else if(L->tag==tag&&level<L->level)
	   {
	   	  cout<<" inside if ";
	   	  L->tag=tag;
	   	  L->level=level;
	   	  L->data=data;
	   	  L=head;
	   }
	}
}
void get_top(bstnode* B,lnode* &L)
{
	if(B!=NULL)
	{
		cout<<" inside get_top ";
		get_top(B->lchild,L);
		get_top(B->rchild,L);
		add_end(L,B->tag,B->level,B->data);
	}
}
void printList(lnode *L)
{
	cout<<" inside printList ";
	while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
	cout<<endl;
}
int main()
{
	bstnode *B=NULL;
	int k;
	/*while(1)
	{
		cout<<"Enter the elment to be inserted in binary search tree\n"
		    <<"Enter -1 to end\n";
		cin>>k;
		if(k==-1)
		 break;
		insert(B,k,0);
	}
	cout<<"\nInitialising\n";
	initi(B);
	cout<<"The inorder of tree is :\n";
	inorder(B);*/
	lnode *L=NULL;
	//cout<<"Getting top view\n";
	//get_top(B,L);
	add_end(L,0,0,4);
	add_end(L,1,1,2);
	add_end(L,0,2,3);
	add_end(L,-1,1,5);
	add_end(L,-2,2,12);
	cout<<"\nThe top view of tree is : ";
	printList(L);
}
