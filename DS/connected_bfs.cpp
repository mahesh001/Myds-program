# include<iostream>
using namespace std;
# define max 100
# define initial 1
# define waiting 2
# define visited 3
int n;
int state[max];
int adj[max][max];
int q[max];
int label[max];
int front=-1, rear=-1;

void create_graph()
{
	int i, max_edges, origin, destin;
	cout<<"\n enter no of nodes \n ";
	cin>>n;
	max_edges=(n*(n-1))/2;
	for(i=1;i<=max_edges;i++)
	{
		cout<<"\n enter edges \n ";
		cin>>origin>>destin;
		if(origin==-1 && destin==-1)
		break;
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			cout<<"\n invalid edges \n ";
			i--;
		}
		else
		adj[origin][destin]=1;
		adj[destin][origin]=1;
	}
}


void insert_q(int vertex)

{
	if(rear==max-1)
	cout<<"\n q izz full \n ";
	else
	if(front==-1)
	front=0;
	rear=rear+1;
	q[rear]=vertex;
}

int is_empty()
{
	if(front==-1 || front>rear)
	return 1;
	else
	return 0;
}

int del_item()
{
	int item;
	if(front==-1 || front>rear)
	{
		cout<<"\n q izz empty \n ";
	}
	item=q[front];
	front=front+1;
	return item;
	
}


void bfs(int v, int components_num)
{
	int i;
	insert_q(v);
	state[v]=waiting;
	while(!is_empty())
	{
		v=del_item();
		cout<<v<<" ";
		state[v]=visited;
		label[v]=components_num;
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1 && state[i]==initial)
			{
				insert_q(i);
				state[i]=waiting;
			}
		}
	}
}

void bf_traversal()
{
	int v, components=0;
	for(v=0;v<n;v++)
	state[v]=initial;
	components++;
	bfs(0,components);
	for(v=0;v<n;v++)
	{
		if(state[v]==initial)
		{
			components++;
			bfs(v,components);
		}
	}
		cout<<"\n number of connected components izz \n "<<components<<endl;
		if(components==1)
	cout<<"\n graph izz connected \n ";
	else
	cout<<"\n graph izz nt connected \n ";
}


int main()
{
	create_graph();
	bf_traversal();
}
