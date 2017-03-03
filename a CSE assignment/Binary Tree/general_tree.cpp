#include<iostream>
using namespace std;

struct gtnode
{
	int x;
	char data;
	int cc;
	gtnode **ch;
};
/*Queue class storing gtnode pointers*/
class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=20;
	}
	private:
		int front;
		int rear;
		int size;
		gtnode* element[20];
		
	public:
		int isfull();
		int isempty();
		void enqueue(gtnode* k);
		gtnode* dequeue();
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

void Queue::enqueue(gtnode* k)
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

gtnode* Queue::dequeue()
{
	gtnode* t;
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
void getx(gtnode *G,int &t)
{
	if(G!=NULL)
	{
		getx(G->ch[0],t);
		G->x=t++;
		for(int i=1;i<G->cc;i++)
		getx(G->ch[i],t);
	}
}
/*function for creating general tree*/
void create(gtnode* &G)
{
	if(G==NULL)
	{
		char ch;
		cin>>ch;
		if(ch!='/')
		{
			G=new gtnode;
			G->data=ch;
			cout<<"Enter the no of child\n";
			cin>>G->cc;
			if(G->cc!=0)
			{
			   G->ch=new gtnode*[G->cc];
			   for(int i=0;i<G->cc;i++)
			   {
				  G->ch[i]=NULL;
				  cout<<"Enter the value "<<i+1<<" child\n";
				  create(G->ch[i]);
			   }
			}
			else
			G->ch=NULL;
			
		}
	}
}
/*levelorder printing*/
void levelorder(gtnode *G)
{
	gtnode *T,*G1;
	G1=new gtnode;
	G1->data='*';
	Queue Q;
	//cout<<"g->data ="<<G->data;
	Q.enqueue(G);
	Q.enqueue(G1);
	//cout<<"T->data ="<<Q.dequeue()->data;
	while(!Q.isempty())
	{
		//cout<<"Inside while\n";
		T=Q.dequeue();
		//cout<<"T->data ="<<T->data;
		if(T->data=='*')
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(G1);
		}
		else
		{
			//cout<<"inside else";
			cout<<T->data<<" ";
			for(int i=0;i<T->cc;i++)
			{
				//cout<<"inside for\n";
				if(T->ch[i]!=NULL)
				Q.enqueue(T->ch[i]);
			}
		}
	}
}
void preorder(gtnode *G)
{
	if(G!=NULL)
	{
		for(int i=0;i<G->cc;i++)
		preorder(G->ch[i]);
		cout<<G->data<<" ";
	}
}
/*printing in treeshape*/
void printtree(gtnode *G)
{
	gtnode *T,*G1;
	G1=new gtnode;
	G1->data='*';
	Queue Q;
	Q.enqueue(G);
	Q.enqueue(G1);
	int xcorr=0;
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data=='*')
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(G1);
			xcorr=0;
		}
		else
		{
			for(xcorr;xcorr<(T->x-1);xcorr++)
			cout<<" ";
			cout<<T->data;
			xcorr++;
			for(int i=0;i<T->cc;i++)
			{
				if(T->ch[i]!=NULL)
				Q.enqueue(T->ch[i]);
			}
		}
	}
}
int main()
{
	gtnode *G;
	G=NULL;
	cout<<"Enter the root value\n";
	create(G);
	cout<<"The preorder is:\n";
	preorder(G);
	cout<<"\nLevel order printing is: \n";
	levelorder(G);
	cout<<"Tree in treeshape\n";
	printtree(G);
	//cout<<G->data;
}
