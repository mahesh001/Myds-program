#include<iostream>
#include<cstring>
using namespace std;
char alpha[]={'a','b','c',' '};

struct trie
{
	
	trie(){
		l=0;
		for(int i=0;i<4;i++)
		ptr[i]=	NULL;
	}
	int l;
	char str[8];
	trie *ptr[4];
};

int Find_index(char *str,char k)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(str[i]==k)
		break;
	}
	if(i>=4)
	return -1;
	else
	return i;
}

void Insert(trie* &T,char *in,int &si)
{
	int i,len=strlen(in),index;
	index=Find_index(alpha,in[si]);
	
	if(T->ptr[index]==NULL)
	{
		trie *temp=T->ptr[index];
		temp=new trie;
		temp->l=1;
		strcpy(temp->str,in);
	}
	else if(T->ptr[index]->l==1)
	{
		trie *temp=T->ptr[index];
		T->ptr[index]=new trie;
		T->ptr[index]->ptr[Find_index(alpha,temp->str[si+1])]=temp;
		
		trie *new_t=new trie;
		new_t->l=1;
		strcpy(new_t->str,in);
		T->ptr[index]->ptr[Find_index(alpha,new_t->str[si+1])]=new_t;
	}
	else
	{
		Insert(T,in,++si);
	}
}

int main()
{
	int si;
	trie *T=new trie;
	cout<<"Enter word to insert\n";
	char in[8];
	while(1)
	{
		si=0;
		cout<<"/ to stop\n";
		cin>>in;
		if(in[0]=='/')
		break;
		Insert(T,in,si);
	}
}

