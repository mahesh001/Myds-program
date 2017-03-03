#include<iostream>
using namespace std;
class stack
{
	public:
		int a[20]={0};
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
void sort(stack &S1,stack &S2)
{    int temp;

     while(!S1.isempty())
     {    temp=S1.pop();
         while(!S2.isempty()&&S2.a[S2.top]>temp)
            S1.push(S2.pop());
            S2.push(temp);
     }
}
int main()
{  stack s1,s2;
   int n;
		   
   while(1)
      {   cout<<"Enter elements(-1 to stop)";
          cin>>n;
          if(n==-1) break;
	      s1.push(n);
	  }
	 sort(s1,s2);
	 cout<<"\nthe sorted numbers are:";
	   while(!s2.isempty())
	      cout<<s2.pop()<<" ";
		  
		  return 0;  
}		
