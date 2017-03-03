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

int find_middle(lnode *L)
{
	lnode *mid=L;
	int c=0,mc=0;
	while(L!=NULL)
	{
		if(c/2>mc)
		{
		   mid=mid->next;
		   mc++;
		}
		L=L->next;
		c++;
	}
	return mid->data;
}
void print(lnode *L)
{
	while(L!=NULL)
	{
		cout<<L->data<<" ";
		L=L->next;
	}
}
int main()
{
	lnode *L=NULL;
	int k;
	cout<<"Enter the element for linked list\n";
	while(1)
	{
		cout<<"Enter -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		addend(L,k);
	}
	cout<<"Linked list is :";
	print(L);
	cout<<"printed\n";
	cout<<"Middle is : "<<find_middle(L);
}
