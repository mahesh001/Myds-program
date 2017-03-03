#include<iostream>
using namespace std;

struct kdnode
{
	kdnode *lchild;
	void *data[3];
	kdnode *rchild;
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
		kdnode* element[6];
		
	public:
		int isfull();
		int isempty();
		void enqueue(kdnode* k);
		kdnode* dequeue();
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

void Queue::enqueue(kdnode* k)
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

kdnode* Queue::dequeue()
{
	kdnode* t;
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
//for insert value in tree
void insert(kdnode* &T,void *v[],int k,int l)
{
	if(T==NULL)
	{
		T=new kdnode;
		T->data[0]=new int;
		T->data[1]=new char;
		T->data[2]=new double;
		T->lchild=NULL;
		T->rchild=NULL;
		*(int *)(T->data[0])=*(int *)v[0];
		*(char *)(T->data[1])=*(char *)v[1];
		*(double *)(T->data[2])=*(double *)v[2];
	}
	else
	{
		switch(l)
		{
			case 0:
				if(*(int *)(T->data[0])<*(int *)(v[0]))
				insert(T->lchild,v,k,(l+1)%k);
				else
				insert(T->rchild,v,k,(l+1)%k);
			break;
			case 1:
				if(*(char *)(T->data[1])<*(char *)(v[1]))
				insert(T->lchild,v,k,(l+1)%k);
				else
				insert(T->rchild,v,k,(l+1)%k);
			break;
			case 2:
				if(*(double *)(T->data[2])<*(double *)(v[2]))
				insert(T->lchild,v,k,(l+1)%k);
				else
				insert(T->rchild,v,k,(l+1)%k);
			break;
		}
	}
}

/*To print tree in level order*/
void levelorder(kdnode *T,int k)
{
	Queue Q;
	Q.enqueue(T);
	kdnode* T1;
	T1=new kdnode;
	T1->data[0]=new int;
	*(int *)T1->data[0]=-1;
	Q.enqueue(T1);
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(*(int *)(T->data[0])==-1)
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(T1);
		}
		else
		{
			cout<<*(int *)(T->data[0])<<" ";
			cout<<*(char *)(T->data[1])<<" ";
			cout<<*(double *)(T->data[2])<<" ";
		
			cout<<"\t";
			if(T->lchild!=NULL)
			Q.enqueue(T->lchild);
			if(T->rchild!=NULL)
			Q.enqueue(T->rchild);
		}
	}
}

int main()
{
	int k=3;//it is order of kd tree
	kdnode *T=NULL;
	void *v[3];
	v[0]=new int;
	v[1]=new char;
	v[2]=new double;
	char ans;//for user response
	do
	{
		cout<<"Enter three value as int char and double\n";
		cin>>*(int *)v[0]>>*(char *)v[1]>>*(double *)v[2];
		insert(T,v,k,0);
		cout<<"Do you want to enter more y or n\n";
		cin>>ans;
	}while(ans=='y');
	cout<<"\nLevelorder is : \n";
	levelorder(T,k);
}
