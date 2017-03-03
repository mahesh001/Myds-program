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
		int relevance(char ch)
        {
         if(ch=='*'||ch=='/')
         return 2;
         else if(ch=='+'||ch=='-')
         return 1;
         else
         return 0;
         }
  /*int last()
  {
      return (relevance(a[top]));
      }
	*/	
		int main()
		{
		stack k;	
		char rev[100],pre[100],ch;
			string s;
			int i,j=0,l;
			cout<<"enter the expression in infix form\n";
			cin>>s;
			l=s.length();
			for(i=0;i<l;i++)
			{
				rev[j++]=s[l-i-1];
			}
			
			for(i=0;i<l;i++)
			{
				if(rev[i]!='*'&&rev[i]!='/'&&rev[i]!='+'&&rev[i]!='-')
				{
					pre[j++]=s[i];
             }
             else
             {
                 int x=relevance(k.a[k.top]);
                 int b=relevance(rev[i]);
                 if(b>x)
                 k.push(rev[i]);
                 else
                     {
                     pre[j++]=k.pop();
                     k.push(rev[i]);
                     }
             }
        	}
        	ch=k.pop();
                     while(!k.isempty())
                     			{
                                   pre[j++]=ch;
                                   ch=k.pop();
                                   }
        	
        	//output
        	for(i=j-1;i>=0;i--)
        	{
        		if(pre[i]!=')'||pre[i]!='(')
        		cout<<pre[i];
        	}
				return 0;	
		}
		//(a–b)/c*(d + e – f / g)
