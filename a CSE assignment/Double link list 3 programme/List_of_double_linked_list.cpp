#include<iostream>
using namespace std;
struct ddown{
	ddown *up;
	int data;
	ddown *down;
};
struct drow{
	drow *left;
	int data;
	drow *right;
	ddown *down;
};
void addendcol(ddown *LC,int k)
{
	ddown *T;
	T=new ddown;
	T->down=NULL;
	T->data=k;
	while(LC->down!=NULL)
	   LC=LC->down;
	LC->down=T;
	LC->up=LC;
}
void addend(drow *LR,int k)
{
	drow *TR;
	TR=new drow;
	TR->data=k;
	TR->right=NULL;
	TR->down=NULL;
	while(LR->right!=NULL)
	 LR=LR->right;
	LR->right=TR;
	TR->left=LR;
}
void addno(drow* LR,int k)
{
	int match=k%10;
	while(LR->data!=match&&LR!=NULL)
	{
		LR=LR->right;
	}
	if(LR->down==NULL)
	{
		ddown *T;
	    T=new ddown;
	    T->data=k;
	    T->down=NULL;
	    LR->down=T;
	}
	else
	{
		addendcol(LR->down,k);
	}
}
void printcol(ddown *LC)
{
	while(LC!=NULL)
	{
		cout<<LC->data<<" ";
		LC=LC->down;
	}
}
void printrow(drow *LR)
{
	cout<<"Row is as follow\n";
	while(LR!=NULL)
	{
		cout<<LR->data<<" ";
		printcol(LR->down);
		 cout<<endl;
		LR=LR->right;
	}
}

int main(){
	drow *LR;
	int i,temp;
	char ch;
	LR=new drow;
	LR->data=0;
	for(i=1;i<=9;i++)
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
