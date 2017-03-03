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

void DFT(graph **G,int k,int *visited,char *V,int v)
{
	if(visited[k]==0)
	{
		cout<<V[k]<<" ";
		visited[k]=1;
		graph *L=G[k];
		while(L!=NULL)
		{
			DFT(G,L->value,visited,V,v);
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
	cout<<"Enter vertex about DFT\n";
	cin>>ans;
	int k=Find_index(O,ans,v);
	int *visited=new int[v+1];
	for(i=0;i<=v;i++)
	visited[i]=0;
	DFT(G,k,visited,O,v);
}
