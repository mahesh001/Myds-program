#include<iostream>
using namespace std;
struct lnodec{
	lnodec(){
		next=NULL;
	}
	int data;
	lnodec *next;
};
struct lnoder{
	lnoder(){
		nextr=NULL;
		nextc=NULL;
	}
	int data;
	lnoder *nextr;
	lnodec *nextc;
};
void addend(lnoder* LR,int k)
{
	lnoder *TR;
	TR=new lnoder;
	TR->data=k;
	while(LR->nextr!=NULL)
	LR=LR->nextr;
	LR->nextr=TR;
}
void addendcol(lnodec *LC,int k)
{
	lnodec *TC;
	TC=new lnodec;
	TC->data=k;
	while(LC->next!=NULL)
	 LC=LC->next;
	LC->next=TC;
}
void addno(lnoder* LR,int k)
{
	int match=k%10;
	while(LR->data!=match&&LR!=NULL)
	{
		LR=LR->nextr;
	}
	if(LR->nextc==NULL)
	{
		lnodec *TC;
	    TC=new lnodec;
	    TC->data=k;
	    LR->nextc=TC;
	}
	else
	{
		addendcol(LR->nextc,k);
	}
}
void printcol(lnodec *LC)
{
	while(LC!=NULL)
	{
		cout<<LC->data<<" ";
		LC=LC->next;
	}
}
void printrow(lnoder *LR)
{
	cout<<"Row is as follow\n";
	while(LR!=NULL)
	{
		cout<<LR->data<<" ";
		printcol(LR->nextc);
		 cout<<endl;
		LR=LR->nextr;
	}
}

int main(){
	lnoder *LR;
	int i,temp;
	char ch;
	LR=new lnoder;
	LR->data=1;
	for(i=2;i<=9;i++)
	 addend(LR,i);
	cout<<"The row is\n";
	printrow(LR);
	cout<<"Enter the no for List of Linked list\n";
	do
	{
		cin>>temp;
		addno(LR,temp);
		cout<<"Want to Enter more type y for yes or n for no\n";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	cout<<"Your List of Linked List is \n";
	printrow(LR);
}
