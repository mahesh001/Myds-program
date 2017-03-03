#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
ifstream fin,fin1,fin2,fin3,fin4;
ofstream fout,fout1,fout2,fout3,fout4;
 int sort(int d[],int i)
{
	for(int j=0;j<i;j++)
	{
		for(int k=0;k<i-1;k++)
		{
			if(d[k]>d[k+1])
			{
				int t=d[k];
				d[k]=d[k+1];
				d[k+1]=t;
			}
		}
	}
}
int main()
{    int n;
char a[100];
	fin.open("data.txt");
//	cout<<"enter the size \n";
//	cin>>n;
//	cout<<"enter the data \n";
//	for(int i=0;i<n;i++)
//	cin>>a[i];
	int d[3],d1,d2,d3,d4=0,f1,f2,f3,f4;
	fout1.open("3w1.txt");
	fout2.open("3w2.txt");
	fout3.open("3w3.txt");
	
	fin>>f1>>f2>>f3;
	d[0]=f1;d[1]=f2;d[2]=f3;
	sort(d,3);d1=0,d2=0,d3=0;
	while(!fin.eof())
	{
		if(d1==0||(d4==4&&d2<7))
		{
			fout1<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
			d1++;d2++;
		}
		else if(d1==1||(d4==4&&d3<6))
		{
			fout2<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
			d1++;d3++;
		}
		else if(d4<4)
		{
			fout3<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
			d1=0;d4++;
		}
		fin>>f1>>f2>>f3;
		d[0]=f1;d[1]=f2;d[2]=f3;sort(d,3);
	}
	fout1.close();
	fout2.close();
	fout3.close();
	fout4.open("3w4.txt");
	fin1.open("3w1.txt");
	fin2.open("3w2.txt");
	fin3.open("3w3.txt");
	fin3>>f3;
	while(!fin3.eof())
	{
		fin2>>f2;fin1>>f1;
		d[0]=f1;d[1]=f2;d[2]=f3;sort(d,3);
		fout4<<d[0]<<" ";
		do
		{
			if(d[0]==f1&&!fin1.eof()&&f1!=-1)
			{
				fin1>>f1;
				if(f1!=-1)
				{
					d[0]=f1;
					sort(d,3);
					fout4<<d[0]<<" ";
				}
				else
					d[0]=f2;
			}
			else if(f1==-1)
				d[0]=f2;
			if(d[0]==f2&&!fin2.eof()&&f2!=-1)
			{
				fin2>>f2;
				if(f2!=-1)
				{
					d[0]=f2;
					sort(d,3);
					fout4<<d[0]<<" ";
				}
				else
					d[0]=f3;
			}
			else if(f2==-1)
				d[0]=f3;
			if(d[0]==f3&&!fin3.eof()&&f3!=-1)
			{
				fin3>>f3;
				if(f3!=-1)
				{
					d[0]=f3;
					sort(d,3);
					fout4<<d[0]<<" ";
				}
				else
					d[0]=f1;
			}
			else if(f3==-1)
				d[0]=f1;
		}while(f1!=-1||f2!=-1||f3!=-1);
		fout4<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
		fin3>>f3;
	}
	fin3.close();
	fout4.close();
	fout3.open("3w3.txt");
	fin4.open("3w4.txt");
	fin2>>f2;
	while(!fin2.eof())
	{
		fin4>>f4;fin1>>f1;
		d[0]=f1;d[1]=f4;d[2]=f2;sort(d,3);
		fout3<<d[0]<<" ";
		do
		{
			if(d[0]==f1&&!fin1.eof()&&f1!=-1)
			{
				fin1>>f1;
				if(f1!=-1)
				{
					d[0]=f1;
					sort(d,3);
					fout3<<d[0]<<" ";
				}
				else
					d[0]=f4;
			}
			else if(f1==-1)
				d[0]=f4;
			if(d[0]==f4&&!fin4.eof()&&f4!=-1)
			{
				fin4>>f4;
				if(f4!=-1)
				{
					d[0]=f4;
					sort(d,3);
					fout3<<d[0]<<" ";
				}
				else
					d[0]=f2;
			}
			else if(f4==-1)
				d[0]=f2;
			if(d[0]==f2&&!fin2.eof()&&f2!=-1)
			{
				fin2>>f2;
				if(f2!=-1)
				{
					d[0]=f2;
					sort(d,3);
					fout3<<d[0]<<" ";
				}
				else
					d[0]=f1;
			}
			else if(f2==-1)
				d[0]=f1;
		}while(f1!=-1||f4!=-1||f2!=-1);
		fout3<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
		fin2>>f2;
	}
	fin2.close();
	fout2.open("3w2.txt");
	fout3.close();
	fin3.open("3w3.txt");
	fin1>>f1;
	while(!fin1.eof())
	{
		fin4>>f4;fin3>>f3;
		d[0]=f1;d[1]=f4;d[2]=f3;sort(d,3);
		fout2<<d[0]<<" ";
		do
		{
			if(d[0]==f1&&!fin1.eof()&&f1!=-1)
			{
				fin1>>f1;
				if(f1!=-1)
				{
					d[0]=f1;
					sort(d,3);
					fout2<<d[0]<<" ";
				}
				else
					d[0]=f4;
			}
			else if(f1==-1)
				d[0]=f4;
			if(d[0]==f4&&!fin4.eof()&&f4!=-1)
			{
				fin4>>f4;
				if(f4!=-1)
				{
					d[0]=f4;
					sort(d,3);
					fout2<<d[0]<<" ";
				}
				else
					d[0]=f3;
			}
			else if(f4==-1)
				d[0]=f3;
			if(d[0]==f3&&!fin3.eof()&&f3!=-1)
			{
				fin3>>f3;
				if(f3!=-1)
				{
					d[0]=f3;
					sort(d,3);
					fout2<<d[0]<<" ";
				}
				else
					d[0]=f1;
			}
			else if(f3==-1)
				d[0]=f1;
		}while(f1!=-1||f4!=-1||f3!=-1);
		fout2<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
		fin1>>f1;
	}
	fin1.close();
	fout1.open("3w1.txt");
	fout2.close();
	fin2.open("3w2.txt");
	fin4>>f4;fin3>>f3;fin2>>f2;
		d[0]=f2;d[1]=f4;d[2]=f3;sort(d,3);
		fout1<<d[0]<<" ";
		do
		{
			if(d[0]==f2&&!fin2.eof()&&f2!=-1)
			{
				fin2>>f2;
				if(f2!=-1)
				{
					d[0]=f2;
					sort(d,3);
					fout1<<d[0]<<" ";
				}
				else
					d[0]=f4;
			}
			else if(f2==-1)
				d[0]=f4;
			if(d[0]==f4&&!fin4.eof()&&f4!=-1)
			{
				fin4>>f4;
				if(f4!=-1)
				{
					d[0]=f4;
					sort(d,3);
					fout1<<d[0]<<" ";
				}
				else
					d[0]=f3;
			}
			else if(f4==-1)
				d[0]=f3;
			if(d[0]==f3&&!fin3.eof()&&f3!=-1)
			{
				fin3>>f3;
				if(f3!=-1)
				{
					d[0]=f3;
					sort(d,3);
					fout1<<d[0]<<" ";
				}
				else
					d[0]=f2;
			}
			else if(f3==-1)
				d[0]=f2;
		}while(f2!=-1||f4!=-1||f3!=-1);
		fout1<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
	return 0;
}
