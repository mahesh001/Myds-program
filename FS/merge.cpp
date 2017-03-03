#include<iostream>
using namespace std;
struct node
{
       int data;
       node* next;
};
void add(node* &L,int k)
{    
    if(L==NULL)
     {
        L=(node*)new(node);
         //node L=new node;
         L->data=k;
         L->next=NULL;
     }
    else
     {   while(L->next!=NULL) L=L->next;
         L->next=(node*)new(node);
         //node *L->next=new node;
         L->next->data=k;
         L->next->next=NULL;
     }
}
void print(node *L)
{
     while(L!=NULL)
     {
        cout<<L->data<<"  ";
        L=L->next;
     }
     cout<<"\n";
}
node merge(node *L1,node *L2)
{
     node *t;
     t=NULL;
     while(L1!=NULL && L2!=NULL)
     {
      if(L1–>data < L2->data)
      {
       t–>data=L1–>data;
       L1=L1–>next;
      }
      else
      {
       if(L1–>data > L2->data)
      {
      t–>data=L2–>data;
       L2=L2–>next;
      }
      else
      
      if(L1–>data == L2->data)
      {
      t->data =L2->data ;
      L1=L1–>next ;
      L2=L2–>next;
      }
     }
    }
    return(t);
}
int main()
{
node *L1,*L2,*p,*q,*z;
    L1=NULL;L2=NULL;
    add(L1,15);
        p=L1;      print(p);
    add(L1,20);print(p);
    add(L1,25);print(p);
    add(L2,35);
          q=L2;     print(q);
    add(L2,50);print(q);
    add(L2,100);print(q);
z=merge(L1,L2);
print(z);
system("pause");
return(0);
}
