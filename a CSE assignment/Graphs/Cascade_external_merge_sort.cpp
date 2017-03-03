#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void show_array(int ram[],int no)
{
	for(int i=0;i<no;i++)
	cout<<ram[i]<<" ";
}

int final(int *table,int k)
{
	int i,one=0,zero=0;
	for(i=0;i<=k;i++)
	{
		if(table[i]==0)
		zero++;
		else
		one++;
	}
	
	if(zero==k && one==1)
	return 1;
	else
	return 0;
}

int min(int *table,int k,int &index)
{
	int i,t=10000;
	for(i=0;i<=k;i++)
	{
		if(table[i]!=0 && table[i]<t)
		{
			t=table[i];
			index=i;
		}
	}
	return t;
}

int mini(int *no,int *tag,int k,int &taken)
{
	int i,t=10000;
	
	for(i=0;i<=k;i++)
	{
		if(tag[i]==1 && no[i]<t)
		{
			t=no[i];
			taken=i;
		}
	}
	
	return t;
}

int all_tag_zero(int *tag,int k)
{
	int i;
	for(i=0;i<=k;i++)
	{
		if(tag[i]==1)
		break;
	}
	if(i>k)
	return 1;
	else
	return 0;
}

void Polyphase(fstream *file,char **name,int *table,int *size,int *touchble,int &output,int k,int &pie,int &sigma)
{
	int i,j,index;         //index is index for new output file
	int no_of_records=min(table,k,index);
	
	cout<<"table is :";
	show_array(table,k+1);
	cout<<endl;
	cout<<"size is  :";
	show_array(size,k+1);
	cout<<endl;
	
	int *count=new int[k+1];
	int *tag=new int[k+1];
	int *no=new int[k+1];
	
	for(i=0;i<no_of_records;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(j==output || touchble[j]==0)
			tag[j]=0;
			else
			tag[j]=1;
			
			count[j]=0;
		}
		
		for(j=0;j<=k;j++)
		{
			if(tag[j]==1)
			{
				file[j]>>no[j];
				count[j]++;
			}
		}
		
		int taken;
		while(!all_tag_zero(tag,k))
		{
			int temp;
			temp=mini(no,tag,k,taken);
			file[output]<<temp<<" ";
			
			if(count[taken]>=size[taken])
			tag[taken]=0;
			else
			{
				file[taken]>>no[taken];
				count[taken]++;
			}
		}
	}
	
	int t=0;
	for(i=0;i<=k;i++)
	{
		if(i!=output && touchble[i]==1)
		{
			table[i]=table[i]-no_of_records;
			t=t+size[i];
		}
	}
	
	table[output]=no_of_records;
	size[output]=t;
	table[index]=size[index]=0;
	
	sigma=table[output]*size[output];
	
	
	file[output].close();
	file[output].open(name[output],ios::in);
	
	output=index;
	
	file[output].close();
	file[output].open(name[output],ios::out);
	
	t=0;
	for(i=0;i<=k;i++)
	{
		if(i!=output)
		{
			t=t+table[i];
		}
	}
	pie=t;
}

void Cascade(fstream *file,char **name,int *table,int *size,int output,int k,int step,int phase,int pie,int sigma,int &stop)
{
	if(!final(table,k))
	{
		int i,j;
		
		int *touchble=new int[k+1];
		for(i=0;i<=k;i++)
		touchble[i]=1;
		
		for(i=0;i<(k-1) && !final(table,k);i++)
		{
			touchble[output]=0;	
			Polyphase(file,name,table,size,touchble,output,k,pie,sigma);
		}
		Cascade(file,name,table,size,output,k,step,phase,pie,sigma,stop);
	}
}

int main()
{
	int ram[4],i,j,s,k,no;
	
	cout<<"Enter the value of s \n";
	cin>>s;
	
	char data_file[20];
	cout<<"Enter the name of data file\n";
	cin>>data_file;
	
	ifstream fin;
	fin.open(data_file);
	
	if(fin.fail())
	cout<<"opening of datafile fail\n";
	
	cout<<"Enter the value of k\n";
	cin>>k;
	
	int *table=new int[k+1];
	int *size=new int[k+1];
	
	char **name=new char*[k+1];
	for(i=0;i<=k;i++)
	name[i]=new char[20];
	
	cout<<"Enter the name of files\n";
	for(i=0;i<=k;i++)
	cin>>name[i];
	
	fstream *file=new fstream[k+1];
	for(i=0;i<=k;i++)
	file[i].open(name[i],ios::out);
	
	for(i=0;i<14;i++)
	{
		fin>>no;
		file[0]<<no<<" ";
	}
	
	for(i=0;i<11;i++)
	{
		fin>>no;
		file[1]<<no<<" ";
	}
	
	for(i=0;i<6;i++)
	{
		fin>>no;
		file[2]<<no<<" ";
	}
	
	fin.close();
	
	for(i=0;i<=k;i++)
	file[i].close();
	
	table[0]=14;
	table[1]=11;
	table[2]=6;
	table[3]=0;
	
	size[0]=size[1]=size[2]=1;
	size[3]=0;
	
	for(i=0;i<=k;i++)
	{
		if(i==k)
		file[i].open(name[i],ios::out);
		else
		file[i].open(name[i],ios::in);
	}
	
	int step=0,phase=0,pie=31,sigma=0,output=k,stop=0;
	
	Cascade(file,name,table,size,output,k,step,phase,pie,sigma,stop);
	
	for(i=0;i<=k;i++)
	file[i].close();	
}
