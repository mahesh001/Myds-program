#include<iostream>
#include<string>
#include<iomanip>
#include<cstring>
#include<cstdlib>
using namespace std;

class stack
{
	public:
		char a[20]={0};
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
		void calculate(char ch,stack &opd)
	{	char q[1],w[1];
			int n1, n2, n3 ;		/* if operator is encountered */
			q[0] = opd.pop( ) ;
			w[0] = opd.pop( ) ;
			n1=atoi(q);
			n2=atoi(w);
			switch ( ch )
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

				default :
					  cout << "Unknown operator" ;
				break;
			}

			opd.push ( n3 ) ;
		}
	
		int relevance(char ch)
     	 {
         if(ch=='*'||ch=='/')
         return 2;
         else if(ch=='+'||ch=='-')
         return 1;
         else
         return 0;
         }
		
		
		
		int main()
		{
			string s;
			stack opd,opr;
			int i,j,k;
			
			cout<<"enter the infix expression to be evaluated\n";
			cin>>s;
			
			for(i=0;i<s.length();i++)
			{
				if(isdigit(s[i]))
				{
					opd.push(s[i]);
				}
				else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
				{
					int a=relevance(s[i]);
					int b=relevance(opr.a[top]);
					if(b>a)
        			{
                 		if(!opr.isempty())
                 	char k=opr.pop(opr.a[top]);
                 	calculate(k,opd);
					 opr.push(s[i]);
					 }
					 else
                 	{
                    opr.push(s[i]);
                    }
                }
				}
				while(!opr.isempty())
				{
					char l=opr.pop();
					calculate(l,opd);
				}
				char ans=opd.pop();
				cout<<"the value is:\n";
				cout<<ans;
				
				return 0;
				
			}
			
			
			
		
		
		
