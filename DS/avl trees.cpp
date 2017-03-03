#include<iostream>
using namespace std;
struct bstnode
{
       bstnode *lchild;
       int data;
       bstnode *rchild;
};
int height(bstnode *t)
{
           if(t==NULL)
           return (-1);
           else
           return (max(height(t->lchild),height(t->rchild))+1);
           }
           int max(int a,int b)
           {
               if(a>b)
               return a;
               else
               return b;
               }
               void sleft(bstnode* &k2)
               {
                    bstnode* k1=k2->lchild;
                    k2->lchild=k1->rchild;
                    k1->rchild=k2;
                    k2=k1;
                    }
                    void sright(bstnode* &k2)
                    {
                         bstnode* k1=k2->rchild;
                         k2->rchild=k1->lchild;
                         k1->lchild=k2;
                         k2=k1;
                         }
                         void dleft(bstnode* &k3)
                         {
                              sright(k3->lchild);
                              sleft(k3);
                              }
                              void dright(bstnode* &k3)
                              {
                                   sleft(k3->rchild);
                                   sright(k3);
                                   }
                                   void insert(bstnode* &t,int k)
                                   {
                                        if(t==NULL)
                                        {
                                        t=(bstnode*)new (bstnode);
                                        t->data=k;
                                        t->lchild=NULL;
                                        t->rchild=NULL;
                                        }
                                        else if(k<t->data)
                                        {
                                             insert(t->lchild,k);
                                             if(height(t->lchild)-height(t->rchild)==2)
                                             {
                                                                                       if(k<t->lchild->data)
                                                                                       sleft(t);
                                                                                       else
                                                                                       dleft(t);
                                                                                       }
                                                                                       }
                                                                                       else if(k>t->data)
                                                                                       {
                                                                                            insert(t->rchild,k);
                                                                                            if(height(t->rchild)-height(t->lchild)==2)
                                                                                            {
                                                                                                                                      if(k>t->rchild->data)
                                                                                                                                      sright(t);
                                                                                                                                      else
                                                                                                                                      dright(t);
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      }
                                                                                                                                      void display(bstnode *t)
                                                                                                                                      {
                                                                                                                                           if(t!=NULL)
                                                                                                                                           {
                                                                                                                                                      display(t->lchild);
                                                                                                                                                      cout<<t->data;
                                                                                                                                                      display(t->rchild);
                                                                                                                                                      }
                                                                                                                                                      }
                                                                                                                                                      int main()
                                                                                                                                                      {
                                                                                                                                                          bstnode* l=NULL;
                                                                                                                                                          int k;
                                                                                                                                                          for(;;)
                                                                                                                                                          {
                                                                                                                                                                 char op;
                                                                                                                                                                 cout<<"1.enter\n";
                                                                                                                                                                 cout<<"2.display\n";
                                                                                                                                                                 cout<<"3.exit\n";
                                                                                                                                                                 cin>>op;
                                                                                                                                                                 switch(op)
                                                                                                                                                                 {
                                                                                                                                                                           case '1':
                                                                                                                                                                                {
                                                                                                                                                                                    cout<<"enter value\n";
                                                                                                                                                                                    cin>>k;
                                                                                                                                                                                    insert(l,k);
                                                                                                                                                                                    }
                                                                                                                                                                                    break;
                                                                                                                                                                                    case '2':
                                                                                                                                                                                         display(l);
                                                                                                                                                                                         break;
                                                                                                                                                                                         case '0':
                                                                                                                                                                                              exit(0);
                                                                                                                                                                                              break;
                                                                                                                                                                                         
                                                                                                                                                                                                      
                                                                                                                                                                                                      
                                                                                                                                                                                                      }
                                                                                                                                                                                                      }
                                                                                                                                                                                                      system("pause");
                                                                                                                                                                                                      return 0;
                                                                                                                                                                                                      }
                                                                                                                                                                            
