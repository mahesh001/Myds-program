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
int search(lnode *L,int k)
{
	while((L->data!=k)&&(L->next!=NULL))
		L=L->next;
	if(L->next==NULL&&L->data!=k)
	  return 0;
	else
	  return 1;
}
void del(lnode *L,int k)
{
	if(search(L,k))
	{
	   while(L->next->data!=k)
	   {
		L=L->next;
	   }
	L->next=L->next->next;
    }
    else
	{
		cout<<"element not present in List\n";
    }
}
void deldup(lnode *L)
{
	lnode *T;
	while(L!=NULL&&L->next!=NULL)
	{
        T=L;
		while(T->next!=NULL)
		{
			if(L->data==T->next->data)
			{
				T->next=T->next->next;
		    }
		    else
		    T=T->next;
		}
		L=L->next;
	}
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
   lnode *L;
   int i,k,x,size;
   L=new lnode;
   cout<<"Enter the no of you want to enter\n";
   cin>>size;
   cout<<"Enter the nos\n";
   cin>>L->data;
   for(i=1;i<size;i++)
   {
   	cin>>k;
   	addend(L,k);
   }
   cout<<"You Entered\n";
   printList(L);
   cout<<"List without dupicate elements\n";
   //cout<<"Enter no you want to delete\n";
   //cin>>k;
   deldup(L);
   //del(L,k);
   printList(L);
}
