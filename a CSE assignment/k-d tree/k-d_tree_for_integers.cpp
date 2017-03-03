#include<iostream>
using namespace std;

int k=2;
struct kdnode
{
	kdnode *lchild;
	int data[2];
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

/*to insert values in the tree*/
void insert(kdnode* &T,int v[],int l)
{
	if(T==NULL)
	{
		T=new kdnode;
		T->lchild=NULL;
		T->rchild=NULL;
		for(int i=0;i<k;i++)
		T->data[i]=v[i];
	}
	else
	{
		if(v[l]<T->data[l])
		insert(T->lchild,v,(l+1)%k);
		else
		insert(T->rchild,v,(l+1)%k);
	}
}
/*To print tree in level order*/
void levelorder(kdnode *T)
{
	Queue Q;
	Q.enqueue(T);
	kdnode* T1;
	T1=new kdnode;
	T1->data[0]=-1;
	Q.enqueue(T1);
	while(!Q.isempty())
	{
		//cout<<" inside while ";
		T=Q.dequeue();
		if(T->data[0]==-1)
		{
			//cout<<" inside if ";
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(T1);
		}
		else
		{
			//cout<<" inside else ";
			for(int i=0;i<k;i++)
			cout<<T->data[i]<<" ";
			cout<<"\t";
			if(T->lchild!=NULL)
			Q.enqueue(T->lchild);
			if(T->rchild!=NULL)
			Q.enqueue(T->rchild);
		}
	}
}

int search(kdnode *T,int v[],int l)
{
	if(T==NULL)
	return 0;
	else if(T->data[l]==v[l])
	return 1;
	else if(v[l]<T->data[l])
	search(T->lchild,v,(l+1)%k);
	else
	search(T->rchild,v,(l+1)%k);
}

int main()
{
	kdnode *T=NULL;
	int v[k];//contains values for single node
	char ans;//for user responce
	do
	{
		cout<<"Enter "<<k<<" values for a node\n";
		for(int i=0;i<k;i++)
		cin>>v[i];
		insert(T,v,0);
		cout<<"do you want to enter more y or n \n";
		cin>>ans;
	}while(ans=='y');
	//cout<<"T->data[0]="<<T->data[0];
	cout<<"The tree in levelorder is:\n";
	levelorder(T);
	cout<<"Enter the value to be search\n";
	for(int i=0;i<k;i++)
	cin>>v[i];
	if(search(T,v,0))
	cout<<"Element found\n";
	else
	cout<<"Not found\n";
}
