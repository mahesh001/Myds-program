#include <iostream>
#include <fstream>
#include <cstring>
char x[10][2][10];
using namespace std;
void swapit(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
}
int minimum(int x[],int m)
{
    int c=10000,d=0,g=0;
    for(int i=0;i<m;i++)
    {
        if(x[i]==-1)g++;
        if(x[i]<c && x[i]!=-1){c=x[i];d=i;}
    }
    if(g==m)return -1;
    return d;
}
void sortit(int a[],int i)
{
    int k;
    for(k=0;k<i;k++)
        for(int j=k+1;j<i;j++)
            if(a[k]>a[j])swapit(a[k],a[j]);
}
int check(int m,int checker)
{
    ifstream fi[10];
    ofstream fout[10];
    int c[10],k;
    for(int i=0;i<m;i++)
    {
        fi[i].open(x[i][checker]);
        c[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        while(!fi[i].eof())
        {
            fi[i]>>k;
            cout<<k<<" ";
            if(k==-1)c[i]++;
        }
        fi[i].close();
        cout<<endl;
    }
    k=0;
    for(int i=0;i<m;i++)
    {
        if(c[i]>0)c[i]--;
        if(c[i]>k)k=c[i];
    }
    for(int i=0;i<m;i++)
    {
        fout[i].open(x[i][0],ios::app);
        for(int j=0;j<k-c[i];j++)
        {
            fout[i]<<"-1 ";
        }
        fout[i].close();
    }
    return k;
}

void tempsort(int &m,int l,int &checker)
{
    ofstream fout;
    ifstream fi[10];
    int out=0,c[10];
    for(int i=0;i<m;i++)
    {
        fi[i].open(x[i][checker]);
        c[i]=0;
    }
    int a[10];

    int y;
    for(int j=0;j<l;j++)
    {
        for(int i=0;i<m;i++) {fi[i]>>a[i];}
        int h=(checker)?0:1;
        fout.open(x[j][h]);
        while(true)
        {
            y=minimum(a,m);
            if(y==-1)break;
            fout<<a[y]<<" ";
            fi[y]>>a[y];
        }
        fout<<"-1 ";
        fout.close();
    }
    m=l;
    checker=(checker)?0:1;
    for(int i=0;i<m;i++)
    {
        fi[i].close();
    }
    check(m,checker);
}

int main()
{
    ifstream fin,fi[10];
    fin.open("data.txt");
    strcpy(x[0][0],"a1.txt");
    strcpy(x[1][0],"b1.txt");
    strcpy(x[2][0],"c1.txt");
    strcpy(x[3][0],"d1.txt");
    strcpy(x[4][0],"e1.txt");
    strcpy(x[5][0],"f1.txt");
    strcpy(x[6][0],"g1.txt");
    strcpy(x[7][0],"h1.txt");
    strcpy(x[8][0],"i1.txt");
    strcpy(x[9][0],"j1.txt");
    strcpy(x[0][1],"a2.txt");
    strcpy(x[1][1],"b2.txt");
    strcpy(x[2][1],"c2.txt");
    strcpy(x[3][1],"d2.txt");
    strcpy(x[4][1],"e2.txt");
    strcpy(x[5][1],"f2.txt");
    strcpy(x[6][1],"g2.txt");
    strcpy(x[7][1],"h2.txt");
    strcpy(x[8][1],"i2.txt");
    strcpy(x[9][1],"j2.txt");
    cout<<"enter the value of m less than or 10\n";
    int m,checker=0;cin>>
    m;
    ofstream fout[10];
    for(int i=0;i<m;i++)
    {
        fout[i].open(x[i][0]);
    }
    int i=0,c=0,j=0,a[10];
    while(!fin.eof())
    {
        c++;
        fin>>a[j];
        j++;
        if(j==3)
        {
            sortit(a,j);
            j=0;
            fout[i]<<a[0]<<" "<<a[1]<<" "<<a[2]<<" -1 ";
            i=(i+1)%m;
        }
    }
    if(j!=0)
    {
        sortit(a,j);
        if(i==0)
            for(int k=0;k<j;k++)fout[i]<<a[k]<<" ";
        fout[i]<<"-1 ";
        i=(i+1)%m;
    }
    for(int h=0;h<m;h++)
        fout[h].close();
    int t=check(m,0);
    while(t>0)
    {int p;cin>>p;
        tempsort(m,t--,checker);
    }
    cout<<endl<<checker;

    return 0;
}
