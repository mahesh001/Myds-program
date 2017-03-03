#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct lnode;
union u
{
	char ch;
	lnode *ptr;
};
struct lnode
{
   int tag; 
   u ob; 
   lnode *next;	
};

void printList(lnode *L)
{
	lnode *pre=NULL;
	while(L->next!=NULL)
	{
		if(L->tag==1)
		{
			cout<<L->ob.ch;
			L=L->next;
		}
		else if(L->tag==2)
		{
			pre=L->next;
			L=L->ob.ptr;
			cout<<"(";
		}
		if(L->next==NULL&&pre!=NULL)
		{
		   L=pre;
		   cout<<")";
		   pre=NULL;	
		}
  	}
}

int main()
{
	/*lnode decleration*/
	lnode *L;
	lnode *pre;
	lnode *head;
	
	L=new lnode;
	L->next=NULL;
	head=L;
	
	int i=0,length;
	char ch,exp[20];
	cout<<"Enter the expression\n";
	cin>>exp;
	length=strlen(exp);
	
	while(i<length)
	{
		ch=exp[i];
		if(isalpha(ch))
		{
			L->tag=1;              /*tag 1 for alpha and 2 for lnode ptr*/
			L->ob.ch=ch;
			L->next=new lnode;
			L=L->next;
			L->next=NULL;
			
		}
		else if(ch=='(')
		{
		    L->next=new lnode;
		    L->next->next=NULL;
		    pre=L->next;
		    L->tag=2;
		    L->ob.ptr=new lnode;
		    L->ob.ptr->next=NULL;
		    L=L->ob.ptr;
		}
		else if(ch==')')
		{
			L->tag=1;
			L->ob.ch=' ';
			L=pre;
		}
		if(i==length-1)
		{
			L->tag=1;
			L->ob.ch=' ';
		}
		i++;
	}
	
	cout<<"Your list is\n";
	printList(head);
	return 0;
}
