#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct student
{
	char rollno[6];
	char cname[6];
	int fc;
	int bc;
	int fr;
	int br;
};

struct rno
{
	int rollno;
	int offset;
};

struct cname
{
	char cname[6];
	int offset;
};

int Search_in_rollno(rno rno_file[],int k,int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		if(rno_file[mid].rollno==k)
		return mid;
		else if(k>rno_file[mid].rollno)
		Search_in_rollno(rno_file,k,mid+1,h);
		else
		Search_in_rollno(rno_file,k,l,mid-1);
	}
	else
	return -1;
}

void Read_rno_file(ifstream &fin_rno,rno rno_file[])
{
	int rollno,offset,index=-1;
	char rno[6],off[6];
	for(int i=0;i<5;i++)
	{
		fin_rno>>rollno;
		itoa(rollno,rno,10);
		fin_rno.seekg(5-strlen(rno),ios::cur);
		fin_rno>>offset;
		itoa(offset,off,10);
		fin_rno.seekg(5-strlen(off),ios::cur);
		
		rno_file[++index].rollno=rollno;
		rno_file[index].offset=offset;
	}
}

void Read_cname_file(ifstream &fin_cname,cname cname_file[])
{
	char cname[6],off[6];
	int offset,index=-1;
	for(int i=0;i<5;i++)
	{
		fin_cname>>cname;
		fin_cname.seekg(5-strlen(cname),ios::cur);
		fin_cname>>offset;
		itoa(offset,off,10);
		fin_cname.seekg(5-strlen(off),ios::cur);
		
		strcpy(cname_file[++index].cname,cname);
		cname_file[index].offset=offset;
	}
}

void Read_Direct(fstream &data,int index,student S)
{
	char temp[4];
	data.seekg(index*22,ios::beg);
	data>>S.rollno;
	int len=strlen(S.rollno);
	data.seekg(5-len,ios::cur);
	data>>S.cname;
	len=strlen(S.cname);
	data.seekg(5-len,ios::cur);
	data>>S.fr;
	//len=strlen(temp);
	//data.seekg(3-len,ios::cur);
	data>>S.br;
	//len=strlen(temp);
	//data.seekg(3-len,ios::cur);
	data>>S.fc;
	//len=strlen(temp);
	//data.seekg(3-len,ios::cur);
	data>>S.bc;
	//len=strlen(temp);
	//data.seekg(3-len,ios::cur);
}

void Find_Records(fstream &data,int index)
{
	student S;
	Read_Direct(data,index,S);
	while(S.fr!=-1)
	{
		cout<<"Rollno = "<<S.rollno<<endl;
		cout<<"Course name = "<<S.cname<<endl;
		index=S.fr;
		Read_Direct(data,index,S);
	}
}

int main()
{
	rno rno_file[5];
	cname cname_file[5];
	
	ifstream fin_rno,fin_cname;
	fin_rno.open("rno.txt");
	fin_cname.open("cname.txt");
	fstream data;
	data.open("std_data.txt",ios::in|ios::out);
	
	Read_rno_file(fin_rno,rno_file);
	Read_cname_file(fin_cname,cname_file);
	
	cout<<"Enter the rollno\n";
	int k;
	cin>>k;
	int index=Search_in_rollno(rno_file,k,0,5);
	Find_Records(data,index);
	
	
	cout<<"Enter course name\n";
	char cno[6];
	cin>>cno;
}
