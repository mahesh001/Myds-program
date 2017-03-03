#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;

/*stack of string*/

class stack{
	public:
		string a[20];
		int top;
	public:
		stack()
		{
			top=-1;
		}
		int isEmpty()
		{
			if(top==-1)
			return 1;
			else
			return 0;
		}
		int isFull()
		{
			if(top==19)
			return 1;
			else
			return 0;
		}
		void push(string str)
		{
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=str;
		}
		string pop()
		{
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};

/*stack of intergers*/

class stackint{
	public:
		int a[20];
		int top;
	public:
		stackint(){
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
		void push(int i){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=i;
		}
		int pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};

int operation(int a,int b,char op)
{
	switch(op)
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
			return a/b;
			break;
    }
}
int main()
{
	stack st;
	stackint integers,postfix;
	string exp;
	char ch1='y',ch;
	int i,k,a,b,length,term=0;
	
	/* input for stack */
	cout<<"Enter the postfix expression\n";
	while(ch1=='y')
	{
		cin>>exp;
		st.push(exp);
		cout<<"want to enter more (y for yes and n for no)\n";
		cin>>ch1;
	}
	ch1='y';
	/*input for stack of integers*/
	cout<<"Enter the no for stack of integers for exit enter -1\n";
	while(1)
	{
		cin>>k;
		if(k==-1)
		break;
		integers.push(k);
	}
	/*poping the stack for expressions*/
	while(!st.isEmpty())
	{
		exp=st.pop();
		length=exp.length();
		for(i=0;i<length;i++)
		{
		  ch=exp[i];
		  if(!isalpha(ch))
		  {
			a=integers.pop();
			b=integers.pop();
			integers.push(operation(a,b,ch));                                                               
		  }
		}
		cout<<"The ans for term "<<++term<<" is "<<integers.pop()<<endl;
	}
}
