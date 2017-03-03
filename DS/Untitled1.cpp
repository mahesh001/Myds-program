#include<iostream>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;
int swap(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void sort(char a[],int i)
{
	int k;
	for(k=0;k<i,k++)
	  for(int =k+1;j<i;j++)
	  if(a[k]>a[j])
	  {
	  	swap( a[k],a[j]);
	  }
}
int find min(int a,int b,int c,int d)
{
	if(a==-1&&b==-1&&c==-1&&d==-1)
	return -1;
	  if(a<=b && a<=c && a<=d)
	  return 0;
    if(b<=a && b<=c && b<=d)
	return 1;
    if(c<=b && c<=a && c<=d
	)return 2;
    if(d<=b && d<=c && d<=a)
	return 3;
}
void copy(ifstream &fin, char a[])
{
	char x[100],i=0;
	ifstream fin;
	fin.open("data")
	while(!fin.eof())
	{
		fin>>x[i++];
	}
	fin.close();
	ofstream fout;
	fout.open(a);
	for(int j=0;j<i-1;j++)
	fout<<x[j]<<" ";
}
void edit( ifstream &fin,char a[],char b[],char c[],char d[])
{  int n;
	switch(n)
	case 0:
		copy(f1,b);
		copy(f2,c);
		copy(f3,d);
		 break;
	case 1:
	    copy(f1,)	 
		}
