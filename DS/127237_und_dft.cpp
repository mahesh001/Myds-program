#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
int n,c,i=-1,next=0,st=0;
vector <int> ptem;
vector <int> pt;
struct vertex
{
	int data;
	vertex * next;
	vertex()
	{
		data=-1;
		next=NULL;
	}
};
void
constg (vertex * g[])
{
  vertex *temp = NULL, *temp1 = NULL;
  int c;
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
      for (int j = 0; c != -1; j++)
	{
	  temp = new (vertex);
	  temp->data = c;
	  temp1->next = temp;
	  temp1 = temp;
	  cin >> c;
	}
    }
}
void deletel(vertex * g[],int a,int b)
{
vertex *temp1=NULL;
temp1=g[a-1];
while(temp1->next->data!=b)
temp1=temp1->next;
if(temp1->next->next==NULL)
	temp1->next=NULL;
else
	temp1->next=temp1->next->next;
}
bool allemp(vertex * g[])
{
	for(int i=0;i<n;i++)
	{
		if(g[i]->next!=NULL)
		return false;
	}
	return true;
}
void
DFT (vertex * v,vertex * g[])
{
	i++;
  int a=0,b=0,con=0;
  vertex *temp = NULL;
  while (v->next!=NULL)
    {
      temp = v;
      a=temp->data;
      ptem.push_back(temp->data);
      temp=temp->next;
      b=temp->data;
      if(a==b)
      break;
      deletel(g,a,b);
      deletel(g,b,a);
      v=g[b-1];
    }
   if(i==0)
		{
				pt=ptem;
				next=pt[i+1];
		}
   else
    {
   if(ptem.empty())
	   next=ptem[i-1];
   else 
   {
	   next=pt[i];
	  while(!ptem.empty())
	  {
		  con=i-1;
		  pt.insert(pt.begin()+con,ptem.front());
		  ptem.erase(ptem.begin());
		  con++;
	}
	}
}
	ptem.clear();
}
void run(vertex * g[])
{
  cout << "Where do you want to start the eulers path from \n";
  cin >> c;
  st=c;
	while(!allemp(g))
	  {
		 cout<<"entered loop \n";
		 DFT(g[c-1],g);
		 c=next;
	  }
}
void print()
{
	pt.push_back(st);
for(unsigned int i=0;i<pt.size();i++)
	cout<<pt[i]<<" ";	
}
int
main ()
{
  cout << "ENter the number of vertexex \n";
  cin >> n;
  vertex **graph = new vertex *[n];
  constg (graph);
  run(graph);
  print();
  return 0;
}
