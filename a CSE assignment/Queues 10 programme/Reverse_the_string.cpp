#include<iostream>
#include<cstring>
using namespace std;

struct lnode
{
   char data;
   lnode *next;	
};

void addend(lnode *L,char k)
{
   lnode *T;
   T=new lnode;
   T->data=k;
   T->next=L;
   while(L->next!=L)
    L=L->next;
    L->next=T;
}

int main()
{
	lnode *L;
	int i,l;
	char str[20];
	cout<<"Enter the string\n";
	cin>>str;
	l=strlen(str);
	L=new lnode;
	L->next=L;
	L->data=str[0];
	for(i=1;i<l;i++)
	{
		addend(L,str[i]);
	}
}
