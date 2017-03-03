#include<iostream.h>
#include<string.h>

template<class t>
class stack
{
	struct node
	{
	  t data;
	 node *next;
	};
	node *head;
	public:
		t s[30];
		int k;
		stack();
		void postfix();
		void push(t& a);
		void pop(t& a);
};

template<class t>
stack<t>::stack()
{
	head=NULL;
}

template<class t>
void stack<t>::push(t& a)
{
	t j;
	j=a;

	 if(head==NULL)
	{
		head=new node;
		head->data=j;
		head->next=NULL;
		 cout<<head->data;
		}

	else
	{
		node *current=head;
		node *temp=new node;
		temp->data=j;
		temp->next=current;
		head=temp;
		cout<<head->data;
		}
}

template<class t>
void stack<t>::pop(t& a)
{
	 t j;
	j=a;
	node *current=head;
	if(j!='(' && j!=')' && j!='*' && j!='+')
		cout<<j;
	else
	{
	 while(current->next!=NULL && current->data!='(')
	{
		cout<<current->data;
		head=current->next;
		current->next=NULL;
		current=head;
	}
	 if(current->next==NULL)
	{
		cout<<current->data;
		head=NULL;
	}
	 else
	 {
	 head=current->next;
	 current->next=NULL;
	 current=head;
	 cout<<current->data;
	  }
	}
}

template<class t>
void stack<t>::postfix()
{	int i;
	i=strlen(s);
	t a,m;
	int p=0;
	for(k=0;k<i;k++)
	{
		a=s[k];

		if(a!='(' && a!=')' && a!='*' && a!='+')
		{
		pop(a);
		}
		else
		{
			if(p==0)
			{
			push(a);
			p++;
			m=a;
			}
			 if(a!=m)
			{
			  if(a<m || a=='(')
			 {
				if(a==')')
				pop(a);
				else
				push(a);
			 }
			 else
			 {
				pop(a);
				push(a);
			 }
			}
			 m=a;
		}
	}
	//pop(a);
}


int main()
{
	stack<char> S;

	cout<<"enter the infix expression"<<endl;
	cin>>S.s;
	S.postfix();
	 return 0;
}