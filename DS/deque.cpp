#include<iostream.h>
#include<stdlib.h>
template<class t>
class deque
{
	struct node
	{
     t data;
	 node *next;
	};
	node *head;
	node *curr;
	public:
		deque();
		void push();
		void pop();
		void display();
		void insert();
        void eject();		
};

template<class t>
deque<t>::deque()
{
	head=NULL;
	curr=NULL;
}

template<class t>
void deque<t>::push()
{
	t j;
	cout<<"enter a number";
	cin>>j;
	 if(head==NULL)
	{
		head=new node;
		head->data=j;
		head->next=NULL;
		curr=head;
	}
	else
	{
		node *current=head;
		node *temp=new node;
		temp->data=j;
		temp->next=current;
		head=temp;
	}
}

template<class t>
void deque<t>::pop()
{
	node *current=head;
	if(current->next==NULL)
	head->data=0;
	else
	head=current->next;
	current->next=NULL;
}

template<class t>
void deque<t>::insert()
{
	t j;
	cout<<"enter the element u wish to insert into the list"<<endl;
	cin>>j;
	node *temp=new node;
	temp->data=j;
	curr->next=temp;
	temp->next=NULL;
	curr=temp;
}

template<class t>
void deque<t>::eject()
{
	node *current=head;
	
	if(current->next==NULL)
	head->data=0;
	else
	{
	while(current->next!=curr)
		current=current->next;
	curr=current;
	current->next=NULL;
	}
}

template<class t>
void deque<t>::display()
{
	node *current=head;
	while(current->next!=NULL)
	{
		cout<<current->data<<endl;
		current=current->next;
	}
	if(current->data==0)
	cout<<"no elements in the list"<<endl;
	else
	cout<<current->data<<endl;
}

int main()
{
	deque<int> q;
	int k,i=0;
	while(i==0)
	{
	cout<<"press 1 to push"<<endl;
	cout<<"press 2 to pop"<<endl;
	cout<<"press 3 to insert"<<endl;
	cout<<"press 4 to eject"<<endl;
	cout<<"press 5 to exit"<<endl;
	cin>>k;
    if(k<0 || k>5)
		cout<<"wrong entry"<<endl;
	else
	{
		switch(k)
		{
		case 1:q.push();
				 cout<<"the list after the push operation is :"<<endl;
				q.display();break;
        case 2:q.pop();
                cout<<"the list after the pop operation is done is :"<<endl;
				q.display();break;
		case 3:q.insert();
			    cout<<"the elements after the insertion are :"<<endl;
			   q.display();
			   break;
        case 4:q.eject();
			   cout<<"the elements in the list after the ejection are"<<endl;
			    q.display();
				break;
		case 5:break;
		}
	}
	if(k==5)
	{
		i++;
		exit(1);
	}
	}
return 0;
}
