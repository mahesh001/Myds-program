#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
union u
{
	char mob[13];
	char room[5];
};
class student
{
	char rno[5];
	char *name;
	char cgpa[4];
	int size;
	u detail;

  public:
  		char buffer1[60];
  		char buffer2[60];
  		int l;

void pack(char* buffer,char* field)
{//cout<<"hello";
	strcat(buffer,field);
	strcat(buffer,"|");
}
void addrecord()
{
	int n;
	flush(buffer1);	flush(buffer2);
		cout<<"\n1.mob no\n2.room no\n";
	cin>>l;
	if(l==1)
	{
		cout<<"\nenter mobile no\n";
		cin>>detail.mob;
		pack(buffer1,detail.mob);
	}
		if(l==2)
	{
		cout<<"\nenter room no\n";
		cin>>detail.room;
		pack(buffer2,detail.room);
	}
	cout<<"enter the size of the name\n";
	cin>>n;
	name=new char[n];
	cout<<"\nnow enter the name\n";
	cin>>name;
	if(l==1)
	pack(buffer1,name);
	else
	pack(buffer2,name);
	cout<<"\nenter the roll no\n";
	cin>>rno;
		if(l==1)
	pack(buffer1,rno);
	else
	pack(buffer2,rno);
	cout<<"\nenter the cgpa\n";
	cin>>cgpa;
		if(l==1)
	pack(buffer1,cgpa);
	else
	pack(buffer2,cgpa);
	if(l==1)
	strcat(buffer1,"#");
	else
	strcat(buffer2,"#");
}
void unpack(char* buffer)
{
	int i;
	int l=strlen(buffer);
	for(i=0;buffer[i]!='#';i++)
	{
		if(buffer[i]=='|')
		{
			cout<<endl;continue;
		}
		cout<<buffer[i];
	}
}
void flush(char* buffer)
{
	strcpy(buffer,"\0");
}
};
int main()
{
	student s;
	int n,i;
	cout<<"\nhow many records you want to store\n";
	cin>>n;
	ofstream fout1("f111.txt");
	ofstream fout2("f112.txt");
	for(i=0;i<n;i++)
	{
	s.addrecord();
	if(s.l==1)
	fout1<<s.buffer1<<endl;
	else if(s.l==2)
	fout2<<s.buffer2<<endl;
    } 
	fout1.close();
	fout2.close();
}

