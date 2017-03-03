#include<iostream>
using namespace std;

struct lnode
{
	char data;
	lnode *next;
	lnode *arbit;
};

void addend(lnode* &L,char k)
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

void print(lnode *T)
{
	cout<<"\nThe list is : ";
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->next;
	}
	cout<<endl;
}

lnode* find(lnode *T,char ch)
{
	while(T!=NULL)
	{
		if(T->data==ch)
		return T;
		T=T->next;
	}
}

void assigarbit(lnode *T)
{
	while(T!=NULL)
	{
	   cout<<"Enter arbit node for "<<T->data<<endl;
	   char ch;
	   cin>>ch;
	   T->arbit=find(T,ch);
	   T=T->next;
	}
}

lnode* copy(lnode *L)
{
	lnode *T=NULL;
	lnode *head=L;
	while(L!=NULL)
	{
		addend(T,L->data);
		L=L->next;
	}
	L=head;
	lnode *temp=T;
	while(L!=NULL)
	{
		char ch;
		if(L->arbit!=NULL)
		{
			ch=L->arbit->data;
			T->arbit=find(T,ch);
		}
		else
		{
			temp->arbit=NULL;
		}
		L=L->next;
	}
	return T;
}

int main()
{
	lnode *L=NULL;
	char k;
	cout<<"Enter the data for linked list\n";
	while(1)
	{
		cout<<"Enter value / to stop\n";
		cin>>k;
		if(k=='/')
		break;
		addend(L,k);
	}
	cout<<"Copying\n";
	lnode *T=copy(L);
}
