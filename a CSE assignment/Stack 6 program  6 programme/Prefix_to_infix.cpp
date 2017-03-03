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
void reverse(string& ex,int size){
	string temp=ex;
	int i;
	for(i=0;i<size;i++)
	temp[i]=ex[size-1-i];
	for(i=0;i<size;i++)
	ex[i]=temp[i];
}
void ptoi(stack& st){
	int i;
	char temp;
		temp=st.pop();
		if(!isalpha(temp)){
			cout<<"(";
			ptoi(st);
			cout<<temp;
			ptoi(st);
			cout<<")";
		}
		else{
			cout<<temp;
		}
	
}
int main(){
	stack st;
	string ex;
	int i,length;
	cout<<"Enter the expression\n";
	cin>>ex;
	length=ex.length();
	reverse(ex,length);
	for(i=0;i<length;i++)
	st.push(ex[i]);
	ptoi(st);
}
