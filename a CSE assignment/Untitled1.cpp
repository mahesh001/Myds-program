#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int frist,sec,thr;
	ofstream fout;
	ifstream fin;
	fout.open("Frist10.txt");
	fout<<1<<"\n"<<2<<"\n"<<"\n"<<3<<"\n";
	fout.close();
	fin.open("Frist10.txt");
	fin>>frist>>sec>>thr;
	cout<<"Sum of 3 integer is "<<(frist+sec+thr);
	
}
