#include <iostream>
#include <fstream>
using namespace std;
int g[20][20];
int h[20][20];
int n,a[20],b[20];
int m[11][3];
void create(int x,int y,int z)
{

        g[x][y]=g[y][x]=z;

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
int nextcon(int x)
{
    for(int i=1;i<=n;i++)
        if(g[x][i]>=1)
            if(a[i]==0)
                {a[i]=1;return i;}
    return 0;
}
void init()
{
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<20;j++)
            {g[i][j]=0;h[i][j]=0;}
        a[i]=0;b[i]=0;
    }

}
void init(int a)
{
    if(a)
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<=2;j++)
            m[i][j]=999;
    }
    else
    for(int i=1;i<10;i++)
        b[i]=0;
}
int checker(int&,int);
int prims(int x)
{
    for(int i=1;i<=n;i++)
    {
     int cou=0;
     init(1);
     for(int j=1;j<=n;j++)
     {
         if(a[j]==1)
         {
             cout<<"\ntrue for "<<j;
             int k=j;
             int l=checker(k,0);
             if(l==1000)
                continue;
             m[cou][0]=l;
             m[cou][1]=j;
             m[cou][2]=k;
             cou++;
         }
     }
     int d=1000,e;
     cout<<endl;
     for(int i=0;i<10;i++)
        {
        for(int j=0;j<=2;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
        }
     for(int i=0;i<cou;i++)
     {
         if(m[i][0]<d)
         {
             d=m[i][0];
             e=i;
         }

     }
     cout<<"\ne is"<<e<<" "<<m[e][2]<<" "<<m[e][1]<<" "<<m[e][0];
         h[m[e][1]][m[e][2]]=h[m[e][2]][m[e][1]]=m[e][0];
         a[m[e][1]]=a[m[e][2]]=1;
         cout<<"done";
    }
}

int checker(int &x,int i)
{
    int z=nextcon(x);
    cout<<"\nin checker the z is "<<z<<endl;;
    if(z!=0)
    {
        b[z]=g[x][z];
        checker(x,i+1);
        a[z]=0;
    }
    int l=1000,p;
    if(i==0)
    {
        for(int i=1;i<=n;i++)cout<<b[i]<<" ";
        for(int j=1;j<=n;j++)
            if(b[j]<l && b[j]!=0)
            {
                l=b[j];
                p=j;
            }
            cout<<"\nl and p are "<<l<<" "<<p;
        init(0);
        x=p;
        return l;
    }
}
int main()
{
    fstream fin;
    n=0;
    fin.open("data.txt");
    int x,y,z;
    init();
    init(1);
    init(0);
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
    print(g);
    a[1]=1;
    cout<<"enter the vertex to find MST\n";
    int az;
    cin>>az;
    prims(az);
    print(h);
}
