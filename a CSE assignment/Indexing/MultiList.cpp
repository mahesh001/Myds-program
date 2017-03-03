#include<iostream>
#include<fstream>
using namespace std;

struct student
{
	char rollno[6];
	char cname[6];
	char fc[4];
	char bc[4];
	char fr[4];
	char br[4];
};

void Pack(char *buffer,student S)
{
	int i;
	int len=strlen(S.rollno);
	strcpy(buffer,S.rollno);
	for(i=len;i<=5;i++)
	buffer[i]=' ';
	len=strlen(S.cname);
	strcat(buffer,S.cname);
	for(i=4+len;i<=10;i++)
	buffer[i]=' ';
}

void Insert(fstream data,char *buffer,int data_index,int rno_index, )
{
	
}

int main()
{
	student S;
	
	fstream data;
	data.open("student_data.txt",ios::out|ios::in);
	fstream rollno;
	rollno.open("rollno.txt",ios::out|ios::in);
	fstream cname;
	cname.open("cname.txt",ios::out|ios::in);
	
	char ans;
	char buffer[50];
	int data_index=0,rno_index=0,cname_index=0;
	
	do
	{
		cout<<"Enter rollno\n";u
		cin>>S.rollno;
		cout<<"Enter course name\n";
		cin>>S.cname;
		Pack(buffer,S);
		Insert(data,buffer);
	}while(ans=='y');
}
