#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
static int k=0;
static int t=0;
class student
{
	char rno[5];
	char name[10];
	char age[5];

  public:
  char buffer[40];
	

void addrecord()
{
	int n;
	flush(buffer);
	cout<<"enter the size of the name\n";
	cin>>n;
	cout<<"\nnow enter the name\n";
	cin>>name;
	pack(buffer,name);
	cout<<"\nenter the roll no\n";
	cin>>rno;pack(buffer,rno);
	cout<<"\nenter the cgpa\n";
	//cin>>cgpa;pack(buffer,cgpa);
	strcat(buffer,"#");
	
}
void pack(char* buffer,char* field)
{   if(k%3==0)
     flush(buffer);
	strcat(buffer,field);
	strcat(buffer,"|");
	k++;
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

class fix :public student
{
	char *name;
	char rno[5];
	char cgpa[4];
	public:
		char buffer1[40];
		void flush(char* buffer)
{
	strcpy(buffer,"\0");
}
		void add()
{
	int n;
	flush(buffer1);
	cout<<"enter the size of the name\n";
	cin>>n;
	name=new char[n];
	cout<<"\nnow enter the name\n";
	cin>>name;
	pack(buffer1,name);
	cout<<"\nenter the roll no\n";
	cin>>rno;pack(buffer1,rno);
	cout<<"\nenter the cgpa\n";
	cin>>cgpa;pack(buffer1,cgpa);
	strcat(buffer1,"#");
	
}
void pack(char* buffer1,char* field)
{   if(t%3==0)
     flush(buffer1);
	strcat(buffer1,field);
	strcat(buffer1,"|");
	t++;
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
};

int main()
{
	student s;
	fix f;int i,g=0;
	char sd[12][40];
	int j;
	ifstream fin1("f11.txt");
	ofstream fout("f112.txt");

    while(!fin1.eof())
    {
    	fin1.getline(sd[g],35,'#');
    	g++;
    }
    
    for(i=0;i<g-1;i++)
    {  
        if(sd[i][0]!='@')
    	fout<<i+1<<" ";
    
	   for(j=i+1;j<g-1;j++)
       { 
       	if(sd[j][0]!='@')
       	{
       	if(strcmp(sd[i],sd[j])==0)
       	{ fout<<j+1<<" ";
       	   sd[j][0]='@';
       	   }
       }
        }
    	fout<<endl;
    }
    fin1.close();
    fout.close();

		


}

