#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
char buff[100];
struct B{
	char dur[4];
	char branch[5];
};
struct M{
	char dur[4];
};
union u1{
	B b;
	M m;
};
struct stdengg{
	int tag;
	char rollno[5];
	char name[20];
	u1 type;
};
struct GNM{
	char dur[4];
	char branch[5];
};
struct MBBS{
	char dur[4];
};
union u2{
	GNM g;
	MBBS mb;
};
struct stdmed{
	int tag;
	char rollno[5];
	char name[20];
	u2  type;
};

void pack(ofstream& fout,stdengg SE)
{
	strcpy(buff,"\0");
	strcat(buff,SE.rollno);
	strcat(buff,"|");
	strcat(buff,SE.name);
	strcat(buff,"|");
	if(SE.tag==1)
	{
		strcat(buff,SE.type.b.dur);
		strcat(buff,"|");
		strcat(buff,SE.type.b.branch);
		strcat(buff,"|");
	}
	else
	{
		strcat(buff,SE.type.m.dur);
		strcat(buff,"|");
	}
	strcat(buff,"#");
	fout<<buff;
}

void pack(ofstream& fout,stdmed SM)
{
	strcpy(buff,"\0");
	strcat(buff,SM.rollno);
	strcat(buff,"|");
	strcat(buff,SM.name);
	strcat(buff,"|");
	if(SM.tag==1)
	{
		strcat(buff,SM.type.g.dur);
		strcat(buff,"|");
		strcat(buff,SM.type.g.branch);
		strcat(buff,"|");
	}
	else
	{
		strcat(buff,SM.type.mb.dur);
		strcat(buff,"|");
	}
	strcat(buff,"#");
	fout<<buff;
}

void Merge(ifstream& fin1,ifstream& fin2,ofstream& fout)
{
	int roll1,roll2;
	char fld1[30],fld2[30],record[100],ch;
	fin1.getline(fld1,30,'|');
	roll1=atoi(fld1);
	fin2.getline(fld2,30,'|');
	roll2=atoi(fld2);
	if(roll1<roll2)
	{
		fout<<fld1;
		while(fin1.peek()!='@')
		{
			fin1.getline(record,100,'#');
			fout<<record<<"#";
		}
		fout<<fld2;
		while(fin2.peek()!='@')
		{
			fin2.getline(record,100,'#');
			fout<<record<<"#";
		}
	}
	else
	{
		fout<<fld2;
		while(fin2.peek()!='@')
		{
			fin2.getline(record,100,'#');
			fout<<record<<"#";
		}
		fout<<fld1;
		while(fin1.peek()!='@')
		{
			fin1.getline(record,100,'#');
			fout<<record<<"#";
		}
	}
}
int main()
{
	stdengg SE[3];
	stdmed  SM[3];
	int i,t;
	ofstream fout1("enggstd.txt"),fout2("medstd.txt");
	if(fout1.fail()||fout2.fail())
	cout<<"File opening fail\n";
	
	cout<<"Enter the details of 3 engg std (1 for btech and 2 for Mtech)\n";
	for(i=0;i<3;i++)
	{
		cout<<"Enter the tag\n";
		cin>>t;
		SE[i].tag=t;
		cout<<"Enter the rollno\n";
		cin>>SE[i].rollno;
		cout<<"Enter the name\n";
		cin>>SE[i].name;
		if(t==1)
		{
		   cout<<"Enter duration and branch\n";
		   cin>>SE[i].type.b.dur;
		   cin>>SE[i].type.b.branch;	
		}
		else if(t==2)
		{
			cout<<"Enter the duration\n";
			cin>>SE[i].type.m.dur;
		}
		pack(fout1,SE[i]);
	}
	fout1<<"@";
	fout1.close();
	cout<<"Enter details of Medical std (1 for GNM and 2 for MBBS)\n";
	for(i=0;i<3;i++)
	{
		cout<<"Enter the tag\n";
		cin>>t;
		SM[i].tag=t;
		cout<<"Enter the rollno\n";
		cin>>SM[i].rollno;
		cout<<"Enter the name\n";
		cin>>SM[i].name;
		if(t==1)
		{
		   cout<<"Enter duration and branch\n";
		   cin>>SM[i].type.g.dur;
		   cin>>SM[i].type.g.branch;	
		}
		else if(t==2)
		{
			cout<<"Enter the duration\n";
			cin>>SM[i].type.mb.dur;
		}
		pack(fout2,SM[i]);
	}
	fout2<<"@";
	fout2.close();
	
	ifstream fin1("enggstd.txt"),fin2("medstd.txt");
	ofstream fout("mixstd.txt");
	if(fin1.fail()||fin2.fail()||fout.fail())
	cout<<"File opening fail\n";
	Merge(fin1,fin2,fout);
	fout<<"@";
	fin1.close();
	fin2.close();
	fout.close();
	return 0;
}
