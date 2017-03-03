#include<iostream>
#include<fstream>
using namespace std;
void swap(int&a ,int& b)
{	int c=a;
	a=b;
	b=c;
}
void sort(int a[])
{	int i,j;
for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		if(a[j]>a[j+1])
			swap( a[j],a[j+1]);	
}
int main()
{
	ifstream fin;
	fin.open("data.txt");
	ofstream f,f0;
	f.open("f1.txt");
	f0.open("f2.txt");
	int i,j,a,b;
	int* k=new int[3];
	for(i=0;i<8;i++)
	{	for(j=0;j<3;j++)
			fin>>k[j];
			sort(k);
		for(j=0;j<3;j++)
			{	
				if(i%2==0)
					f<<k[j]<<" ";
				else
					f0<<k[j]<<" ";
			}
		if(i%2==0)
			f<<endl;
		else
			f0<<endl;
	}f.close();f0.close();fin.close();
	ofstream f3,f4;
		f3.open("f3.txt");
		f4.open("f4.txt");
	ifstream f1,f2;
		f1.open("f1.txt");
		f2.open("f2.txt");
	for(i=0;i<4;i++)
	{	//int u=1;int u1=1;
			
		for(j=0;j<6;j++)
				{ 
					if(j==0)
					{ 
						f1>>a;
						f2>>b;
						//if(i==1)
							cout<<a<<"  "<<b<<endl;
					}
					else if(a>b && j!=5)
						f2>>b;
					else if(a<b && j!=5) 
						f1>>a;
					else if(j==5)
						{
							if(i%2==0)
								{
								if(a>b)
									f3<<a<<" "<<endl;
								else
									f3<<b<<" "<<endl;
								}
							if(i%2!=0)
								{
								if(a>b)
									f4<<a<<" "<<endl;
								else
									f4<<b<<" "<<endl;
								}
								break;
									break;
						}

						if(i%2==0 && j!=5)
								{
									if(a<b)
										f3<<a<<" ";
									else
										f3<<b<<" ";
									//if(u%3==0)
									//		f3<<endl;
								}
							else if(j!=5)
								{
									if(a<b)
										f4<<a<<" ";
									else
										f4<<b<<" ";
									//if((i+1)%3==0)
									//		f4<<endl;
								}

		}
	}
f3.close();f4.close();
f1.open("f3.txt");
f2.open("f4.txt");
f3.open("f5.txt");
f4.open("f6.txt");
for(i=0;i<2;i++)
{
	for(j=0;j<12;j++)
	{
		if(j==0)
			{
				f1>>a;
				f2>>b;
				cout<<a<<"   "<<b<<endl;
			}
			else if(a>b && j!=11)
				f2>>b;
			else if(a<b && j!=11) 
				f1>>a;
			if(j==11)
			{
				if(i%2==0)
					{
					if(a>b)
						f3<<a<<" "<<endl;
					else
						f3<<b<<" "<<endl;
					}
				if(i%2!=0)
					{	if(a>b)
						f4<<a<<" "<<endl;
					else
						f4<<b<<" "<<endl;
					}
		//			break;
			}
			if(i%2==0 && j!=11)
				{
					if(a<b)
						f3<<a<<" ";
					else
						f3<<b<<" ";
					//if(u%3==0)
					//		f3<<endl;
				}
			else if(j!=11)
				{
					if(a<b)
						f4<<a<<" ";
					else
						f4<<b<<" ";
					//if((i+1)%3==0)
					//		f4<<endl;
				}

		
	}
}
f3.close();
f4.close();

return 0;
}
