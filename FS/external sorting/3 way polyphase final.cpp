#include<iostream>
#include<fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

char a[4][20]={"a1.txt","a2.txt","a3.txt","a4.txt"};
int g; 
int pass,pass1;

struct sss
{
	int partition[10];
	int size[10];
}s[4];

void swap(int& a,int& b)
 {
     int t=a;
     a=b;
     b=t;
 }

int findmin(int m[],int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(m[i]<m[j])
          {
             j=i;
          }
    }
    return j;
}
int minimum(int t)
{
    int w=999; int d;
   for(int i=0;i<4;i++)
   {
   	if(s[i].partition[t]==0) 
   	pass1=i;
   	if(s[i].partition[t]!=0) 
   	if(s[i].partition[t]<w)
   	{
   		w=s[i].partition[t]; 
   		d=i;
   	}
   }
   return d;
}

int min(int t)
{
   int w=999;
   for(int i=0;i<4;i++)
   {
   	if(s[i].partition[t]==0) 
   	pass=i;
   	if(s[i].partition[t]!=0) 
   	if(s[i].partition[t]<w)
   	{
   		w=s[i].partition[t]; 
   	}
   }
   return w;
}

void ini(int a[])
{
	for(int i=0;i<4;i++)
	a[i]=0;
}

void polyphase(fstream f[],int t)
{
	int pos;
	g=min(t); 
	for(int i=0;i<g;i++)
	{
		int m[4],c[4];
		ini(m);
		ini(c);
		for(int j=0;j<4;j++)
		{
			if(j!=pass)
			f[j]>>m[j];
		}
		m[pass]=999;
		while(1)
		{
			pos=findmin(m,4);
			if(m[pos]>=999) 
			break;
			f[pass]<<m[pos]<<endl;
			c[pos]++;
			if(c[pos]==s[pos].size[t])
			{
				m[pos]=m[pos]+999;
			}
			else
			{
				f[pos]>>m[pos];
			}
		}
	}
	for(int k=0;k<4;k++)
	{
		if(k!=pass)
		{
			s[k].partition[t+1]=s[k].partition[t]-g;
			if(s[k].partition[t+1]==0)
			 s[k].size[t+1]=0;
			else
			s[k].size[t+1]=s[k].size[t];
		}
		s[pass].size[t+1]+=s[k].size[t];
	}
	s[pass].partition[t+1]=g;
	g=minimum(t+1); 
	if(s[pass].size[t+1]!=68)
	{
	    {
			f[pass].close();
			f[pass1].close();
	    }
	    f[pass].open(a[pass],ios::in);
	    f[pass1].open(a[pass1],ios::out);
		polyphase(f,t+1);
	}
	else
	return;
	
}
int main()
{
	    fstream f[4];
		f[0].open("a1.txt",ios::out);
		f[1].open("a2.txt",ios::out);
		f[2].open("a3.txt",ios::out);
		f[3].open("a4.txt",ios::out);
	fstream F;
	F.open("data.txt",ios::in);
	int ch,b[4],j,k;
	    for( k=0;k<7;k++)
	    {
		for( j=0;j<4;j++)
		{
			F>>ch;
			if(ch==-1) break;
			else b[j]=ch;
		}
		sort(b,b+j);
		for( j=0;j<4;j++)
		{
			f[0]<<b[j]<<endl;
		}
	    }
	    s[0].partition[0]=k; 
	    s[0].size[0]=j;
	    for( k=0;k<6;k++)
	    {
		for(j=0;j<4;j++)
		{
			F>>ch;
			if(ch==-1) break;
			else b[j]=ch;
		}
		sort(b,b+j);
		for( j=0;j<4;j++)
		{
			f[1]<<b[j]<<endl;
		}
	    }
	    s[1].partition[0]=k; 
	    s[1].size[0]=j;
	    for(k=0;k<4;k++)
	    {
		for(j=0;j<4;j++)
		{
			F>>ch;
			if(ch==-1) break;
			else b[j]=ch;
		}
		sort(b,b+j);
		for(j=0;j<4;j++)
		{
			f[2]<<b[j]<<endl;
		}
	    }
	    s[2].partition[0]=k; 
	    s[2].size[0]=j;
	    s[3].partition[0]=0; 
	    s[3].size[0]=0;
	    for(int i=0;i<4;i++)
	    {
	    	s[i].partition[0];
	    }
	    for(int i=0;i<4;i++)
	    {
			f[i].close();
	    }
	    for(int i=0;i<3;i++)
	    {
	    	f[i].open(a[i],ios::in);
	    }
	    f[3].open(a[3],ios::out);
	    polyphase(f,0);
}
