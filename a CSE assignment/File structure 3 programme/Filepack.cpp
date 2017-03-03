#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
char buff[1000];

void pack(char* buff,char* fld){
	strcat(buff,fld);
	strcat(buff,"|");
}

void unpack(ifstream& fin,char*fld){
	fin.getline(fld,30,'|');
	cout<<fld;
}
struct student{
	char rollno[5];
	char name[15];
	char rank[5];
};
istream& operator>>(istream& cin,student s){
	cout<<"Enter the Rollno\n";
	cin.getline(s.rollno,5);
	pack(buff,s.rollno);
	cout<<"Enter the name\n";
	cin.getline(s.name,15);
	pack(buff,s.name);
	cout<<"Enter the rank\n";
	cin.getline(s.rank,5);
	pack(buff,s.rank);
}

int main(){
	student s[3];
	char ch;
	int size=3,i,k=1;

	for(i=0;i<size;i++){
		strcat(buff,"#");
	    cin>>s[i];
	}
	ofstream fout;
	fout.open("stdDetail.txt");
	if(fout.fail()){
		cout<<"Output opening of file failed";
		exit(1);
	}
	fout<<buff;
	fout.close();
	ifstream fin;
	fin.open("stdDetail.txt");
	while(!fin.eof()){
		fin>>ch;
		if(ch=='#'){
			cout<<k<<" ";
			cout<<"Rollno ";
			unpack(fin,s[k-1].rollno);
			
			cout<<"Name ";
			unpack(fin,s[k-1].name);
			
			cout<<"Rank ";
			unpack(fin,s[k-1].rank);
			cout<<endl;
		}
		ch='l';
		k++;
	}
	fin.close();
	return 0;
}
