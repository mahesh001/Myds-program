#include<iostream>
#include<fstream>
using namespace std;
struct bintree
{
	bintree *lchild;
	int data;
	bintree *rchild;
};
void createTree(bintree* &T,int l)
{
	if(T==NULL && l==1)
	{
		T=new(bintree);
		T->lchild=NULL;
		T->rchild=NULL;
		T->data=-1;
	}
	else
	{
		createTree(T->lchild,l-1);
		createTree(T->rchild,l-1);
	}
}
void insertData(bintree* &T,int a[])
{
	static int i=0;
	if(T->lchild==NULL && T->rchild==NULL)
	{
		if(i<4)
			T->data=a[i++];
	}
	else
	{
		insertData(T->lchild,a);
		insertData(T->rchild,a);
	}
}
void print(bintree *T)
{
	if(T->lchild==NULL && T->rchild==NULL)
		cout<<T->data<<" ";
	else
	{
		print(T->lchild);
		print(T->rchild);
	}
}
void selectionSort(bintree* &T)
{
	if(T!=NULL)
	{
		selectionSort(T->lchild);
		selectionSort(T->rchild);
		if(T->lchild!=NULL && T->rchild!=NULL)
		{
			if(T->rchild->data<0 && T->lchild->data>0)
				T->data=T->lchild->data;
			else if(T->lchild->data<0 && T->rchild->data>0)
				T->data=T->rchild->data;
			else if(T->lchild->data < T->rchild->data)
				T->data=T->lchild->data;
			else 
				T->data=T->rchild->data;
		}
	}
}
void reset(bintree* T,int k,int m,int flag)
{
	if(T!=NULL)
	{
		if(T->data==k)
		{
			if(T->lchild==NULL && T->rchild==NULL)
			{
				if(flag==1)
					T->data=(-1)*(T->data);
				else
					T->data=m;
			}		
			else
				T->data=-1;
		}
		reset(T->lchild,k,m,flag);
		reset(T->rchild,k,m,flag);
	}	
}
void makePos(bintree *T)
{
	if(T!=NULL)
	{
		if(T->lchild==NULL && T->rchild==NULL)
			T->data=(-1)*T->data;
		makePos(T->lchild);
		makePos(T->rchild);
	}
}
void swap(int& flag1,int& flag2)
{
	int flag;
	flag=flag1;
	flag1=flag2;
	flag2=flag;
}
int empty(bintree *T)
{
	if(T->lchild==NULL && T->rchild==NULL)
	{
		if(T->data==-1)
			return 1;
		else
			return 0;
	}
	else
	{
		empty(T->lchild);
		empty(T->rchild);
	}
}
void inorder(bintree *T)
{
	if(T!=NULL)
	{
		inorder(T->lchild);
		cout<<T->data<<" ";
		inorder(T->rchild);
	}
}
int main()
{
	bintree *T=NULL;
	ifstream fin;
	ofstream fout;
	int a[4];
	int k;
	int count1=0;
	int m,count=0;
	
	fin.open("data.txt");
	fout.open("a1.txt",ios::app);
	for(int k=1;k<=3;k++)
		createTree(T,k);
	for(int i=0;i<4;i++)
		fin>>a[i];
	insertData(T,a);
	inorder(T);cout<<endl;
	selectionSort(T);
	inorder(T);//cout<<endl;
	k=T->data;
	fout<<k<<" ";
	fin>>m;
	reset(T,k,m,0);
	inorder(T);cout<<endl;
	while(!fin.eof())
	{	
			selectionSort(T);
			inorder(T);cout<<endl;
			if(T->data>k)
			{
				fout<<T->data<<" ";
				//flush(fout);
				fin>>m;
				k=T->data;
				reset(T,T->data,m,0);
				inorder(T); 
				cout<<endl;
			}
			else
			{
				reset(T,T->data,m,1);
				inorder(T);cout<<endl;
				count++;
			}		
			
		if(count==4)
		{
			count=0;k=0;
			cout<<"entered ";
			fout<<-1<<" ";
			makePos(T);
			inorder(T);cout<<endl;
			if(count1%2==0)
			{
				fout.close();
				fout.open("a2.txt",ios::app);
			}
			else
			{
				fout.close();
				fout.open("a1.txt",ios::app);
			}
			count1++;
		}
	}int x=0;
	while(x<4)
	{
		selectionSort(T);
		fout<<T->data<<" ";
		reset(T,T->data,-1,0);
		x++;
	}
	
}
