#include<iostream>
#include<cstring>
using namespace std;
template<class object>
class stack
{
	protected:
		struct node
		{
			object element;
			node *next;
			node(object c=0,node * n=NULL):element(c),next(n){}
		};
		node * tops;
		public:
			stack():tops(new node),j(0){}
			void push(const object &x);
			object pop();
			object top();
			int j;
};
template<class object>
void stack<object>::push(const object & x)
{
	tops=new node(x,tops);
	j++;
}
template<class object>
object stack<object>::pop()
{
	object r=tops->element;
	node *t=tops;
	tops=tops->next;
	j--;
	delete t;
	return r;
}
template<class object>
object stack<object>::top()
{
	object r=tops->element;
	return r;
}
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
        list()
        {
            listhead=new node;
        }
        void insert(const object x,int w)
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
			cout<<"245153413"<<endl;
            while(temp->next!=NULL)
			{				
				cout<<"check deletion 1"<<endl;
				if(x==temp->next->element)
				{
					node * z=temp->next;
					temp->next=z->next;
					delete z;
					j--;
					return;
				}
				cout<<"check deletion 2"<<endl;
				temp=temp->next;
			}
		}
		int j;
};
template<class object>
class vertex : list<object>
{
    public:
        list<object> adj;
		list<object> adj1;
		vertex(object x)
        {
            adj.listhead->element=x;
        }
        vertex(){}
        void insert(const object x,int w=0)
        {
            adj.insert(x,w);
        }
		void insert1(const object x,int w=0)
        {
            adj1.insert(x,w);
        }
        void assign(int i)
        {
            adj.listhead->element=i;
        }
		int returnweight(int z)
		{
			node * r=adj.listhead->next;
			while(r && r->element!=z)
				r=r->next;
			return r->weight;
		}
		void del(object x)
		{
			adj.dele(x);
		}
		void print()
		{
			cout<<endl;
			node * temp=adj1.listhead;
			while(temp->next!=NULL)
			{
				cout<<temp->element<<"\t";
				temp=temp->next;
			}
			cout<<temp->element;
		}
		void assign1(int i)
        {
            adj1.listhead->element=i;
        }
		
};
template<class object>
class graph : public list<object>
{
    public:
        int num;
        vertex<object> * ver;
        graph(int n)
        {
            num=n;
			ver=new vertex<object>[num];
            int i;
			for(i=0;i<num;i++)
			{
				ver[i].assign(i);
				ver[i].assign1(i);
			}
            array=new a[num];
            for(i=0;i<num;i++)
            {
                array[i].visited=0;
                array[i].no=-1;
				array[i].marked=0;
            }
			cc=num;
			counter=0;
        }
		int cc;
		int counter;
        struct a
        {
            int visited;
            int no;
			int marked;
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
					cout<<"\n\t Wanna enter more\n\tPress 1 for yes or any other no. for no :";
					cin>>b;
				}
           }
		}
		void reverse()
		{
			for(int i=0;i<num;i++)
			{
				node * r=ver[i].adj.listhead->next;
				while(r)
                {
					ver[r->element].insert1(i);
					r=r->next;
				}
			}
		}
		void strongcomp()
		{
			cout<<"aaaaaaaaaaa"<<endl;
			int s;
			for(s=0;s<num;s++)
			{
				if(array[s].no<0)
					number(s);
			}
			for(s=0;s<num;s++)
			{
				cout<<"\n\t"<<s<<"\t"<<array[s].no;
			}
			reverse();
			for(s=0;s<num;s++)
			{
				ver[s].print();
			}
			cout<<"cccccccccc"<<endl;
			while(cc>0)
			{
				s=0;
				int k=100000;
				int d=0;
				while(s<num)
				{
					if(d<array[s].no && array[s].visited!=1)
					{
						d=array[s].no;
						k=s;
					}
					s++;
				}
				cout<<"\n";
				dft(k);
				//cout<<"\n\thhhhhhhhhhhhh"<<cc<<endl;
			}
		}
		void dft(int v)
		{
			if(v>=num)
				return;
			//cout<<"dft"<<endl;
			array[v].visited=1;
			cc--;
			cout<<"\t"<<v;
			node * r=ver[v].adj1.listhead->next;
			while(r)
            {
				if(array[r->element].visited!=1)
				{
					//cout<<"\t"<<r->element;
					dft(r->element);
				}
				r=r->next;
			}
		}
		/*void number(int v)
		{
			cout<<"xxxxxxxxxxx"<<v<<endl;
			node * r=ver[v].adj.listhead->next;
			while(r)
            {
				if(array[r->element].no<0)
				{
					cout<<"zzzzzzzzzzzzzz"<<r->element<<endl;
					number(r->element);
					array[v].no=++counter;
				}
				r=r->next;
				cout<<"yyyyyyyyyyyyy"<<endl;
			}
		}*/
		void number(int v)
		{
			stack<object> q;
			q.push(v);
			array[v].marked=1;
			node * r=ver[v].adj.listhead->next;
			while(q.j!=0)
			{
				while(r)
				{
					if(array[r->element].no<0 && array[r->element].marked!=1)
					{
						q.push(r->element);
						array[r->element].marked=1;
						r=ver[r->element].adj.listhead->next;
					}
					else
						r=r->next;
				}
				if(q.j!=0)
				{
					int s=q.top();
					r=ver[s].adj.listhead->next;
					int m=0;
					while(r)
					{
						if(array[r->element].marked!=1)
						{
							m=1;
							break;
						}
						r=r->next;
					}
					if(m==0)
					{
						s=q.pop();
						array[s].no=++counter;
					}
				}
			}
		}

};
int main()
{
    graph<int> g(10);
    g.insert();
	g.strongcomp();
	return 0;
}


