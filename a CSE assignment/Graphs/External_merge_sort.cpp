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


void showfile(ifstream &file)
{
	int t;
	cout<<"File is : ";
	file>>t;
	while(!file.eof())
	{
		cout<<t<<" ";
		file>>t;
	}
	cout<<endl;
	file.seekg(0,ios::beg);
}

void Read(ifstream &file,int ram[],int &no)
{
	int i;
	for(i=0;i<4 && !file.eof();i++)
	file>>ram[i];
	no=i;
}

void Write(ofstream &file,int ram[],int no)
{
	for(int i=0;i<no;i++)
	file<<ram[i]<<" ";
}

int file_empty(ifstream & file)
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

int min(int *no,int *tag,int *count,int k,int s,int &taken)
{
	int i,t=10000;
	for(i=0;i<k;i++)
	{
		if(tag[i]==1 && no[i]<t && count[i]<s)
		{
			t=no[i];
			taken=i;
		}
	}
	return t;
}

int count_fine(int *count,int s,int k)
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
	cout<<"External_sort\n";
	
	int i,j;
	ifstream *fin=new ifstream[k];
	ofstream *fout=new ofstream[k];
	
	if(l==0)  //open file depanding value of l
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
	
	cout<<"after opening of file\n";
	
	int *tag=new int[k];
	int *no=new int[k];
	int mini;
	
	for(i=0;i<k;i++)
	{
		if(file_empty(fin[i]))  //if file is empty then tag is 0
		tag[i]=0;
		else
		tag[i]=1;
	}
	
	cout<<"tag are : ";
	show_array(tag,k);
	cout<<"After show array\n";
	
	if(tag[1]==1)
	{
		cout<<"Main_step\n";
		
		int point=0;
		int taken;     //taken is index of file form which next no has to be read
		int *count=new int[k];
		for(i=0;i<k;i++)
		count[i]=0;
		
		while(!all_empty(tag,k))
		{
			cout<<"inside_while\n";
			
			for(i=0;i<k;i++)
			{
				if(tag[i]==1)
				fin[i]>>no[i];
			}
			
			for(i=0;i<(s*k) && !all_empty(tag,k) && count_fine(count,s,k);i++)
			{	
				mini=min(no,tag,count,k,s,taken);
				fout[point]<<mini<<" ";          //write mini into output file
				
				count[taken]++;
				
				if(file_empty(fin[taken]))
				tag[taken]=0;
				else if(count[taken]<s)
				fin[taken]>>no[taken];
			}
			
			for(i=0;i<k;i++)
			count[i]=0;
			
			point=(point+1)%k;  //it is index of output file in which we are going to write min no
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
		
		External_sort(name_a,name_b,s*k,k,(l+1)%2,final);  //recursive call
	
	}
}

int main()
{
	int ram[4],s,k,i,j,point=0,no;
	
	cout<<"Enter the value of s \n";
	cin>>s;
	
	char data_file[20];
	cout<<"Enter the name of data file\n";
	cin>>data_file;
	
	ifstream dfile;
	dfile.open(data_file);
	
	cout<<"Enter the value of no of file\n";
	cin>>k;
	char **name_a=new char*[k];
	char **name_b=new char*[k];
	for(i=0;i<k;i++)
	{
		name_a[i]=new char[20];
		name_b[i]=new char[20];
	}
	
	cout<<"Enter names of file of a\n";
	for(i=0;i<k;i++)
	cin>>name_a[i];
	
	cout<<"Enter names of file of b\n";
	for(i=0;i<k;i++)
	cin>>name_b[i];
	
	ofstream *a=new ofstream[k];
	
	for(i=0;i<k;i++)
	a[i].open(name_a[i]);
	
//	cout<<"The datafile is :\n";
//	showfile(dfile);
	
	while(!dfile.eof())
	{
		Read(dfile,ram,no);
		cout<<"no is ="<<no<<endl;
		sort(ram,ram+no);
		show_array(ram,no);
		Write(a[point],ram,no);
		point=(point+1)%k;
	}
	
	dfile.close();
	
	//for(i=0;i<k;i++)
	//showfile(a[i]);
	
	for(i=0;i<k;i++)
	a[i].close();
	
	//delete [] a;
	
	char final[20];
	External_sort(name_a,name_b,4,k,0,final);
	
	ifstream fin;
	ofstream fout;
	fin.open(final);
	fout.open(data_file);
	
	fin>>i;
	while(!fin.eof())
	{
		fout<<i<<" ";
		fin>>i;
	}
	
	fin.close();
	fout.close();
}
