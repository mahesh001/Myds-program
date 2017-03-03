#include<iostream>
using namespace std;
struct lnode{
	int data;
	lnode *next;
};

void addend(lnode *L,int k)
{
	lnode *T;
	lnode *head;
	head=L;
	T=new lnode;
	T->data=k;
	T->next=L;
	while(L->next!=head)
	  L=L->next;
	L->next=T;
}

void josephes(lnode *L,int j)
{
	int i;
	lnode *pre,*head;
	head=L;
	while(L->next!=L)
	{
		for(i=0;i<j;i++)
		{
			pre=L;
			L=L->next;
		}
		pre->next=pre->next->next;
		pre=L;
		L=L->next;
	}
	cout<<"alive person is \n";
	cout<<L->data;
}
int main()
{
	lnode *L;
	L=new lnode;
	L->next=L;
	int i,j,k,no;
	char ch;
	cout<<"Enter the no of no you want to enter\n";
	cin>>no;
	cout<<"enter the no\n";
	cin>>k;
	L->data=k;
	for(i=1;i<no;i++){
		cin>>k;
		addend(L,k);
	}
	cout<<"Enter the variable of josephe problem\n";
	cin>>j;
	josephes(L,j);
}
