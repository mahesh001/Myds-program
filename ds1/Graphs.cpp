#include<iostream>
using namespace std;
int **A;
int n;
class queue
{
	public:
		int size;
		int e[50];
		int front;
		int rear;
		queue(int s)
		{
			size=s;
			front=-1;
			rear=-1;
		}
		bool isEmpty();
		void enqueue(int);
		int dequeue();
};
bool queue::isEmpty()
{
	return (front==-1);
}
void queue::enqueue(int x)
{
	if(front==-1)
		front++;
	rear=(rear+1)%size;
	e[rear]=x;
}
int queue::dequeue()
{
	int x=e[front];
	if(front==rear)
	{
		front=rear=-1;
		return x;
	}
	else
	{
		front=(front+1)%size;
		return x;
	}
}
void getdata()
{
	ifstream fin;
	fin.open("Input.txt");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin>>A[i][j];
}
void display()
{
	cout<<"\n\nEntered Adjacency Matrix:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
}
void degree()
{
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
			if(A[i][j]>0)
				count++;
		cout<<"Degree Of Vertex "<<i+1<<":"<<count<<endl;
	}
}
void bft()
{
	int visited[n];
	queue q(10);
	
	q.enqueue(0);
	visited[0]=1;
	while(!q.isEmpty())
	{
		int u=q.dequeue();
		cout<<char(u+65)<<" ";
		for(int v=0;v<n;v++)
			if(A[u][v]>0 && visited[v]!=1)
			{
				q.enqueue(v);	
				visited[v]=1;
			}
	}
}
int visited[5];
void dft(int u)
{
	cout<<(char)(u+65)<<" ";
	visited[u]=1;
	
	for(int v=0;v<n;v++)
		if(A[u][v]>0&&visited[v]!=1)
			dft(v);
}
int main()
{
	
	cout<<"Enter the Number Of vertices:";
	cin>>n;
	

	A=new int*[n];
	for(int i=0;i<n;i++)
		A[i]=new int[n];
		
	getdata();	
	display();
	
	int u;
	cout<<"\nEnter The Starting Point For BFT:";
	cin>>u;
	cout<<"\n******Breadth First Traversal******\n";
	bft();
	cout<<"\nEnter The Starting Point For DFT:";
	cin>>u;
	cout<<"\n******Depth First Traversal******\n";
	dft(u);
	return 0;
}
