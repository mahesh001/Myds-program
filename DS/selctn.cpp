#include <iostream>
#include <fstream>
using namespace std;
ifstream fin;
ofstream fout[3];
struct bnode
{
	int flag;
	int data;
	bnode* lchild;
	bnode* rchild;
};
bnode* q;
int k=2,k2=2,c=0,n,k1=0,r=0,r1=0,m=0,r2=0;
void add(bnode* &l,int c)
{
	if(l==NULL)
	{
		l=new(bnode);
		l->data=0;
		l->flag=0;
		l->rchild=NULL;
		l->lchild=NULL;
	}
	if(c==k)
	{
		if(!fin.eof())
		fin>>n;
		else
		n=-1;
		l->data=n;
		l->flag=0;
		return;
	}
	add(l->lchild,c+1);
	add(l->rchild,c+1);
}
int height(bnode* B)
{
	int a,b;
	if(B==NULL)
		return -1;
	else
	{
		a=1+height(B->lchild);
		b=1+height(B->rchild);
		return (a>b)?a:b;
	}
}
void levelorder(bnode *N, int k)
{
	if(N!=NULL)
	{
		if(k==0)
		{
			cout<<N->data;
		}
		else 
		{
			levelorder(N->lchild,k-1);
			levelorder(N->rchild,k-1);
		}
	}
}
void print(bnode *N)
{
	int h=height(N);
	for(int i=0;i<=h;i++) 
	{
		levelorder(N,i);
		cout << endl;
	}
}
void selection(bnode* t,int n1)
{
		if(n1==k-1)
		{
			if(t->lchild->flag==0||t->rchild->flag==0)
			{
			if(t->lchild->flag==1&&t->rchild->flag==0)
			{
			t->data=t->rchild->data;
			if(r2==1)
				t->rchild->data=-1;
			}
			else if(t->rchild->flag==1&&t->lchild->flag==0)
			{
			t->data=t->lchild->data;
			if(r2==1)
				t->lchild->data=-1;
			}
			else if(t->lchild->data<t->rchild->data)
			{
			if(t->lchild->data==-1)
			{
				t->data=t->rchild->data;
				if(r2==1)
				t->rchild->data=-1;
			}
			else
			{
			t->data=t->lchild->data;
			if(r2==1)
				t->lchild->data=-1;
			}
			}
			else
			{
			if(t->rchild->data==-1)
			{
				t->data=t->lchild->data;
				if(r2==1)
				t->lchild->data=-1;
			}
			else
			{
			t->data=t->rchild->data;
			if(r2==1)
				t->rchild->data=-1;
			}
			}
	    }
	    else 
	    	t->data=-1;
		return;
	}
	selection(t->lchild,n1+1);
	selection(t->rchild,n1+1);
}
void getvalue(bnode* &l,int n1,int c)
{
	if(c==k)
	{
		if(l->data==n1)
		{
			if(!fin.eof())
				fin>>n;
			else
				n=-1;
			l->data=n;
		}
		return;
	}
	getvalue(l->lchild,n1,c+1);
	getvalue(l->rchild,n1,c+1);
}
void assignflag(bnode* t,int n1,int c)
{
	if(t==NULL)
		return;
	if(c==k2)
	{
		if(t->data==n1)
			t->flag=1;
	}
	assignflag(t->lchild,n1,c+1);
	assignflag(t->rchild,n1,c+1);
}
void resetflag(bnode* t,int c)
{
	if(t==NULL)
		return;
	if(c==k2)
	{
		t->flag=0;
	}
	resetflag(t->lchild,c+1);
	resetflag(t->rchild,c+1);
}
int main()
{
	r1=0;
	fin.open("data.txt");
	fout[1].open("s1.txt");
	fout[2].open("s2.txt");
	bnode* t=NULL;
	add(t,0);
	print(t);
	q=t;
	int k2=2;
	do
	{
		while(k!=0)
		{
			selection(t,0);
			k--;
		}
		if(k==0)
		{
			k=k2;
			if(t->data!=-1)
			{
			//	k=k2;
				if(t->data!=0)
				{
					if(t->data<r)
					{
						assignflag(t,t->data,0);
					}
					if(t->data>r)
					{
						if(r1==0)
							fout[1]<<t->data<<" ";
						else
							fout[2]<<t->data<<" ";
						r=t->data;
						getvalue(t,t->data,0);
						t->data=-1;
					}
				}
			}
			else
			{
				k=k2;
				resetflag(t,0);
				r=0;
				if(r1==0)
				{
					fout[1]<<"-1"<<" ";
					r1=1;
				}
				else
				{
					fout[2]<<"-1"<<" ";
					r1=0;
				}
			}
		}
		cout<<endl<<endl;
		print(t);
	}while(!fin.eof());
	int i=0;
	for(;i<3;i++)
	{
		r2=1;
		while(k!=0)
		{
			selection(t,0);
			k--;
		}
		if(k==0)
		{
			k=k2;
			if(t->data!=-1)
			{
				k=k2;
				if(t->data!=0)
				{
					if(t->data<r)
					{
						assignflag(t,t->data,0);
					}
					if(t->data>r)
					{
						if(r1==0)
							fout[1]<<t->data<<" ";
						else
							fout[2]<<t->data<<" ";
						r=t->data;
						getvalue(t,t->data,0);
						t->data=-1;
					}
				}
			}
			else
			{
				k=k2;
				resetflag(t,0);
				r=0;
				if(r1==0)
				{
					fout[1]<<"-1"<<" ";
					r1=1;
				}
				else
				{
					fout[2]<<"-1"<<" ";
					r1=0;
				}
			}
		}
	}
	return 0;
}