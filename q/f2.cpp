#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
struct game
{
	char gem[10];
};
class student
{
	char rno[5];
	char *name;
	char cgpa[4];
	int size;
	game* g;

  public:
  		char buffer[60];
/*int findsize(char* buffer,char* name,char* rno,char* cgpa)
{
	int l1=strlen(name);
	int l2=strlen(rno);
	int l3=strlen(cgpa);
	int n=l1+l2+l3+4;
	buffer=new char[n];
	return n;
}
*/	
void pack(char* buffer,char* field)
{//cout<<"hello";
	strcat(buffer,field);
	strcat(buffer,"|");
}
void addrecord()
{
	int n,c,d;
	flush(buffer);
	cout<<"enter the size of the name\n";
	cin>>n;
	name=new char[n];
	cout<<"\nnow enter the name\n";
	cin>>name;
	pack(buffer,name);
	cout<<"\nenter the roll no\n";
	cin>>rno;pack(buffer,rno);
	cout<<"\nenter the cgpa\n";
	cin>>cgpa;pack(buffer,cgpa);
	cout<<"\ndo u play any gem\n1.for yes\n2.for no";
	cin>>c;
	if(c==1)
	{
		cout<<"how many gems do u play\n";
		cin>>d;
		g=new game[d];
		for(int i=0;i<d;i++)
		{
			cout<<"mention game "<<i+1;
			cin>>g[i].gem;
			pack(buffer,g[i].gem);
		}
	}
	else
	{
		cout<<"\ngood beta\n";
	}	
	strcat(buffer,"#");
	
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
	ofstream fout1("f21.txt");
	/*ofstream fout2("f22.txt");
	fout2<<1<<endl;
	fout2<<1<<endl;
	fout2<<10<<endl;
	fout2.close();*/
	ifstream fin2("f22.txt");int k=0;
	while(!fin2.eof())
	{int d,i;
		fin2>>d;
		for(i=0;i<d;i++)
		{
			
			s.addrecord();
			fout1<<s.buffer;
		}
	}
	cout<<k;
	//fout1.close();
	fin2.close();
}

