#include<iostream>
#include<conio.h>
using namespace std;
struct dnode
{
      int data;
      dnode *left;
      dnode *right;
};
void add(dnode *L,int k)
{     while(L->right!=NULL) L=L->right;
         L->right=(dnode*)new(dnode);
         L->right->data=k;
         L->right->left=L;
         L->right->right=NULL;
}
void print(dnode *L,dnode *k)
{
     while(L->right!=k)
     {
        cout<<L->data<<"  ";getch();
        L=L->right;
     }
     cout<<L->data;
     cout<<"\n";
}
void fn(dnode *C)
{
     dnode *t;
     t=(dnode*)new dnode;
     t=C;
     while(C->right!=NULL) C=C->right;
      C->right=t;t->left=C;
}
void merge(dnode *C1,dnode *C2,dnode *p,dnode *q)
{
     while(C1->right!=p) C1=C1->right;
     while(C2->right!=q) C2=C2->right;
     C1->right=q;q->left=C1;
     C2->right=p;p->left=C2;
}
int main()
{
    dnode *L1,*L2,*p,*q;
    int size1,size2;
    int d,ch,k;
    cout<<"Enter the size1:";
    cin>>size1;
    
    for(int i=0;i<size1;i++)
    {cout<<"\n Enter data:";cin>>d;
            if(i==0){ p=(dnode*)new dnode;
                      p->data=d;p->left=NULL;p->right=NULL;L1=p;}
             else add(L1,d);
             //print(L1);
    }
    cout<<"Enter the size2:";
    cin>>size2;
    for(int i=0;i<size2;i++)
    {cout<<"\n Enter data:";cin>>d;
            if(i==0){ q=(dnode*)new dnode;
                      q->data=d;q->left=NULL;q->right=NULL;L2=q;}
             else add(L2,d);
             //print(L2);
    }
    fn(L1);fn(L2);
    print(L1,p);print(L2,q);
    merge(L1,L2,p,q);
    print(L1,p);
system("pause");
return(0);
}