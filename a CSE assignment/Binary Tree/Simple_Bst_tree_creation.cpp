#include<iostream>
#include<cmath>
using namespace std;
/*struct for binary search tree*/
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};

void insert(bstnode* &B,int k)
{
	if(B==NULL)
	{
		B=new bstnode;
		B->data=k;
		B->lchild=NULL;
		B->rchild=NULL;
	}
	else if(k<B->data)
	  insert(B->lchild,k);
	else
	  insert(B->rchild,k);
}

int main()
{
	bstnode *B=NULL;
	int k;
	
	while(1)
	{
		cout<<"Enter the elment to be inserted in binary search tree\n"
		    <<"Enter -1 to end\n";
		cin>>k;
		if(k==-1)
		 break;
		insert(B,k);
	}
}
