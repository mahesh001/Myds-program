#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;

void show_array(int ram[],int no)
{
	cout<<"Array is : ";
	for(int i=0;i<no;i++)
	cout<<ram[i]<<" ";
	cout<<endl;
}

void Read(ifstream &file,int ram[],int &no)
{
	int i;
	for(i=0;i<4 && !file.eof();i++)
	file>>ram[i];
	no=i;
}

void Write(fstream &file,int ram[],int no)
{
	for(int i=0;i<no;i++)
	file<<ram[i]<<" ";
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

/*int count_fine(int *count,int *size,int k)
{
	int i;
	for(i=0;i<=k;i++)
	{
		if(i!=output && count[i]<size[i])
		break;
	}
	if(i<=k)
	return 1;
	else
	return 0;
}*/

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

void Polyphase(fstream *file,char **name,int s,int k,int *table,int *size,int output)
{
	if(!final(table,k))   //final function detemine whether sorting is done or not
	{
		cout<<"Polyphase\n";
		int i,j,index;         //index is index for new output file
		int no_of_records=min(table,k,index);
		cout<<"no_of_records = "<<no_of_records<<endl;
		
		cout<<"table is :";
		show_array(table,k+1);
		cout<<"size is  :";
		show_array(size,k+1);
		
//		ifstream *fin=new ifstream[k+1];
//		ofstream fout;
		
		/*for(i=0;i<=k;i++)
		{
			if(table[i]!=0)
			fin[i].open(name[i]);
			else
			output=i;
		}*/
		
//		fout.open(name[output]);
		
		int *count=new int[k+1];
		int *tag=new int[k+1];
		int *no=new int[k+1];
		
		/*for(j=0;j<=k;j++)
		{
			if(table[j]!=0)
			tag[j]=1;
			else
			tag[j]=0;
		}*/
		
		/*-cout<<"tag are : ";
		show_array(tag,k+1);*/
		
		for(i=0;i<no_of_records;i++)
		{
			for(j=0;j<=k;j++)
			{
				if(j==output)
				tag[j]=0;
				else
				tag[j]=1;
				
				count[j]=0;
			}
			
			for(j=0;j<=k;j++)
			{
				if(j!=output)
				{
					file[j]>>no[j];
					count[j]++;
				}
			}
			cout<<"no are : ";
			show_array(no,k+1);
			int taken;
			while(!all_tag_zero(tag,k))
			{
				int temp;
				temp=mini(no,tag,k,taken);
				cout<<"temp="<<temp<<endl;
				cout<<"taken="<<taken<<endl;
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
			if(i!=output)
			{
				table[i]=table[i]-no_of_records;
				t=t+size[i];
			}
		}
		table[output]=no_of_records;
		size[output]=t;
		table[index]=size[index]=0;
		
		file[output].close();
		file[output].open(name[output],ios::in);
		file[index].close();
		file[index].open(name[index],ios::out);
		
		output=index;
		
		Polyphase(file,name,s,k,table,size,output);
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
	
	for(i=0;i<7;i++)
	{
		Read(fin,ram,no);
		sort(ram,ram+no);
		Write(file[0],ram,no);
	}
	
	for(i=0;i<6;i++)
	{
		Read(fin,ram,no);
		sort(ram,ram+no);
		Write(file[1],ram,no);
	}
	
	for(i=0;i<4;i++)
	{
		Read(fin,ram,no);
		sort(ram,ram+no);
		Write(file[2],ram,no);
	}
	
	fin.close();
	
	for(i=0;i<=k;i++)
	file[i].close();
	
	for(i=0;i<k;i++)
	file[i].open(name[i],ios::in);
	
	file[k].open(name[k],ios::out);
	
	table[0]=7;
	table[1]=6;
	table[2]=4;
	table[3]=0;
	
	size[0]=size[1]=size[2]=s;
	size[3]=0;
	
	Polyphase(file,name,s,k,table,size,k);
	
	for(i=0;i<=k;i++)
	file[i].close();
}
