#include<iostream>
using namespace std;

class stack{
	public:
		int a[20];
		int top;
	public:
		stack(){
			top=-1;
		}
		int isEmpty(){
			if(top==-1)
			return 1;
			else
			return 0;
		}
		int isFull(){
			if(top==19)
			return 1;
			else
			return 0;
		}
		void push(int ch){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=ch;
		}
		int pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
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

void Initi(int **A,int N)
{
	int i,j;
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
		A[i][j]=0;
	}
}

void DFT(int  **A,int k,int *visited,stack S,int v)
{
	if(visited[k]==0)
	{
		int i;
		S.push(k);
		visited[k]=1;
		for(i=1;i<=v;i++)
		{
			if(A[k][i]!=0)
			DFT(A,i,visited,S,v);
		}
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

void Reverse_grah(int **A,int v)
{
	int i,j;
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			int temp=A[i][j];
			A[i][j]=A[j][i];
			A[j][i]=temp;
		}
	}
}

void printdft(int **A,int k,int *visited,int v)
{
	if(visited[k]==0)
	{
		cout<<k<<" ";
		visited[k]=1;
		for(int i=1;i<=v;i++)
		{
			if(A[k][i]!=0)
			printdft(A,i,visited,v);
		}
	}
}

void strongly_connected(int **A,int v)
{
	stack S;
	int i,j;
	int visited[v];
	for(i=1;i<=v;i++)
	visited[i]=0;
	
	int no[v+1],index=-1;
	while(all_visited(visited,v))
	{
		DFT(A,1,visited,S,v);
		while(!S.isEmpty())
		no[++index]=S.pop();
	}
	
	Reverse_grah(A,v);
	
	for(i=1;i<=v;i++)
	visited[i]=0;
	for(i=v;i>=1;i--)
	{
		if(visited[i]==0)
		printdft(A,i,visited,v);
	}
}

int main()
{
	int v,i,j;
	cout<<"Enter the no of vertex\n";
	cin>>v;
	char *V,ans;
	V=new char[2*v];
	int oi=-1;
	int *O;
	O=new int[2*v];
	
	int** A;      //creating dynamic array
	A=new int*[v+1];
	for(i=0;i<=(v+1);i++)
	A[i]=new int[v+1];
	
	Initi(A,v);  //Initiallizing all to 0
	
	cout<<"Enter vertics\n";
	for(i=1;i<=v;i++)
	{
		cin>>V[i];
	}
	cout<<"Enter the adjacent as (u,v) where v is adjacent of u\n";
	do
	{
		char u,w;
		int ui,vi;
		cin>>u>>w;
		ui=Find_index(V,u,v);
		vi=Find_index(V,w,v);
		cout<<"ui="<<ui<<" vi="<<vi<<endl;
		A[ui][vi]=1;
		cout<<"Want to enter more y or n\n";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	
	strongly_connected(A,v);
}
