#include<iostream>
#include<string>
using namespace std;

int operator > (string k1,string k2)
{
	int l1=k1.length();
	int l2=k2.length();
	int min;
	if(l1>l2)
	min=l2;
	else
	min=l1;
	int i;
	for(i=0;i<min;i++)
	{
		if(k1[i]!=k2[i])
		break;
	}
	if(i!=min)
	{
		if(k1[i]>k2[i])
		return 1;
		else
		return 0;
	}
	else
	{
		if(l1>l2)
		return 1;
		else
		return 0;
	}
}

int main()
{
	string k1,k2;
	cout<<"Enter the strings\n";
	cin>>k1>>k2;
	if(k1>k2)
	cout<<"k1 is grater then k2\n";
	else
	cout<<"k2 is grater then k1\n";
}
