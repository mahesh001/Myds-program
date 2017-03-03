#include<iostream>
using namespace std;

struct btnode
{
	int level;
	btnode *lchild;
	char data;
	btnode *rchild;
};

void create(btnode* &T)
{
	char ch;
	if(T==NULL)
	{
		cout<<"Enter / for end\n";
		cin>>ch;
		if(ch=='/')
		return;
		T=new btnode;
		T->data=ch;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	cout<<"Enter the lchild value of "<<T->data<<" ";
	create(T->lchild);
	cout<<"Enter the rchild value of "<<T->data<<" ";
	create(T->rchild);
}

int height(btnode *T)
{
	if(T==NULL)
	return -1;
	else if(height(T->lchild)>height(T->rchild))
	return 1+height(T->lchild);
	else
	return 1+height(T->rchild);
}

void getlevel(btnode *T,int t)
{
	if(T!=NULL)
	{
		T->level=t;
	    getlevel(T->lchild,t+1);
	    getlevel(T->rchild,t+1);
	}
}

void print_Level(btnode *T,int l)
{
	if(T!=NULL)
	{
		if(T->level==l)
		cout<<T->data<<" ";
		print_Level(T->lchild,l);
		print_Level(T->rchild,l);
	}
}

void print_Reverse(btnode *T)
{
	for(int i=height(T);i>=0;i--)
	print_Level(T,i);
}

int main()
{
	btnode *T=NULL;
	cout<<"Enter the element for tree\n";
	create(T);
	cout<<"Getting level\n";
	getlevel(T,0);
	cout<<"Printing Reverser order\n";
	print_Reverse(T);
}

