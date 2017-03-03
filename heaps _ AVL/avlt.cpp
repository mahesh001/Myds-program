#include <iostream>
using namespace std;
 struct Node
      {
             int data;
             bool empty;
             Node *right,*lchild;
             int height;
      }*Root=NULL;
      
     
              void insert(int n, Node* &t)
              {
                   if(t==NULL)
                   {
                              t=new Node;
                              t->data=n;
                              t->lchild=NULL;
                              t->rchild=NULL;
                              t->empty=false;
                   }
                   else if(n<t->data)
                   {
                        insert(n,t->lchild);
                        if((height(t->lchild) - height(t->rchild)) >= 2)
                        {
                               if(n<t->lchild->data)
							   rotate_left(t);
                               else dblrotate_left(t);
                        }
                   }
                   else if(n>t->data)
                   {
                        insert(n,t->rchild);
                        if((height(t->lchild) - height(t->rchild)) >= 2)
                        {
                               if(n>t->rchild->data)
							   rotate_right(t);
                               else dblrotate_right(t);
                        }
                   }
                   else cout<<"\n\nError: Duplicate entry";
              }
    void rotate_left(Node* &t)
              {
                   Node *m=t->lchild;
                   t->lchild=m->rchild;
                   m->rchild=t;
                   t=m;
              }
    void rotate_right(Node* &t)
              {
                   Node *m=t->rchild;
                   t->rchild=m->lchild;
                   m->lchild=t;
                   t=m;
              }
   void dblrotate_left(Node* &t)
              {
                   rotate_right(t->lchild);
                   rotate_left(t);
              }
  void dblrotate_right(Node* &t)
              {
                   rotate_left(t->rchild);
                   rotate_right(t);
              }
              
             
 void print()
              {
                   cout<<"\n\n";
                   cout<<"PreOrder: ";preorder(Root);
                   cout<<"\nInOrder: ";inorder(Root);
                   cout<<"\nPostOrder: ";postorder(Root);
              }
              
  void preorder(Node *t)
              {
                   if(t!=NULL)
                   {
                              cout<<t->data<<", ";
                              preorder(t->lchild);
                              preorder(t->rchild);
                   }
              }
  void inorder(Node *t)
              {
                   if(t!=NULL)
                   {                              
                              inorder(t->lchild);
                              cout<<t->data<<", ";
                              inorder(t->rchild);
                   }
              }
  void postorder(Node *t)
              {
                   if(t!=NULL)
                   {    
                              postorder(t->lchild);
                              postorder(t->rchild);
                              cout<<t->data<<", ";
                   }
              }
              
  void search(int n)
              {
                   search( n,Root);
              }
  void search(int n,Node *t)
              {
                   if(t==NULL)cout<<"\n\nUnable to find!!";
                   else if(n<t->data)search(n,t->lchild);
                   else if(n>t->data)search(n,t->rchild);
                   else cout<<"\n\nNumber Found!";
              }
   void remove(int n)
              {
                   remove( n,Root);
              }
 void remove(int n,Node* &t)
              {
                   if(t==NULL)cout<<"\n\nUnable to find!!";
                   else if(n<t->data)remove(n,t->lchild);
                   else if(n>t->data)remove(n,t->rchild);
                   else if(t->rchild!=NULL && t->lchild!=NULL)
                   {
                        t->data=FindMin(t->rchild);
                        remove(t->data,t->rchild);
                   }
                   else
                   {
                       Node *temp=t;
                       t=(t->lchild!=NULL) ? t->lchild : t->rchild ;
                       delete temp;
                   }
              }
              
int FindMin(Node* t)
              {
                  if(t->lchild==NULL)
				  return t->data;
                  return FindMin(t->lchild);
              }
              
 int FindMax(Node* t)
              {
                  if(t->rchild==NULL)
				  return t->data;
                  return FindMin(t->rchild);
              }
  int height(Node* t)
              {
                  if(t==NULL)return 0;
                  else
                  {
                      int a=height(t->lchild);
                      int b=height(t->rchild);
                      return (1+((a,b)?a:b));
                  }
              }
              
              void stats()
              {
                   cout<<"\n\nHeight: "<<height(Root);
                   cout<<"\nMin: "<<FindMin(Root);
                   cout<<"\nMax: "<<FindMax(Root);
              }
                   
};


int  main( )
{	

    int n,o;
    
    do
    {
        cout<<"\n\n1.Insert\n2.Search\n3.Delete\n4.Display\n0.Exit";
        cout<<"\n\nEnter Command: ";
        cin>>o;
        
        switch(o)
        {
                 case 1: cout<<"\n\nEnter a number: ";
                         cin>>n;
                         insert(n);
                         print();
                         break; 
                 case 2: cout<<"\n\nEnter number to search: ";
                         cin>>n;
                        search(n);
                         print();
                         break;                
                 case 3: cout<<"\n\nEnter number to delete: ";
                         cin>>n;
                         remove(n);       
                         print();
                         break;
                 case 4: print();
                         stats();
                         break;
                 case 0: break;
                 default: cout<<"\n\nIncorrect Command!";
        };
    }while(o!=0);
	cout<<"\n\n";

	return 0;
}

              
