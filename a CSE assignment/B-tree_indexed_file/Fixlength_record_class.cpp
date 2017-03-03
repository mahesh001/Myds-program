#include<iostream>
#include<cstring>
using namespace std;

struct record
{
	char rollno[6];
	char name[16];
};

class Fixlength_record
{
	public :
		Fixlength_record(){
			Currindex=Nextindex=0;
		}
		void Insert(char *buffer,char *rollno,char *name);
	private :
		int Currindex;
		int Nextindex;
};

void Fixlength_record::Insert(char *buffer,char *rollno,char *name)
{
	int i,len=strlen(rollno);
	
	strcpy(buffer,rollno);
	Currindex=len;
	Nextindex=6;
	
	for(i=Currindex;i<Nextindex;i++)
	buffer[i]='*';
	
	len=strlen(name);
	strncpy(&buffer[5],name,len);
	Currindex=5+len;
	Nextindex=21;
	
	for(i=Currindex;i<Nextindex;i++)
	buffer[i]='*';
	
	buffer[20]=0;
}

int main()
{
	Fixlength_record fixlength;
	
	char buffer[30];
	record student;
	
	cin>>student.rollno;
	cin>>student.name;
	
	fixlength.Insert(buffer,student.rollno,student.name);
	
	cout<<"Buffer="<<buffer<<"Thats_all\n";
}
