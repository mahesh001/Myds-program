#include<iostream>
using namespace std;

class lnode{
	public:
	char data;
	lnode *next;
	
	void add_end(lnode *L,char x)	
	{	lnode *T;
		T=new lnode;
		while(L->next!=NULL)
			L=L->next;
		T->data=x;
		T->next=L->next;
		L->next=T;
	}
	
	void rotate(lnode* &L)
	{
		lnode *T=new lnode;
		lnode *T1=new lnode;
		T=L;
		while(T->next!=L)
		{
			T=T->next;
		}
		T1->next=T->next->next;
		T1->data=L->data;
		T->next=T1;
		L=L->next;
	}
};
	int main()
	{
		lnode *L1=new lnode;
		lnode *L2=new lnode;
		lnode *T1=new lnode;
		lnode *T2=new lnode;
	int i,j,m=1,n=1,x=0,t=0;
	char h1,h2,k1,k2;
	//enter 1st string
	cout<<"enter the original string into the LL\n";
	cout<<"enter the head value\n";
	cin>>h1;
	L1->data=h1;
	L1->next=NULL;
	while(1)
		{
			cout<<"enter the element to be added(enter n to stop)\n";
				cin>>k1;
				if(k1=='n')
				 break;
				
				L1->add_end(L1,k1);
				m++;
		}
	T1=L1;
	while(L1->next!=NULL)
	L1=L1->next;
	L1->next=T1;
	L1=L1->next;
	//enter 2nd string
	cout<<"enter the string to be tested\n";
	cout<<"enter the head value\n";
	cin>>h2;
	L2->data=h2;
	L2->next=NULL;
	while(1)
		{
			cout<<"enter the element to be added(enter n to stop)\n";
				cin>>k2;
				if(k2=='n') break;
				L2->add_end(L2,k2);
				n++;
		}
	T2=L2;
	while(L2->next!=NULL)
	L2=L2->next;
	L2->next=T2;
	
	if(m==n)
	{	
		while(x!=n)
		{
			for(i=0;i<n;i++)
			{
				if(L1->data==L2->data)
				{
					x++;
				}
				else{
					break;
				}
			}
		L1->rotate(L1);
		t++;
		}
	}
	else
	cout<<"the given strings do not  match\n";
	if(x==n)
	cout<<"2nd string is the "<<t<<"th rottation of 1st string\n";
	else
	cout<<"they are not related\n";
	return 0;	
}
	
	
	
	
	
	
	
	
	
	
