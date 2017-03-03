#include<iostream>
using namespace std;
struct lnode{
	lnode(){
		next=NULL;
	}
	int data;
	lnode *next;
};
void addend(lnode *N,int k)
{
   lnode *T;
   T=new lnode;
   T->data=k;
   T->next=NULL;
   while(N->next!=NULL)
    N=N->next;
    N->next=T;
}
void printNo(lnode *N)
{
	int i=-1,a[10];
	cout<<"The no are \n";
	if(N==NULL)
	cout<<"No number\n";
	else
	{
      while(N!=NULL)
       {
  	     a[++i]=N->data;
  	     N=N->next;
       }	
       while(i>=0)
       cout<<a[i--];
       cout<<endl;
    }
}
lnode* addno(lnode *N1,lnode *N2)//N1 has less or equal no of digit that of N2
{
	lnode *T;
	lnode *T1;
	T=new lnode;
	T1=T;
	int carry=0,empty=1;
	while(N1!=NULL)
	{
		if(empty)
		{
		T->data=(N1->data+N2->data+carry)%10;
		carry=(N1->data+N2->data)/10;
		empty=0;
	    }
	    else
		{
	    	addend(T,(N1->data+N2->data+carry)%10);
	    	carry=(N1->data+N2->data)/10;
	    }
	    N1=N1->next;
	    N2=N2->next;
	}
	while(N2!=NULL)
	{
		addend(T,(N2->data+carry)%10);
		carry=(N2->data+carry)/10;
		N2=N2->next;
	}
	return T1;
}
int main()
{
   lnode *N1,*N2,*N3;
   int i,k,x,N1size,N2size,a[20],index=-1;
   N1=new lnode;
   N2=new lnode;
   cout<<"Enter the no of digit in large no 1\n";
   cin>>N1size;
   cout<<"Enter the large no 1 by digit by digit\n";
   for(i=0;i<N1size;i++)
   {
   	cin>>a[++index];
   }
   N1->data=a[index--];
   while(index>=0){
   	addend(N1,a[index--]);
   }
   index=-1;
   cout<<"You Entered\n";
   printNo(N1);
   cout<<"Enter the no of digit in large no 2\n";
   cin>>N2size;
   cout<<"Enter the large no 2 by digit by digit\n";
   for(i=0;i<N2size;i++)
   {
   	 cin>>a[++index];
   }
   N2->data=a[index--];
   while(index>=0){
   	addend(N2,a[index--]);
   }
   cout<<"You Entered\n";
   printNo(N2);
   if(N2size>N1size)//N1 has less or equal no of digits that of N2
   N3=addno(N1,N2);
   else
   N3=addno(N2,N1);
   cout<<"Addition is follow: \n";
   printNo(N3);
}
