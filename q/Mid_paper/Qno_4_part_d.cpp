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

void del(lnode* &T,int pos)
{
	cout<<"inside del\n";
	if(pos==1)
	{
		T=T->next;
	}
	else
	{
		lnode *T1=T,*pre;
		for(int i=0;i<(T1->data-1)&&T1!=NULL;i++)
		{
			//pre=T1;
			T1=T1->next;
		}
		if(T1!=NULL)
		{
			T1->next=T1->next->next;
		}
	}
}

void adjust(lnode* T)
{
	lnode *head=T;
	while(T!=NULL)
	{
		del(T,T->data);
		T=T->next;
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

int main()
{
	lnode *L=NULL;
	int k;
	cout<<"Enter the data for linked list\n";
	while(1)
	{
		cout<<"Enter value -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		addend(L,k);
	}
	cout<<"Adjusting list\n";
	lnode *T1=L;
	while(T1!=NULL)
	{
		int temp=T1->data;
		T1=T1->next;
		del(L,temp);
	}
	print(L);
}
