#include<iostream>
using namespace std;

struct lnode
{
	int data;
	lnode *next;
};

void addend(lnode* &L,int k)
{
	lnode *T=new lnode;
	T->data=k;
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

lnode* mergelist(lnode *L1,lnode *L2)
{
	lnode *L3=new lnode;
	if(L1!=NULL&&L2!=NULL)
	{
		if(L1->data<L2->data)
		{
			L3->data=L1->data;
			L3->next=mergelist(L1->next,L2);
		}
		else
		{
			L3->data=L2->data;
			L3->next=mergelist(L1,L2->next);
	    }
	}
	else if(L1==NULL&&L2!=NULL)
	{
		L3->data=L2->data;
		L3->next=mergelist(L1,L2->next);
	}
	else if(L1!=NULL&&L2==NULL)
	{
		L3->data=L1->data;
		L3->next=mergelist(L1->next,L2);
	}
	else
	return NULL;
	return L3;
}

void print(lnode *L)
{
	while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
	cout<<endl;
}

int main()
{
	lnode *L1=NULL,*L2=NULL;
	int k;
	cout<<"Enter the data for linked list L1\n";
	while(1)
	{
		cout<<"Enter value -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		addend(L1,k);
	}
	cout<<"Enter the data for linked list L2\n";
	while(1)
	{
		cout<<"Enter value -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		addend(L2,k);
	}
	cout<<"Merging 2 lists into Linked List L3\n";
	lnode *L3=mergelist(L1,L2);
	cout<<"The merged list is\n";
	print(L3);
}
