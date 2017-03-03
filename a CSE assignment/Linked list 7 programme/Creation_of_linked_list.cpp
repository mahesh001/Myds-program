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
int isempty(lnode *L)
{
	if(L==NULL)
	return 1;
	else
	return 0;
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
void addafter(lnode *L,int x,int k)
{
	lnode *T;
	T=new lnode;
	while(L->data!=x)
		L=L->next;
	T->data=k;
	T->next=L->next;
	L->next=T;
}
void addbefor(lnode *L,int x,int k)
{
   lnode *T;
   T=new lnode;
   T->data=k;
   if(L->data==x)
   {
   	 T->next=L;
   	 L=T;
   }
   else
   {
     while(L->next->data!=x)
   	   L=L->next;
     T->next=L->next;
     L->next=T;
   }
}
lnode* addfront(lnode *L,int k)
{
	lnode *T;
	T=new lnode;
	T->data=k;
	T->next=L;
	return T;
}
int search(lnode *L,int k)
{
	while((L->data!=k)&&(L->next!=NULL))
		L=L->next;
	if(L->next==NULL&&L->data!=k)
	  return 0;
	else
	  return 1;
}
lnode* del(lnode *L,int k)
{
	lnode *T;
	T=L;
	if(search(L,k))
	{
		if(L->data==k)
		{
			if(L->next==NULL)
			L=NULL;
			else
			L=L->next;
			return L;
		}
		else
		{
			while(L->next->data!=k)
			L=L->next;
			if(L->next->next==NULL)
			L->next=NULL;
			else
			L->next=L->next->next;
			return T;
		}
	}
	else
	{
		cout<<"Element is not present\n";
		return T;
	}
}
void printList(lnode *L)
{
	if(L==NULL)
	cout<<"List is empty\n";
	else
	{
      while(L!=NULL)
       {
  	     cout<<L->data<<" ";
  	     L=L->next;
       }	
       cout<<endl;
    }
}
int main()
{
   lnode *L;
   int i,k,x,size;
   L=new lnode;
   cout<<"Enter the no of you want to enter\n";
   cin>>size;
   cout<<"Enter the nos\n";
   cin>>L->data;
   L->next=NULL;
   for(i=1;i<size;i++)
   {
   	cin>>k;
   	addend(L,k);
   }
   cout<<"You Entered\n";
   printList(L);
   //cout<<"Enter no before you want to add no\n";
   //cin>>x;
   cout<<"Enter the key no You want to delete\n";
   cin>>k;
   //if(search(L,k))
   //cout<<"Key found\n";
   //else
   //cout<<"Key not found\n";
   L=del(L,k);
   cout<<"Now Your List is :\n";
   printList(L);
} 
