#include<iostream>
using namespace std;

class heap
{
	public :
};

class set
{
	public:
		set(){
			v=7;
			for(int i=0;i<8;i++)
			a[i]=0;
		}
	private:
		int v;
		int a[8];
	public :
		void uni(int x,int y);
		int find(int x);
};

int set::find(int x)
{
	if(a[x]==0)
	return x;
	else
	return find(a[x]);
}

void set::uni(int x,int y)
{
	if(a[x]==0)
	a[y]=x;
	else if(a[y]==0)
	a[y]=find(x);
	else
	a[find(y)]=find(x);
} 

struct lnode
{
	lnode(){
		next=NULL;
	}
	int s;
	int w;
	int d;
	lnode *next;
};

void addend(lnode* &N,int s,int w,int d)
{
   lnode *T=new lnode;
   T->s=s;
   T->w=w;
   T->d=d;
   if(N==NULL)
   {
	  N=T;	
   }
   else
   {
   	  lnode *temp=N;
   	  while(temp->next!=NULL)
      temp=temp->next;
      temp->next=T;
   }
}

void init(int A[][8],int visited[],int v)
{
	int i,j;
	for(i=0;i<=v;i++)
	{
		for(j=0;j<=v;j++)
		A[i][j]=0;
		
		visited[i]=0;
	}
}

int all_visited(int visited[],int v)
{
	int i;
	for(i=1;i<=v;i++)
	{
		if(visited[i]==0)
		break;
	}
	if(i>v)
	return 1;
	else
	return 0;
}

void print_list(lnode *L)
{
	while(L!=NULL)
	{
		cout<<L->s<<"-"<<L->w<<"-"<<L->d<<endl;
		L=L->next;
	}
}

int main()
{
	int v=7,i,j,c,a,w;
	set S;
	int A[8][8],visited[8];
	init(A,visited,v);
	
	cout<<"Enter ajacenace of vertecs\n";
	for(i=1;i<=v;i++)
	{
		while(1)
		{
			cout<<"Enter -1 to stop\n";
			cout<<"Enter adjacncy of "<<i<<" vertex\n";
			cin>>a;
			if(a==-1)
			break;
			cout<<"Enter weight\n";
			cin>>w;
			A[i][a]=w;
			A[a][i]=w;
		}
	}
	
	cout<<"Enter current vertex\n";
	cin>>c;
	lnode *tree=NULL;
	
	while(!all_visited(visited,v))
	{
		int min=1000,d;
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
			{
				if(S.find(i)!=S.find(j) && A[i][j]!=0 && A[i][j]<min)
				{
					c=i;
					d=j;
					min=A[i][j];
				}
			}
		}
		S.uni(c,d);
		addend(tree,c,min,d);
		visited[d]=1;
	}
	
	cout<<"Minimum spannig tree is\n";
	print_list(tree);
}
