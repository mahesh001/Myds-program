#include<iostream>
#include<string>
using namespace std;
class stack
{
	public:
		char a[20];
		int top;
		stack()
		{top=-1;
		}
		int isfull(){
			if(top==19)
			return 1;
			else 
			return 0;
		}
		
		int isempty(){
			if(top==-1)
			return 1;
			else 
			return 0;
		}
		void push(char x){
			if(isfull())
			cout<<"stack overflow";
			else
			a[++top]=x;
			
		}
		
		
		char pop(){
			if(isempty())
			cout<<"stack underflow";
			else{
				
				return a[top--];
				
				}
		}
		};
int isSymbol(char x){
	if(x=='+'||x=='-'||x=='*'||x=='/'||x=='('||x==')'){
		return 1;
	}
	else{
		return 0;
	}
}
int priority(char ch){
	switch(ch){
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
		    return 3;
	        break;
		case '/':
			return 2;
			break;
		case '(':
			return 7;
			break;
		case ')':
			return 7;
			break;
	}
}
int main(){
	stack st;
	int i;
	char ch,ch1;
	string ex;
	cout<<"Enter the infix expression\n";
	cin>>ex;
	for(i=0;i<ex.length();i++){
		ch=ex.at(i);
		if(isSymbol(ch)){
			if(ch=='('){
				st.push(ch);
			}
			if(ch==')'){
				ch=st.pop();
				while(ch!='('){
					cout<<ch;
					ch=st.pop();
				}
			}
			if(!st.isempty()){
			   ch1=st.pop();
			   if(priority(ch)>priority(ch1)){
			   	cout<<ch;
			   }
			else{
			   	st.push(ch);
			   }	
			}
		}
		else{
			cout<<ch;
		}
	}
	while(!st.isempty()){
		ch=st.pop();
		cout<<ch;
	}
}
