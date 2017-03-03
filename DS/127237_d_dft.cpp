#include<iostream>
#include<cstdlib>
#include<stack>
#include<vector>
using namespace std;
vector<char> vtemp;
vector <int > arr;
int n,max1=0;
struct vertex
{
  char data;
  int flag;
  int val;
  vertex *next;
    vertex ()
  {
    data = -1;
    flag = 0;
    next = NULL;
    val=-1;
  }
};
void
constg (vertex * g[])
{
  vertex *temp = NULL, *temp1 = NULL;
  char c;
  for (int i = 0; i < n; i++)
    {
      cout << "ENter the vertex \n";
      cin >> c;
      temp = new (vertex);
      temp->data = c;
      g[i] = temp;
    }
  for (int i = 0; i < n; i++)
    {
      temp1 = g[i];
      cout << "enter the neighbor of " << g[i]->data << "\n";
      cin >> c;
      for (int j = 0; c != '-'; j++)
	{
	  temp = new (vertex);
	  temp->data = c;
	  temp1->next = temp;
	  temp1 = temp;
	  cin >> c;
	}
    }
}
void
visited (vertex * g[], char a)
{
  vertex *temp = NULL;
  for (int i = 0; i < n; i++)
    {
      temp = g[i];
      while (temp != NULL)
	{
	  if (temp->data == a)
	    temp->flag = 1;
	  temp = temp->next;
	}
    }
}
void numberele(vertex * g[])
{
	char a;
	vertex * temp=NULL;
	static int x=0;
	for(int i=vtemp.size()-1;i>=0;i--)
	{
		a=vtemp[i];
		++x;
		for(int j=0;j<n;j++)
		{
			temp=g[j];
		while(temp!=NULL)
		{
			if(temp->data==a)
				temp->val=x;
			temp=temp->next;
		}
		}
	}
	max1=x;
}
int find(char c,vertex * g[])
{
	for(int i=0;i<n;i++)
	{
		if(g[i]->data==c)
		return i;
	}
}
void
DFT (vertex * g[],char c,int flag)
{
  int count = 0, pop = 0,i=0;
  stack < vertex * >s;
  vertex *temp = NULL;
  s.push (g[find(c,g)]);
  while (!s.empty () && count < n)
    {
      temp = s.top ();
      visited (g, temp->data);
      temp = g[find(temp->data,g)];
      if (pop == 0)
		vtemp.push_back(temp->data);
      pop = 0;
      temp = temp->next;
      if(temp!=NULL)
      {
      if (temp->flag == 0)
	{
	  s.push (temp);
	  count++;
	}
      else
	{
	  while (temp != NULL)
	    {
	      if (temp->flag == 0)
		break;
	      temp = temp->next;
	    }
	  if (temp != NULL)
	    {
	      s.push (temp);
	      count++;
	    }
	  else
	    {
	      s.pop ();
	      pop = 1;
	    }
	}
    }
    else
    {
		s.pop();
		pop=1;
	}
	if(s.empty()&&count<n)
	{
		if(flag==1)
		break;
		pop=0;
		for(i=0;i<n;i++)
		{
			if(g[i]->flag==0)
			{
				s.push(g[i]);
				break;
			}
		}
		if(i==n)
		break;
		numberele(g);
		vtemp.clear();
}
}
if(flag==0)
{
numberele(g);
vtemp.clear();
}
}
bool found(int a)
{
	for(int i=0;i<arr.size();i++)
	{
		if(a==arr[i])
		return true;
		}
	return false;
}
int findm(char c,vertex * g[])
{
	vertex * temp=NULL;
	for(int i=0;i<n;i++)
	{
		if(g[i]->data==c)
		continue;
		else
		{
			temp=g[i];
			temp=temp->next;
			while(temp!=NULL)
			{
				if(temp->data==c)
				{
					if(!found(i))
					{
						arr.push_back(i);
						return i;
					}
				}
				temp=temp->next;
			}
		}
	}
	return -1;
}
void constrg(vertex * gr[],vertex * g[])
{
	int pos=0;
	vertex * temp=NULL,*temp1=NULL;
	char a;
	for(int i=0;i<n;i++)
	{
		temp=new(vertex);
		temp->data=g[i]->data;
		temp->val=g[i]->val;
		gr[i]=temp;
	}
	for(int i=0;i<n;i++)
	{
		a=gr[i]->data;
		temp=gr[i];
		for(int j=0;j<n;j++)
		{
			if(j==i)
			continue;
			else
			{
				pos=findm(a,g);
				if(pos!=-1)
				{
				temp1=new(vertex);
				temp1->data=g[pos]->data;
				temp1->val=g[pos]->val;
				temp->next=temp1;
				temp=temp1;
				}	
			}
		}
		arr.clear();
	}
}
void print()
{
	for(int i=0;i<vtemp.size();i++)
	cout<<" "<<vtemp[i]<<" ";
}
int main()
{
char c; 
int i=0;
vertex * temp=NULL;
cout<<"ENter the numeber of elements \n";
cin>>n;
vertex ** graph=new vertex * [n];
vertex ** graphr=new vertex *[n];
constg(graph);
cout << "Where do you want to start DFT from \n";
cin >> c;
DFT(graph,c,0);
constrg(graphr,graph);
cout<<"strong components are \n";
for(;max1>1;)
{
	for(i=0;i<n;i++)
	{
		if(graphr[i]->val==max1)
		break;
	}
	DFT(graphr,graph[i]->data,1);
	cout<<"{";
	print();
	cout<<"}";
	cout<<vtemp.size()<<"\n";
	if(vtemp.size()%2!=0)
	max1=max1-vtemp.size();
	else
	max1-=(vtemp.size()-1);
	cout<<max1<<"\n";
	vtemp.clear();
	cout<<"\n";
}
for(i=0;i<n;i++)
{
	if(graphr[i]->flag==0)
	break;
}
if(i!=n)
{
DFT(graphr,graph[i]->data,1);
cout<<"{";
print();
cout<<"}";
cout<<"\n";
}
return 0;
}
