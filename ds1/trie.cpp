#include<iostream>
#include<cstring>
using namespace std;
struct trie;
struct node
{	char a[26];
	trie* l[27];
	trie* last;
};
union uni
{	
	node p;
	int rptr;
};
struct trie
{	
	int tag;
	uni u;
} *tr;
int search(int n,char a[])
{	int i,count=0;char c,str[20];
	int k;
	do
	{	k=0;
	for(i=0;i<n;i++)
		{
			if(c==a[i])
			{	k++;
				cin>>c;
			}
			else
				break;
		}
	if(k==n)
		count++;
	cin.getline(str,20);
	}while(cin>>c);	
	if(count>1)
		return 1;
	return 0;	
}
int insert(char a[],int n)
{
	int i,count=0;
	char str[20],c;
	cin.getline(str,20);
		if(strlen(str)==n)
		for(i=0;i<n;i++)
			{
				if(str[i]==a[i]);	
				else
					break;
			}
		if(i==n)
			return count;
	cin.getline(str,20);
	count++;
	
}
trie* nonleaf()
{
	trie* t=new trie;
	t->tag=1;
	int i=0;
	char c='a';
	while(i<26)
	{	t->u.p.last=NULL;
		t->u.p.l[i]=NULL;
		t->u.p.a[i]=c;
		c++;i++;
	}
	return t;
}
trie* leaf(char a[],int n)
{	trie* t=new trie;
	int k;
	k=insert(a,n);
	t->u.rptr=k;
	t->tag=0;
	return t;
}
int get(char c[],trie* t,int cno)
{
	int i=0;
	while(i<26)
		{
			if(c[cno]==t->u.p.a[i])
			break;
			i++;
		}
		return i;
	}
int main()
{	
    int x;
	char a[20];int flag=1; 
	trie* tr=nonleaf();
	trie* t1=tr;
	trie* t;int ll=0;
	t1=tr;
	cout<<"enter the no of word \n";
	cin>>x;
	cout<<"enter the word else press 0\n";
	for(int i=0;i<x;i++)
		cin.getline(a,20);
		cout<<a;
		int n=strlen(a);
		cout<<n;
		int k=0;
		int p1=get(a,t1,k);
		cout<<a[0]<<"   "<<p1<<endl;
		cout<<k<<endl;
		while(k<n)
		{	 
			if(t1->u.p.l[p1]==NULL)
			{
				if(!search(k+1,a))
				{	
					 t=leaf(a,n);
					t1->u.p.l[p1]=t;
					break;
				}
				else
				{
					cout<<endl;
					flag=1;
					t=nonleaf();
					t1->u.p.l[p1]=t;
					t1=t;
					k++;
					p1=get(a,t,k);
					cout<<p1<<"    "<<k<<endl;
					while(k<n)
					{	flag=1;
						cout<<endl;
						cout<<k;
						if(search(k+1,a))
						{
							t=nonleaf();
							t1->u.p.l[p1]=t;
							cout<<t1->u.p.a[p1]<<"  "<<p1<<endl;
							t1=t;
							k++;
						}
						else
						{
							t=leaf(a,n);
							t1->u.p.l[p1]=t;
							cout<<t1->u.p.a[p1]<<"   "<<endl;
							t1=t;
							int flag=0;
							break;
						}
							p1=get(a,t,k);
							cout<<"P1==="<<p1;
							cout<<"k==="<<k;
					}
					break;			
					}
					break;
			}
			else
			{	k++;
				trie* t2=t1;
				trie* t3;
						t1=t1->u.p.l[p1];
						p1=get(a,t1,k);
				while(t1->u.p.l[p1]!=NULL )
					{
						cout<<n<<"=="<<k;
						if(k<n)
						{	if(t1->tag==1)
							{
								t1=t1->u.p.l[p1];
								k++;
								p1=get(a,t1,k);
								cout<<a[1];
								cout<<p1<<endl;
							}
							else
							{
								 while(k<n)
								 {
								 	
								 }
							}
						}
						else
						{
							t=leaf(a,n);
							cout<<t->u.rptr;
							t1->u.p.last=t;
							if(t1->u.p.last==t)
								cout<<"  ";
							break;
						}
					}
					while(k<n)
					{
						k++;
						t=nonleaf();
						t1=t1->u.p.l[p1];
						t1=t;
						p1=get(a,t1,k);
					}
				break;	
			}
				break;
			}	
	ll++;

	return 0;

}
