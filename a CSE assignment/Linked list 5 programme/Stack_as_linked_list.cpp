#include<iostream>
using namespace std;
struct lnode{
	int data;
	lnode *next;
};

void push(lnode* &L,int k)
{
   lnode *T;
   T=new lnode;
   T->data=k;
   T->next =L;
   L=T;	
}
int pop(lnode* &L)
{
   int temp;
   temp=L->data;
   L=L->next;
   return temp;	
}
int main()
{
	lnode *L;
	int i;
	cout<<"Here we push 10 integers into the stack\n";
	for(i=0;i<10;i++){
		push(L,i);
	}
	for(i=0;i<10;i++)
	cout<<pop(L)<<" ";
	
}
