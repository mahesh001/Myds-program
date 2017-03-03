#include<iostream>
using namespace std;

class graph
{
	public :
		graph(){
		}
		
		void Init();  //initilisize matrix
		void add_edge(int a,int b); //to add an edge to graph from a->b
		void remove_edge(int a,int b); //to remove edge from a->b
		void remove(int v);   //remove vertex
		int In_degree(int v);  //return indegree of vertec 'v'
		int Out_degree(int v);  //return outdegree of vertec 'v'
		int In_degree_zero();
		void print();
		
	public :
		int v; //no of vertics
	private :
		int **G; //adjisency matrix
		int *In;  //this array store count of indegree of vertex;
		int *Out;
};

void graph::Init()
{
	int i,j,count_in=0,count_out=0;
			
	G=new int*[v+1];      //creating adjacency matrix
	for(i=0;i<=v;i++)
	G[i]=new int[v+1];
	
	In=new int[v+1];
	Out=new int[v+1];
	
	for(i=0;i<=v;i++)     //initilising adjacency matrix
		for(j=0;j<=v;j++)
		G[i][j]=0;
		
	for(i=1;i<=v;i++)     //initilising In_degree and Out_degree
	{
		count_out=0;
		count_in=0;
		for(j=1;j<=v;j++)
		{
			if(G[i][j]==1)
			count_out++;
			if(G[j][i]==1)
			count_in++;
		}
		Out[i]=count_out;
		In[i]=count_in;
	}
}

int graph::In_degree_zero()
{
	int i;
	for(i=1;i<=v;i++)
	{
		if(In[i]==0)
		break;
	}
	if(i>v)
	return -1;
	else
	return i;
}

void graph::add_edge(int a,int b)  //add an undirected edge
{
	if(G[a][b]==0)
	{
		Out[a]++;
		In[b]++;
	}
	
	G[a][b]=1;
}

void graph::remove_edge(int a,int b)
{
	if(G[a][b]==1)
	{
		Out[a]--;
		In[b]--;
	}
	
	G[a][b]=0;
}

void graph::remove(int a)
{
	for(int i=1;i<=v;i++)	//removeing out degree
	{
		remove_edge(a,i);
	}
	
	G[a][0]=-1;
	In[a]=-1;
	Out[a]=-1;
}

int graph::In_degree(int v)
{
	return In[v];
}

int graph::Out_degree(int v)
{
	return Out[v];
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

void Top_sort(graph &G)
{
	int i,j,vertex;
	
	//find the vetex whose indegree is 0
	for(i=1;i<=G.v;i++)
	{
		vertex=G.In_degree_zero();
		
		if(vertex!=-1)
		{
			cout<<vertex<<" ";
			G.remove(vertex);
		}
	}
}

int main()
{
	graph G;
	
	cout<<"Enter no of vertics \n";
	cin>>G.v;
	
	G.Init();
	
	cout<<"adjicancy matix is :"<<endl;
	G.print();
	
	int i,j;
	cout<<"Enter edges as for a->b enter a,b (-1 to stop) \n";
	cin>>i>>j;
	while(i!=-1)
	{
		G.add_edge(i,j);
		
		cin>>i;
		if(i==-1)
		break;
		cin>>j;
	}
	
	cout<<"adjicancy matix is :"<<endl;
	G.print();
	
	cout<<"Topological sort is : ";
	Top_sort(G);
}
