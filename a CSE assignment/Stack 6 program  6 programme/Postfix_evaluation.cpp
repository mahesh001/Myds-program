#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class stack{
	private:
		int S[10];
		int top;
		int size;
		
	public:
		stack(){
			top=-1;
			size=10;
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
	else
	S[++top]=x;
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
	if(top==size)
	return 1;
	else
	return 0;
}
int isSymbol(char x){
	int temp;
	temp=x;
	if(temp<48||temp>57){
		return 1;
	}
	else
	return 0;
}

int operation(int a,int b,char op){
	switch(op){
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


int main(){
	int i,temp1;
	int a,b,ans;
	char ch,temp2,x[2],y[2],z[2];
	stack st;
	string prefix;
	cout<<"Enter prefix expession\n";
	cin>>prefix;
	for(i=0;i<prefix.length();i++){
		ch=prefix.at(i);
	    //cout<<"no in string are "<<prefix.at(i)<<endl;
		if(isSymbol(ch)){
			a=st.pop();
			b=st.pop();
			st.push(operation(a,b,ch));
			//cout<<"The push is"<<operation(a,b,prefix.at(i))<<endl;                                                               
		}
		else{
			z[0]=ch;
			st.push(atoi(z));
		}
		
	}
	ans=st.pop();
	cout<<"The ans is "<<ans<<endl;
	return 0;
}
