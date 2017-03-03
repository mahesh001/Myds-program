#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct student
{
	char rollno[5];
	char name[20];
	char branch[5];
};

void prints(ofstream &fout,int n)
{
	for(int i=0;i<n;i++)
	fout<<"*";
}
int main()
{
	student S;
	/*ofstream fout;
	fout.open("nitin.txt");
	
	for(int i=0;i<2;i++)
	{
		int len;
		cout<<"Enter the rollno\n";
		cin>>S.rollno;
		len=strlen(S.rollno);
		fout<<S.rollno;
		prints(fout,(4-len));
		cout<<"Enter the name\n";
		cin>>S.name;
		fout<<S.name;
		len=strlen(S.name);
		prints(fout,(19-len));
		cout<<"Enter branch\n";
		cin>>S.branch;
		fout<<S.branch;
		len=strlen(S.branch);
		prints(fout,(4-len));
	}*/
	ifstream fin;
	fin.open("nitin.txt");
	if(fin.fail())
	cout<<"fail\n";
	while(!fin.eof())
	{
		char fld[20],ch;
		int temp;
		/*fin>>ch;
		if(fin.fail())
		break;
		else
		{
		  fin.putback(ch);
		  fin.seekg(-1,ios::cur);
	    }*/ 
		fin.getline(fld,20,'*');
		cout<<fld<<" ";
		temp=strlen(fld);
		fin.seekg((4-temp),ios::cur);
		fin.getline(fld,20,'*');
		cout<<fld<<" ";
		temp=strlen(fld);
		fin.seekg((19-temp),ios::cur);
		fin.getline(fld,20,'*');
		cout<<fld<<" ";
		temp=strlen(fld);
		fin.seekg((4-temp),ios::cur);
	}
}
