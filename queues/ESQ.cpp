#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class stack
{
	public:
		int a[50]={0};
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
		
		
		int pop(){
			if(isempty())
			cout<<"stack underflow";
			else{
				
				return a[top--];
				
				}
		}
		};
		
		
	struct queue{
	int front;
	int rear;
	int size;
	string elements[20];
	queue(){
		rear=-1;
		front=-1;
		size=20;
		}
	};
int Qisfull(queue Q){
	if(((Q.rear+1)%(Q.size))==(Q.front)){
		return 1;
	}
	else{
	return 0;
	}
}
int Qisempty(queue Q){
	if(Q.front==-1){
		return 1;
	}
	else{
		return 0;
	}
}
void enque(queue &Q,string k){
	if(Qisfull(Q)==1){
		cout<<"Queue is full";
	}
	else{
		if(Q.front==-1 && Q.rear==-1){
			Q.front=0;
			Q.rear=0;
		}
		else{
			Q.rear=(Q.rear+1)%Q.size;
		}
		Q.elements[Q.rear]=k;
	}
}
void deque(queue &Q,string &st){
	string t;
	if(Qisempty(Q)==1){
		cout<<"Queue is empty ";
	   	
	}
	else{
		if(Q.front==Q.rear){
			t=Q.elements[Q.front];
			Q.front=-1;
			Q.rear=-1;
		}
		else{
			t=Q.elements[Q.front];
			Q.front=(Q.front+1)%Q.size;
		}
	st=t;
	}
}

int evaluate(queue q,string st,stack s)
{	stack s2;
		int i,j,l;
		int nm;
		int a,b,c;
		char *a1,*b1,*c1;
		int n1,n2,n3;
		for(i=0;i<st.length();i++)
		{
			if(isalpha(st[i]))
			{
				a=s.pop();
				itoa(a,a1,10);
				st[i]=a1[0];
			}
		}
		
		for(i=0;i<st.length();i++)
		{
			
			if ( isdigit (st[i]) )
				{
					nm= st[i]-'0' ;
					s2.push ( nm ) ;
				}
			else
				{
// if operator is encountered
					n1 = s2.pop( ) ;
					n2 = s2.pop( ) ;
			switch ( st[i] )
			{
				case '+' :
					  n3 = n2 + n1 ;
					  break ;

				case '-' :
					  n3 = n2 - n1 ;
					  break ;

				case '/' :
					  n3 = n2 / n1 ;
					  break ;

				case '*' :
					  n3 = n2 * n1 ;
					  break ;

				case '%' :
					  n3 = n2 % n1 ;
					  break;

				default :
					  cout << "Unknown operator" ;
					  exit (1) ;
			}
			s2.push(n3);
		}
		
	}
	nm=s2.pop();
	return nm;	
}


int main()
{
	int i=0,j,k,n,x;
	queue q;
	stack s;
	string s1;
	int arr[10],l=0;
	string st;
	
	
	while(1)
		{
		cout<<"enter a number to be pushed on the stack(-1 to stop)\n";			
		cin>>x;
		if(x==-1) break;
		s.push(x);
		}
	string str;	
	cout<<"enter the no. of postfix expressions to be entered\n";
	cin>>n;
	cout<<"enter the postfix expressions into the queue\n";
	for(i=0;i<n;i++)
		{
			cout<<"enter an element\n";
			cin>>str;
			enque(q,str);
		}
	
	
	while(!Qisempty(q))
	{
		deque(q,st);
		arr[l++]=evaluate(q,st,s);
		
	}	
	
	cout<<"the values of the postfix expressions of the stack are\n";
	for(i=0;i<l;i++)
	cout<<arr[i]<<" ";
		
	return 0;	
	}
		
		
			


















