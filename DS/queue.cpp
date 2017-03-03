#include<iostream.h>
template<class Etype>
class deque
{
	private:
		struct Node
		{
			Etype x;
			Node *next;
			Node(Etype e=0,Node *n=NULL):
			x(e),next(n){}
		};
		Node *head;
		Node *current_pos;
		Node *current_pos1;
	public:
		void push();
		void pop();
		void inject();
		void eject();
		deque();
		void print();
};
template<class Etype>
deque<Etype>::deque()
{
	head=new Node(0,NULL);
}
template<class Etype>
void deque<Etype>::push()
{
	int n;
	current_pos=head;
	char choice='y';
	while(choice!='n')
	{
		cout<<"Enter any number into queue"<<endl;
		cin>>n;
		if(current_pos->next==NULL)
		{
			Node *temp=new Node(n,NULL);
			current_pos->next=temp;
			current_pos1=temp;
		}
		else
		{
			Node *temp=new Node(n,current_pos->next);
			current_pos->next=temp;
		}
		cout<<"Want to enter more (y/n):"<<endl;
		cin>>choice;
	}
		cout<<"The queue after push is "<<endl;
	print();
}
template<class Etype>
void deque<Etype>::pop()
{
	current_pos=head;
	if(current_pos->next==NULL)
		cout<<"The queue is empty"<<endl;
	else
		current_pos->next=current_pos->next->next;
	cout<<"The queue after pop is "<<endl;
	print();
}
template<class Etype>
void deque<Etype>::inject()
{
	int n;
	char choice='y';
	while(choice!='n')
	{
		cout<<"Enter any number to inject"<<endl;
		cin>>n;
		Node *temp1=new Node(n,NULL);
		current_pos1->next=temp1;
		current_pos1=temp1;
		cout<<"Want to enter more (y/n):"<<endl;
		cin>>choice;
	}
		cout<<"The queue after inject is "<<endl;
		print();
}
template<class Etype>
void deque<Etype>::eject()
{
	current_pos=head;
	if(current_pos->next==NULL)
		cout<<"The queue is Empty "<<endl;
	while(current_pos->next->next!=NULL)
		current_pos=current_pos->next;
	current_pos->next=NULL;
	cout<<"The queue after eject is "<<endl;
	print();
}
template<class Etype>
void deque<Etype>::print()
{
	current_pos=head;
	current_pos=current_pos->next;
	while(current_pos->next!=NULL)
	{
		cout<<current_pos->x<<"    ";
		current_pos=current_pos->next;
	}
	cout<<current_pos->x<<endl;
}
int main()
{
	deque<int> d;
	int i;
	char choice='y';
	while(choice!='n')
	{
		cout<<"Enter 1-push"<<endl;
		cout<<"      2-pop"<<endl;
		cout<<"      3-inject"<<endl;
		cout<<"      4-eject"<<endl;
		cin>>i;
			switch(i)
			{
				case 1:d.push();
						break;
				case 2:d.pop();
						break;
				case 3:d.inject();
						break;
				case 4:d.eject();
						break;
			}
			cout<<"want to do more operations (y/n):"<<endl;
			cin>>choice;
		}
	return 0;
}

