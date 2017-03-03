#include<iostream>
using namespace std;
int main()
{
	int *p1,*p2;
	p1=new int;
	*p1=4;
     p2=p1;
	cout<<*p1<<*p2;
	delete p1;
	cout<<*p2;
}
