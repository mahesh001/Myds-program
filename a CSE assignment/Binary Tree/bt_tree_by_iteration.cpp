#include<iostream>
using namespace std;

struct btnode
{
	btnode *lchild;
	char data;
	btnode *rchild;
};
/*stack of btnode pointers*/
class stack{
	public:
		btnode* a[20];
		int top;
	public:
		stack(){
			top=-1;
		}
		int isEmpty(){
			if(top==-1)
			return 1;
			else
			return 0;
		}
		int isFull(){
			if(top==19)
			return 1;
			else
			return 0;
		}
		void push(btnode* ch){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=ch;
		}
		btnode* pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};

/*printing binary tree in preorder*/
void preorder(btnode *T)
{
	if(T!=NULL)
	{
		cout<<T->data<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

int main()
{
	stack S;
	/*binary tree*/
	btnode *B;
	B=new btnode;
	B->lchild=NULL;
	B->rchild=NULL;
	char ch;/*for user input*/
	
	cout<<"Enter the root node\n";
	cin>>B->data;
	S.push(B);
	btnode *T=B;
	/*creating binary tree iterativily*/
	while(!S.isEmpty())
	{
		do
		{
			cout<<"Enter the lchild of "<<T->data<<" \n";
			cin>>ch;
			if(ch!='/')
			{
				T->lchild=new btnode;
				T=T->lchild;
				T->lchild=NULL;
				T->rchild=NULL;
				T->data=ch;
				S.push(T);
			}
		}while(ch!='/');
		
		do
		{
			T=S.pop();
			cout<<"Enter the rchild of "<<T->data<<" \n";
			cin>>ch;
			if(ch!='/')
			{
				T->rchild=new btnode;
				T=T->rchild;
				T->lchild=NULL;
				T->rchild=NULL;
				T->data=ch;
				S.push(T);
			}
		}while(ch=='/'&&!S.isEmpty());
	}
	cout<<"The preorder of tree is :\n";
	preorder(B);
}
