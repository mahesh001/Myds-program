/* TODO (#1#): check why preorder is diff while inorder is correct */
#include<iostream>
#include<cmath>
using namespace std;
struct  bstnode
{
        bstnode* lchild;
        int data;
        bstnode* rchild;
};
int height(bstnode *t)
{
    if(t==NULL)
    {
               return -1;
    }
    else 
    {
         return (1+max(height(t->lchild),height(t->rchild)));
    }
}
bstnode* ll(bstnode *u)
{
      bstnode* k=u->lchild;
      u->lchild=k->rchild;
      k->rchild=u;
      u=k;
return(u);
}
bstnode* rr(bstnode* u)
{
     bstnode* k=u->rchild;
     u->rchild=k->lchild;
     k->lchild=u;
     u==k;
}        
bstnode* lr(bstnode *u)
{
     rr(u->lchild);
     ll(u);
return(u);
}
bstnode* rl(bstnode *u)
{
     ll(u->rchild);
     rr(u);
return(u);
}          
bstnode* insert(bstnode *t,int k)
{  
     if(t==NULL)
     {
                t=(bstnode*)new(bstnode);
                t->data=k;
                t->lchild=NULL;
                t->rchild=NULL;
     }
     else if(k<t->data)
     {
          t->lchild=insert(t->lchild,k);
          if(abs(height(t->lchild)-height(t->rchild))>1)
          {  
             if(k<(t->lchild->data))
                { cout<<" a \n";t=ll(t);}
             else
             { cout<<" b \n";t=lr(t);}
          }
     }    
     else if(k>t->data)
     {    t->rchild=insert(t->rchild,k);
           if(abs(height(t->rchild)-height(t->lchild))>1)
          {
            if(k>(t->rchild->data))
            t=rr(t);
            else
            t=rl(t);
          }
     }
return(t);
}     
void displayLRD(bstnode* t)
{
     if(t!=NULL)
     {
      displayLRD(t->lchild);
      cout<<t->data<<"  ";
      displayLRD(t->rchild);
     }       
}
void displayDLR(bstnode* t)
{
     if(t!=NULL)
     {
      cout<<t->data<<"  ";
      displayLRD(t->lchild);
      displayLRD(t->rchild);
     }       
}
int height2(bstnode *t)
{
    if(t==NULL)
    {
               return -1;
    }
    else 
    {
         int a=height2(t->lchild),b=height2(t->rchild);
         if(abs(a-b)>1) cout<<"\n unbalanced at node "<<t->data;
         else cout<<"\n good "<<t->data;
         return (1+max(a,b));
    }
}
int main()
{
    bstnode *l=NULL;
    int k;
    while(1)
  { int ch;
          cout<<"\n 1.Enter 2.Display Preorder 3.Display inorder 4.Check height 0.Exit ";
          cin>>ch;
          switch(ch)
          {
                    case 1:
                         cout<<"\n Enter  data ";
                         cin>>k;
                         l=insert(l,k);
                         break;
                     case 2:cout<<"\n";displayDLR(l);break;
                     case 3:cout<<"\n";displayLRD(l);break;
                     case 4:height2(l);break;
                     case 0:exit(0);break;
                     default:cout<<"\n Invalid Input.Try again";
          }
   }
   
   return(0);
}
