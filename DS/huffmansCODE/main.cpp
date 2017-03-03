#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
int xx[257];

/*void getfile(char a[],int a

             [])
{
    int n=0;int i=0;

}*/
struct btree
{
    int freq;
    char z;
    btree *lchild,*rchild;
};

void coder(btree *T,string x)
{
    if(T==NULL)return;
    if(T->z!='|')
        cout<<"\nThe code for "<<T->z<<" is :"<<x;
    coder(T->lchild,x+"0");
    coder(T->rchild,x+"1");
}
void inorder(btree *T)
{
    if(T==NULL)return;cout<<T->z<<" "<<T->freq<<endl;
    inorder(T->lchild);
    inorder(T->rchild);
}
void increment(char a)
{

}
int main()
{
    for(int i=0;i<258;i++)xx[i]=0;
    ifstream fin;fin.open("data.txt");
    char zzzz[100];
    int j=-1;
    while(!fin.eof())
    {
        fin.getline(zzzz,50);
        for(int i=0;i<strlen(zzzz);i++)
        {
            char a=zzzz[i];
            cout<<a;
            xx[int(a)]++;
        }
    }

    cout<<endl<<endl;
    for(int i=0;i<258;i++)
        if(xx[i]>0)
        cout<<(char)i<<" "<<xx[i]<<"\n";

   char vv;
    int i;
    btree *t[20],*p;
    int jj=0;
    for(i=0;i<258;i++)
    {
        if(xx[i]<1)continue;
        t[jj]=new btree;
        vv=(char)i;
        cout<<vv;
        t[jj]->z=vv;t[jj]->freq=xx[i];
        t[jj]->lchild=NULL;
        t[jj]->rchild=NULL;
        jj++;
    }
    int n=jj,c;

    int q=n,b1=0,b2=0;
    btree *f1=new btree,*f2;
    for(i=0;i<n-1;i++)
    {
        int p1=9999,p2=9999;
        for(int k1=0;k1<n;k1++)
            if(t[k1]!=NULL)
                if(t[k1]->freq<p1)
                {
                    p1=t[k1]->freq;
                    b1=k1;
                }

        for(int k1=0;k1<n;k1++)
            if(t[k1]!=NULL)
                if(t[k1]->freq<p2 && t[k1]->freq!=p1)
                {
                    p2=t[k1]->freq;
                    b2=k1;
                }
        cout<<p2<<" "<<p1<<" "<<b2<<" "<<b1<<endl;
        f1=t[b1];
        t[b1]=NULL;
        t[b1]=new btree;
        t[b1]->freq=p2+p1;
        t[b1]->z='|';
        t[b1]->lchild=t[b2];
        t[b1]->rchild=f1;
        t[b2]=NULL;
    }
    coder(f1,"0");
    return 0;
}
