#include<iostream>
#include<fstream>
using namespace std;
char A[10][9]={"fi1.txt","fi2.txt","fi3.txt","fi4.txt","fi5.txt","fi6.txt","fi7.txt","fi8.txt","fi9.txt","fi10.txt"};
char B[10][9]={"fo1.txt","fo2.txt","fo3.txt","fo4.txt","fo5.txt","fo6.txt","fo7.txt","fo8.txt","fo9.txt","fo10.txt"};
void sort(int a[],int m);
void add(ifstream in[],ofstream &fout,int w);
int min(int a[],int w);
int main()
{
    int w,y=0,a[3],m=0,n=0;
    //char A[20],B[20];
   // A[0]='f';
    //B[0]='k';
    ifstream fin;
    fin.open("data2.txt");
    cout<<"\n enter the number of ways"<<endl;
    cin>>w;
    //char o=w;
    /*for(int i=0;i<w;i++)
    {   
        strcat(A,i);
        strcat(B,i);
        strcat(A,".txt");
        strcat(B,".txt");
    }*/
    ofstream fout[w];
    for(int i=0;i<w;i++)
    {
        fout[i].open(A[i]);
    }
    int i=0,x,j=0;
    int k=0,z=0,t=0,s;
    for(i=0;i<3;i++)
    {
        fin>>x;
        a[k++]=x;
    }
    while(!fin.eof())
    {
        k=j;
        sort(a,3);
        m=j%w; 
        if(a[0]>y)
        {
            fout[m]<<a[0]<<" ";
            y=a[0];
            fin>>x;
            a[0]=x;
        }
        else if(a[1]>y)
        {
            fout[m]<<a[1]<<" ";
            y=a[1];
            fin>>x;
            a[1]=x;
        }
        else if(a[2]>y)
        {
            fout[m]<<a[2]<<" ";
            y=a[2];
            fin>>x;
            a[2]=x;
        }
        else
        {
            fout[m]<<-1<<" ";
            y=0;
            j++;
        }
        if(k!=j)
        {
            n++;
            if(m==0)
                z++;
        }
    }
    j++;
    s=m;
    m=j%w;
    if(m==0)
        z++;
    if(a[0]!=-1)
    {
        if(a[0]<y)
        fout[m]<<a[0]<<" ";
        else
        {
            fout[s]<<a[0]<<" ";
            y=a[0];
        }
    }
    if(a[1]!=-1)
    {
        if(a[1]<y)
        fout[m]<<a[1]<<" ";
        else
        {
            fout[s]<<a[1]<<" ";
            y=a[1];
        }
    }
    if(a[2]!=-1)
    {
        if(a[2]<y)
        fout[m]<<a[2]<<" ";
        else
            fout[s]<<a[2]<<" ";
    }
    fout[m]<<-1<<" ";
    fout[s]<<-1<<" ";
    k++;
    j++;
    m=j%w;
    if(m==0)
        z++;
   // j++;
    //m=j%w;
    //if(m==0)
      //  z++;
    n=n+2;
    m=n%w;
    while(m!=w)
    {
        fout[m++]<<-1<<" ";
    }
    for(int i=0;i<w;i++)
        fout[i].close();
    fin.close();
    ifstream in[w];
    i=0;x=0;
    while(z!=0)
    {
        if(i%2==0)
        {
            for(int t=0;t<w;t++)
            {
                in[t].open(A[t]);
                fout[t].open(B[t]);
            }
        }
        else
        {
            for(int t=0;t<w;t++)
            {
                in[t].open(B[t]);
                fout[t].open(A[t]);
            }
        }
        while(x!=z)
        {
            t=x%w;
            add(in,fout[t],w);
            fout[t]<<-1<<" ";
            x++;
        }
        y=t;
        t=x%w;
        while(t!=0)
        {   
            fout[t]<<-1<<" ";
            x++;
            t=x%w;
        }
        for(int t=0;t<w;t++)
        {   fout[t].close();
            in[t].close();
        }
        x=0;
        z=z/2;
        i++;
    }
    if(i%2==0)
            in[0].open(A[y]);
        else
            in[0].open(B[y]);

    in[0]>>y;
    if(i%2==0)
    cout<<"sorted file is:"<<A[y];
     else
        cout<<"sorted file is:"<<B[y];
    while(y!=-1)
    {
        cout<<y<<endl;
        in[0]>>y;
    }
    in[0].close();
    return 0;
}
int min(int a[],int w)
{
    int x=-1;
    for(int i=0;i<w;i++)
        if(a[i]!=-1)
        {
            x=a[i];
            break;
        }
    for(int i=0;i<w;i++)
        if(a[i]!=-1 && a[i]<x)
                x=a[i];    
    if(x==-1)
        return -1;
        return x;
}
void add(ifstream in[],ofstream &fout,int w)
{
    int x,j=0;
    int a[w];
    for(int i=0;i<w;i++)
        in[i]>>a[i];
    x=min(a,w);
    while(x!=-1)
    {
        for(int i=0;i<w;i++)
        {
            if(a[i]==x)
            {
                j=i;
                break;
            }
        }
        fout<<x<<" ";
        in[j]>>a[j];
        j=0;
        x=min(a,w);
    }
}
void sort(int a[],int m)
{
    for(int i=0;i<m-1;i++)
        for(int j=0;j<m-1;j++)
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}
