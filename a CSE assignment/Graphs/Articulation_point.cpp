#include<iostream>
using namespace std;
int v;

struct lnode
{
	lnode(){
		next=NULL;
	}
	int data;
	lnode *next;
};

void addend(lnode* &N,int k)
{
   lnode *T=new lnode;
   T->data=k;
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

void Init(int **G,int v)
{
	int i,j;
	for(i=0;i<=v;i++)
	{
		for(j=0;j<=v;j++)
		G[i][j]=0;
	}
}

void print(int a[],int v)
{
	for(int i=1;i<=v;i++)
	cout<<a[i]<<" ";
	cout<<"\n";
}

void printlist(lnode *L)
{
	if(L==NULL)
	{
		cout<<"NULL\n";
	}
	else
	{
		while(L!=NULL)
		{
			cout<<L->data<<" ";
			L=L->next;
		}
		cout<<endl;
	}
}

int min(int a,int b)
{
	if(a<=b)
	return a;
	else
	return b;
}

int min(int a,int b,int c)
{
	int temp=min(a,b);
	return min(temp,c);
}

int low_in_list(lnode *L)
{
	if(L==NULL)
	return -1;
	else
	{
		int temp=L->data;
		L=L->next;
		while(L!=NULL)
		{
			if(L->data<temp)
			temp=L->data;
			L=L->next;
		}
		return temp;
	}
}

int min(lnode* &te,lnode* &be,int n)
{
	int t,b;
	t=low_in_list(te);
	b=low_in_list(be);
	
	if(t!=-1 && b!=-1)
	return min(t,b,n);
	else if(t==-1 && b!=-1)
	return min(b,n);
	else if(t!=-1 && b==-1)
	return min(t,n);
	else
	return n;
}



void DFT_num(int **G,int k,int par,int *Num,int &ind,int *visited,int v)
{
	if(visited[k]==0)
	{
		int i;
		Num[k]=++ind;
		
		for(i=1;i<=v;i++)
		{
			if(G[k][i]!=0 && visited[i]==1 && i!=par)  //making back_edge
			G[k][i]=-1;
		}
		
		visited[k]=1;
		for(i=1;i<=v;i++)
		{
			if(G[k][i]!=0)
			{
				DFT_num(G,i,k,Num,ind,visited,v);
			}
		}
	}
}

void DFT_low(int **G,int k,int *Num,int *low,int *visited,int v)
{
	if(visited[k]==0)
	{
		cout<<"dft key = "<<k<<endl;
		int i;
		lnode *te=NULL;
		visited[k]=1;
		for(i=1;i<=v;i++)
		{
			if(G[k][i]!=0 && visited[i]==0)
			{
				cout<<"calling "<<i<<endl;
				addend(te,i);
				DFT_low(G,i,Num,low,visited,v);
			}
		}
		
		lnode *temp=te;
		while(temp!=NULL)
		{
			temp->data=low[temp->data];
			temp=temp->next;
		}
		
		int mini,n=Num[k];
		lnode *be=NULL;
		for(i=1;i<=v;i++)
		{
			if(G[k][i]==-1)
			addend(be,Num[i]);
		}
		
		cout<<"key= "<<k<<endl;
		cout<<"tree_edge low are ";
		printlist(te);
		cout<<"backedge low num are ";
		printlist(be);
		
		mini=min(te,be,n);
		low[k]=mini;
	}
}

void DFT_print(int **G,int k,int par,int Num[],int low[],int visited[],int v)
{
	int i;
	lnode *te=NULL;
	visited[k]=1;
	
	for(i=1;i<=v;i++)
	{
		if(G[k][i]==1 && visited[i]==0)
		{
			addend(te,i);
			DFT_print(G,i,k,Num,low,visited,v);
		}
	}
	
	lnode *temp=te;
	while(temp!=NULL)
	{
		if(low[temp->data]>=Num[k])
		cout<<k<<" ";
		temp=temp->next;
	}
}

void Arti(int **G,int s,int v)
{
	int low[v+1],Num[v+1];
	int i,j,visited[v+1];
	for(i=0;i<=v;i++)
	visited[i]=0;
	
	int ind=0,par=s;
	DFT_num(G,s,par,Num,ind,visited,v);//Numbering vertics
	for(i=0;i<=v;i++)
	visited[i]=0;
	
	DFT_low(G,s,Num,low,visited,v);
	for(i=0;i<=v;i++)
	visited[i]=0;
	
	cout<<"num are : ";
	print(Num,v);
	cout<<"low are : ";
	print(low,v);
	
	cout<<"Articulation point are = ";
	int te=0;
	visited[s]=1;
	for(i=1;i<=v;i++)
	{
		if(G[s][i]==1 && visited[i]==0)
		{
			te++;
			DFT_print(G,i,s,Num,low,visited,v);
		}
	}
	if(te>1)
	cout<<s<<" ";
}
void print_matrix(int **G,int v)
{
	int i,j;
	for(i=0;i<=v;i++)
	{
		for(j=0;j<=v;j++)
		cout<<G[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int i,j;
	cout<<"Enter the no of vertex\n";
	cin>>v;
	
	int** G;      //creating dynamic array
	G=new int*[v+1];
	for(i=0;i<=(v+1);i++)
	G[i]=new int[v+1];
	
	Init(G,v);  //Initiallizing all to 0
	
	cout<<"The matrix is \n";
	print_matrix(G,v);
	
	cout<<"Enter the adjacent as (u,v) where v is adjacent of u\n";
	char ans;
	do
	{
		cout<<"Enter (u,v)\n";
		cin>>i>>j;
		G[i][j]=1;
		G[j][i]=1;
		cout<<"Want to enter more y or n\n";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	
	cout<<"The matrix is \n";
	print_matrix(G,v);
	
	int start;
	cout<<"Enter starting point\n";
	cin>>start;
	
	Arti(G,start,v);
}
