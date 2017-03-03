#include<iostream>
using namespace std;

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

int isEmpty(int **A,int N)
{
	int i;
	for(i=1;(i<=N && A[i][0]==-1);i++);
	if(i>N)
	return 1;
	else
	return 0;
}

void Remove(int **A,int k,int N)
{
	cout<<"inside_remove\n";
	A[k][0]=-1;
	for(int i=1;i<=N;i++)
	A[k][i]=0;
}

int Indegree_zero(int **A,int k,int N)
{
	int i;
	for(i=1;i<=N && A[i][k]==0;i++);
	
	
	if(i>N)
	return 1;
	else
	return 0;
}

void show_array(int *O,int oi)
{
	for(int i=0;i<=oi;i++)
	cout<<O[i]<<" ";
}

void Topological_sort(int** A,int *O,int &oi,int N)
{
	int i;
	for(i=1;i<=N;i++)
	{
		cout<<"inside for "<<i<<endl;
		if(A[i][0]!=-1 && Indegree_zero(A,i,N))
		{
			O[++oi]=i;
		}
	}
	cout<<"here_1\n";
	if(oi==-1)
	{
		cout<<"Topological sort not possible\n";
		return;
	}
	
	show_array(O,oi);
	
	for(i=oi;(i>=0 && O[i]!=-1);i--)
	Remove(A,O[i],N);
	cout<<"here_2\n";
	O[++oi]=-1;
	cout<<"here_3\n";
	if(!isEmpty(A,N))
	{
	   cout<<"Again calling\n";
	   Topological_sort(A,O,N,oi);
	}
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

int main()
{
	int N,i,j;
	cout<<"Enter the no of vertex\n";
	cin>>N;
	char *V,ans;
	V=new char[2*N];
	int oi=-1;
	int *O;
	O=new int[2*N];
	
	int** A;      //creating dynamic array
	A=new int*[N+1];
	for(i=0;i<=(N+1);i++)
	A[i]=new int[N+1];
	
	Initi(A,N);  //Initiallizing all to 0
	
	cout<<"Enter vertics\n";
	for(i=1;i<=N;i++)
	{
		cin>>V[i];
	}
	cout<<"Enter the adjacent as (u,v) where v is adjacent of u\n";
	do
	{
		char u,v;
		int ui,vi;
		cin>>u>>v;
		ui=Find_index(V,u,N);
		vi=Find_index(V,v,N);
		cout<<"ui="<<ui<<" vi="<<vi<<endl;
		A[ui][vi]=1;
		cout<<"Want to enter more y or n\n";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	
	cout<<"Topological sorting\n";
	Topological_sort(A,O,oi,N);
	
	cout<<"Sort\n";
	for(i=0;i<=oi;i++)
	{
		if(O[i]!=-1)
		cout<<V[O[i]]<<" ";
	}
}
