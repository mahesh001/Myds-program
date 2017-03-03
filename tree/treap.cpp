#include<iostream>
#include<cmath>
using namespace std;
struct treapnode
{
	treapnode*lchild;
	treapnode*rchild;
	int key;
	int size;
	int priority;
};
void swap(int* a, int* b)
 { int t = *a;
  *a = *b; 
   *b = t; 
   }
 void max(int&a,int &b)
 {
  return	max(a,b);
 }
void createHeap(int key, int size)
 {   int i;
    treapnode*T = new treapnode;
    T->size = size;   
    T->key = key;
    for (i = (T->size - 2) / 2; i >= 0; --i)
       max(T, i);
       return T;
  }
void check(int* key, int size)
{ 
     treapnode* T ;
   T=createHeap(ar, size);
    while (T->size > 1)
    {
        swap(&T->ar[0], &T->ar[T->size - 1]);
        --T->size;  
    }
}void singlerotatelc(treapnode*&T)
{
	treapnode*k1=T->lchild;
	T->lchild=k1->rchild;
	k1->rchild=T;

	T=k1;
}
void singlerotaterc(treapnode*&T)
{
	treapnode*k1=T->lchild;
		T->lchild=k1->rchild;
	k1->rchild=T;

	T=k1;

void insert(int k,char ch, treapnode* &T)
              {
                   if(T==NULL)
                   {
                              T=new treapnode;
                              T->element=k;
                              T->element=ch;
                              T->lchild=NULL;
                              T->rchild=NULL;
                   }
                   else if(k<T->element)
                   {
                        insert(k,ch,T->lchild);
                        {
                               if(k<T->lchild->element)
							   singlerotatelc(T);
                             
                        }
                   }
                   else if(k>T->element)
                   {
                                insert(k,ch,T->rchild);
                               if(k>T->rchild->element)
							   singlerotaterc(T);
                               
                        
                   }
           }
