#include<iostream>
using namespace std;

class graph
{
	public :
		void Init();  //initilisize matrix
		void add_edge(int a,int b,int w); //to add an edge to graph from a->b
		void print();
	public :
		int v; //no of vertics
	private :
		int **G; //adjisency matrix
};

void graph::add_edge(int a,int b,int w)  //add an undirected edge
{
	G[a][b]=G[b][a]=w;
}

void graph::Init()
{
	int i,j;
			
	G=new int*[v+1];      //creating adjacency matrix
	for(i=0;i<=v;i++)
	G[i]=new int[v+1];
	
	for(i=0;i<=v;i++)     //initilising adjacency matrix
		for(j=0;j<=v;j++)
		G[i][j]=0;
}

void graph::print()
{
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		cout<<G[i][j]<<" ";
		
		cout<<endl;
	}
}

class heap
{
	public :
		heap(){
			index=0;
		}
		void Insert(int w,int a,int b);   //insert a into the heap
		int min(int& s,int& d);            //delete and return min element in the heap
		void print();
	private :
		int index;  //no of vertics
		int A[20];
		int S[20];
		int D[20];
};

void heap::print()
{
	for(int i=1;i<=index;i++)
	cout<<S[i]<<"->"<<D[i]<<"="<<A[i]<<"\n";
}

void heap::Insert(int w,int a,int b)
{
	index++;
	
	int i=index;
	
	while(i>1 && w<A[i/2])
	{
		A[i]=A[i/2];
		S[i]=S[i/2];
		D[i]=D[i/2];
		i=i/2;
	}
	A[i]=w;
	S[i]=a;
	D[i]=b;
}

int heap::min(int& s,int& d)
{
	int mini=A[1],temp=A[index],ts=S[index],td=D[index];
	index--;
	
	s=S[1];
	d=D[1];
	
	int i=1;
	while(i<=index/2)
	{
		if(A[2*i]<A[2*i+1])
		{
			if(temp<A[2*i])
			break;
			else
			{
				A[i]=A[2*i];
				S[i]=S[2*i];
				D[i]=D[2*i];
				i=2*i;
			}
		}
		else
		{
			if(temp<A[2*i+1])
			break;
			else
			{
				A[i]=A[2*i+1];
				S[i]=S[2*i+1];
				D[i]=D[2*i+1];
				i=2*i+1;
			}
		}
	}
	
	A[i]=temp;
	S[i]=ts;
	D[i]=td;
	
	return mini;
}

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

void print_list(lnode *L)
{
	while(L!=NULL)
	{
		cout<<L->s<<"->"<<L->d<<"="<<L->w<<endl;
		L=L->next;
	}
}

int set::find(int x)
{
	if(a[x]==0)
	return x;
	else
	return find(a[x]);
}

void set::uni(int x,int y)
{
	if(a[y]==0)
	a[y]=x;
	else if(a[x]==0)
	a[x]=y;
	else
	a[find(y)]=find(x);
}

int main()
{
	int a,b,w;
	graph G;
	heap H;
	set S;
	lnode *L=NULL;
	cout<<"Enter the no of vertices\n";
	cin>>G.v;
	
	G.Init();
	
	cout<<"Enter edge as a->b (a,b) with w weight Enter -1 to stop\n";
	cin>>a>>b>>w;
	while(a!=-1)
	{
		G.add_edge(a,b,w);
		H.Insert(w,a,b);
		cin>>a;
		if(a==-1)
		break;
		cin>>b>>w;
	}
	
	cout<<"The adjecency matrix is \n";
	G.print();
	cout<<"The heap is \n";
	H.print();
	
	int s,d,edge_accepted=0;
	
	while(edge_accepted<(G.v-1))
	{
		w=H.min(s,d);
		cout<<s<<" "<<d<<endl;
		if(S.find(s)!=S.find(d))
		{
			addend(L,s,w,d);
			S.uni(s,d);
			edge_accepted++;
		}
	}
	
	cout<<"the minimum spanning tree is :\n";
	print_list(L);
}

