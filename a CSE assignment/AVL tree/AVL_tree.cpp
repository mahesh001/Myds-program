#include<iostream>
#include<cmath>
using namespace std;

struct bstnode
{
	int x;
	bstnode *lchild;
	int data;
	bstnode *rchild;
};

/*Queue class*/
class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=100;
	}
	int front;
	int rear;
	int size;
	bstnode* element[100];
		
	int isfull();
	int isempty();
	void enqueue(bstnode* k);
	bstnode* dequeue();
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

void Queue::enqueue(bstnode* k)
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

bstnode* Queue::dequeue()
{
	bstnode* t;
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

void getx(bstnode *B,int &t)
{
	if(B!=NULL)
	{
		getx(B->lchild,t);
		if(B->data>9)
		{
			B->x=t;
			t=t+2;
		}
		else
		B->x=t++;
		getx(B->rchild,t);
	}
}

int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}

int hight(bstnode *T)
{
	if(T==NULL)
	return -1;
	else
	return 1+max(hight(T->lchild),hight(T->rchild)); 
}

void single_left_rotation(bstnode* &B)
{
	bstnode *K;
	K=B->rchild;
	B->rchild=K->lchild;
	K->lchild=B;
	B=K;
}

void single_right_rotation(bstnode* &B)
{
	bstnode *K;
	K=B->lchild;
	B->lchild=K->rchild;
	K->rchild=B;
	B=K;
}

void double_left_rotation(bstnode* &B)
{
	single_right_rotation(B->rchild);
	single_left_rotation(B);
}

void double_right_rotation(bstnode* &B)
{
	single_left_rotation(B->lchild);
	single_right_rotation(B);
}

/*to find leftmost element of right subtree*/
int leftmost_of_right(bstnode* B)
{
	if(B->rchild!=NULL)
	B=B->rchild;
	else
	return B->data;
	while(B->lchild!=NULL)
	{
		B=B->lchild;
	}
	return B->data;
}
/*rightmost of leftsub tree*/
int rightmost_of_left(bstnode* B)
{
	if(B->lchild!=NULL)
	B=B->lchild;
	else
	return B->data;
	while(B->rchild!=NULL)
	{
		B=B->rchild;
	}
	return B->data;
}
/*deleting element in tree*/
void del(bstnode* &B,int k)
{
	if(B->data==k)
   {
   	  if(B->lchild==NULL&&B->rchild==NULL)
	  {
	  	B=NULL;
	  	cout<<"\nDELETED\n";
   	  }
   	  else if(B->lchild==NULL&&B->rchild!=NULL)
	  {
	  	int lm=leftmost_of_right(B);
	  	del(B,lm);
	  	B->data=lm;
   	  }
   	  else
	  {
	  	int rm=rightmost_of_left(B);
	  	cout<<"rm="<<rm<<endl;
	  	del(B,rm);
	  	B->data=rm;
   	  }
   }
	else if(k<B->data)
	{
		del(B->lchild,k);
		if(((hight(B->rchild)-hight(B->lchild))==2))
		{
			if(B->rchild->rchild==NULL)
			double_left_rotation(B);
			else
			single_left_rotation(B);
		}
	}
	else
	{
		del(B->rchild,k);
		if(((hight(B->lchild)-hight(B->rchild))==2))
		{
			if(B->lchild->lchild==NULL)
			double_right_rotation(B);
			else
			single_right_rotation(B);
		}
	}
}

void Insert(bstnode* &B,int k)
{
	if(B==NULL)
	{
		B=new bstnode;
		B->data=k;
		B->lchild=NULL;
		B->rchild=NULL;
		
	}
	else
	{
		if(k<B->data)
		{
			Insert(B->lchild,k);
			if((hight(B->lchild)-hight(B->rchild))==2)
			{
				if(k<=B->data&&k>=B->lchild->data)
				double_right_rotation(B);
				else
				single_right_rotation(B);
			}
		}
		else
		{
			Insert(B->rchild,k);
			if((hight(B->rchild)-hight(B->lchild))==2)
			{
				if(k<=B->rchild->data)
				double_left_rotation(B);
				else
				single_left_rotation(B);
			}
		}
	}
}

void preorder(bstnode *T)
{
	if(T!=NULL)
	{
		cout<<T->data<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

/*print tree in tree shape*/
void printtree(bstnode *B)
{
	bstnode *T,*T1;
	T1=new bstnode;
	T1->data='*';
	Queue Q,Q1;
	Q.enqueue(B);
	Q.enqueue(T1);
	int xcorr=0,par_count=0;
	while(!Q.isempty())
	{
		//cout<<"inside while loop";
		T=Q.dequeue();
		if(T->data=='*')
		{
			cout<<endl;
			int l=0;
			while(!Q1.isempty())
			{
				//cout<<"in / for";
				bstnode *temp;
				temp=Q1.dequeue();
				for(l;l<temp->x-2;l++)
				cout<<" ";
				if(B->data>9)
				l=l+4;
				else
				l=l+3;
				if(temp->lchild!=NULL)
				cout<<"/";
				else
				cout<<" ";
				if(B->data>9)
				cout<<" ";
				if(temp->rchild!=NULL)
				cout<<" \\";
				else
				cout<<"  ";
			}
			cout<<endl;
			if(!Q.isempty())
			{
				Q.enqueue(T1);
			}
			par_count=0;
			xcorr=0;
		}
		else
		{
			Q1.enqueue(T);
			for(xcorr;xcorr<(T->x-1);xcorr++)
			cout<<" ";
			xcorr++;
			cout<<T->data;
			if(T->lchild!=NULL)
			{
				Q.enqueue(T->lchild);
				par_count++;
			}
			if(T->rchild!=NULL)
			{
				Q.enqueue(T->rchild);
				par_count++;
			}
		}
	}
}

int main()
{
	bstnode *B=NULL;
    int k;
    int t=5;
	do
	{
		cout<<"Enter the no\n";
		cin>>k;
		if(k==-1)
		break;
		Insert(B,k);
		getx(B,t);
		t=5;
		cout<<"The tree is :\n";
		printtree(B);
		cout<<endl;
	}while(k!=-1);
	
	do
	{
		cout<<"Enter the no you want to delete\n";
		cin>>k;
		if(k==-1)
		break;
		del(B,k);
		cout<<"\nInside main DELETED\n";
		getx(B,t);
		t=5;
		cout<<"The tree is :\n";
		printtree(B);
		cout<<endl;
	}while(k!=-1);
}
