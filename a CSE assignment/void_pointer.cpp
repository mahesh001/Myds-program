#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	void *ptr;
	ptr=new int;
	cout<<"Enter the no\n";
	cin>>*(int *)ptr;
	
	cout<<"You entered: ";
	cout<<*(int *)ptr;
}
