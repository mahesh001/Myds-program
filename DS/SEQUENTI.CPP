#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
class buffer
{
private:
	int next;
public:
	char buff[25];
	buffer();
	void pack(char []);
	void unpack(char []);
};
buffer::buffer()
{
	buff[0]='\0';
	next=0;
}
void buffer::pack(char a[])
{
	strcat(buff,a);
	strcat(buff,"|");
}
void buffer::unpack(char b[])
{
	int c=0;
		while(buff[next]!='|')
		b[c++]=buff[next++];
	b[c]='\0';
	next++;
}
class student
{
char name[20];
char rno[5];
public:
	void add();
	void read();
	void search();
};
void student::add()
{
	buffer b1;
	//student s1;
	fstream file1;
	cout<<"Enter the name of the student:";
	cin>>name;
	b1.pack(name);
	cout<<"Enter roll number of the student:";
	cin>>rno;
	b1.pack(rno);
	file1.open("data.cpp",ios::app);
	file1.write((char *)&b1,sizeof(b1));
	file1.close();
}
void student::read()
{
	buffer b2;
	//student s2;
	fstream file2;
	file2.open("data.cpp",ios::in);
       //	file2.read((char *)&b2,sizeof(b2));
	while(file2.read((char *)&b2,sizeof(b2)))
	{
	       //	file2.read((char *)&b2,sizeof(b2));
		b2.unpack(name);
		b2.unpack(rno);
		cout<<"\n"<<name<<"\t"<<rno<<endl;
		//file2.read((char *)&b2,sizeof(b2));
	}
	file2.close();
}
void student::search()
{
	char a[10];
	cout<<"Enter roll number of the student:\n";
	cin>>a;
	buffer b3;
	int c;
	student s3;
	fstream file3;
	file3.open("data.cpp",ios::in);
	file3.read((char *)&b3,sizeof(b3));
	while(!file3.eof())
	{
		b3.unpack(s3.name);
		b3.unpack(s3.rno);
		if(strcmp(s3.rno,a)==0)
		{
			c=1;
			cout<<"Record found!\n";
			cout<<s3.rno<<"\t"<<s3.name<<endl;
			return;
		}
		else
			file3.read((char *)&b3,sizeof(b3));
	}
	if(c!=1)
		cout<<"Record not found!\n";
	file3.close();
}
int main()
{
	int k;
	char c;
	student s;
	do
	{
		cout<<"Enter ur choice:\n";
		cout<<"1-ADD  2-READ  3-SEARCH 4-EXIT \n";
		cin>>k;
		switch(k)
		{
			case 1:
				s.add();
				break;
			case 2:
				s.read();
				break;
			case 3:
				s.search();
				break;
			default:
				return 0;
		}
		cout<<"Want to do again press y:\n";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}

