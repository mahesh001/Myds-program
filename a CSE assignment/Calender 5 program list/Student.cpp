#include<iostream>
using namespace std;
struct student
{
	int Rollno;
	char Name[15];
	double CGPA;
};
student getStdDetail(){
	student temp;
	cout<<"Enter student Rollno name and CGPA\n";
	cin>>temp.Rollno>>temp.Name>>temp.CGPA;
	return temp;
}
int avg(student stdList[],int size){
	int sum=0;
	for(int i=0;i<size;i++){
		sum=sum+stdList[i].CGPA;
	}
	return sum/size;
}
int main(){
	int average;
	student stdList[10];
	for(int i=0;i<10;i++){
		stdList[i]=getStdDetail();
	}
	average=avg(stdList,10);
	cout<<"The average of CGPA of student is "<<average<<endl;
	return 0;
}
