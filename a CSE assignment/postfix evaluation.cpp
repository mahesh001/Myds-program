#include <iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;

class stack
{
	public:
		int a[20]={0};
	//	int nm;
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
		
		int main()
		{
			int i,j,l;
			stack s;
			string s1;
			int nm;
			int n1,n2,n3;
			cout<<"enter the postfix expression\n";
			cin>>s1;
		for(i=0;i<s1.length();i++)
		{
			
				if ( isdigit (s1[i]) )
		{
			nm= s1[i]-'0' ;
			s.push ( nm ) ;
		}
		else
		{
// if operator is encountered
			n1 = s.pop( ) ;
			n2 = s.pop( ) ;
			switch ( s1[i] )
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
			s.push(n3);
		}
		
	}
	//output
	cout<<"the value is:\n";
	nm=s.pop();
	cout<<nm;

	return 0;	

}

