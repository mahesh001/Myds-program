#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
struct bstnode
{	int data;
	bstnode* lchild;
	bstnode* rchild;
	bstnode()
	{	data=0;
		rchild=NULL;
		lchild=NULL;
	}
};
int height(int a)
{	
	int i=0;
	while((pow(2,i))<a)
		i++;
	return i;
}
void create(bstnode* &t,int height)
{
	if(height==1)
	{
		t=new(bstnode);
		t->data=0;
	}
else
   {
	create(t->lchild,height-1);
	create(t->rchild,height-1);
   }
}int w=0;
void leafins(bstnode* &t,int p)
{	//if(w=0)
	//	{
			if(t->lchild==NULL && t->rchild==NULL && t->data==0 )
			t->data=p;
	//	}  
	//	else if(t->lchild==NULL && t->rchild==NULL && t->data!=0

				if(t->lchild!=NULL)
					leafins(t->lchild,p);
				if(t->rchild!=NULL)
					leafins(t->rchild,p);	
}
void leafprint(bstnode* &t)
{	
		if(t->lchild==NULL && t->rchild==NULL)
			cout<<t->data;
				if(t->lchild!=NULL)
					leafprint(t->lchild);
				if(t->rchild!=NULL)
					leafprint(t->rchild);
	
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
void flag(bstnode* &t,int q)
{ 
if(t->data==q)
{t->data=-q; } 
if(t->lchild!=NULL)
	flag(t->lchild,q);
if(t->rchild!=NULL)
	flag(t->rchild,q);
}
void search1(bstnode* &t,int q)
{ 
if(t->data==q)
t->data=0;
if(t->lchild!=NULL)
	search1(t->lchild,q);
if(t->rchild!=NULL)
	search1(t->rchild,q);
}
int check(bstnode* &t)
{	int c; 
	bstnode* l=t->lchild;
	bstnode* m=t->rchild;
	if(l->lchild->data<=0)
			if(l->rchild->data<=0)
					if(m->lchild->data<=0)
						if(m->rchild->data<=0)
							int c=1;
	else c=0;else c=0;else c=0;else c=0;
	return c;
}
int main()
{
	bstnode* t=NULL;
	int n,i=0,n1;
	cout<<"enter number of numbers";
	cin>>n;
	int* p=new int[n];
		int* q=new int[n];
	//int h=height(n);
	for(int l=1;l<=3;l++)
		create(t,l);
	leafprint(t);
	int z=0,k=0;
	bstnode* l=t->lchild;
	bstnode* m=t->rchild;
	cout<<"enter numbers:";
	for(int o=0;o<=3;o++)
		{	cin>>n1;
			if(o==0)
				l->lchild->data=n1;
				if(o==1)
				l->rchild->data=n1;
				if(o==2)
				m->lchild->data=n1;
				if(o==3)
				m->rchild->data=n1;			
		}
		p[z++]=func(t);
		cout<<p[0]<<"aaaaa";
		search1(t,p[0]);		
		leafprint(t);
	while(i<n)
	{
	 int c1=check(t);
		cin>>n1;
		leafins(t,n1);
		cout<<c1;
		//if(i<3)
		//else
		//{ 	
			//if(z==0)
				//p[z++]=func(t);
				p[z++]=func(t);
		 if(c1!=0)
			{	//p[z]=
				if(p[z-2]<p[z-1])
					flag(t,p[z--]);
				else
				{
					search1(t,p[z-1]);		
					//z++;
				}
			}
			else 
			{	
				q[k++]=func(t);

			}	
i++;
	}
	for(i=0;i<z;i++)
	cout<<" "<<p[i]<<"  "; cout<<endl;
	for(int h=0;h<k;h++)
	cout<<q[h]<<"  ";		

return 0;
}