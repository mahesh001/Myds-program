#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
const int big=2147483647;
int n;
struct vertex
{
int data;
int flag;
int dis;
vertex * next;
vertex()
{
data=-1;
flag=0;
dis=0;
next=NULL;
}	
};
struct arrele
{
int data;
int vis;
int dis;
int via;
arrele()
{
	data=-1;
	vis=0;
	dis=big;
	via=-1;
}
};	
void constg(vertex * g[])
{
	vertex * temp=NULL,*temp1=NULL;
	int c,dis=0;
for(int i=0;i<n;i++)
{
	cout<<"ENter the vertex \n";
	cin>>c;
	temp=new(vertex);
	temp->data=c;
	g[i]=temp;
}
for(int i=0;i<n;i++)
{
	temp1=g[i];
	cout<<"enter the neighbor of "<<g[i]->data<<"\n";
	cin>>c;
	cout<<"ENter the distance between "<<g[i]->data<<" and "<<c<<"\n";
	cin>>dis;
	for(int j=0;c!=-1;j++)
	{
		temp=new(vertex);
		temp->data=c;
		temp->dis=dis;
		temp1->next=temp;
		temp1=temp;
		cin>>c;
		if(c!=-1)
		{
		cout<<"ENter the distance between "<<g[i]->data<<" and "<<c<<"\n";
	    cin>>dis;
	}
	}
}	
}
int findmind(arrele * m[])
{
	int min=big,rer;
	for(int i=0;i<n;i++)
	{  
		if(m[i]->dis<min&&m[i]->vis==0)
		{
			min=m[i]->dis;
			rer=i;
		}
	}
	return rer;
}	
void fillarrele(arrele * m[],vertex * g[])
{
	arrele * temp;
	for(int i=0;i<n;i++)
	{
		temp=new(arrele);
		temp->data=g[i]->data;
		m[i]=temp;
	}
}
int search(arrele * m[],int a)
{
	for(int i=0;i<n;i++)
	{
		if(m[i]->data==a)
		return i;
		}
}
bool search(int m[],int a)
{
	int i=0;
	while(m[i]!=-1)
	{
		if(m[i]==a)
		break;
		i++;
		}
		if(m[i]==-1)
		return false;
		return true;
	
	}
void findmind(arrele * m[],vertex * g[])
{
	int s,d,i,a,j,pre,cele=0;
	int path[10],ele[10];
	for(i=0;i<10;i++)
	{
		path[i]=-1;
		ele[i]=-1;
	}
	arrele * temp=NULL;
	vertex * t=NULL,*t1=NULL;
	cout<<"Enter the starting vertix and the destination vertix \n";
	cin>>s;
	cin>>d;
	for(i=0;i<n;i++)
	{
		if(m[i]->data==s)
		break;
	}
	temp=m[i];
	t=g[i];
	while(t->data!=d)
	{
		temp->vis=1;
		ele[cele++]=temp->data;
		t1=t->next;
		if(temp->dis!=big)
		pre=temp->dis;
		else
		pre=0;
		while(t1!=NULL)
		{
			a=t1->data;
			j=search(m,a);
			if(m[j]->dis>t1->dis+pre)
			{
			m[j]->dis=t1->dis+pre;
			if(!search(ele,m[j]->data))
			m[j]->via=t->data;
		    }
			t1=t1->next;
		}
		j=findmind(m);
		t=g[j];
		temp=m[j];
	}
		temp=m[j];
		i=0;
		while(temp->via!=-1)
		{   
			path[i]=temp->data;
			temp=m[temp->via-1];
			i++;	
		}
		path[i++]=temp->data;
		i--;
		cout<<"path of the road is \n";
		for(;i>=0;i--)
		cout<<path[i]<<" ";
		cout<<"shortest path is "<<m[j]->dis<<"\n";
	}
int main()
{
	cout<<"ENter the number of vertex \n";
	cin>>n;
vertex ** graph=new vertex *[n];
arrele ** mind=new arrele*[n];
constg(graph);
fillarrele(mind,graph);
findmind(mind,graph);
return 0;
}
