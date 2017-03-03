#include<iostream.h>
#include<string.h>
template<class object1>
class queue
{
	public:
		struct node
		{
			object1 data;
			node * next;
			node(object1 c=0,node * r=NULL):data(c),next(r){}
		};
		
		node *front;
		node * rear;
		queue()
			{
				front=new node;
				rear=new node;
				front=NULL;
				rear=NULL;
				j=0;

			}
		int j;
			void enqueue(const object1 x)
			{
				node *temp=new node(x);
				if(front==NULL)
					front=rear=temp;
				else
				{
					rear->next=temp;
					temp->next=NULL;
					rear=temp;
				}
				j++;
			}
			object1 dequeue()
			{
				node * temp=front;
				front=front->next;
				object1 x=temp->data;
				j--;
				delete temp;
				return x;
				
			}
};
template<class object>
class list
{
    public:
        struct node
        {
            object element;
            int weight;
            node * next;
            node(object e=0,int w=0,node * n=NULL):element(e),weight(w),next(n){}
        };
        node * listhead;
		int j;
        list()
        {
            listhead=new node;
        }
        void insert(const object x,int w=0)
        {
           	node * r=new node(x,w,NULL);
            node * temp=listhead;
           	while(temp->next!=NULL)
                        temp=temp->next;
	       	temp->next=r;
			j++;
        }
		void dele(object x)
		{
			node * temp=listhead;
			while(temp->next!=NULL)
			{				
				if(x==temp->next->element)
				{
					node * z=temp->next;
					temp->next=z->next;
					delete z;
					j--;
					return;
				}
				temp=temp->next;
			}
		}
};
template<class object>
class graph : public list<object>
{
    public:
        int * * a;
		struct am
		{
			int visited;
			int degree;
		};
		int num;
		int count;
        struct am * array;
        graph(int n)
        {
            num=n;
			a=new int *[num];
			int i;
			for(i=0;i<num;i++)
			{
				a[i]=new int[num];
			}
			for(i=0;i<num;i++)
					for(j=0;j<num;j++)
						a[i][j]=0;
			count=0;
         	z=0;
			elist=new list<object>;
			array=new am[num];
			for(i=0;i<num;i++)
			{
				array[i].visited=0;
				array[i].degree=0;
			}
        }
		int z;
        void insert()
        {
            cout<<"\n\tENTER THE ADJACENCY LIST\n";
			for(int i=0;i<num;i++)
            {
                int b=1;
                cout<<"\n______________________________________________________________"<<endl;
				cout<<"\n\t NOW Enter Elements for for vertex "<<i;
				cout<<"\n\t Wanna enter more\n\tPress 1 for yes or any other no. for no :";
					cin>>b;
                while(b==1)
                {
				   	cout<<"\n\tEnter the element"<<endl;
				   	object aa;
				   	cin>>aa;
					a[i][aa]=1;
					a[aa][i]=1;
					array[i].degree++;
					array[aa].degree++;
					cout<<"\n\t Wanna enter more\n\tPress 1 for yes or any other no. for no :";
					cin>>b;
				}
           }
		}
		void dfs(int v,list<object> & t)
		{
			array[v].visited=1;
			for(int r=0;r<num;r++)
			{
				if(a[v][r])
				{
					if(array[r].visited!=1)
					{
						t.insert(r);
						array[r].visited=1;
						a[v][r]=0;
						array[v].degree--;
						a[r][v]=0;
						array[r].degree--;
						dfs(r,t);
					}
				}
			}
		}
		int isdegree()
		{
			for(int i=z;i<num;i++)
            {
                if(array[i].visited==0 && array[i].degree!=0)
				{
					z++;
					return i;
				}
            }    
			return -1;
		}
		list<object> * elist;
		void euler(int v)
		{
		   int m=0;
		   list<object> a;
		   a.insert(v);
		   dfs(v,a);
		   merge(a,z);
		   int k=isdegree();
		   while(k>-1)
		   {
			   node * temp=elist->listhead;
			   for(int i=0;i<k;i++)
			      temp=temp->next;
			   list<object> C;
			   dfs(k,C);
			   merge(C,z);
			   k=isdegree();
			}
		}
		void merge(list<object> & C,int & z)
		{
			node * temp=elist->listhead;
		   for(int i=0;i<z && temp->next!=NULL;i++)
			  temp=temp->next;
		   node * t=C.listhead;
		   while(t->next!=NULL)
		   	   t=t->next;
		   t->next=temp->next;
		   temp->next=C.listhead->next;
		}
		void display()
		{
		   list<object>::node * t=elist->listhead;
		   while(t->next!=NULL)
		   {
			   t=t->next;
			   cout<<"\t"<<t->element;
		   }
		  //cou t<<"\t"<<t->element;
		}
};           
        
int main()
{
    graph<int> g(12);
    g.insert();
	g.euler(5);
	g.display();
    return 0;
}


