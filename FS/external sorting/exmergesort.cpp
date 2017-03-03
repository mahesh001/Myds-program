#include<iostream>
#include<fstream>
using namespace std;
int a[3],k=-1;
void swap(int &a,int &b)
{
int temp=a;
     a=b;
     b=temp;
}
void sort(int a[])
{
	for(int i=0;i<3;i++)
		for(int j=i+1;j<=2;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
int main()
{
	ifstream fin;int h1=1;
	fin.open("data.txt");
	fin>>a[0]>>a[1]>>a[2];
	int f=0;int h=1;
	ofstream fout,fout1;
	fout.open("f1.txt");
	fout1.open("f2.txt");
	while(!fin.eof())
	{
		sort(a);
		if(a[0]>k&&f!=1)
		{
			fout<<a[0]<<" ";
			k=a[0];
			fin>>a[0];
		}
		else if(a[0]>k&&f==1)
		{
			fout1<<a[0]<<" ";
			k=a[0];
			fin>>a[0];
		}
		else
		{
			if(a[0]<k&&f!=1)
			{
				int i=0;
				while(i<3)
				{
					sort(a);
					if(a[i]>k)
					{
						fout<<a[i]<<" ";
						k=a[i];
						fin>>a[i];
					}
					else
						i++;
				}
				fout<<-1<<endl;
				f=1;
				k=-1;
			}
			else if(a[0]<k && f==1)
			{
			int i=0;
				while(i<3)
				{
					sort(a);
					if(a[i]>k)
					{
						fout1<<a[i]<<" ";
						k=a[i];
						fin>>a[i];
					}
					else
						i++;
				}
				fout1<<-1<<endl;
				f=0;
				k=-1;
			}
		}
	}
	fout1<<a[1]<<" "<<a[2]<<" "<<-1<<endl;
	fout.close();
	fout1.close();
	fin.close();
	a[0]=a[1]=a[2]=-1;
	ifstream inf,inf1;
	ofstream out,out1;
	inf.open("f1.txt");
	inf1.open("f2.txt");
	out.open("f3.txt");
	out1.open("f4.txt");
	inf>>a[0];
	inf1>>a[1];
	while(!(inf.eof())||!(inf1.eof()))
	{
		while(h!=0)
		{
			if(a[0]==-1&&a[1]==-1)
			{
				out<<-1<<endl;
				inf>>a[0];
				inf1>>a[1];
				h=0;
			}
			if(a[0]==-1)
			{
				out<<a[1]<<" ";
				inf1>>a[1];
			}
			else if(a[1]==-1)
			{
				out<<a[0]<<" ";
				inf>>a[0];
			}
			else if(a[0]<a[1])
			{
				out<<a[0]<<" ";
				inf>>a[0];
			}
			else 
			{
				out<<a[1]<<" ";
				inf1>>a[1];	
			}
		}
		while(h1!=0)
		{
			if(a[0]==-1&&a[1]==-1)
			{	out1<<-1<<endl;
				inf>>a[0];
				inf1>>a[1];
				h1=0;
			}
			else if(a[0]==-1)
			{
				out1<<a[1]<<" ";
				inf1>>a[1];
			}
			else if(a[1]==-1)
			{
				out1<<a[0]<<" ";
				inf>>a[0];
			}
			if(a[0]>a[1])
			{
				out1<<a[1]<<" ";
				inf1>>a[1];
			}
			else if(a[0]<a[1])
			{
			out1<<a[0]<<" ";
				inf>>a[0];	
			}
		}
	}
	inf.close();
	inf1.close();
	out.close();
	out1.close();
	inf.open("f3.txt");
	inf1.open("f4.txt");
	out.open("f2.txt");
	inf>>a[0];
	inf1>>a[1];
	int h2,h3;
	while(!(inf.eof())||!(inf1.eof()))
	{
		while(h2!=0)
		{
			if(a[0]==-1&&a[1]==-1)
			{
				out<<-1<<endl;
				inf>>a[0];
				inf1>>a[1];
				h2=0;
			}
			if(a[0]==-1)
			{
				out<<a[1]<<" ";
				inf1>>a[1];
			}
			else if(a[1]==-1)
			{
				out<<a[0]<<" ";
				inf>>a[0];
			}
			else if(a[0]<a[1])
			{
				out<<a[0]<<" ";
				inf>>a[0];
			}
			else 
			{
				out<<a[1]<<" ";
				inf1>>a[1];	
			}
		}
	}
	return 0;
}
