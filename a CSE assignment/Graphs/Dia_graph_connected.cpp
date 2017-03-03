#include<iostream>
using namespace std;

struct graph
{
	graph(){
		next=NULL;
	}
	int value;
	graph *next;
};

int Find_index(char *V,char k,int N)
{
	int i;
	for(i=1;i<=N;i++)
	{
		if(V[i]==k)
		break;
	}
	if(i>N)
	return -1;
	else
	return i;
}

void addend(graph* &L,int k)
{
	if(L==NULL)
	{
		L=new graph;
		L->value=k;
		return;
	}
	graph *T=L;
	while(T->next!=NULL)
	T=T->next;
	T->next=new graph;
	T=T->next;
	T->value=k;
}

void print(graph *L,char *O)
{
	while(L!=NULL)
	{
		cout<<O[L->value]<<" ";
		L=L->next;
	}
	cout<<endl;
}

void print_graph(graph **G,char *O,int v)
{
	for(int i=1;i<=v;i++)
	{
		cout<<O[i]<<"-> ";
		print(G[i],O);
	}
}

void DFT(graph **G,int k,int *visited,int v)
{
	if(visited[k]==0)
	{
		visited[k]=1;
		graph *L=G[k];
		while(L!=NULL)
		{
			DFT(G,L->value,visited,v);
			L=L->next;
		}
	}
}

void inti(int *visited,int v)
{
	for(int i=0;i<=v;i++)
	visited[i]=0;
}

int all_visited(int *visited,int v)
{
	int i;
	for(i=1;(i<=v && visited[i]==1);i++);
	if(i>v)
	return 1;
	else
	return 0;
}

int connected(graph** G,int v)
{
	int i;
	int *visited=new int[v+1];
	inti(visited,v);
	
	for(i=1;i<=v;i++)
	{
		DFT(G,i,visited,v);
		if(!all_visited(visited,v))
		break;
		inti(visited,v);
	}
	if(i>v)
	return 1;
	else
	return 0;
}

int search(graph *L,int k)
{
	while(L!=NULL && L->value!=k)
	L=L->next;
	if(L==NULL)
	return 0;
	else
	return 1;
}

void convert_into_undia(graph **G,int v)
{
	for(int i=1;i<=v;i++)
	{
		graph *L=G[i];
		while(L!=NULL)
		{
			if(!search(G[L->value],i))
			addend(G[L->value],i);
			L=L->next;
		}
	}
}

int main()
{
	int v,i;
	char ans;
	cout<<"Enter no of vertics\n";
	cin>>v;
	graph **G;   //creating graph with dynamic array
	G=new graph*[v+1];
	
	for(i=0;i<=v;i++)  //Initilising
	G[i]=NULL;
	
	char *O;
	O=new char[v+1];
	cout<<"Enter vertices\n";
	for(i=1;i<=v;i++)
	cin>>O[i];
	
	for(i=1;i<=v;i++)
	{
		int index;
		cout<<"Enter ajacency of "<<O[i]<<" / to stop\n";
		cin>>ans;
		while(ans!='/')
		{
			index=Find_index(O,ans,v);
			addend(G[i],index);
			cin>>ans;
		}
	}
	print_graph(G,O,v);
	/*convert_into_undia(G,v);
	print_graph(G,O,v);*/
	if(connected(G,v))
	cout<<"graph is strongly connected\n";
	else
	{
		convert_into_undia(G,v);
		if(connected(G,v))
		cout<<"graph is weakly connected\n";
		else
		cout<<"graph is unconnected\n";
	}
	
}
