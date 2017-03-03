#include<iostream.h>
template<class Etype>
class AvlTree;
template<class Etype>
class AvlNode
{
	public:
		Etype elem;
		AvlNode *left;
		AvlNode *right;
		int height;
		AvlNode()
		{
			elem=0;
			left=NULL;
			right=NULL;
			height=0;
		}
};
template<class Etype>
class AvlTree:public AvlNode<Etype>
{
	public:
		AvlNode<Etype> *root;
		AvlTree();
		int hi(AvlNode<Etype> *&T);
		void remove(Etype &x,AvlNode<Etype> *&T);
		void del(Etype &x,AvlNode<Etype> *&T);
		AvlNode<Etype>* find_min(AvlNode<Etype> *&T);
		//void calc_hi(AvlNode<Etype> *&T);
		void single_rotl(AvlNode<Etype> *&T);
		void single_rotr(AvlNode<Etype> *&T);
		void double_rotl(AvlNode<Etype> *&T);
		void double_rotr(AvlNode<Etype> *&T);
		void insert(Etype &x,AvlNode<Etype> *&T);
		void insert(Etype &x);
		void preorder(AvlNode<Etype> *&T);
		void postorder(AvlNode<Etype> *&T);
		void inorder(AvlNode<Etype> *&T);
		void menu();
};
template<class Etype>
AvlTree<Etype>::AvlTree()
{
	root=NULL;
}
template<class Etype>
int AvlTree<Etype>::hi(AvlNode<Etype> *&T)
{
	if(T==NULL)
		return -1;
	else
		return T->height;
}
template<class Etype>
void AvlTree<Etype>::insert(Etype &x)
{
	insert(x,root);
}
template<class Etype>
void AvlTree<Etype>::insert(Etype &x,AvlNode<Etype> *&T)
{
	if(T==NULL)
	{
		T=new AvlNode<Etype>;
		T->elem=x;
	}
	else if(x<T->elem)
	{
		insert(x,T->left);
		if(hi(T->left)-hi(T->right)==2)
			if(x<(T->left)->elem)
				single_rotl(T);
			else
				double_rotl(T);
		/*else
			calc_hi(T);*/
	}
	else if(x>T->elem)
	{
		insert(x,T->right);
		if(hi(T->right)-hi(T->left)==2)
			if(x>T->right->elem)
				single_rotr(T);
			else
				double_rotr(T);
		/*else
			calc_hi(T);*/
	}
	T->height=hi(T->left)>hi(T->right)?1+hi(T->left):1+hi(T->right);
}
template<class Etype>
void AvlTree<Etype>::single_rotl(AvlNode<Etype> *&T)
{
	AvlNode<Etype> *T1=T->left;
	T->left=T1->right;
	T1->right=T;
	T->height=hi(T->left)>hi(T->right)?1+hi(T->left):1+hi(T->right);
	T1->height=hi(T1->left)>hi(T->right)?1+hi(T1->left):1+hi(T->right);
	T=T1;
}
template<class Etype>
void AvlTree<Etype>::single_rotr(AvlNode<Etype> *&T)
{
		AvlNode<Etype> *ch=T->right;
		 T->right=ch->left;
		 ch->left=T;
		 T->height=hi(T->left)>hi(T->right)?(hi(T->left)+1):(hi(T->right)+1);
		 ch->height=hi(ch->right)>hi(T->left)?(hi(ch->right)+1):(hi(T->left)+1);
		 T=ch;
}
template<class Etype>
void AvlTree<Etype>::double_rotl(AvlNode<Etype> *&T)
{
	single_rotr(T->left);
	single_rotl(T);
}
template<class Etype>
void AvlTree<Etype>::double_rotr(AvlNode<Etype> *&T)
{
	single_rotl(T->right);
	single_rotr(T);
}
template<class Etype>
void AvlTree<Etype>::inorder(AvlNode<Etype> *&T)
{

	if(T!=NULL)
	{
		inorder(T->left);
		cout<<T->elem<<"     ";
		inorder(T->right);
	}
}
template<class Etype>
void AvlTree<Etype>::preorder(AvlNode<Etype> *&T)
{
	if(T!=NULL)
	{
		cout<<T->elem<<"     ";
		preorder(T->left);
		preorder(T->right);
	}
}
template<class Etype>
void AvlTree<Etype>::postorder(AvlNode<Etype> *&T)
{
	if(T!=NULL)
	{
		postorder(T->left);
		postorder(T->right);
		cout<<T->elem<<"     ";
	}
}
template<class Etype>
void AvlTree<Etype>::remove(Etype &x,AvlNode<Etype> *&T)
{
	AvlNode<Etype> *temp;
	if(T==NULL)
		cout<<"THE ELEMENT IS NOT FOUND"<<endl;
	else if(x<T->elem)
		remove(x,T->left);
	else if(x>T->elem)
		remove(x,T->right);
	else
	{
		if((T->left!=NULL)&&(T->right!=NULL))
		{
			temp=find_min(T->right);
			T->elem=temp->elem;
			remove(T->elem,T->right);
		}
		else
		{
			temp=T;
			if(T->left)
				T=T->left;
			else
				T=T->right;
			delete temp;
		}
	}
	if(T)
			T->height=hi(T->left)>hi(T->right)?1+hi(T->left):1+hi(T->right);
}
template<class Etype>
void AvlTree<Etype>::del(Etype &x,AvlNode<Etype> *&T)
{
	if(T!=NULL)
	{
		if(x==T->elem)
			remove(x,T);
		else if(x<T->elem)
		{
			del(x,T->left);
			if(hi(T->right)-hi(T->left)==2)
			{
				if(T->right)
				{
					if(T->right->right)
						single_rotr(T);
					else
					{
						if(T->right->left)
							double_rotr(T);
					}
				}
			}
		}
		else if(x>T->elem)
		{
			del(x,T->right);
			if(hi(T->left)-hi(T->right)==2)
			{
				if(T->left)
				{
					if(T->left->left)
						single_rotl(T);
					else
					{
						if(T->left->right)
							double_rotl(T);
					}
				}
			}
		}
		else
			cout<<"NOT FOUND"<<endl;
	}
}
template<class Etype>
AvlNode<Etype>* AvlTree<Etype>::find_min(AvlNode<Etype> *&T)
{
	if(T==NULL)
		return NULL;
	else if(T->left==NULL)
		return T;
	else
		return find_min(T->left);
}
template<class Etype>
void AvlTree<Etype>::menu()
{
	Etype x,y;
	int i;
	char choice='y';
	while(choice!='n')
	{
		cout<<"Enter any element into the tree"<<endl;
		cin>>x;
		insert(x);
		cout<<"Want to insert more (y/n):"<<endl;
		cin>>choice;
	}
	cout<<"Enter 1 for INORDER TRAVERSE"<<endl;
	cout<<"      2 for PREORDER TRAVERSE"<<endl;
	cout<<"      3 for POSTORDER TRAVERSE "<<endl;
	cout<<"      4 to exit                "<<endl;
	cin>>i;
	switch(i)
	{
	case 1:inorder(root);break;
	case 2:preorder(root);break;
	case 3:postorder(root);break;
	}
	cout<<"Enter the element to delete"<<endl;
	cin>>y;
	del(y,root);
	cout<<"The tree after deletion in preorder is "<<endl;
	preorder(root);
	cout<<endl;
}
int main()
{
	AvlTree<int> p;
	p.menu();
	return 0;
}






