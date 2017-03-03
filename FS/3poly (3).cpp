#include <iostream>
#include <cstring>
#include<fstream>
using namespace std;

int min(int a,int b,int c, int d)
{
    if(a==-1 && b==-1 && c==-1 && d==-1)return -1;
    if(a==-1)a=9999;if(b==-1)b=9999;if(c==-1)c=9999;if(d==-1)d=9999;
    if(a<=b && a<=c && a<=d)return 0;
    if(b<=a && b<=c && b<=d)return 1;
    if(c<=b && c<=a && c<=d)return 2;
    if(d<=b && d<=c && d<=a)return 3;
}

void copier(ifstream &fin,char a[])
{
    int x[1000],i=0;
    while(!fin.eof())
    {
        fin>>x[i++];
    }
    fin.close();
    ofstream fout;
    fout.open(a);
    for(int j=0;j<i-1;j++)fout<<x[j]<<" ";
}
void editor(int n,ifstream& f1,ifstream& f2,ifstream& f3,char a[],char b[],char c[],char d[])
{
    switch (n)
    {
    case 0:
    copier(f1,b);
    copier(f2,c);
    copier(f3,d);
            break;

    case 1:
    copier(f1,a);
    copier(f2,c);
    copier(f3,d);    break;

    case 2:
            copier(f1,a);
    copier(f2,b);
    copier(f3,d);break;

    case 3:
            copier(f1,a);
    copier(f2,b);
    copier(f3,c);
    break;
    default:break;
    }
}
void opener(ofstream &fout,ifstream &f1,ifstream &f2,ifstream &f3,int n,char a[],char b[],char c[],char d[])
{
    switch (n)
    {
    case 0:
        fout.open(a);
        f1.open(b);f2.open(c);f3.open(d);
        break;

    case 1:
        fout.open(b);
        f1.open(a);f2.open(c);f3.open(d);
        break;

    case 2:
        fout.open(c);
        f1.open(a);f2.open(b);f3.open(d);
        break;

    case 3:
        fout.open(d);
        f1.open(a);f2.open(b);f3.open(c);
        break;
    default:break;
    }
}
void tempsort(int n,int l,char a[],char b[],char c[],char d[])
{
    ofstream fout;
    ifstream fi[3];
    opener(fout,fi[0],fi[1],fi[2],n,a,b,c,d);
    int x[3];

    int y;
    for(int j=0;j<l;j++)
    {
        for(int i=0;i<3;i++) {fi[i]>>x[i];cout<<x[i]<<" ";}
        while(true)
        {
            y=min(x[0],x[1],x[2],-1);cout<<"y is "<<y<<endl;
            if(y==-1)break;
            fout<<x[y]<<" ";
            cout<<x[y]<<" ";
            fi[y]>>x[y];
        }
        fout<<"-1 ";
    }
    editor(n,fi[0],fi[1],fi[2],a,b,c,d);
    fi[0].close();
    fi[1].close();
    fi[2].close();


}
void swapit(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
}
void sortit(int a[],int i)
{
    cout<<"yes";
    int k;
    for(k=0;k<i;k++)
        for(int j=k+1;j<i;j++)
            if(a[k]>a[j])swapit(a[k],a[j]);
}
int main()
{
    ifstream fin;
    ofstream fout;
    fout.open("data2.txt");
    fin.open("data.txt");

    int count[4],ch[4],j=0,cc=0,aa[4],DD=0;

    for(int i=0;i<4;i++)
    {
        count[i]=0;
        ch[i]=0;
    }
    while(!fin.eof())
    {
        DD++;
        fin>>aa[j];
        j++;
        if(j==3)
        {
            cc++;
            sortit(aa,j);
            j=0;
            fout<<aa[0]<<" "<<aa[1]<<" "<<aa[2]<<" "<<-1<<endl;
        }
    }
    if(j!=0)
    {
        cc++;
        sortit(aa,j);
        for(int k=0;k<j;k++)fout<<aa[k]<<" ";
        fout<<"-1 ";
    }
    if(cc!=17)for(int i=cc;i<17;i++)fout<<"-1 ";
    cout<<cc<<" "<<DD<<endl;
    fout.close();
    fin.close();
    fin.open("data2.txt");
    count[0]=7;count[1]=6;count[2]=4;count[3]=0;
    int z;
    char a[6]="a.txt";char d[6]="d.txt";char c[6]="c.txt";char b[6]="b.txt";
    ofstream fo[4];
    fo[0].open(a);
    fo[1].open(b);
    fo[2].open(c);
    fo[3].open(d);
    for(int i=0;i<7;i++)
    {
        fin>>z;
        while(z!=-1)
        {
            fo[0]<<z<<" ";
            fin>>z;
        }
        if(z==-1)fo[0]<<"-1 ";
    }
    for(int i=0;i<6;i++)
    {
        fin>>z;
        while(z!=-1)
        {
            fo[1]<<z<<" ";
            fin>>z;
        }
        if(z==-1)fo[1]<<"-1 ";
    }
    for(int i=0;i<4;i++)
    {
        fin>>z;
        while(z!=-1)
        {
            fo[2]<<z<<" ";
            fin>>z;
        }
        if(z==-1)fo[2]<<"-1 ";
    }
    for(int i=0;i<4;i++)fo[i].close();
    fin.close();
    while(count[0]+count[1]+count[2]+count[3]!=1)
    {
        int y=min(count[0],count[1],count[2],count[3]);
        int yy=1000;
        for(int jj=0;jj<4;jj++)
            if(count[jj]<=yy && count[jj]!=0)yy=count[jj];
        tempsort(y,yy,a,b,c,d);
        for(int i=0;i<4;i++){count[i]-=yy;cout<<endl<<count[i];}
        count[y]=count[y]+yy+yy;
        int h;cin>>h;
    }
    return 0;
}
