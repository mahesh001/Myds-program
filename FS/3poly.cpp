#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
void sort(int a[])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}
int full(int a[])
{
	int flag=0;
	for(int i=0;i<4;i++)
	{
		if(a[i]!=-1)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		return 1;
	else
		return 0;
}
int findMin(int count[])
{
	int min;
	int k;
	for(int i=0;i<4;i++)
	{
		if(count[i]!=0 && count[i]!=-1)
		{
			min=count[i];
			k=i;
			break;
		}
	}
	for(int i=0;i<4;i++)
	{
		if(min > count[i] && count[i]!=0 && count[i]!=-1)
		{
			min=count[i];
			k=i;
		}
	}
	return k;
}
int main()
{
	ifstream fin1;
	fin1.open("data.txt");
	int count[4]={7,6,4,0};
	
	ofstream fout[4];
	char s[2];
	int a[3];
	for(int i=0;i<4;i++)
	{
		char x[]={"a"};
		itoa(i,s,10);
		strcat(x,s);
		strcat(x,".txt");
		fout[i].open(x);
	}
	int p=0;
	while(!fin1.eof())
	{
		for(int i=0;i<count[p];i++)
		{
			for(int k=0;k<3;k++)
				fin1>>a[k];
			sort(a);
			for(int k=0;k<3;k++)
				fout[p]<<a[k]<<" ";
			fout[p]<<-1<<" ";
		}		
		p++;
	}	
	for(int i=0;i<4;i++)
		fout[i].close();
	fin1.close();

	//merge..........
	int min;
	int zero;
	int min1;
	int b[4];
	ifstream fin[4];
		for(int i=0;i<4;i++)
		{
			char x[]={"a"};
			itoa(i,s,10);
			strcat(x,s);
			strcat(x,".txt");
			if(count[i]!=0)
				fin[i].open(x);		
		}
		
	while(count[0]+count[1]+count[2]+count[3]!=1)
	{
		min=findMin(count);
		cout<<"rahul "<<count[min]<<endl;
		for(int i=0;i<4;i++)
		{
			if(count[i]==0)
			{
				char x[]={"a"};
				itoa(i,s,10);
				strcat(x,s);
				strcat(x,".txt");
				fout[i].open(x);
				zero=i;
			}
		}
		
		for(int i=0;i<4;i++)
		{
			if(count[i]!=0)
				fin[i]>>b[i];
			else
				b[i]=-1;
		}
		while(!fin[min].eof())
		{
			min1=findMin(b);
			cout<<"sanjay "<<b[min1]<<" ";
			fout[zero]<<b[min1]<<" ";
			fin[min1]>>b[min1];
			if(full(b))
			{
				for(int i=0;i<4;i++)
				{
					if(count[i]!=0)
						fin[i]>>b[i];
					else
						b[i]=-1;
				}
				fout[zero]<<-1<<" ";
			}
		}
		fout[zero].close();
		char x[]={"a"};
		itoa(zero,s,10);
		strcat(x,s);
		strcat(x,".txt");
		fin[zero].open(x);
		int tmp=count[min];
		for(int i=0;i<4;i++)
		{
			if(count[i]!=0)
				count[i]=count[i]-tmp;
			else
				count[i]=tmp;
		}
		cout<<"count ";
		for(int i=0;i<4;i++)
			cout<<count[i]<<" ";
		cout<<endl;
	}	 
}
