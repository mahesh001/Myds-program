
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

class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=20;
	}
	private:
		int front;
		int rear;
		int size;
		int element[20];
		
	public:
		int isfull();
		int isempty();
		void enqueue(int k);
		int dequeue();
};

int Queue::isfull()
{
	if((rear+1)%size==front)
	 return 1;
	else
	 return 0;
}

int Queue::isempty()
{
	if(front==-1)
	 return 1;
	else
	 return 0;
}

void Queue::enqueue(int k)
{
	if(isfull())
	  cout<<"Queue is full\n";
	else if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear=(rear+1)%size;
	}
	element[rear]=k;
}

int Queue::dequeue()
{
	int t;
	if(isempty())
	  return -1;
	else
	{
		if(front==rear)
		{
		  t=element[front];
		  front=-1;
		  rear=-1;	
		}
		else
		{
			t=element[front];
			front=(front+1)%size;
		}
		return t;
	}
}

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

void BFT(graph **G,int vertice,char O[],int v)
{
	Queue Q;
	graph *L;
	int i;
	int *visited=new int[v+1];
	for(i=0;i<=v;i++)
	visited[i]=0;
	cout<<O[vertice]<<endl;
	Q.enqueue(vertice);
	visited[vertice]=1;
	Q.enqueue(-1);
	while(!Q.isempty())
	{
		int temp=Q.dequeue();
		if(temp==-1)
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(-1);
		}
		else
		{
			L=G[temp];
			while(L!=NULL)
			{
				if(visited[L->value]!=1)
		    	{
		    		cout<<O[L->value]<<" ";
		    		visited[L->value]=1;
		    		Q.enqueue(L->value);
		    	}
		    	L=L->next;
			}
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
	//print_graph(G,O,v);
	cout<<"Enter the vertice about which you want BFT\n";
	cin>>ans;
	int vertice=Find_index(O,ans,v);
	BFT(G,vertice,O,v);
}
