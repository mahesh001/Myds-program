#include<iostream>
using namespace std;

struct avlnode
{
	int element;
	avlnode *lc;
	avlnode*rc;
	int height;
	
}*root=NULL;
int min(avlnode*T);
int height(avlnode*T)
{
	if(T==NULL)
	return -1;
	else
	return(1+(height(T->lc),height(T->rc)));
}
void rotatelc(avlnode*&T)
{
	avlnode*k1=T->lc;
	T->lc=k1->rc;
	k1->rc=T;

	T=k1;
}
void rotaterc(avlnode*&T)
{
	avlnode*k1=T->lc;
		T->lc=k1->rc;
	k1->rc=T;

	T=k1;
	
}
void doublelc(avlnode*&T)
{
	rotatelc(T->lc);
	rotatelc(T);
	
}
void doublerc(avlnode*&T)
{
		rotaterc(T->lc);
	rotaterc(T);
	
}

              void insert(int n, avlnode* &T)
              {
                   if(T==NULL)
                   {
                              T=new avlnode;
                              T->element=n;
                              T->lc=NULL;
                              T->rc=NULL;
                   }
                   else if(n<T->element)
                   {
                        insert(n,T->lc);
                        if((height(T->lc) - height(T->rc)) >= 2)
                        {
                               if(n<T->lc->element)
							   rotatelc(T);
                               else
							    doublelc(T);
                        }
                   }
                   else if(n>T->element)
                   {
                        insert(n,T->rc);
                        if((height(T->lc) - height(T->rc)) >= 2)
                        {
                               if(n>T->rc->element)
							   rotaterc(T);
                               else 
							   doublerc(T);
                        }
                   }
           }
		 
void inorder(avlnode*T)
{

 if(T!=NULL)
 
 {
  inorder(T->lc);
  cout<<T->element<<" ";
  inorder(T->rc);
 }

}

void preorder(avlnode*T)
{
 if(T!=NULL)

 {
  cout<<T->element<<" ";
  preorder(T->lc);
  preorder(T->rc);
 }

}

void postorder(avlnode*T)
{
 if(T!=NULL)

 {
  postorder(T->lc);
  postorder(T->rc);
  cout<<T->element<<" ";
 }
}
avlnode* remove(avlnode *t, int k)
{
	if(t == NULL)
		return t;
	if(k == t->element)
	{
		    avlnode *L = NULL;
		    if(t->lc == NULL)
		    {
			      L = t->rc;
			      delete t;
			      return L;
		    }
		    else if(t->rc == NULL)
		    {
			      L = t->lc;
			      delete t;
			      return L;
		    }
		    else
		    {
			       t->element = min(t->lc);
			       t->lc = remove(t->lc, min(t->lc));
		    }
	}
	else if(k < t->element)
	{
	   	   t->lc = remove(t->lc, k);
	}
	else
	{
	  	   t->rc = remove(t->rc, k);
	}
}
	 
int min(avlnode*T)
{
	if(T->lc==NULL)
	return T->element;
	else
	return
	min(T->lc);
}
void check(avlnode*T,int n)
{
                  if(T!=NULL)
                   if(n<T->element)
                   {
                        insert(n,T->lc);
                        if((height(T->lc) - height(T->rc)) >= 2)
                        {
                               if(n<T->lc->element)
							   rotatelc(T);
                               else
							    doublelc(T);
                        }
                   }
                   else if(n>T->element)
                   {
                        insert(n,T->rc);
                        if((height(T->lc) - height(T->rc)) >= 2)
                        {
                               if(n>T->rc->element)
							   rotaterc(T);
                               else 
							   doublerc(T);
                        }
                   }
           }
void print (avlnode * T, int & p)
{
    if (!T) return;

    print (T->lc,p);

    p++;
    cout << p << ' ' << T->element << endl;

    print (T->rc,p);
}

int main()
{
	int element,i,p,n,x,k;
	do
	{ 
	   cout<<"press your choice \n"<<endl;
	   cout<<" 1    for insert "<<endl;
	   cout<<" 2    for tree travels "<<endl;
	   cout<<" 3    for delete"<<endl;
	   cout<<" 4    for print "<<endl;
	   cin>>i;
switch(i)
{
case 1:
	cout<<"enter element \n";
	cin>>element;
	insert(element,root);
	break;
case 2:
       cout<<" preorder---> ";
	    preorder(root);
	    cout<<endl;
      cout<<" inorder---> ";
	   inorder(root);
	   cout<<endl;
      cout<<" postorder---> ";
	   postorder(root);
	   cout<<endl;
case 3:
      cout<<"enter the element \n";
	  cin>>n;
	 remove(root,n);	
	 check(root,k)  ;
case 4:
      cout<<"enter the value\n";
      cin>>p;
	  print(root,p);	  
	default: cout<<"wrong choice \n";
	cout<<endl;
}
cout<<" you want to continue ";
cin>>x;
}
while(x==1);
return 0;
}

