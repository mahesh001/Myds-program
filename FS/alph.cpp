#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>
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
{	int i,count=0;char c;
	ifstream fin;char str[20];
	fin.open("data.txt");
	fin>>c;	
	int k;
	do
	{	k=0;//cout<<c<<endl;
	for(i=0;i<n;i++)
		{	//cout<<"hii"<<endl;
			if(c==a[i])
			{	k++;
				fin>>c;
			}
			else
				break;
		}
		//cout<<"k=="<<k<<endl;
	if(k==n)
		count++;//cout<<"count=="<<count<<endl;
	fin.getline(str,20);
	}while(fin>>c);	//cout<<count;
	if(count>1)
		return 1;
	return 0;	
}
int index(char a[],int n)
{	ifstream f;
	f.open("data.txt");
	int i,count=0;
	char str[20],c;
	f.getline(str,20);
	while(!f.eof())
	{	if(strlen(str)==n)
		for(i=0;i<n;i++)
			{
				if(str[i]==a[i]);	
				else
					break;
			}
		if(i==n)
			return count;
	f.getline(str,20);
	count++;
	}
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
	k=index(a,n);
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

	char a[20];int flag=1;
	trie* tr=nonleaf();
	//cout<<tr->u.rptr;
	ifstream fin;
	fin.open("data.txt");
	trie* t1=tr;
	trie* t;int ll=0;
	while(/*ll<4*/!fin.eof())
	{	t1=tr;
		fin.getline(a,20);
		//fin.getline(a,20);
		cout<<a;
		int n=strlen(a);
		cout<<n;
		int k=0;
		int p1=get(a,t1,k);
		cout<<a[0]<<"   "<<p1<<endl;
		//search(3,a);
		cout<<"loool"<<k<<endl;
		while(k<n)
		{	 
			if(t1->u.p.l[p1]==NULL)
			{	cout<<"hello"<<endl;
				if(!search(k+1,a))
				{	cout<<"are"<<endl;
					 t=leaf(a,n);
					t1->u.p.l[p1]=t;
					break;
				}
				else
				{
					cout<<"wow"<<endl;
					flag=1;
					t=nonleaf();
					t1->u.p.l[p1]=t;
					//cout<<t1->u.p.a[p1]<<"aaaa";
					t1=t;
					k++;
					p1=get(a,t,k);
					cout<<p1<<"    "<<k<<endl;
					while(k<n)
					{	flag=1;
						cout<<"lol"<<endl;
						//cout<<search(k+1,a);
						cout<<k;
						if(search(k+1,a))
						{	cout<<"y000";
							t=nonleaf();
							t1->u.p.l[p1]=t;
							cout<<t1->u.p.a[p1]<<"  "<<p1<<endl;
							t1=t;
							k++;
						}//k++;
						else
						{	cout<<"thuuu";
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
			{	k++;// cout<<endl<<k<<"woowwowowowow "<<p1<<n<<endl;
				trie* t2=t1;
				trie* t3;
				/*while(t1->u.p.l[p1]!=NULL)
					{ cout<<"pooo";
					t1=t1->u.p.l[p1];
							k++;
						p1=get(a,t1,k);
						cout<<p1<<"   "<<k;
					}
					cout<<p1; 
					if(t1->u.p.l[p1]==NULL)
						cout<<"ayyo";*/
						t1=t1->u.p.l[p1];
						p1=get(a,t1,k);
				while(t1->u.p.l[p1]!=NULL )
					{	//t1=t1->u.p.l[p1]
						cout<<n<<"=="<<k;
						if(k<n)
						{	if(t1->tag==1)
							{
								t1=t1->u.p.l[p1];
								k++;
								p1=get(a,t1,k);
								cout<<a[1];
								cout<<p1<<"wtffff"<<endl;
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
							cout<<"fghj";
							t=leaf(a,n);
							cout<<t->u.rptr;//<<
							//if(t1->u.p.last==NULL)
								//cout<<"LOL";
							t1->u.p.last=t;
							if(t1->u.p.last==t)
								cout<<"LOL";
							break;
						}
					}
					while(k<n)
					{	cout<<"eeeek";
						k++;cout<<"ssejkh";
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
}
	//cout<<tr->u.p.l[2]->u.p.l[0]->u.p.last->u.rptr;//<<tr->u.p.l[1]->u.p.l[8]->tag;
	/*cout<<"   "<<tr->u.p.l[0]->u.rptr<<"yoooo    ";
	trie* x=tr->u.p.l[2];
	cout<<tr->u.p.l[0]->u.rptr;
	cout<<x->u.p.a[0];
	cout<<x->u.p.l[0]->u.p.a[17];
	cout<<x->u.p.l[0]->u.p.l[17]->u.p.a[17];
	cout<<x->u.p.l[0]->u.p.l[17]->u.p.l[17]->u.rptr;
	trie* y=tr->u.p.l[1];
	cout<<"      "<<endl<<y->u.p.l[20]->u.rptr;*/
	//cout<<x->u.p.a[];*/
	return 0;

}
