#include<iostream>
using namespace std;
template<class T>
class list
{
	public:
		struct node
		{
			T data;
			node* next;
		};
		node* listhead;
		node* currentpos;
		node* temp;
		list()
		{
			listhead=new node;
			listhead->next=NULL;
			currentpos=listhead;
		}
		void insert(const T & x)
		{
			temp=new node;
			temp->data=x;
			temp->next=NULL;
			currentpos->next=temp;
			currentpos=temp;
		}
};
class graph
{
	public:
			int v;
			int m;
			int * degree;
			list<int> * al;
			int * * am;
			int i,j;
			graph()
			{
				cout<<"\nEnter number of vertices in the graph\n";
				cin>>v;
				m=0;
				al=new list<int>[v+1];
				am=new int* [v+1];
				degree=new int[v+1];
				am[0]=NULL;
				degree[0]=-1;
				for(i=1;i<=v;i++)
				{
					am[i]=new int[v+1];
					am[i][0]=-50;
					degree[i]=0;
				}
				for(i=1;i<=v;i++)
					for(j=1;j<=v;j++)
						am[i][j]=0;
			}
			void insertedges()
			{
				cout<<"ENTER THE ADJACENCY LIST\n";
				for(int i=1;i<=v;i++)
				{
					int w=1;
					cout<<" NOW Enter Elements for for vertex \n"<<i;
					cout<<"Press 1 for yes or any other no. for no :";
						cin>>w;
					while(w==1)
					{
				   		cout<<"\n\tEnter the element"<<endl;
				   		int aa;
				   		cin>>aa;
						am[i][aa]=1;
						am[aa][i]=1;
						degree[aa]++;
						degree[i]++;
						cout<<"\n\t Wanna enter more\n\tPress 1 for yes or any other no. for no :";
						cin>>w;
					}
			   }
			}
			void eulerpath()
			{
				int k;
				for(i=1;i<=v;i++)
				{
					if(degree[i]%2==1)
					{
						k=i;
						m++;
					}
				}
				if(m!=0&&m!=2)
				{
					cout<<"\nEuler path not possible\n";
					return;
				}
				if(m==2)
				{
					i=k;
				}
				else
				{
					cout<<"\nEnter the vertex from which you want to start\n";
					cin>>i;
				}
				list<int> l;
				l.insert(i);
				list<int>::node* t;
				list<int>::node* t1;
				list<int>* temp;
				while(1)
				{
					t1=l.listhead;
					t=l.listhead->next;
					while(t!=NULL)
					{
						if(degree[t->data]==0)
						{
							t1=t;
							t=t->next;
						}
						else
							break;
					}
					if(t!=NULL)
						i=t->data;
					else
						break;
					k=i;
					temp=new list<int>;
					temp->insert(k);
					while(degree[k]!=0)
					{
						for(j=1;j<=v;j++)
						{
							if(am[i][j]!=0)
							{
								temp->insert(j);
								am[i][j]=0;
								am[j][i]=0;
								degree[i]--;
								degree[j]--;
								break;
							}
						}
						if(j==v+1)
							break;
						i=j;
					}
					temp->currentpos->next=t->next;
					t1->next=temp->listhead->next;
					delete t;
				}
				t=l.listhead->next;
				cout<<"\nEuler's path is as follows:\n";
				while(t!=NULL)
				{
					cout<<t->data<<"  ";
					t=t->next;
				}
				cout<<"\n";
			}
};
int main()
{
	graph g;
	g.insertedges();
	g.eulerpath();
	return 0;
}
