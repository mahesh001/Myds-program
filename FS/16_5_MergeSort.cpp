# include <iostream>

const int max=5;

struct node
          {
            int n;
            node* next;
            node(int k)
            {
                     n=k;
                     next=NULL;
            }
          };

typedef node* PTR;
PTR findend(PTR t)
{
    if(t==NULL);
    else
    for(;t->next!=NULL;t=t->next);
    return t;
}
void addend(PTR &t, int n)
{
     if(t==NULL)
     t=new node(n);
     else
     addend(t->next,n);
}
void prn(PTR t)
{
     for(;t!=NULL;t=t->next)
     cout<<t->n<<" ";
}
void mergesort(PTR a, PTR b, PTR &c)
{
     while(a!=NULL && b!=NULL)
     if(a->n<b->n)
     {
                  addend(c,a->n);
                  a=a->next;
     }
     else
     {
         addend(c,b->n);
         b=b->next;
     }
     if(a!=NULL)
     findend(c)->next=a;
     else if(b!=NULL)
     findend(c)->next=b;
}
int main()
{
    PTR s1=NULL, s2=NULL, m=NULL;
    int i,n=0;
    cout<<"Enter first sorted list:";
    while(n<max)
    {
            cin>>i;
            addend(s1,i);
            n++;
    }
    cout<<"Enter second sorted list:";
    n=0;
    while(n<max)
    {
            cin>>i;
            addend(s2,i);
            n++;
    }
    mergesort(s1,s2,m);
    prn(m);
    cin.get();
    cin.get();
}
