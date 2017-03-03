#include<iostream>
#include<cstdlib>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
bstnode *t,*t1,*t2;
int n1,n2,n3;
int height(bstnode* t)
{
	if(t==NULL)
		return -1;
	else
	{
		 int hl = 1+ height(t->lchild);
		 int hr = 1+ height(t->rchild);
		if(hl>hr)
			return(hl);
		else
			return(hr);			

	}
}
void rl(bstnode* &t1)
{
	t2=t1->rchild;
	t1->rchild=t2->lchild;
	t2->lchild=t1;
}
void rr(bstnode* &t1)
{
	t2=t1->lchild;
	t1->lchild=t2->rchild;
	t2->rchild=t1;
}
void rlrr(bstnode* &t3)
{
	rl(t3->lchild);
	t3->lchild=t2;
	rr(t3);
}
void rrrl(bstnode* &t3)
{
	rr(t3->rchild);
	t3->rchild=t2;
	rl(t3);
}
int k1=1,k=1;
void insert(bstnode * &t, int d)
{
	if(t==NULL)
	{
		t=new(bstnode);
		t->data=d;
		t->lchild=NULL;
		t-> rchild =NULL;
	}
	
	else if(d < t->data)
	{
		insert(t->lchild , d);
		if(height(t->lchild) - height(t->rchild)>=2)
		{
			if(d < t->lchild ->data)
				rr(t);
			else
				rlrr(t);
			if(t->data == t2->rchild->data)
				t=t2;
			else
				t->lchild=t2;
		}
	}
	else if(d > t->data)
	{
		insert(t->rchild , d);
		if(height(t->rchild) - height(t->lchild) >=2)
		{
			if(d > t->rchild -> data)
				rl(t);
			else
				rrrl(t);
			if(t->data == t2->lchild->data)
				t=t2;
			else
				t->rchild=t2;
		}	
	}
	else 
		return;
	
}
void tprint (bstnode * t)
{	
	if(t==NULL)
		return;
	if(t->rchild == NULL && t-> lchild == NULL)
		{
		cout<<t->data<<" ";
		return;
		}
	tprint(t->rchild);
	
	tprint(t->lchild);
	
}
void prints( bstnode *t)
{	
	if(t-> lchild != NULL)
		prints(t->lchild);
	cout<<t->data<<" ";
	if(t->rchild!=NULL)
		prints(t-> rchild);
	return;
}
/*bstnode* remove(bstnode *t, int k)
{
	if(t == NULL)
		return t;
	if(k == t->data)
	{
		    bstnode *L = NULL;
		    if(t->lchild == NULL)
		    {
			      L = t->rchild;
			      delete t;
			      return L;
		    }
		    else if(t->rchild == NULL)
		    {
			      L = t->lchild;
			      delete t;
			      return L;
		    }
		    else
		    {
			       t->data = max(t->lchild);
			       t->lchild = remove(t->lchild, max(t->lchild));
		    }
	}
	else if(k < t->data)
	{
	   	   t->lchild = remove(t->lchild, k);
	}
	else
	{
	  	   t->rchild = remove(t->rchild, k);
	}
	 
	if(height(t->lchild) - height(t->rchild)>=2)
	{
		if(height(t) > 1 && height(t->lchild) >= 0)
			rr(t);
		else if(height(t) > 1 && height(t->lchild) < 0)
			rlrr(t);
		if(t->data == t2->rchild->data)
			t=t2;
		else
			t->lchild=t2;
	}
	if(height(t->rchild) - height(t->lchild) >=2)
	{
		if(height(t) < -1 && height(t->rchild) <= 0)
			rl(t);
		else if(height(t) < -1 && height(t->rchild) > 0)
			rrrl(t);
		if(t->data == t2->lchild->data)
			t=t2;
		else
			t->rchild=t2;
	}	
	return t;
}*/
int main()
{
	t=NULL;
	int d;
	cout<<"enter elements"<<endl;
	cin>>d;
	while(d!=-1)
	{
		insert(t, d);
		cin>>d;
	}
	/*cout<<"Enter the element to be deleted"<<endl;
	cin>>d;
	t=remove(t,d);*/
	cout<<"Sorted order is"<<endl;
	prints(t);cout<<endl;
	cout<<endl;
return 0;
}
