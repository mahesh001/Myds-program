#include<iostream>
using namespace std;

struct lnode {
	int data;
	lnode *next;
};

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

int subList(lnode *L1,lnode *L2)
{
	lnode *T;
	while(L1!=NULL)
	{
		T=L2;
		while(L1!=NULL&&L1->data!=L2->data)
		{
			L1=L1->next;
		}
        if(L1==NULL)
        return 0;
        else
		{
		    while(T!=NULL&&L1!=NULL)
		   {
			  if(T->data!=L1->data)
			  break;
			  else
			  {
				  L1=L1->next;
				  T=T->next;
			  }
		   }
		   if(T==NULL)
	        return 1;
	       else
	        return 0; 
	    }
	}
	
}
int main()
{
	int no,k,i;
	lnode *L1,*L2;
	L1=new lnode;
	L2=new lnode;
	L1->next=NULL;
	L2->next=NULL;
	cout<<"Enter the no of no you want to enter for list L1\n";
	cin>>no;
	cout<<"Enter the nos\n";
	cin>>k;
	L1->data=k;
	for(i=1;i<no;i++)
	{
		cin>>k;
		addend(L1,k);
	}
	cout<<"Your List is \n";
	printList(L1);
	
	cout<<"Enter the subList\n";
	
	cout<<"Enter the no of no you want to enter for list L2\n";
	cin>>no;
	cout<<"Enter the nos\n";
	cin>>k;
	L2->data=k;
	for(i=1;i<no;i++)
	{
		cin>>k;
		addend(L2,k);
	}
	cout<<"Your List is \n";
	printList(L2);
	if(subList(L1,L2))
	cout<<"L2 is subList of L1\n";
	else
	cout<<"L2 is not subList of L1\n";
	return 0;
}
