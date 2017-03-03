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

void bubble_sort(lnode *T)
{
	if(T==NULL)
	return;
	lnode *head=T;
	if(T->next!=NULL)
	{
		bubble_sort(T->next);
		while(T->next!=NULL)
		{
			if(T->data>T->next->data)
			{
			   int temp=T->data;
			   T->data=T->next->data;
			   T->next->data=temp;
			}
			T=T->next;
		}
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
	cout<<"Sorting the list\n";
	bubble_sort(L);
	print(L);
}
