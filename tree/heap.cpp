#include <iostream>
using namespace std;

struct hnode{
    int data;
    hnode *lchild;
     hnode *rchild;
}*root=NULL;
void swap(int* a, int* b)
 { int t = *a;
  *a = *b; 
   *b = t; 
   }
void checkheap(hnode *&T)
{
	if(T==NULL)
	{
		T->lchild=NULL;
	    T->rchild=NULL;
	    
	}
else if(T->lchild>=T->data && T->rchild>=T->data)
{
checkheap(T->lchild);
checkheap(T->rchild);
}
else 
cout<<"invalid \n";
	
}
void creatheap(hnode*T,int k)
{

if(T == NULL)
{
      
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else{
        if( T->data > k)
           {
            creatheap( T->lchild,k);
            checkheap(T);
        }
        else
            creatheap( T->rchild,k);
            checkheap(T);
    }
}

void heapify(int h[],int i)
{
	int j=min(h[2*i],h[2*i+1],i);
	if(h[i]<h[j/2])
	swap(h[i],h[j/2]);
}
void printArray(int* ar, int size)
{
    int i;
    for (i = 0; i < size; ++i)
       cout<< ar[i];
}
int main()
{
    int key;
     cout<<"enter key element \n";
     cin>>key;
  creatheap(root,key)
    return 0;
}
