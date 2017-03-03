#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
int findmin(int a[],int t)
{
	int min=7777,index=-1;
	for(int i=0; i<t;i++)
	{
		if(min>a[i])
		{
			min=a[i];
			index=i;
		}
	}
	if(min==7777)
	return min;
	else
	return index;
}
int findminp(int a[],int t)
{
	int min=7777,index=-1;
	for(int i=0; i<t;i++)
	{
		if(a[i]==0)
		 a[i]=777;
		if(min>a[i])
		{
			min=a[i];
		}
	}
	return min;
}
void print(int p[],int su[]);
void  bal(int p[],int r,int t,int su[])
{
	int j=0;
	for(int i=0;i<4;i++)
    {
   	 if(p[i]==777)
   	 p[i]=0;
   	 j=j+su[i];
     if(p[i]==0)
      su[i]=j;
     p[i]=p[i]-r;
     if(p[i]<0)
     p[i]=-p[i];
     
  }
   su[t]=0;
  print(p,su);
}
 void print(int p[],int su[])
 {  int level=0;
 	cout<<endl;
   cout<<"partition"<<"- ";
   for(int j=0;j<4;j++)
   cout<<p[j]<<"\t";   
   cout<<endl;
   cout<<"size     "<<"- ";
   for(int j=0;j<4;j++)
   cout<<su[j]<<"\t";
 }

 void process(fstream  &f1,fstream *f,int p[],int su[])
{
	string s1,s2;
	int s=4;
	char buffer[100];
	
//	for(int i=0;i<s+1;i++)
//	f[i]=new fstream;
	s1="f";
	for(int i=0;i<s+1;i++)
	{
		f[i].open((s1+".txt").c_str(),ios::out);
		s1=s1+"f";
	}
    f1.open("inpdata.txt",ios::in);
    int k=0,a[10];
	while(k<=3)
   { 
     if(f1.eof())
     break;
	for(int i=0;i<p[k];i++)
	{
		for(int j=0;j<s;j++)
		 {
		  f1.getline(buffer,15,'\n');
		  a[j]=atoi(buffer);
         }
		sort(a,a+s);
		for(int j=0;j<s;j++)
		f[k]<<a[j]<<endl;
	}
	 su[k]=s;
	 k++;
   }
    print(p,su);
   /*cout<<"partition"<<"- ";
   for(int j=0;j<4;j++)
   cout<<p[j]<<"\t";   
   cout<<endl;
   cout<<"size     "<<"- ";
   for(int j=0;j<4;j++)
   cout<<su[j]<<"\t";*/
   for(int i=0;i<4;i++)
   f[i].close();
   f1.close();
}   
int main()
{
	int count;
	char buffer[100];
	fstream f1;  
	f1.open("inpdata.txt",ios::in);
	while(!f1.eof())
	{
		f1.getline(buffer,15,'\n');
		if(f1.eof())
		break;
		count++;
	}
	f1.close();
	cout<<count<<"\n";
	int i,j,k,c,s,n,m,r;
	n=count;
	k=3;
	s=4;
	cout<<" way of external sort\n";
	cout<<k<<endl;
	cout<<"\t"<<"   "<<"f1"<<"\t"<<" f2"<<"\t"<<"f3"<<"\t"<<"f4"<<endl;
	int a[10],p[4],su[4];
	fstream f[k+1];
	string s1,s2;
	s1="f";
	for(int i=0;i<k+1;i++)
	{
		f[i].open((s1+".txt").c_str(),ios::out);
		s1=s1+"f";
	}
	f1.open("inpdata.txt",ios::in);
	p[0]=7;
	p[1]=6;
	p[2]=4;
	p[3]=0;
//	process(f1,f,p,su);
	  k=0;
	while(k<=3)
   { 
     if(f1.eof())
     break;
	for(int i=0;i<p[k];i++)
	{
		for(int j=0;j<s;j++)
		 {
		  f1.getline(buffer,15,'\n');
		  a[j]=atoi(buffer);
         }
		sort(a,a+s);
		for(int j=0;j<s;j++)
		f[k]<<a[j]<<endl;
	}
	if(p[k]==0)
	 su[k]=0;
	 else
	 su[k]=s;
	 k++;
   }
  /*cout<<"partition"<<"- ";
   for(int j=0;j<4;j++)
   cout<<p[j]<<"\t";   
   cout<<endl;
   cout<<"size     "<<"- ";
   for(int j=0;j<4;j++)
   cout<<su[j]<<"\t";*/
   print(p,su);
   for(int i=0;i<4;i++)
   f[i].close();
   f1.close();
   r=findminp(p,4);
   j=findmin(p,4);
   
   bal(p,r,j,su);
   process(f1,f,p,su);
  /*for(int i=0;i<4;i++)
   {
   	 if(p[i]==777)
   	 p[i]=0;
     p[i]=p[i]-r;
     if(p[i]<0)
     p[i]=-p[i];
     cout<<p[i]<<" ";
   }*/
    return 0;
}
