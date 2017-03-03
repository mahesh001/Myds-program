#include <iostream>
using namespace std;
      struct avltnode
      {
             int data;
             bool empty;
             avltnode *right,*left;
      }*Root;
void insert( int n,avltnode*T)
              {
                   if(T==NULL)
                   {
                              T=new avltnode;
                              T->data=n;
                              T->left=NULL;
                              T->right=NULL;
                              T->empty=false;
                   }
                   else if(n<T->data)
                   {
                        insert(n,T->left);
                        if((height(T->left) - height(T->right)) >= 2)
                        {
                               if(n<T->left->data)rotate_left(T);
                               else dblrotate_left(T);
                        }
                   }
                   else if(n>T->data)
                   {
                        insert(n,T->right);
                        if((height(T->left) - height(T->right)) >= 2)
                        {
                               if(n>T->right->data)rotate_right(T);
                               else dblrotate_right(T);
                        }
