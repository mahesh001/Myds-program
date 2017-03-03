#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
void Readfile(ifstream &file,int a[],int &n)
{
	int i;
	for(i=0;i<4 && !file.eof();i++)
	file>>a[i];
	n=i;
}

void Writefile(ofstream &file,int a[],int n)
{
	for(int i=0;i<n;i++)
	file<<a[i]<<" ";
}

int fileempty(ifstream & file)
{
	int curr=file.tellg();
	int i;
	file>>i;
	int t;
	t=file.eof();
	if(t==0)
	file.seekg(curr,ios::beg);
	return t;
}

int all_empty(int *tag,int k)
{
	int i;
	for(i=0;i<k;i++)
	{
		if(tag[i]==1)
		break;
	}
	if(i==k)
	return 1;
	else
	return 0;

}

int min(int *no,int *tag,int *count,int k,int s,int &temp)
{
	int i,t=10000;
	for(i=0;i<k;i++)
	{
		if(tag[i]==1 && no[i]<t && count[i]<s)
		{
			t=no[i];
			temp=i;
		}
	}
	return t;
}

int countover(int *count,int s,int k)
{
	int i;
	for(i=0;i<k;i++)
	{
		if(count[i]<s)
		break;
	}
	if(i<k)
	return 1;
	else
	return 0;
}

void External_sort(char **name_a,char **name_b,int s,int k,int l,char *final)
{
	int i,j;
	ifstream *fin=new ifstream[k];
	ofstream *fout=new ofstream[k];

	if(l==0)
	{
		for(i=0;i<k;i++)
		{
			fin[i].open(name_a[i]);
			fout[i].open(name_b[i]);
		}
	}
	else
	{
		for(i=0;i<k;i++)
		{
			fin[i].open(name_b[i]);
			fout[i].open(name_a[i]);
		}
	}
	int *tag=new int[k];
	int *no=new int[k];
	int mini;
	for(i=0;i<k;i++)
	{
		if(fileempty(fin[i]))
		tag[i]=0;
		else
		tag[i]=1;
	}
	if(tag[1]==1)
	{
		int point=0;
		int taken;
		int *count=new int[k];
		for(i=0;i<k;i++)
		count[i]=0;

		while(!all_empty(tag,k))
		{
			for(i=0;i<k;i++)
			{
				if(tag[i]==1)
				fin[i]>>no[i];
			}

			for(i=0;i<(s*k) && !all_empty(tag,k) && countover(count,s,k);i++)
			{
				mini=min(no,tag,count,k,s,taken);
				fout[point]<<mini<<" ";
				count[taken]++;

				if(fileempty(fin[taken]))
				tag[taken]=0;
				else if(count[taken]<s)
				fin[taken]>>no[taken];
			}

			for(i=0;i<k;i++)
			count[i]=0;
			point=(point+1)%k;
		}

		for(i=0;i<k;i++)
		{
			fin[i].close();
			fout[i].close();
		}

		if(l==1)
		strcpy(final,name_a[0]);
		else
		strcpy(final,name_b[0]);
		External_sort(name_a,name_b,s*k,k,(l+1)%2,final);

	}
}

int main()
{
	int b[4],s,k,i,j,point=0,n;

	cout<<"Enter the value of s \n";
	cin>>s;

	char data_file[20];
	cout<<"Enter the name of data file\n";
	cin>>data_file;

	ifstream dfin;
	dfin.open(data_file);

	cout<<"Enter the value of no of file\n";
	cin>>k;
	char **a1=new char*[k];
	char **b1=new char*[k];
	for(i=0;i<k;i++)
	{
		a1[i]=new char[20];
		b1[i]=new char[20];
	}

	cout<<"Enter names of file of a\n";
	for(i=0;i<k;i++)
	cin>>a1[i];

	cout<<"Enter names of file of b\n";
	for(i=0;i<k;i++)
	cin>>b1[i];
	
	ofstream *a=new ofstream[k];

	for(i=0;i<k;i++)
	a[i].open(a1[i]);
	while(!dfin.eof())
	{
		Readfile(dfin,b,n);
		sort(b,b+n);
		Writefile(a[point],b,n);
		point=(point+1)%k;
		cout<<"hello";
	}
	cout<<"abc";
	dfin.close();
	for(i=0;i<k;i++)
	a[i].close();
	char f[20];
	External_sort(a1,b1,4,k,0,f);

	ifstream fin;
	ofstream fout;
	fin.open(f);
	fout.open(data_file);
	fin>>i;
	fin>>i;
	while(!fin.eof())
	{
		fout<<i<<" ";
		fin>>i;
	}

	fin.close();
	fout.close();
}
