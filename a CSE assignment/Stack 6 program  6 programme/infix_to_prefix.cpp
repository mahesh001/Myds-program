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
void reverse(string& a,int size){
	string temp=a;
	int i;
	for(i=0;i<size;i++)
	temp[size-1-i]=a[i];
	for(i=0;i<size;i++)
	a[i]=temp[i];
}
void reverse(char temp[],int k)
	{  
		char temp1[50];int i,j;
		for (i=k-1,j=0;i>=0;i--,j++) {
		temp1[j]=temp[i];}
		for(i=0;i<k;i++)
		temp[i]=temp1[i];
	}
void comp(stack& st,char ch,char ch1,char c[],int& k){
	if(priority(ch)>priority(ch1)||priority(ch1)==3){
		st.push(ch1);
		st.push(ch);
	}
	else if(priority(ch1)>=priority(ch))
	{
		c[k++]=ch1;
		if(st.isEmpty()){
			st.push(ch);
		}
		else
		comp(st,ch,st.pop(),c,k);
	}
	
}
void infixtoprefix(string& ex,int size,stack& st){
	int i,k=-1;
	char c[20],ch,ch1;
   for(i=0;i<size;i++){
		ch=ex.at(i);
		if(isalpha(ch)){
			c[k++]=ch;
		}
		else if(ch==')'){
			st.push(ch);
		}
		else if(ch=='('){
			ch1=st.pop();
			while(ch1!=')'){
				c[k++]=ch1;
				ch1=st.pop();
			}
		}
		else if(st.isEmpty()){
			st.push(ch);
		}
		else{
			comp(st,ch,st.pop(),c,k);
			}
	}
	while(!st.isEmpty()){
		c[k++]=st.pop();
	}
	reverse(c,k);
	cout<<c;	
}
int main(){
	stack st;
	string ex;
	int a[20],i,k=0,length;
	char ch,ch1;
	cout<<"Enter the infix expression\n";
	cin>>ex;
	length=ex.length();
	reverse(ex,length);
    infixtoprefix(ex,length,st);
}
