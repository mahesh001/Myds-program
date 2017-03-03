#include<iostream>
using namespace std;
struct avlnode
{
	int element;
	avlnode *lc;
	avlnode*rc;
	int height;
	
}*root=NULL;
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
  cout<<T->element;
  inorder(T->rc);
 }

}

void preorder(avlnode*T)
{
 if(T!=NULL)

 {
  cout<<T->element;
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
  cout<<T->element;
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
	int element,i,p,n,x;
	do
	{ 
	   cout<<"press your choice \n"<<endl;
	   cout<<" 1    for insert "<<endl;
	   cout<<" 2    for preorder "<<endl;
	   cout<<" 3    for inorder  "<<endl;
	   cout<<" 4    for  postorder "<<endl;
	   cout<<" 5    for delete"<<endl;
	   cout<<" 6    for print "<<endl;
	   cin>>i;
switch(i)
{
case 1:
	cout<<"enter element \n";
	cin>>element;
	insert(element,root);
	break;
case 2:
       cout<<"preorder \n";
	   preorder(root);
	   break;
case 3:
      cout<<"inorder \n";
	  inorder(root);
	  break;
case 4:
      cout<<"postorder \n";
	  postorder(root);
	  break;
case 5:
      cout<<"enter the element \n";
	  cin>>n;
	//  delete(root,n);	  
case 6:
      cout<<"enter the value\n";
      cin>>p;
	  print(root,p);	  
	default: cout<<"wrong choice \n";
}
cout<<"you want to continue \n";
cin>>x;
}
while(x==1);
return 0;
}

