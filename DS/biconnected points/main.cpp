#include <iostream>
#include <fstream>

using namespace std;
int zz=0,count=1,n=0,g[20][20],d[20][20],a[20],b[20],c[20],e[20],k[20];


void init()
{
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<20;j++)
            {g[i][j]=0;d[i][j]=0;}
        a[i]=0;b[i]=0;c[i]=0;e[i]=0;k[20]=0;
    }
}

void create(int x,int y,int z)
{
    if(z>0)
        g[x][y]=z;
    else
    {
        g[x][y]=g[y][x]=1;
    }
}

int nextcon(int x,int y)
{
    if(y==1)
    {
        for(int i=1;i<=n;i++)
        if(g[x][i]>=1)
            if(a[i]==0)
                {return i;}
    return 0;
    }
    if(y==3)
    {
        for(int i=1;i<=n;i++)
        if(d[x][i]>=1)
            if(e[i]==0)
                {return i;}
    return 0;
    }
    if(y==4)
    {
        for(int i=1;i<=n;i++)
        if(d[x][i]>=1)
            if(k[i]==0)
                {return i;}
    return 0;
    }
    for(int i=1;i<=n;i++)
        if(d[x][i]>=1)
            if(a[i]==0)
                {return i;}
    return 0;
}


void dft(int y)
{
    while(true)
    {
        int x=nextcon(y,1);
        if(x==0)break;
        cout<<"\n processing :"<<y<<" "<<x;
        d[y][x]=1;
        a[x]=1;a[y]=1;
        b[x]=++count;
        dft(x);
    }
}


void front(int x,int y)//to find the previous vertex
{
    if(x==1)zz=999;
    while(true)
    {
        int c=nextcon(y,4);
        if(c==x){zz=y;}
        if(c==0)break;
        k[c]=1;
        front(x,c);
    }
}

int bedge(int x)
{
    int b=x,c,aa=nextcon(x,2);
    if(aa==0)aa=999;
    for(int i=0;i<20;i++)k[i]=0;
    front(b,1);
    b=zz;
    for(int i=0;i<20;i++)
    {
        if(g[x][i]>0 && i!=aa && i!=b)
        {
            return i;
        }
    }
    return 999;
}

void low(int v)
{
    cout<<"\nlow is called for "<<v;
    for(int i=0;i<20;i++)e[i]=0;
    int x=b[v];
    int y=999;
    while(true)
    {
        int z=nextcon(v,3);
        if(z==0)break;
        e[z]=1;cout<<"YO";
        if(c[z]<y)y=c[z];
    }
    cout<<"\ncount and next ones count is: "<<x<<" "<<y;
    x=min(x,y);
    y=bedge(v);
    cout<<"\nbedge is "<<y;
    x=min(x,y);
    c[v]=x;
    cout<<"min for v "<<v<<" is "<<x<<endl;
}

void setnos(int v)
{
    a[v]=1;
    cout<<"called for "<<v;
    if(v==0)return;
    while(true){
    int x=nextcon(v,2);
    if(x==0)break;
    a[x]=1;
    setnos(x);
    }
    low(v);
}
void artpts(int aa)
{
    if(aa==0)return;
    int k=9999;
    while(true)
    {
        int y=nextcon(aa,2);
        if(y==0)break;
        a[y]=1;
        if(c[y]<k)k=c[y];
        if(c[y]>k && k!=9999) k=c[y];
    }


    if(b[aa]<=k && k!=9999 && b[aa]!=1)cout<<"\narticulation point found :"<<aa;
    artpts(nextcon(aa,4));
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
    }
    b[1]=1;
    dft(1);
    for(int i=0;i<20;i++)a[i]=0;

    setnos(1);
    for(int i=0;i<20;i++){k[i]=0;a[i]=0;}


artpts(1);
    return 0;
}
