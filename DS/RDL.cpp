#include<iostream>
#include<stack>
using namespace std;
struct bt
{
   bt *lchild;
   int data;
   bt *rchild;
};
int ch;
bt* insert(bt *b,int k)
{
         
         if(b==NULL) { b=(bt*)new bt;b->data=k;
                        b->lchild=NULL;b->rchild=NULL;cout<<"hjhkshk";}
         else
         {
              if(k>b->data) b->rchild=insert(b->rchild,k);
              else {
                     if(k<b->data) b->lchild=insert(b->lchild,k);
                     else cout<<"Same data cannot be given again \n";
                    }
          }
   return(b);//each fn should return
}
stack<bt*> s;
bt *t;

void print(bt *b)
{
  while(1)
  {
     while(b!=NULL)
     { s.push(b);
       b=b->rchild;
       }
     if(!s.empty())
     { t=s.top();s.pop();
      cout<<t->data<<"  ";
      b=t->lchild;
      }
      else break;
  }
}
int main()
{
    bt *T;
    int ch;
    T=NULL;
    int d;
    while(1)
    { cout<<"\n 1.Enter data 2.Print 3.Exit:";cin>>ch;
      switch(ch)
      {
       case 1:cout<<" \n Enter data"; cin>>d; T=insert(T,d);break;
       case 2:print(T);break;
       case 3:exit(0);break;
       default:cout<<"\n Invalid Input.Try again";
      }
    }
system("pause");
return(0);
}