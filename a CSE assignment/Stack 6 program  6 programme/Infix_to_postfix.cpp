#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class stack{
	public:
		char a[50];
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
int priority(char x){
	if(x=='+'||x=='-')
	return 1;
	else if(x=='*'||x=='/')
	return 2;
	else
	return 3;
}
void comp(stack& st,char ch,char ch1){
	if(priority(ch)>priority(ch1)||priority(ch1)==3){
		st.push(ch1);
		st.push(ch);
	}
	else if(priority(ch1)>=priority(ch))
	{
		cout<<ch1;
		if(st.isEmpty()){
			st.push(ch);
		}
		else
		comp(st,ch,st.pop());
	}
	
}
int main(){
	stack st;
	string ex;
	int i,length;
	char ch,ch1;
	cout<<"Enter the infix expression\n";
	cin>>ex;
	length=ex.length();
	for(i=0;i<length;i++){
		ch=ex.at(i);
		if(isalpha(ch)){
			cout<<ch;
		}
		else if(ch=='('){
			st.push(ch);
		}
		else if(ch==')'){
			ch1=st.pop();
			while(ch1!='('){
				cout<<ch1;
				ch1=st.pop();
			}
		}
		else if(st.isEmpty()){
			st.push(ch);
		}
		else{
			comp(st,ch,st.pop());
			}
	}
	while(!st.isEmpty()){
		cout<<st.pop();
	}
}
