#include<iostream>
using namespace std;

struct lnode{
	lnode(){
		next=NULL;
	}
	int coff;
	int degree;
	lnode *next;
};

void addend(lnode *P,int k1,int k2)
{
	lnode *T;
	T=new lnode;
	T->coff=k1;
	T->degree=k2;
	/*As P is empty frist time*/
	if(P==NULL)
	P=T;
	else
	while(P->next!=NULL)
	 P=P->next;
	P->next=T;
}

void printpoly(lnode *P)
{
	while(P!=NULL)
	{
		cout<<P->coff<<"x"<<P->degree<<"+";
		P=P->next;
	}
	cout<<endl;
}

void addpoly(lnode *P1,lnode *P2)
{
	lnode *S;
	S=new lnode;
	S->coff=0;
	S->degree=0;
	while(P1!=NULL||P2!=NULL)
	{
		if(P1->degree==P2->degree)
		{
			addend(S,P1->coff+P2->coff,P1->degree);
			P1=P1->next;
			P2=P2->next;
		}
		else if(P1->degree>P2->degree)
		{
			addend(S,P1->coff,P1->degree);
			P1=P1->next;
		}
		else if(P2->degree>P1->degree)
		{
			addend(S,P2->coff,P2->degree);
			P2=P2->next;
		}
	}
	if(P1!=NULL)
	{
		addend(S,P1->coff,P1->degree);
		P1=P1->next;
	}
	if(P2!=NULL)
	{
		addend(S,P2->coff,P2->degree);
		P2=P2->next;
	}
	cout<<"Addition of Polynomial is :\n";
	printpoly(S);
}
void subpoly(lnode *P1,lnode *P2)
{
	lnode *S;
	S=new lnode;
	S->coff=0;
	S->degree=0;
	while(P1!=NULL||P2!=NULL)
	{
		if(P1->degree==P2->degree)
		{
			addend(S,P1->coff-P2->coff,P1->degree);
			P1=P1->next;
			P2=P2->next;
		}
		else if(P1->degree>P2->degree)
		{
			addend(S,P1->coff,P1->degree);
			P1=P1->next;
		}
		else if(P2->degree>P1->degree)
		{
			addend(S,-1*P2->coff,P2->degree);
			P2=P2->next;
		}
	}
	if(P1!=NULL)
	{
		addend(S,P1->coff,P1->degree);
		P1=P1->next;
	}
	if(P2!=NULL)
	{
		addend(S,-1*P2->coff,P2->degree);
		P2=P2->next;
	}
	cout<<"Subtraction of Polynomial is :\n";
	printpoly(S);
}
int main()
{
	lnode *P1,*P2;
	int i,size,k1,k2;
	
	P1=new lnode;
	P2=new lnode;
	
	cout<<"Enter the no of terms in polynomial P1\n";
	cin>>size;
	cout<<"Enter the polynmial as coff and its degree\n";
	cin>>k1>>k2;
	P1->coff=k1;
	P1->degree=k2;
	for(i=1;i<size;i++)
	{
		cin>>k1>>k2;
	     addend(P1,k1,k2);
	}
	cout<<"polynomial P1 is: \n";
	printpoly(P1);
	cout<<"Enter the no terms of in polynomial P2\n";
	cin>>size;
	cout<<"Enter the polynmial as coff and its degree\n";
	cin>>k1>>k2;
	P2->coff=k1;
	P2->degree=k2;
	for(i=1;i<size;i++)
	{
		cin>>k1>>k2;
	    addend(P2,k1,k2);
	}
	cout<<"polynomial P2 is: \n";
	printpoly(P2);
	//addpoly(P1,P2);
	subpoly(P1,P2);
	return 0;
}
