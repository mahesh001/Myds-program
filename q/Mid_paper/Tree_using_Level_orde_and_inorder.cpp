#include<iostream>
#include<cstring>
using namespace std;

struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};

int find(char *in,char k)
{
	int i;
	for(i=0;in[i]!=k;i++);
	if(in[i]==k)
	return i;
	else
	return -1;
}

void create_tree(bstnode* &T,char *in,char *lev,int &index,int start,int end)
{
	char root=lev[index++];
	int index_in_inorder=find(in,root);
	if(index_in_inorder==-1)
	{
	  T=new bstnode;
	  T->data=root;
	  T->lchild=NULL;
	  T->rchild=NULL;
	  if(index_in_inorder<end)
	  create_tree(T->rchild,in,lev,index,(index_in_inorder+1),end);
	  if(start<index_in_inorder)
	  create_tree(T->lchild,in,lev,index,start,(index_in_inorder-1));
	}
	else
	{
	   T=new bstnode;
	   T->data=root;
	   T->lchild=NULL;
	   T->rchild=NULL;
	   if(start<index_in_inorder)
	   create_tree(T->lchild,in,lev,index,start,(index_in_inorder-1));
	   if(index_in_inorder<end)
	   create_tree(T->rchild,in,lev,index,(index_in_inorder+1),end);
	}
}

int main()
{
	char in[20],lev[20];
	cout<<"Enter the inorder exp\n";
	cin>>in;
	cout<<"Enter the level order exp\n";
	cin>>lev;
	bstnode *T=NULL;
	int index=0;
	create_tree(T,in,lev,index,0,strlen(in));
}
