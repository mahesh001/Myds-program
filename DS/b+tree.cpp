#include<iostream>
using namespace std;
class Node
{
	public:
		int keys[5];
		Node *child[6];
		int fill;
		Node *sibbling;
		Node *parent;
		friend class btree;
		Node();
};
Node::Node()
{
	for(int i=0;i<5;i++)
	{
		keys[i]=0;
		child[i]=NULL;
	}
	child[5]=NULL;
	sibbling=NULL;
	parent=NULL;
	fill=0;
}
class btree
{
	public:
		Node *root;
		btree();
		void accept();
		void insert(Node *,int ,Node *,Node *);
		void sortins(Node *,int ,Node *,Node *);
		void checkoverflow(Node *);
		void display(Node *);
		void menu();
};
btree::btree()
{
	root=NULL;
}
void btree::accept()
{
	int x;
	//cout<<"Enter any element into the tree"<<endl;
	cin>>x;
	Node *prev,*temp;
	int fil;
	if(root!=NULL)
	{
		prev=root;
		temp=prev;
		while(temp->child[0]!=NULL)
		{
			fil=0;
			while(temp->keys[fil]<x&&fil<temp->fill)
				fil++;
			prev=temp->child[fil];
			temp=prev;
		}
	}
	else
	{
		prev=new Node;
		root=prev;
	}
	insert(prev,x,NULL,NULL);
}
void btree::insert(Node *temp,int x,Node *lc,Node *rc)
{
	sortins(temp,x,lc,rc);
	temp->fill++;
	checkoverflow(temp);
}
void btree::sortins(Node *temp,int x,Node *lc,Node *rc)
{
	int i=0;
	while(i<temp->fill&&temp->keys[i]<x)
		i++;
	if(temp->fill==i)
	{
		temp->keys[i]=x;
		temp->child[i+1]=rc;
		temp->child[i]=lc;
	}
	else
	{
		int j;
		for(j=temp->fill;j>i;j--)
		{
			temp->keys[j]=temp->keys[j-1];
			temp->child[j+1]=temp->child[j];
		}
		temp->keys[j]=x;
		temp->child[j+1]=rc;
		temp->child[j]=lc;
	}
}
void btree::checkoverflow(Node *temp)
{
	if(temp->fill<5)
		return;
	else
	{
		Node *temp1;
		Node *rbn;
		rbn=new Node;
		//if(temp->parent!=NULL)
		//{
			temp1=temp->parent;
			int i=0;
			while(temp1->child[i]!=temp)
				i++;
			if(temp->child[0]==NULL)
			{
				rbn->keys[0]=temp->keys[2];
				cout<<rbn->keys[0]<<endl;
				rbn->keys[1]=temp->keys[3];
				rbn->keys[2]=temp->keys[4];
				rbn->fill=3;
			}
			else
			{
				rbn->keys[0]=temp->keys[3];
				rbn->keys[1]=temp->keys[4];
				rbn->fill=2;
			}
			rbn->child[0]=temp->child[3];
			rbn->child[1]=temp->child[4];
			rbn->child[2]=temp->child[5];
			rbn->sibbling=temp->sibbling;
			temp->sibbling=rbn;
			for(int m=0;m<3;m++)
			{
				if(rbn->child[m]!=NULL)
				{
					Node *lbn=rbn->child[m];
					lbn->parent=rbn;
				}
			}
			if(temp!=root)
			{ 
				rbn->parent=temp->parent;
				int j;
				for(j=temp->fill;j>i;j--)
				{
					temp1->keys[j]=temp->keys[j-1];
					temp1->child[j+1]=temp1->child[j];
				}
				temp1->child[j+1]=temp->child[j];
				temp1->keys[i]=temp->keys[2];
				temp1->child[i]=temp;
				temp1->child[i+1]=rbn;
				temp1->fill++;
				temp->fill=2;
				checkoverflow(temp1);
			}
		//}
			else
				{
					Node *pare;
					pare=new Node;
					root=pare;
					pare->child[0]=temp;
					pare->child[1]=rbn;
					pare->fill=1;
					pare->keys[0]=temp->keys[2];
					pare->parent=NULL;
					rbn->parent=root;
					temp->parent=root;
				}
	}
}
void btree::display(Node *T)
{
	int i;
	for(i=0;i<T->fill;i++)
	{
		if(T->child[i]!=NULL)
			display(T->child[i]);
		cout<<"    "<<T->keys[i];
	}
	if(T->child[T->fill])
		display(T->child[T->fill]);
}
void btree::menu()
{
	char choice='y';
	while(choice!='n')
	{
		cout<<"Enter any element into the tree"<<endl;
		accept();
		cout<<"Want to enter more (y/n):"<<endl;
		cin>>choice;
	}
	display(root);
	cout<<endl;
}
int main()
{
	btree b;
	b.menu();
	return 0;
}


