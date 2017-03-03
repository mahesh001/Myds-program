#include<iostream>
using namespace std;

int Hunt(char **A,int &t,int x,int y,int &N,int &end)
{
	if(end==1)
	return 0;
	if(x==(N-1)&&y==(N-1))
	{
		end=1;
		return 0;
	}
	if(A[x][y]=='*')
	t++;
	int a,b,ta,tb;
	if(x<=N-1)
	a=Hunt(A,t,x+1,y,N,end);
	ta=t;
	if(y<=N-1)
	b=Hunt(A,t,x,y+1,N,end);
	tb=t;
	if(a>b)
	return a+1;
	else if(b>a)
	return b+1;
	else if(a==b&&ta>tb)
	return a+1;
	else
	return b+1;
}

int main()
{
	char **a;
	int input,N,t,len,end;
	cin>>input;
	while(input>=0)
	{
		cin>>N;
		a=new char*[N];
		for(int i=0;i<N;i++)
		{
			a[i]=new char[N];
			for(int j=0;j<N;j++)
			cin>>a[i][j];
		}
		len=Hunt(a,t,0,0,N,end);
		if(end!=1)
		cout<<"-1";
		else
		cout<<len;
	}
}
