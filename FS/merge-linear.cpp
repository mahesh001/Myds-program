#include<iostream>
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
void print(dnode *L)
{
     while(L!=NULL)
     {
        cout<<L->data<<"  ";
        L=L->right;
     }
     cout<<"\n";
}
void merge(dnode *L1,dnode *L2)
{
     while(L1->right!=NULL) 
     L1=L1->right;
     L1->right=L2;
     L2->left=L1;
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
             print(L1);
    }
    cout<<"Enter the size2:";
    cin>>size2;
    for(int i=0;i<size2;i++)
    {cout<<"\n Enter data:";cin>>d;
            if(i==0){ q=(dnode*)new dnode;
                      q->data=d;q->left=NULL;q->right=NULL;L2=q;}
             else add(L2,d);
             print(L2);
    }
    merge(L1,L2);
    L1=p;
    print(L1);
    system("pause");
    return(0);
}