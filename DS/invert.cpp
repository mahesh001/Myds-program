#include<iostream>
#include<fstream>
using namespace std;
struct student
{ char name[20];
  int rno;
  float cgpa;
  int sno;
};
struct course
{ int no;
  int dur;
  int ino;
};
struct reg
{int ind;
 int rno;
  int no;
  int fptr;
  int bptr;
  int fptr1;
  int bptr1;
};	
ofstream& operator << (ofstream& out, student& st)
	{
	out<<st.rno<<" ";	
	out<<st.name<<" ";
	out<<st.cgpa<<" ";
	out<<st.sno<<endl;
	return out;
	}
ofstream& operator << (ofstream& outt, course& c1)
	{
	outt<<c1.no<<" ";	
	outt<<c1.dur<<" ";
	outt<<c1.ino<<endl;
	return outt;
	}
ifstream& operator >> (ifstream& in, student& st)
	{
	in>>st.rno;
	in>>st.name;
	in>>st.cgpa;
	in>>st.sno;
	return in;
	}
ifstream& operator >> (ifstream& inn, course& c1)
	{
	inn>>c1.no;	
	inn>>c1.dur;
	inn>>c1.ino;
	return inn;
	}
	ifstream& operator >> (ifstream& inn, reg& l)
	{
	inn>>l.ind;	
	inn>>l.rno;
	inn>>l.fptr;
	inn>>l.bptr;	
	inn>>l.no;
	inn>>l.fptr1;
	inn>>l.bptr1;
	return inn;
	}
void search(student& s,int* &p,int& i,reg& l)
{				ifstream in;
		in.open("reg.txt");
		int a; char str[50];
		in>>l;
		reg l2;
		while(l.rno!=s.rno)
		{
			in>>l;
		}
		p[i++]=l.ind;
		if(l.fptr!=-1)
			p[i++]=l.fptr;
		//else
		//	p[i++]=l.ind;

		while(l.fptr!=-1 )
		{
			while(p[i-1]!=l.ind)
				in>>l;
		if(l.fptr!=-1)
			p[i++]=l.fptr;
		//else
		//	p[i++]=l.ind;
		}

}
int main()
{
	ifstream fin;
	int i=0,j=0,f=0,g=0;
	ofstream fout;
	ofstream fout1;
	ofstream fout2;
	fout.open("student.txt");
	fout1.open("course.txt");
	char a='y';
	student s1,s,s2;
	course  c,c1,c2;
	reg r[10];
	for(i=0;i<10;i++)
	{
	 r[i].ind=i;
 	 r[i].fptr=-1;
 	 r[i].bptr=-1;
 	 r[i].fptr1=-1;
 	 r[i].bptr1=-1;
	}
	i=0;
	cout<<"Enter the roll no"<<endl;
		cin>>s1.rno;	
	cout<<"Enter the name ";
		cin>>s1.name;
		cout<<"Enter the cgpa "<<endl;
		cin>>s1.cgpa;
		s1.sno=i;
		i++;
		fout<<s1;
		cout<<"enter course number";
		cin>>c1.no;
		cout<<"course duration";
		cin>>c1.dur;
		c1.ino=j;
		j++;
		fout1<<c1;
	fout2.open("reg.txt");
	int k=0;
	r[k].rno=s1.rno;
	r[k].no=c1.no;
	k++;
	while(a=='y')
	{	ifstream fin,fin1;
		
	cout<<"Enter the roll no"<<endl;
		cin>>s1.rno;
		cout<<"Enter the name ";
		cin>>s1.name;
		cout<<"Enter the cgpa "<<endl;
		cin>>s1.cgpa;
		s1.sno=i;
	fin.open("student.txt");
	fin>>s;
	s2=s;
		while(!fin.eof())
		{ 
		   if(s2.rno==s1.rno)
			{	f=1;
				cout<<"hi";
				break;
			}
			fin>>s;
			s2=s;
		}
		fin.close();
		if(f==0)
		{i++;
		fout<<s1;
		}
		cout<<"enter course number";
		cin>>c1.no;
		cout<<"course duration";
		cin>>c1.dur;
		c1.ino=j;
		fin1.open("course.txt");
		fin1>>c;
		 c2=c;
		while(!fin1.eof())
		{ 
		   if(c2.no==c1.no)
			{	g=1;
				cout<<"hii";
				break;
			}
			fin1>>c;
			c2=c;
		}
		fin1.close();		
		if(g==0)
		{j++;
		fout1<<c1;
		}
	r[k].rno=s1.rno;
	r[k].no=c1.no;
	k++;					
	cout<<"enter y to continue";
	cin>>a;
	}
for(i=0;i<10;i++)
{  for(j=i+1;j<10;j++)
 	{
		if(r[i].rno==r[j].rno)
		{r[i].fptr=r[j].ind;break;}		
	}
}	
for(i=0;i<10;i++)
{  for(j=i+1;j<10;j++)
 	{
		if(r[i].no==r[j].no)
			{r[i].fptr1=r[j].ind;break;}	
	}
}

for(i=0;i<k;i++)
fout2<<r[i].ind<<" "<<r[i].rno<<" "<<r[i].fptr<<" "<<r[i].bptr<<" "<<r[i].no<<" "<<r[i].fptr1<<" "<<r[i].bptr1<<endl;	
	fout2.close();
	ifstream finn,fin2;
finn.open("reg.txt");
fin2.open("student.txt");
ofstream f1;
f1.open("invert.txt");
reg l;//student s;
fin2>>s;
finn>>l;
while(!fin2.eof())
	{
	int* p=new int(20);int z=0;
		f1<<s.rno<<"---";
		search(s,p,z,l);
		for(int i=0;i<z;i++)
			f1<<p[i]<<" ";
		f1<<endl;
		fin2>>s;
	}
return 0;
}
