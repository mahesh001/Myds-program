#include<iostream>
#include<string>
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
        struct lnode
        {
            object element;
            int weight;
            lnode * next;
            lnode(object e=0,int w=0,lnode * n=NULL):element(e),weight(w),next(n){}
        };
        lnode * listhead;
		int j;
        list()
        {
            listhead=new lnode;
        }
        void insert(const object x,int w)
        {
            lnode * r=new lnode(x,w,NULL);
            lnode * temp=listhead;
            while(temp->next!=NULL)
				if(temp->element==r->element)
					return;
				else
					temp=temp->next;
			temp=listhead;
			while(temp->next!=NULL)
                        temp=temp->next;
	        temp->next=r;
			j++;
        }
		void dele(object x)
		{
			lnode * temp=listhead;
            while(temp->next!=NULL)
			{
				if(x==temp->next->element)
				{
					lnode * z=temp->next;
					temp->next=temp->next->next;
					delete z;
				}
				temp=temp->next;
			}
			j--;
		}
};
template<class object>
class vertex : list<object>
{
    public:
        list<object> adj;
        vertex(object x)
        {
            adj.listhead->element=x;
        }
        vertex(){}
        void insert(const object x,int w=0)
        {
            adj.insert(x,w);
        }
        void assign(int i)
        {
            adj.listhead->element=i;
        }
		int returnweight(int z)
		{
			lnode * r=adj.listhead->next;
			while(r && r->element!=z)
				r=r->next;
			return r->weight;
		}
		void print()
		{
			node * temp=adj.listhead;
			while(temp->next!=NULL)
			{
				cout<<temp->element<<"\t";
				temp=temp->next;
			}
			cout<<temp->element;
		}
};
template<class object>
class graph : public list<object>
{
    public:
        int num;
		int count;
		int counter;
        vertex<object> * ver;
        graph(int n)
        {
            counter=1;
			num=n;
			ver=new vertex<object>[num];
            int i;
			for(i=0;i<num;i++)
                  ver[i].assign(i);
            array=new a[num*num];
			count=0;
            for(i=0;i<num*num;i++)
            {
                array[i].no=-1;
                array[i].low=-1;
				array[i].visited=0;
				array[i].parent=-1;
            }    
        }
        struct a
        {
            int no;
            int low;
            int visited;
			int parent;
        };
        a * array;
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
				   	object a;
				   	cin>>a;
					ver[i].insert(a);
					ver[a].insert(i);
					cout<<"\n\t Wanna enter more\n\tPress 1 for yes or any other no. for no :";
					cin>>b;
				}
           }
			for( i=0;i<num;i++)
            {
				cout<<"\n";
				ver[i].print();
			}
		}
		int sss;
		void findar(int v)
		{
			sss=v;
			findart(v);
			int s=0;
			node * r=ver[v].adj.listhead->next;
			while(r)
			{
				if(array[r->element].parent==v)
					s++;
				r=r->next;
			}
			if(s>=2)
			{
				 cout<<"\n\n\t"<<v<<"is an articulation point";
			}
		}
		void findart(int v)
	   {
		   array[v].visited=1;
		   array[v].low=array[v].no=counter++;
		   node * r=ver[v].adj.listhead->next;
		   while(r)
           {
			   if(array[r->element].visited!=1)
			   {
				   array[r->element].parent=v;
				   findart(r->element);
				   if(array[r->element].low>=array[v].no && v!=sss)
					   cout<<"\n\n\t"<<v<<"is an articulation point";
					if(array[v].low>array[r->element].low)
						array[v].low=array[r->element].low;
			   }
			  else
			  {
				  if(array[v].parent!=r->element)
					  if(array[v].low>array[r->element].low)
							array[v].low=array[r->element].low;
			  }
			  r=r->next;
		   }
		  }
};           
        
int main()
{
    graph<int> g(7);
    g.insert();
	g.findar(3);
	return 0;
}


