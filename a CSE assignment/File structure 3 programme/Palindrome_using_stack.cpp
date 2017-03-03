#include<iostream>
#include<string>
using namespace std;

class stack{
	private:
		char S[10];
		int top;
		int size;
		
	public:
		stack(){
			top=-1;
			size=10;
		}
		void push(char x);
		char pop();
		int isEmpty();
		int isFull();

};

void stack::push(char x){
	if(isFull()){
		cout<<"Stack is full\n";
	}
	else
	S[++top]=x;
}
char stack::pop(){
	if(isEmpty()){
		cout<<"Stack is Empty\n";
	}
	else
	return S[top--];
}
int stack::isEmpty(){
	if(top==-1){
		return 1;
	}
	else
	return 0;
}
int stack::isFull(){
	if(top==size)
	return 1;
	else
	return 0;
}

int main(){
	int i,j;
	string s;
	cout<<"Enter a string\n";
	cin>>s;
	stack st;
	for(i=0;i<s.length();i++){
		st.push(s.at(i));
	}
	for(i=0;i<s.length();i++){
		if(st.pop()!=s.at(i)){
	      break;
         }
	}
	if(i==(s.length())){
		cout<<"String is Palindrome\n";
	}
	else{
		cout<<"String is not palindrome\n";
	}
	return 0;
}
