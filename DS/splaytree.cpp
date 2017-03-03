#include<iostream>
#include<cstring>
using namespace std;
template<class object>
class avlnode
{
		public:
		object element;
		avlnode *left;
		avlnode *right;
		avlnode *parent;
		avlnode(object e,avlnode * l=NULL,avlnode *r=NULL,avlnode * h=NULL):element(e),left(l),right(r),parent(h){}
};
template <class object>
class avltree
{
	public:
		avlnode<object> * root;
		avltree():root(NULL){}
		int height(const avlnode<object>* t)const;
		void insert(const object x,avlnode<object> * &t)
		{
			avlnode<object> * t1=NULL;
			insert(x,t,t1);
		}
		void insert(const object x,avlnode<object> * &t,avlnode<object> * t1)
		{
			if (t==NULL)
				t=new avlnode<object>(x,NULL,NULL);
			else if(x < t->element)
				insert(x,t->left,t);
			else if(x > t->element)
				insert(x,t->right,t);
			t->parent=t1;
		}
		void find(object s,avlnode<object> * &t)
		{
			if(t->element==s)
			{
				cout<<"!";
				splay(t);
			}
			else if(s<t->element)
				find(s,t->left);
			else if(s>t->element)
				find(s,t->right);
			else
				;
		}			
		void splay(avlnode<object> * x)
		{
			cout<<"@";
			avlnode<object> *p,*g;
			if(x->parent)
			{
				cout<<"#";
				p=x->parent;
				g=p->parent;
				if(g==NULL)
					if(p->left==x)
						sleftrot(x);
					else
						srightrot(x);
				else
					if((g->left)==p)
						if((p->left)==x)
							dleftleft(x);
						else
							dleftright(x);
					else
						if((p->left)==x)
							drightleft(x);
						else
							drightright(x);
			}
		}
		void sleftrot(avlnode<object> * x)
		{
			avlnode<object> *p=x->parent;
			avlnode<object> *b=x->right;
			x->right=p;
			x->parent=p->parent;
			p->parent=x;
			p->left=b;
			root=x;
		}
		void srightrot(avlnode<object> * x)
		{
			avlnode<object> *p=x->parent;
			avlnode<object> *b=x->left;
			x->left=p;
			x->parent=p->parent;
			p->parent=x;
			p->right=b;
			root=x;
		}
		void dleftright(avlnode<object> * x)
		{
			avlnode<object> *b=x->left;
			avlnode<object> *c=x->right;
			avlnode<object> *p=x->parent;
			avlnode<object> *g=p->parent;
			avlnode<object> *ggp=g->parent;
			if(ggp)
			{
				if(ggp->left==g)
					ggp->left=x;
				else
					ggp->right=x;
			}
			else
				root=x;
			x->parent=ggp;
			x->left=p;
			x->right=g;
			p->right=b;
			p->parent=x;
			if(b)
				b->parent=p;
			g->left=c;
			g->parent=x;
			if(c)
				c->parent=g;
		}
		void drightleft(avlnode<object> * x)
		{
			avlnode<object> *b=x->left;
			avlnode<object> *c=x->right;
			avlnode<object> *p=x->parent;
			avlnode<object> *g=p->parent;
			avlnode<object> *ggp=g->parent;
			if(ggp)
			{
				if(ggp->left==g)
					ggp->left=x;
				else
					ggp->right=x;
			}
			else
				root=x;
			x->parent=ggp;
			x->left=g;
			x->right=p;
			g->right=b;
			g->parent=x;
			if(b)
				b->parent=g;
			p->left=c;
			p->parent=x;
			if(c)
				c->parent=g;
		}
		void drightright(avlnode<object> * x)
		{
			avlnode<object> *c=x->left;
			avlnode<object> *p=x->parent;
			avlnode<object> *b=p->left;
			avlnode<object> *g=p->parent;
			avlnode<object> *ggp=g->parent;
			if(ggp)
			{
				if(ggp->left==g)
					ggp->left=x;
				else
					ggp->right=x;
			}
			else
				root=x;
			x->parent=ggp;
			x->left=p;
			p->left=g;
			g->right=b;
			g->parent=p;
			if(b)
				b->parent=g;
			p->right=c;
			p->parent=x;
			if(c)
				c->parent=p;
		}
		void dleftleft(avlnode<object> * x)
		{
			avlnode<object> *b=x->right;
			avlnode<object> *p=x->parent;
			avlnode<object> *c=p->right;
			avlnode<object> *g=p->parent;
			avlnode<object> *ggp=g->parent;
			if(ggp)
			{
				if(ggp->left==g)
					ggp->left=x;
				else
					ggp->right=x;
			}
			else
				root=x;
			x->parent=ggp;
			x->right=p;
			p->right=g;
			g->left=c;
			g->parent=p;
			if(c)
				c->parent=g;
			p->left=b;
			p->parent=x;
			if(b)
				b->parent=p;
		}
		void printpost(avlnode<object> *t) const
		{
			if(t->left!=NULL)
				printpost(t->left);
			if(t->right!=NULL)
				printpost(t->right);
			cout<<"\t"<<t->element;
		}
		void printpre(avlnode<object> *t) const
		{
			cout<<"\t"<<t->element;
			if(t->left!=NULL)
				printpre(t->left);
			if(t->right!=NULL)
				printpre(t->right);
		}
		void printin(avlnode<object> *t) const
		{
			if(t->left!=NULL)
				printin(t->left);
			cout<<"\t"<<t->element;
			if(t->right!=NULL)
				printin(t->right);
		}
};
template<class object>
int avltree<object>::height(const avlnode<object> *t)const
{
	if(t==NULL)
		return -1;
	else
		return 1+max(height(t->left),height(t->right));
}
int max(int x,int y)
{
if(x>y)
return x;
else
return y;
}
int main()
{
avltree<int> b;
int q;
int n;
do
{
	cout<<"\n\t1.Insert the expression:";
	cout<<"\n\t2.list the tree";
	cout<<"\n\t3.Display";
	cout<<"\n\t4.exit";
	cin>>n;
	switch(n)
	{
	case 1:
		cout<<"enter the element to be inserted";
		cin>>q;
		b.insert(q,b.root);
		break;
	case 2:
		cout<<"enter the element to be deleted";
		cin>>q;
		b.find(q,b.root);
		break;
	case 3:
		cout<<"\n\n\tThe height of the tree    :";
		q=b.height(b.root);
		cout<<q;
		cout<<"________________________________________________________________";
		cout<<"\n\n\tThe preorder output of the tree    :\n\n";
		b.printpre(b.root);
		cout<<"________________________________________________________________";
		cout<<"\n\n\tThe inorder output of the tree    :\n\n";
		b.printin(b.root);
		cout<<"________________________________________________________________";
		cout<<"\n\n\tThe postorder output of the tree    :\n\n";
		b.printpost(b.root);
		
	case 4:
		break;
	};
}while(n!=4);
return 0;
}


