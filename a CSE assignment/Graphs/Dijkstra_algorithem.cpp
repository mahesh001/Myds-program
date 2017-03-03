#include<iostream>
using namespace std;

void inti(int A[][8],int v)
{
	int i,j;
	for(i=0;i<=v;i++)
	{
		for(j=0;j<=v;j++)
		A[i][j]=0;
	}
}
int main()

{
	int v=7,i,j,a,w;
	int visited[8],pv[8],dis[8];
	int c,d;
	
	int A[8][8];
	inti(A,v);
	
	for(i=1;i<=v;i++)
	{
		dis[i]=1000;
		visited[i]=0;
	}
	
	cout<<"Enter ajacenace of vertecs\n";
	for(i=1;i<=v;i++)
	{
		while(1)
		{
			cout<<"Enter / to stop\n";
			cout<<"Enter adjacncy of "<<i<<" vertex\n";
			cin>>a;
			if(a=='/')
			break;
			cout<<"Enter weight\n";
			cin>>w;
			A[i][a]=w;
		}
	}
	cout<<"Enter current vertex\n";
	cin>>c;
	cout<<"Enter destination vertex\n";
	cin>>d;
	
	visited[c]=1;
	pv[c]=c;
	dis[c]=0;
	
	while(c!=d)
	{
		for(i=1;i<=v;i++)
		{
			if(visited[i]!=1 && A[c][i]!=0 && dis[i]>(dis[c]+A[c][i]))
			{
				dis[i]=dis[c]+A[c][i];
				pv[i]=c;
			}
		}
		
		int min=1000,t,j;
		for(i=1;i<=v;i++)
		{
			if(visited[i]==0 && dis[i]<min)
			{
				min=dis[i];
				c=i;
			}
		}

		visited[c]=1;
	}
	
	cout<<"Shortest path is\n";
	while(c!=pv[c])
	{
		cout<<c<<"->";
		c=pv[c];
	}
	cout<<c;

return 0;
}
