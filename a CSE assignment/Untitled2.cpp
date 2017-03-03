#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	int a,b,c;
	char d;
	ofstream fout;
	ifstream fin;
	fout.open("Frist10.txt",ios::app);

	fout.close();
	fin.open("Frist10.txt");
	fin>>a>>b>>c;
	cout<<a<<b<<c;
	while(!fin.eof()){
	fin.get(d);
	cout<<d;
}
	
}
