#include<iostream>
using namespace std;

struct btnode
{
	btnode *lchild;
	char data;
	btnode *rchild;
};

/*stack of pointer of type btnode*/
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

/*for printing postorder*/
void postorder(btnode *T)
{
	if(T!=NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout<<T->data<<" ";
	}
}

int main()
{
	/*bt node object*/
	btnode *B;
	/*stack object*/
	stack S;
	S.push(B);
	/*creation of binary tree by iteration*/
	cout<<"Enter the root value of bt tree\n";
	while(!S.isEmpty())
	{
		btnode *T;
		T=S.pop();
		T=new btnode;
		cout<<"Enter the value\n";
		cin>>T->data;
		cout<<"Want to lchild of "<<T->data<<" y for yes n for no"<<endl;
		char ch;/*for user's response*/
		cin>>ch;
		if(ch=='y')
		S.push(T->lchild);
		cout<<"Want to rchild of "<<T->data<<" y for yes n for no"<<endl;
		cin>>ch;
		if(ch=='y')
		S.push(T->rchild);
	}
	/*printing postorder*/
	cout<<"The postorder is :";
	postorder(B);
}
