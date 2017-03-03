#include<iostream>
#include<cstring>

using namespace std;

struct hnode
{
	hnode()
	{
		next=NULL;
		lchild=NULL;
		rchild=NULL;
	}
	char data;
	int f;
	hnode *lchild;
	hnode *rchild;
	hnode *next;
};

class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=6;
	}
	private:
		int front;
		int rear;
		int size;
		hnode* element[6];
		
	public:
		int isfull();
		int isempty();
		void enqueue(hnode* k);
		hnode* dequeue();
};
int Queue::isfull()
{
	if((rear+1)%size==front)
	 return 1;
	else
	 return 0;
}

int Queue::isempty()
{
	if(front==-1)
	 return 1;
	else
	 return 0;
}

void Queue::enqueue(hnode* k)
{
	if(isfull())
	  cout<<"Queue is full\n";
	else if(front==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear=(rear+1)%size;
	}
	element[rear]=k;
}

hnode* Queue::dequeue()
{
	hnode* t;
	if(isempty())
	  return NULL;
	else
	{
		if(front==rear)
		{
		  t=element[front];
		  front=-1;
		  rear=-1;	
		}
		else
		{
			t=element[front];
			front=(front+1)%size;
		}
		return t;
	}
}

void addend(hnode* &L,hnode* T)
{
	if(L==NULL)
	{
		L=T;
	}
	else
	{
	  hnode *temp=L,*pre=NULL;
	  while(temp!=NULL&&T->f>temp->f)
	  {
	  	 pre=temp;
	  	 temp=temp->next;
	  }
	  if(pre==NULL)
	  {
	  	 T->next=L;
	  	 L=T;
	  }
	  else
	  {
	  	 T->next=pre->next;
	  	 pre->next=T;
	  }
    }
   
}


void printList(hnode *L)
{
	if(L==NULL)
	cout<<"List is empty\n";
	else
	{
      while(L!=NULL)
       {
  	     cout<<L->data<<" "<<L->f<<" "<<endl;
  	     L=L->next;
       }	
       cout<<endl;
    }
}

hnode* hoffman(hnode* &L)
{
	hnode *left,*right;
	while(L!=NULL)
	{	
	  left=L;
	  L=L->next;
	  if(L==NULL)
	  break;
	  right=L;
	  L=L->next;
	  hnode *T=new hnode;
	  T->lchild=left;
	  T->rchild=right;
	  T->data='+';
	  T->f=(left->f+right->f);
	  addend(L,T);
	}
	return left;
}
void eval(char *exp,hnode *H)
{
	hnode *head=H;
	char ch;
	int len=strlen(exp);
	for(int i=0;i<len;i++)
	{
		ch=exp[i];
		if(ch=='0')
		{
		   H=H->lchild;
		}
		else if(ch=='1')
		{
		   H=H->rchild;
		}
		if(H->data!='+')
		{
		   cout<<H->data;
		   H=head;
		}
	}
}

void Level_order(hnode *H)
{
	Queue Q;
	hnode *T;
	hnode *T1=new hnode;
	T1->data='*';
	Q.enqueue(H);
	Q.enqueue(T1);
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data=='*')
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(T1);
		}
		else
		{
			cout<<T->data<<" "<<T->f<<"\t";
			if(T->lchild!=NULL)
			Q.enqueue(T->lchild);
			if(T->rchild!=NULL)
			Q.enqueue(T->rchild);
		}
	}
}

int main()
{
   hnode *L=NULL;
   hnode *T;
   char ch;
   int f;
   do
   {
   	 cout<<"Enter the charctor enter / to stop\n";
     cin>>ch;
     if(ch=='/')
     break;
     T=new hnode;
     T->data=ch;
     cout<<"Enter the frequency\n";
     cin>>f;
     T->f=f;
     addend(L,T);
   }while(ch!='/');
   
   cout<<"You Entered\n";
   printList(L);
   hnode *H;
   H=hoffman(L);
   cout<<"Hoffman tree is :\n";
   Level_order(H);
   cout<<"Enter binary string\n";
   char exp[20];
   cin>>exp;
   eval(exp,H);
}
