#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node *link;
};
struct node *insert_s(struct node *start, int data);
void search (struct node *start, int data);
void display(struct node *start);

int main()
{
	int choice,data;
	struct node *start=NULL;
	char ch='y';
	while(ch=='y')
	{
		cout<<"1.insert \n 2.display \n 3.search \n";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"enter the element to be inserted \n";
			        cin>>data;
			        start=insert_s(start,data);
			        break;
			case 2: display(start);
			        break;
			case 3: cout<<"enter the element to be searched \n";
			        cin>>data;
					search(start,data);
					break;
			default: cout<<"wrong choice";				        
		}
		cout<<"do you want to continue \n";
		cin>>ch;
	}
}

struct node *insert_s(struct node *start, int data)
{
	struct node *p, *temp;
	temp=new node;
	temp->info=data;
	if(start==NULL|| data<start->info)
	{
		temp->link=start;
		start=temp;
		return start;
	}
	else 
	{
		p=start;
		while(p->link!=NULL && p->link->info < data)
		  p=p->link;
		temp->link = p->link;
		p->link=temp;
	}
	return start;
}

void search(struct node *start, int data)
{
	struct node *p;
	int pos;
	if(start==NULL|| data < start->info)
	{
		cout<<"not found in list";
		return;
	}
	p=start;
	pos=1;
	while(p!=NULL && p->info < data)
	{
		if(p->info==data)
		{
			cout<<data<<"found at position"<<pos<<"\n";
			return;
		}
		p=p->link;
		p++;
	}
	cout<<data<<"not found in list \n";
}

void display(struct node *start)
{
	struct node *q;
	if(start==NULL)
	{
		cout<<"list is empty \n";
		return;
	}
	q=start;
	cout<<"list is \n";
	while(q!=NULL)
	{
		cout<<q->info;
		q=q->link;
	}
	cout<<"\n";
}
