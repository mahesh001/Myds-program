#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
struct lnode
{
	int data;
	lnode *next;
}*L;
struct BTnode
{
 BTnode *lchild;
 BTnode *mchild;
 int  data;
 BTnode *rchild;
};
class queue
{
	public:
	int front;
	int rear;
	int size;
	queue()
	{
		front=-1;
		rear=-1;
	}
	BTnode * element[40];
int queueisFULL()
{
	if((rear+1)%size==front)
	   return 1;
	   else
	return 0;
}
	    
int queueisEMPTY()
{
	if(front==-1)
	   return 1;
	   else
	    return 0;
}
void enque(BTnode* k)

{
	if(queueisFULL())
	{
		cout<<"sorry ! queue is full"<<"\n";
	}
	else
	{
		if(front==-1)
		{
			front=0;
			rear=0;
			element[front]=k;
		}
		else
		{
			rear=(rear+1)%size;
		}
	element[rear]=k;
	//cout<<q.element[q.rear];
	}	
}
BTnode* dqueue()
{
	BTnode* t=new BTnode;
	if (queueisEMPTY())
	{
		cout<<"SORRY ....no element"<<"\n";
	} 
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
	//return t;
}
void display()
{
	for(int i=front;i<=rear;i++)
	{
     cout<<element[i]<<"     ";
	}
}
}q,p;
void create(BTnode *T,int k)
{
	if(T==NULL)
	{
	
	T=new BTnode;
	T->data=k;
	T->lchild=NULL;
	T->mchild=NULL;
	T->rchild=NULL;

   }
   else
   {
   	if(k<T->data)
   	{
   	
	create(T->lchild,k);
    }
	else if(k>T->data)
	{
	
	create(T->rchild,k);
   }
}
}
void insert(BTnode *&T,int k)
{
	if(T==NULL)
	{
	T=new BTnode;
	T->data=k;
	T->lchild=NULL;
	T->rchild=NULL;
		
	}
	else
	{
		if(k<T->data)
		{insert(T->lchild,k);}
		else
		{insert(T->rchild,k);}
		
	}
}
 int search(BTnode *T,int k)
{
	if(T!=NULL)
	{
		if(k==T->data)
		return 1;
		else
		{
		if(k<T->data)
		{
			search(T->lchild,k);
		}
		else
		{
	   search(T->rchild,k);
		}
	    } 
    }
    else
    return 0;
}
void preorder(BTnode *T)
{
	if(T!=NULL)
	{
		cout<<T->data<<"  ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
void inorder(BTnode *T)
{
	if(T!=NULL)
	{
		inorder(T->lchild);
		cout<<T->data<<"  ";
		//inorder(T->mchild);
		inorder(T->rchild);
	}
}

lnode* create(lnode *L,int k)
{
	L=new lnode;
	L->data=k;
	L->next=NULL;
	return L;
}
void append(lnode *L,int k)
{
	lnode *T;
	T=new lnode;
	while(L->next!=NULL)
	{
		L=L->next;	
	}
	T->data=k;
	L->next=T;
	T->next=NULL;
	
}
void display(lnode *L)
{
	while(L->next!=NULL)
	{
		cout<<L->data<<" ";
	
	  L=L->next;
    }
   cout<<L->data<<endl;
}
void create(BTnode* T,queue &q,queue &p,lnode* &L)
{
	if(L!=NULL)
	{
	BTnode *tmp=new BTnode;
    tmp->data=L->data;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	tmp->mchild=NULL;
	T->lchild=tmp;
	q.enque(tmp);
	//cout<<q.dqueue()->data;
	p.enque(tmp);
	L=L->next;
	}
	if(L!=NULL)
	{
   	BTnode *tmp1=new BTnode;
    tmp1->data=L->data;
	tmp1->lchild=NULL;
	tmp1->rchild=NULL;
	tmp1->mchild=NULL;
	T->mchild=tmp1;
	q.enque(tmp1);
	p.enque(tmp1);
	L=L->next;
	}
	if(L!=NULL)
	{
	BTnode *tmp2=new BTnode;
    tmp2->data=L->data;
	tmp2->lchild=NULL;
	tmp2->rchild=NULL;
	tmp2->mchild=NULL;
	T->rchild=tmp2;
	q.enque(tmp2);
	p.enque(tmp2);
	L=L->next;
	}
}
void print(BTnode *T,queue p)
{
	if(!p.queueisEMPTY())
	{
		BTnode* num=new BTnode;
		num=p.dqueue();
		cout<<num->data<<" ";
	}
}
void dis(queue p)
{
	int num;
	while(!p.queueisEMPTY())
	{ 
	num=p.dqueue()->data;
	cout<<num;
	}
}	
	

int main()
{
q.size=10;p.size=10;
L=new lnode;
BTnode*z=new BTnode;
cout<<"\n";
  int m,n,i; 	  
cout<<"enter the elemnt that u want to add "<<"\n";
cin>>m;
L=create(L,m);
cout<<"enter the elements"<<"\n";
cout<<"how many elements u want to enter";
cin>>n;

    for(i=0;i<n;i++)
   		  {
   		  	cin>>m;
   		   append(L,m);
         	}
   		 
cout<<"display of linklist<<"<<"\n";
display(L);	
	
	z->data=L->data;
	z->lchild=NULL;
	z->rchild=NULL;
	z->mchild=NULL;
	q.enque(z);
	p.enque(z);
	L=L->next;
	while(L!=NULL)
	{
		BTnode *c=q.dqueue();
		create(c,q,p,L);
	}
	dis(p);
	//print(z,p);
	return 0;
}
