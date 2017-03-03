#include<iostream>
using namespace std;
struct lnode
{
	lnode(){
		next=NULL;
	}
   int data;
   lnode *next;	
};
void printList(lnode *L)
{
  while(L!=NULL)
  {
  	cout<<L->data<<" ";
  	L=L->next;
  }	
  cout<<endl;
}
void addend(lnode *L,int k)
{
   lnode *T;
   T=new lnode;
   T->data=k;
   T->next=NULL;
   while(L->next!=NULL)
    L=L->next;
    L->next=T;
}
void Merge(lnode *L1,lnode *L2)
{
	lnode *M;
	if(L1->data<L2->data){
		M=L1;
		while(L1->next!=NULL)
		L1=L1->next;
		L1->next=L2;
	}
	else if(L1->data>L2->data)
	{
		M=L2;
		while(L2->next!=NULL)
		L2=L2->next;
		L2->next=L1;
	}
	cout<<"Merged List is:\n";
	printList(M);
}
int main()
{
   lnode *L1,*L2;
   int i,k,size;
   L1=new lnode;
   L2=new lnode;
   cout<<"Enter the nos of integer you want to enter in L1\n";
   cin>>size;
   
   cout<<"Enter the nos\n";
   cin>>L1->data;
   
   for(i=1;i<size;i++)
   {
   	cin>>k;
   	addend(L1,k);
   }
   cout<<"Enter the nos of integer you want to enter in L2\n";
   cin>>size;
   
   cout<<"Enter the nos\n";
   cin>>L2->data;
   
   L2->next=NULL;
   for(i=1;i<size;i++)
   {
   	cin>>k;
   	addend(L2,k);
   }
   cout<<"You Entered in L1\n";
   printList(L1);
   
   cout<<"You Entered in L2\n";
   printList(L2);
   
   Merge(L1,L2);
   return 0;
}
