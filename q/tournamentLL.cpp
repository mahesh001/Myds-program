#include<iostream>
using namespace std;
struct btnode
{
	btnode *lchild;
	int data;
	btnode *rchild;
	btnode *down;
};
struct Q
{
	int front,rear,size;
	btnode *ele[20];
}q;
int isfull(Q q)
{
	if((q.rear+1)%q.size==q.front)
	return 1;
	else
	return 0;
}
int isempty(Q q)
{
	if(q.front==-1)
	return 1;
	else
	return 0;
}
void enq(Q& q,btnode* k)
{
	if(isfull(q))
	cout<<"Queue is full\n";
	else
	{
		if(q.front==-1)
		{
			q.front=0;
			q.rear=0;
		}
		else
		{
		q.rear=(q.rear+1)%q.size;
		}
		q.ele[q.rear]=k;
	}
}
btnode* dq(Q& q)
{
	btnode* t;
	if(isempty(q))
	cout<<"Queue is empty\n";
	else
	{
		if(q.front==q.rear)
		{
		t=q.ele[q.front];
		q.front=-1;q.rear=-1;
		}
		else
		{
		t=q.ele[q.front];
		q.front=(q.front+1)%q.size;
		}
	}
	return t;
}
btnode* min(btnode *temp)
{	
	while(!isempty(q))
	{
		btnode *p1,*p2,*B=new btnode;
		p2=dq(q);
		p1=dq(q);
		B->lchild=p1;
		B->rchild=p2;
		if(p1->data<p2->data)
		{
		B->data=p1->data;
		}
		else if(p2->data<p1->data)
		{
		B->data=p2->data;
		}
		enq(q,B);
		if(q.front==q.rear)
		{
		temp=dq(q);
		}
	}
return temp;
}
int main()
{
	q.front=-1;q.rear=-1;
	q.size=20;
	int n,num;
	btnode *root=new btnode;
	root->lchild=NULL;
	root->rchild=NULL;
	root->data=0;
	cout<<"Enter the no. of linked-list\n";
	cin>>n;
	btnode **t=new btnode*[n];
	for(int i=0;i<n;i++)
	{
	t[i]=new btnode;
	}
	for(int i=0;i<n;i++)
	{
	cout<<"Enter the no. of elements in linked list "<<i+1<<"\n";
	cin>>num;
	cout<<"Enter the elements in linked list "<<i+1<<"\n";
	for(int j=0;j<num;j++)
	{
	int q;
	cin>>q;
	btnode *temp=t[i],*p=new btnode;
	if(j==0)
	{
	p->data=q;
	p->lchild=NULL;
	p->rchild=NULL;
	p->down=NULL;
	t[i]=p;
	}	
	else
	{
		while(temp->down!=NULL)
		temp=temp->down;
	p->data=q;
	p->lchild=NULL;
	p->rchild=NULL;
	p->down=NULL;
	temp->down=p;
	}
	}
	}
	for(int i=0;i<20;i++)
	{
	for(int j=0;j<n;j++)
	enq(q,t[j]);	
	root=min(root);
	cout<<root->data<<"  ";
	for(int k=0;k<n;k++)
	{
		if(t[k]->data==root->data)
		{
		if(t[k]->down!=NULL)
		t[k]=t[k]->down;
		else if(t[k]->down==NULL)
		t[k]->data+=1000;
		}
	}
	}
return 0;	
}
