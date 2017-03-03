#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char buff[100];
int z;
struct data
{
	char roll[7];
	char name[11];
	char cgpa[5];
};
int compare(char x, char y)
{
	if(y>x)
		return 1;
	else if (x>y) return -1;
	else return 0;
}
struct record
{
	int l;
	char cgpa[5];
};
void pack(data E)
{
	int i=0;
	buff[0]='\0';
	strcat(buff,E.roll);
	for(i=strlen(E.roll);i<7;++i)
	strcat(buff," ");
	strcat(buff,E.name);
	for(i=strlen(E.name);i<11;++i)
	strcat(buff," ");
	strcat(buff,E.cgpa);
	for(i=strlen(E.cgpa);i<5;++i)
	strcat(buff," ");
}
void unpack(istream &in, data &E)
{
	int i;char ch;
	/*in.getline(E.roll,7,' ');
	in.getline(E.name,7,' ');
	in.getline(E.cgpa,5,' ');*/
	in>>E.roll;
	in>>E.name;
	in>>E.cgpa;

}
ostream &operator<<(ostream &out, data &E)
{
	out<<E.roll<<endl;
	out<<E.name<<endl;
	out<<E.cgpa<<endl;
}
istream &operator>>(istream &in, data &E)
{
    cout<<"Enter Roll Number, Name and CGPA";
    in>>E.roll>>E.name>>E.cgpa;
}
int main()
{
	data D[5],d;
	record r[5];
	int i,j,k,flag;
	ifstream fin;
	ofstream fout;
	fout.open("len1.txt");
	cout<<"Enter five students detail";
	for( i=0;i<5;++i)
	{
	    cin>>D[0];
	    pack(D[0]);
	    fout<<buff;
	}
	fout.close();
	fin.open("len1.txt");
	for(i=0;i<5;++i)
	{
		unpack(fin,D[i]);
	}
	fin.close();
	for(k=0;k<5;++k)
	{  for(i=k+1;i<5;++i)
	   {
		flag=0;
		for(j=0;j<4;++j)
		{
	
				flag=compare(D[k].cgpa[j], D[i].cgpa[j]);
			    if(flag==1)
				{
					break;
				}
			else if(flag==-1)
				break;
		}
		if(flag==1)
		{
			strcpy(d.roll,D[i].roll);
			strcpy(d.name,D[i].name);
			strcpy(d.cgpa,D[i].cgpa);
			strcpy(D[i].roll,D[k].roll);
			strcpy(D[i].name,D[k].name);
			strcpy(D[i].cgpa,D[k].cgpa);
			strcpy(D[k].roll,d.roll);
			strcpy(D[k].name,d.name);
			strcpy(D[k].cgpa,d.cgpa);
		}
	   }
	   strcpy(r[k].cgpa,D[k].cgpa);
	}
	for(i=0;i<5;++i)
	{
		cout<<D[i];
	}
	fout.open("len2.txt");
	for(i=0;i<5;++i)
	{
		pack(D[i]);
		fout<<buff;
	}
	fout.close();
	fin.open("len1.txt");
	for(i=0;i<5;++i)
	{
		unpack(fin,D[i]);
	}
	fin.close();
	for(i=0;i<5;++i)
	{
		for(j=0;j<5;++j)
		{
			if(!strcmp(r[i].cgpa,D[j].cgpa))
			{
				r[i].l=j+1;
				break;
			}

		}
	}
	fout.open("len3.txt");
	for(i=0;i<5;++i)
	{
		fout<<r[i].l<<endl;
		fout<<r[i].cgpa<<endl;
	}
	fout.close();
	cin>>i;

}