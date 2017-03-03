#include <iostream>
#include<string>
using namespace std;

int main()
{
	string a,b,c,d,e;
	
	cout<<"enter the namwe";
	cin>>a;
	cout<<"enter surname";
	cin>>b;
	
	if(a.length()<=7)
	{	d=b[0];
		c=a+d;
	}
	else if(a.length()>=7 && b.length()<=7)
	{
		d=a[0];
		c=d+b;
	}
	else if(a.length()>=7 && b.length()>=7)
	{
		d=a[0];
		e=b[0];
		c=d+e;
	}
	else if(a.length()<=4 && b.length()<=4)
	{
		c=a+b;
	}
	
	cout<<"the modified name is\n";
	cout<<c;
	
	return 0;
}
	
	
	
	

