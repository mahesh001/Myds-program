#include <iostream>

using namespace std;

int g[20][20];
int n,a[20],b[20],maxcount=0;


struct node
{
    int data;
    node* next;

};

class stack
{
public:
    node *top;
    node *T;
    int pop();
    void push(int);
    int isempty();
    stack()
    {
        top=NULL;
    }
}s;

int stack::isempty()
{
    if(top==NULL)return 1;
    return 0;
}

int stack::pop()
{
    if(isempty()) {cout<<"empty stack\n";return 0;}
    int x=top->data;
    top=top->next;
    return x;
}



void stack::push(int f1)
{
    T=new node;
    T->data=f1;
    T->next=top;
    top=T;
}

void create(int x,int y,int z)
{

        g[x][y]=z;
        maxcount+=z;
}

void init()
{
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<20;j++)
            {g[i][j]=0;}
        a[i]=0;b[i]=0;
    }

}
int nextcon(int x,int y)
{
    for(int i=y;i<=n;i++)
        if(g[x][i]>=1)
            if(a[i]==0)
                {return i;}
    return 0;
}
int BF(int u,int v,int distance)
{
    s.push(u);cout<<"\npushed "<<u;
    if(distance>maxcount)return distance;
    cout<<"\ncalled for "<<u;
    int o=1,i=0,c[10];
    for(int j=0;j<10;j++)c[j]=999;
    if(u==v)return distance;
    while(true)
    {
        int z=nextcon(u,o);
        o=z+1;
        if(z==0)break;
        int y=g[u][z];
        cout<<"\nz and distance are "<<z<<" "<<distance;
        c[i]=BF(z,v,distance+y);
        cout<<"\nreceived distance was "<<c[i];
        int l=999,ll;
        for(int j=0;j<10;j++)
        {
            cout<<" "<<c[j];
            if(c[j]<l)l=c[j];
            ll=j;
        }
        cout<<"\nleast is "<<l;
        if(c[i]!=l){int q=s.pop();cout<<"\npopped "<<q;}
        i++;

    }int k=999;
    for(int j=0;j<i;j++)
    {
        if(k>c[j])k=c[j];
    }
    cout<<"k is "<<k;
    return k;
}

#include <fstream>

int main()
{
    fstream fin;
    n=0;
    fin.open("data.txt");
    int x,y,z;
    init();
    fin>>x;
    while(x!=-1)
    {
        cout<<x<<" ";
        if(x>n)n=x;
        fin>>y>>z;
        if(y>n)n=y;
        create(x,y,z);
        fin>>x;
    }

    cout<<"\nenter starting and terminating position ";
    int u,v;
    cin>>u>>v;
    a[u]=1;
    cout<<endl<<BF(u,v,0)<<" is the least cost";
    while(!s.isempty())
    {
        int o=s.pop();
        cout<<o<<" ";
    }
    return 0;
}
