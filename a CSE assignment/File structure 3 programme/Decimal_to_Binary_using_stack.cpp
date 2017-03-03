#include<iostream>
using namespace std;
class stack{
	private:
		int S[50];
		int top;
		int size;
		
	public:
		stack(){
			top=-1;
			size=50;
		}
		void push(int x);
		int pop();
		int isEmpty();
		int isFull();
		

};


void stack::push(int x){
	if(isFull()){
		cout<<"Stack is full\n";
	}
	else{
	S[++top]=x;
    }
}
int stack::pop(){
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
	if(top==size){
		return 1;
	}
	else
	return 0;
}

int main(){
	 stack st;
	 int no;
	 cout<<"Enter no in Decimal\n";
	 cin>>no;
	 while(no/2!=0){
	 	st.push(no%2);
	 	no=no/2;
	 }
	 st.push(no);
	cout<<"Binary equivalent of no is ";
	while(!st.isEmpty()){
		cout<<st.pop();
	}
	 return 0;
}
