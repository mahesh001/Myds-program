#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;

struct enode
{
	enode *lchild;
	char data;
	enode *rchild;
};

/*stack of enode pointers*/
class stack{
	public:
		enode* a[20];
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
		void push(enode* ch){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=ch;
		}
		enode* pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};
/*calcualte fucntion*/
int calculate(int a,int b,char ch)
{
	switch(ch)
	{
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return b/a;
			break;
		default :
			cout<<"unknown operator\n";
	}
}
/*evaluate fucntion for posatfix expression*/
int evaluate(enode *E)
{
	char temp[2];
	if(E!=NULL)
	{
		if(isdigit(E->data))
		{
			temp[0]=E->data;
			return atoi(temp);
		}
		else
		{
			calculate(evaluate(E->lchild),evaluate(E->rchild),E->data);
		}
	}
}

int main()
{
	/*stack object*/
	stack S;
	/*enode object*/
	enode *E;
	enode *T;
	char exp[20];
	cout<<"Enter the postfix expression\n";
	cin>>exp;
	int length=strlen(exp);
	for(int i=0;i<length;i++)
	{
		if(isdigit(exp[i]))
		{
			T=new enode;
			T->data=exp[i];
			S.push(T);
		}
		else
		{
			T=new enode;
			T->data=exp[i];
			T->lchild=S.pop();
			T->rchild=S.pop();
			S.push(T);
		}
	}
	E=S.pop();
	cout<<"The value of postfix expression is: \n";
	cout<<evaluate(E);
}
