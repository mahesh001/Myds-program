#include<iostream>
#include<cmath>
using namespace std;
struct bstnode
{	int data;
	bstnode* lchild;
	bstnode* rchild;
	bstnode()
	{	data=-1;
		rchild=NULL;
		lchild=NULL;
	} 
};
int k=0;
void leafins(bstnode* &t,int p[],int x)
{	if(k<x)
	{
		if(t->lchild==NULL && t->rchild==NULL && t->data==-1)
				t->data=p[k++];
				//return;
				if(t->lchild!=NULL)
				leafins(t->lchild,p,x);
				if(t->rchild!=NULL)
				leafins(t->rchild,p,x);
	}
}
int func(bstnode* &t)
{	
	if(t->lchild!=NULL&&t->rchild!=NULL)
	{
		t->lchild->data=func(t->lchild);
		t->rchild->data=func(t->rchild);

		if(t->lchild->data>t->rchild->data)
			t->data=t->lchild->data;
		else 
			t->data=t->rchild->data;
	}
	return t->data;
}
int search(bstnode* &t,int q)
{ 
if(t->data==q)
t->data=-1; 
if(t->lchild!=NULL)
	search(t->lchild,q);
if(t->rchild!=NULL)
	search(t->rchild,q);
}
int height(int a)
{	
	int i=0;
	while((pow(2,i))<a)
		i++;
	return i;
}
void create(bstnode* &t,int height)
{
	if(height==0)
	//{
		t=new(bstnode);
		//t->data=-1;
	//}
else
   {
	create(t->lchild,height-1);
	create(t->rchild,height-1);
   }
}

void print(bstnode* &t,int height)
{
	if(height==0)
		cout<<t->data<<endl;
else if(height>=1)
   {
	print(t->lchild,height-1);
	print(t->rchild,height-1);
   }
}
int main()
{
	bstnode* t=NULL;
	int n,i=0,z;
	cout<<"enter number of numbers";
	cin>>n;
	int* p=new int[n];
	int h=height(n);
	for(int l=0;l<h+1;l++)
		create(t,l);
	//for(int l=1;l<=h+1;l++)
		//print(t,l);
	i=0;
	while(i<n)
		cin>>p[i++];
	leafins(t,p,n);
	//for(int l=1;l<=h+1;l++)
		//print(t,l);
	int r=0;
	cout<<"Sorted order(descending)"<<endl;
	while(r<n)
	{
		z=func(t);
		if(z!=-1)
		cout<<z<<" ";
		search(t,z);
		r++;
	}
}