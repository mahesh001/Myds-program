#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
	ofstream of;
	ifstream if1,if2;
	int k,i,j,pos=0,temp,maxh,l,m,n,x,y,z;
	char a[2],b[2];
	int inte[20],fre[20];
	
	if1.open("f1.txt");
	if2.open("f2.txt");
	of.open("f3.txt");
	if(if1.fail()||if2.fail()||of.fail())
	cout<<"File opening fail\n";
	while(!if1.eof())
	{
	    k=0;
	    if1>>a;
	    cout<<"a="<<a;
	    i=atoi(a);
	    while(!if2.eof())
		{
		  if2>>b[0];
		  j=atoi(b);
	      if(i==j)
		  {
		    k++;
	      }
	    }
	    of<<i<<"-"<<k<<endl;
	    inte[pos]=i;
	    fre[pos]=k;
	    pos++;
	    if2.seekg(0,ios::beg);	
	}
	pos--;
	temp=fre[0];
	for(x=1;x<pos;x++)
	{
		if(fre[x]>temp)
		{
			temp=fre[x];
		}
	}
	maxh=temp;
	for(l=0;l<temp;l++)
	{
		for(m=0;m<pos;m++)
		{
			if(fre[m]>=maxh)
			{
				cout<<"*  ";
			}
			else{
				cout<<"   ";
			}
		}
	maxh--;
	cout<<endl;	
	}
	for(n=0;n<pos;n++)
	{
		cout<<inte[n]<<"  ";
	}
     if1.close();
     if2.close();
     of.close();


return 0;
}
