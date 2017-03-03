#include<iostream>
#include<cstring>
using namespace std;

class TextIndex
{
	public :
	TextIndex()
	{
		Maxkeys=100;
		Numkeys=0;
		keys=new char*[Maxkeys];
		for(int i=0;i<Maxkeys;i++)
		{
			keys[i]=new char[10];
		}
		recadd= new int[Maxkeys];
	}
	private :
		int Maxkeys;
		int Numkeys;
		char **keys;
		int *recadd;
		int isgrater(char *k1,char *k2);
		void shiftdown(int index);
	public :
		void insert(char *key,int rcno);
		int search(char *key);
		void print();
};

class Record
{
	private :
		char idno[5];
		char labal[10];
		char title[20];
	public :
		void pack(ofstream &fout);
		void unpack(ifstream& fin);
};

int TextIndex::isgrater(char *k1,char *k2)
{
	int l1=strlen(k1);
	int l2=strlen(k2);
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

void TextIndex::print()
{
	for(int i=0;i<Numkeys;i++)
	{
		cout<<keys[i]<<" "<<recadd[i]<<endl;
	}
}

void TextIndex::shiftdown(int index)
{
	for(int i=Numkeys;i>=index;i--)
	{
		strcpy(keys[i+1],keys[i]);
		recadd[i+1]=recadd[i];
	}
}

void TextIndex::insert(char *key,int rcno)
{
	if(Numkeys==0)
	{
		strcpy(keys[Numkeys],key);
		recadd[Numkeys]=rcno;
		Numkeys++;
	}
	else
	{
		int i=0;
		while(isgrater(key,keys[i]))
		{
			i++;
		}
		shiftdown(i);
		Numkeys++;
		strcpy(keys[i],key);
		recadd[i]=rcno;
	}
}

int main()
{
	TextIndex test;
	char name[20];
	int no;
	for(int i=0;i<3;i++)
	{
		cout<<"Enter the Record\n";
		cin>>name;
		cin>>no;
		test.insert(name,no);
	}
	cout<<"Records are \n";
	test.print();
}
