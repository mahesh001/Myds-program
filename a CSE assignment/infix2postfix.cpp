#include<iostream>
using namespace std;
int top=0;
char s[50];
void push(char ch)
{
     s[++top]=ch;
     }
char pop()
{
     return (s[top--]);
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
  int last()
  {
      return (relevance(s[top]));
      }
      int main()
      {
          int a,b,i,j=0;
          push('#');
          char ch,in[50],post[50];
          cout<<"enter the infix expression\n";
          cin>>in;
          for(i=0;in[i]!='\0';i++)
          {
          if(in[i]!='%'&&in[i]!='*'&&in[i]!='/'&&in[i]!='+'&&in[i]!='-')
          {
             post[j++]=in[i];
             }
             else
             {
                 a=last();
                 b=relevance(in[i]);
                 if(b>a)
                 push(in[i]);
                 else
                 {
                     post[j++]=pop();
                     push(in[i]);
                     }
                     }
                     }
                     ch=pop();
                     while(ch!='#')
                     {
                                   post[j++]=ch;
                                   ch=pop();
                                   }
                          cout<<"the postfix expression is\n";
                          for(i=0;i<j;i++)
                          cout<<post[i];
                          return 0;
                          }


