#include<iostream>
#include<string>
using namespace std;

class stack{
	public:
		char a[20];
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

int main(){
	stack st;
	string name;
	int i,length;
	char ch;
	cout<<"Enter your name\n";
	cin>>name;
	length=name.length();
	for(i=0;i<length;i++){
	ch=name.at(i);
	st.push(ch);	
	}
	cout<<"You Entered\n";
	while(!st.isEmpty())
	cout<<st.pop();
}
