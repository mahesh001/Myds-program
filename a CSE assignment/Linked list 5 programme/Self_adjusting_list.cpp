#include<iostream>
using namespace std;

struct lnode {
	int data;
	lnode *next;
};

void addfront(lnode* &L,int k)
{
	lnode *T;
	T=new lnode;
	T->data=k;
	T->next=L;
	L=T;
}
int search(lnode* &L,int k)
{
	lnode *T;
	T=L;
	while(T->next!=NULL)
	{
		if(T->next->data==k)
		break;
		T=T->next;
	}
	if(T->next==NULL)
	{
		cout<<"Element not present in the List\n";
		return 0;
    }
    else
	{
		if(L==T)
		 return 1;
		else
		{
			T->next=T->next->next;
			addfront(L,k);
		}
    }
		
}

void addend(lnode* L,int k)
{
	lnode* T;
	T=new lnode;
	T->data=k;
	T->next=NULL;
	while(L->next!=NULL)
	  L=L->next;
	L->next=T;
}

void printList(lnode *L)
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
	int no,k,i;
	lnode *L;
	L=new lnode;
	L->next=NULL;
	cout<<"Enter the no of no you want to enter\n";
	cin>>no;
	cout<<"Enter the nos\n";
	cin>>k;
	L->data=k;
	for(i=1;i<no;i++)
	{
		cin>>k;
		addend(L,k);
	}
	cout<<"Your List is \n";
	printList(L);
	cout<<"Enter the search element\n";
	cin>>k;
	if(search(L,k))
	cout<<"Element found\n";
	else
	cout<<"Element not found\n";
	cout<<"Now the list is :\n";
	printList(L);
}
