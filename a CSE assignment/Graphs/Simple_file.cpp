#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int all_tag_zero(int *tag,int k)
{
	int i;
	for(i=0;i<=k;i++)
	{
		if(tag[i]==1)
		break;
	}
	if(i>k)
	return 1;
	else
	return 0;
}

int file_empty(ifstream & file)
{
	int i;
	file>>i;
	int t;
	
	t=file.eof();
	
	if(t==0)
	file.seekg(0,ios::beg);
	
	return t;
}

int main()
{
	int tag[4]={0,0,0,0};
	
	if(all_tag_zero(tag,4))
	cout<<"true\n";
	else
	cout<<"false\n";
}
