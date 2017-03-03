#include <iostream>
#include <fstream>
using namespace std;
int g[20][20];
int df[20][20];
int n,a[20],b[20];

void create(int x,int y,int z)
{
    if(z>0)
        g[x][y]=z;
    else
    {
        g[x][y]=g[y][x]=1;
    }
}

void print(int k[20][20])
{
    cout<<endl<<endl<<"   ";
    for(int i=1;i<=n;i++)
        cout<<i<<" ";
    cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    {
        if(i>9)cout<<i<<" ";
        else cout<<i<<"  ";
        for(int j=1;j<=n;j++)
        {
            if(j<10)cout<<k[i][j]<<" ";
            else cout<<k[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void init()
{
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<20;j++)
            {g[i][j]=0;df[i][j]=0;}
        a[i]=0;b[i]=0;
    }

}
int nextcon(int x,int o)
{if(x>n/2){
    for(int i=(x%n)+1;i!=x;i=(i%n)+1)
        if(g[x][i]>=1)
            if(a[i]==0 && i!=o)
                {return i;}
    return 0;}
    else{
        for(int i=x-1;i!=x;i--){
        if(i==0)i+=n;
        if(g[x][i]>=1)
            if(a[i]==0 && i!=o)
                {return i;}}
    return 0;
    }
}
int nextcon(int x,int y,int z)
{
    for(int i=1;i<=n;i++)
        if(g[x][i]>=1)
            if(a[i]==0)
                {a[i]=1;return i;}
    return 0;
}
int nextcon(int x)
{
    for(int i=1;i<=n;i++)
        if(g[x][i]>=1)
            if(a[i]==0)
                {return i;}
    return 0;
}

struct node//for printing the path, stack....CHECK
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


int DFT(int x,int l,int count,int o)
{

    a[x]=1;
    cout<<"\ncalled for "<<x;
    int c=0;

    if(g[l][x]>=1 && count>2){s.push(x);cout<<"here";return -1;}
    while(true)
    {
        int z=nextcon(x,o);
        o=z;
        cout<<"\nand the z is "<<z;
        if(z==0)break;
        else{
            c++;
            s.push(x);
            cout<<"\npushed "<<x;
            int y=DFT(z,l,count+1,o);
            cout<<"\nprocess returned y "<<y;
            if(y==-1)return -1;
            if(!y)
            {
                a[z]=0;c--;
                int k=s.pop();
                cout<<"\npopped "<<k;
            }
        }
    }
    return c;
}

void pstack(node *&L)
{
    if(s.isempty()){L=NULL;return;}
    int k=s.pop();
    L=new node;
    L->data=k;
    L->next=NULL;
    pstack(L->next);


}
void eraser(node *L)
{
    if(L->next==NULL)return;
    cout<<"erasing "<<L->data<<" "<<L->next->data;
    g[L->data][L->next->data]=g[L->next->data][L->data]=0;
    eraser(L->next);
}
void circuit(int x,int count,int y)
{
    int o=0;
    a[x]=1;
    int z=nextcon(x,o);
    if(count>2 && g[y][z]){cout<<z<<"break";return;}
    if(z==0)return;

    cout<<z<< " ";
    circuit(z,count+1,y);

}

void dft(int x)
{
    a[x]=1;
    while(true)
    {
        int z=nextcon(x,0);
        if(z==0)return;
        df[x][z]=df[z][x]=1;
        //cout<<"("<<char(64+x)<<" "<<char(64+z)<<") ";
        cout<<"("<<x<<" "<<z<<") ";
        dft(z);
    }
    cout<<endl;
}
int nonzerovertex(node* L)
{
    if(L==NULL)return 0;
    int c=0,z=nextcon(L->data);
    if(z==0)nonzerovertex(L->next);
    else return L->data;

}

int eulerckt(int aa,node *P)
{
    int o;cin>>o;
    int z=1;int k=0;
    while(z!=0)
    {
        for(int u=1;u<=n;u++)a[u]=b[u]=0;
        DFT(aa,aa,1,0);
        node *L=new node;

        L->data=aa;
        pstack(L->next);
        node *J=L;
        while(J!=NULL)
        {
            cout<<J->data<<" ";
            J=J->next;
        }
        if(k==0){cout<<"yea\n";P=L;}
        else
        {
            cout<<"yea in else\n";
            node *C=P,*D=L,*X;
            while(C->data!=D->data)
                C=C->next;
            node *H=C->next;
            C->next=D->next;
            while(D->next!=NULL)
                D=D->next;
            D->next=H;
        }
        node *M=P;
        cout<<"yea\n";
        while(M!=NULL)
            {cout<<M->data<<" ";M=M->next;}

        eraser(L);for(int u=1;u<=n;u++)a[u]=b[u]=0;
        z=nonzerovertex(P);
        cout<<z;
        cin>>aa;
        aa=z;

        k++;
    }
}
int main()
{
    fstream fin;
    n=0;
    fin.open("a.txt");
    int x,y;
    init();
    fin>>x;
    while(x!=-1)
    {
        cout<<x<<" ";
        if(x>n)n=x;
        fin>>y;
        if(y>n)n=y;
        create(x,y,0);
        fin>>x;
        cout<<"yo";
    }

    cout<<endl;

    dft(1);cout<<endl;cout<<endl; print(df);cout<<endl;cout<<endl;
    cout<<endl;cout<<endl; print(g);cout<<endl;cout<<endl;
    for(int u=1;u<=n;u++)a[u]=b[u]=0;
    cout<<"enter the point to start\n";
    int zz;cin>>zz;


    node *L=new node;
    eulerckt(zz,L);
    return 0;
}
