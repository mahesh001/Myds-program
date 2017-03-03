#include<iostream>
using namespace std;
struct H{
			int hours;
			char salary[5];
		};
struct M{
			char salary[5];
		};
union type{
		H h;
		M m;
	};
struct Employ{
	char employno[5];
	char name[20];
	int tag;//1 for hourly and 2 for monthly
	type tp;
};
int main()
{
	Employ E;
	cout<<"Enter employno\n";
	cin>>E.employno;
	cout<<"Enter name\n";
	cin>>E.name;
	cout<<"Enter it is hourly or monthly base\n (for hourly 1 and for monthly 2)\n";
	cin>>E.tag;
	if(E.tag==1)
	{
		cout<<"Enter no of hours employ work\n";
		cin>>E.tp.h.hours;
		cout<<"Enter salary\n";
		cin>>E.tp.h.salary;
	}
	else if(E.tag==2){
		cout<<"Enter the salary\n";
		cin>>E.tp.m.salary;
	}
	cout<<"your Record is: \n";
	cout<<"Employno: "<<E.employno<<endl;
	cout<<"Employ name: "<<E.name<<endl;
	if(E.tag==1){
	cout<<"No of hours employ work = "<<E.tp.h.hours<<" Salary= "<<E.tp.h.salary<<endl;
    }
	else if(E.tag==2){
	cout<<"Salary= "<<E.tp.m.salary<<endl;
    }
}
