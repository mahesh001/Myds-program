#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>
using namespace std;

class stackchar{
	public:
		char a[50];
		int top;
	public:
		stackchar(){
			top=-1;
		}
		int isEmpty(){
			if(top==-1)
			return 1;
			else
			return 0;
		}
		int isFull(){
			if(top==49)
			return 1;
			else
			return 0;
		}
		void push(char ch){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=ch;
		}
		char pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};
class stackint{
	public:
		int a[50];
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
			if(top==49)
			return 1;
			else
			return 0;
		}
		void push(int x){
			if(isFull())
			cout<<"Stack overflow\n";
			else
			a[++top]=x;
		}
		int pop(){
			if(isEmpty())
			cout<<"Stack is underflow\n";
			else
			return a[top--];
		}
};
int operate(int a,int b,char ch1){
	switch(ch1){
		case '+':
			return a+b;
			break;
		case '-':
			return b-a;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return b/a;
			break;
	}
}
int priority(char x){
	if(x=='+'||x=='-')
	return 1;
	else if(x=='*'||x=='/')
	return 2;
	else
	return 0;
}
void comp(char ch,char ch1,stackchar& opr,stackint& opn){
	int temp;
	if(priority(ch1)>priority(ch)){
		temp=operate(opn.pop(),opn.pop(),ch1);
		opn.push(temp);
		opr.push(ch);
	}
	else{
		opr.push(ch1);
		opr.push(ch);
	}
}
void infixevaluation(stackchar& opr,stackint& opn,string& ex){
	int i,length;
	length=ex.length();
	char ch[2],ch1,a,b;
	for(i=0;i<length;i++){
		ch[0]=ex.at(i);
		if(isdigit(ch[0])){
			opn.push(atoi(ch));
		}
		else if(opr.isEmpty()){
			opr.push(ch[0]);
		}
	    else if(ch[0]=='('){
				opr.push(ch[0]);
		}
		else if(ch[0]==')'){
				ch1=opr.pop();
				while(ch1!='('){
					a=opn.pop();
					b=opn.pop();
					opn.push(operate(a,b,ch1));
					ch1=opr.pop();
				}
		}
		else{
				comp(ch[0],opr.pop(),opr,opn);
			}
	}
}

int main(){
	//stacks
	stackchar opr;
	stackint opn;
	//string
	string ex; //infix expression string
	int i,result,a,b,length;
	cout<<"Enter infix expression\n";
	cin>>ex;
	length=ex.length();
	infixevaluation(opr,opn,ex);
	cout<<"Evaluated Value is :";
	while(opn.top!=0){
		a=opn.pop();
		b=opn.pop();
		result=operate(a,b,opr.pop());
		opn.push(result);
	}
	cout<<opn.pop();
}
