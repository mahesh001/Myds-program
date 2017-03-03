#include<iostream>
using namespace std;

void Init(int **G,int v)
{ int visited[20];
	int i,j;
	for(i=0;i<=v;i++)
	{
		for(j=0;j<=v;j++)
		A[i][j]=0;
		
		visited[i]=0;
	}
}

int main()
{
	int i,j,v;
	cout<<"Enter the no of vertex\n";
	cin>>v;
	
	int** G;             //creating dynamic array
	G=new int*[v+1];
	for(i=0;i<=(v+1);i++)
	G[i]=new int[v+1];
	
	int *visited=new int[v+1];
	
	Initi(G,visited,v);  //Initiallizing all to 0
	
	cout<<"Enter the adjacent as (u,v) where v is adjacent of u\n";
	int i,j;
	char ans;
	do
	{
		cout<<"Enter (u,v)\n";
		cin>>i>>j;
		A[i][j]=1;
		A[j][i]=1;
		cout<<"Want to enter more y or n\n";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	
	int start;
	cout<<"Enter starting point\n";
	cin>>start;
	
	
}
