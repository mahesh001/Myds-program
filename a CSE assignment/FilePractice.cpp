#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;
void make_neat(ifstream& messy_file,ofstream& neat_file,int no_after_decimal,int width);

int main(){
	ifstream fin;
	ofstream fout;
	fin.open("Messy_file.dat");
	if(fin.fail()){
		cout<<"File opening failed\n";
		exit(1);
	}
	fout.open("neat_file.dat");
	if(fout.fail()){
		cout<<"File opening failed\n";
		exit(1);
	}
	make_neat(fin,fout,5,12);
}
void make_neat(ifstream& messy_file,ofstream& neat_file,int no_after_decimal,int width){
	double next;
	neat_file.setf(ios::fixed);
	neat_file.setf(ios::showpoint);
	neat_file.setf(ios::showpos);
	neat_file.precision(no_after_decimal);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout.precision(no_after_decimal);
	while(messy_file>>next){
		cout<<setw(width)<<next<<endl;
		neat_file<<setw(width)<<next<<endl;
	}
}
