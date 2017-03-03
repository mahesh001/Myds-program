#include<iostream>
using namespace std;
const int d=1;

struct bdnode
{
	bdnode()
	{
		c=0;
		for(int i=0;i<2*d+2;i++)
		ptr[i]=NULL;
	}
	int data[2*d+1];
	bdnode* ptr[2*d+2];
	int c;
};

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
		bdnode* element[20];
		
	public:
		int isfull();
		int isempty();
		void enqueue(bdnode* k);
		bdnode* dequeue();
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

void Queue::enqueue(bdnode* k)
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

bdnode* Queue::dequeue()
{
	bdnode* t;
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

void Level_order(bdnode *B)
{
	Queue Q;
	bdnode *T,*T1;
	T1=new bdnode;
	T1->data[0]=-1;
	Q.enqueue(B);
	Q.enqueue(T1);
	
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data[0]==-1)
		{
			cout<<endl;
			if(!Q.isempty())
			Q.enqueue(T1);
		}
		else
		{
			int i;
			for(i=0;i<T->c;i++)
			cout<<T->data[i]<<" ";
			for(i;i<2*d;i++)
			cout<<"* ";
			cout<<"\t";
			
			for(i=0;i<=T->c;i++)
			{
			   if(T->ptr[i]!=NULL)
			   Q.enqueue(T->ptr[i]);
			}
		}
	}
}

void Sort(int a[],int size)
{
	int i=0,j=0,temp;
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1);j++)
		{
		   if(a[j]>a[j+1])
		   {
			  temp=a[j];
			  a[j]=a[j+1];
			  a[j+1]=temp;
		   }
		}
	}
}

int Find_index(int *a,int k,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==k)
		return i;
    }
}

void Insert_and_Sort(bdnode *B,int k)
{
	int i,j;
	B->data[B->c++]=k;
	int t,size=B->c;
	bdnode* tptr;
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1);j++)
		{
			if(B->data[j]>B->data[j+1])
			{
				t=B->data[j];
				B->data[j]=B->data[j+1];
				B->data[j+1]=t;
				tptr=B->ptr[j+1];
				B->ptr[j+1]=B->ptr[j+2];
				B->ptr[j+2]=tptr;
			}
		}
	}
}

int check_leafnode(bdnode *B)
{
	int i;
	for(i=0;i<(2*d+1);i++)
	{
		if(B->ptr[i]!=NULL)
		break;
	}
	if(i==(2*d+1))
	return 1;
	else
	return 0;
}

int Find(int *a,int k)
{
   int i;	
   for(i=0;i<2*d;i++)
   {
   	 if(a[i]==k)
   	 return i;
   }
}

void Node_split(bdnode *T,bdnode* &N,int &median)
{
	int i;
	N=new bdnode;
	if(check_leafnode(T))
	{
		int temp[2*d+1];
		for(i=0;i<(2*d+1);i++)
		temp[i]=T->data[i];
		Sort(temp,2*d+1);     //Sorting temp array
		T->c=0;               //deleting all element of Node
		for(i=0;i<d;i++)
		T->data[T->c++]=temp[i];
		median=temp[d];
		for(i=d+1;i<2*d+1;i++)
		N->data[N->c++]=temp[i];
		
	}
	else
	{
		int temp[2*d+1];
		bdnode *New=T->ptr[2*d+1];  //storing New node pointer into New variable
		int Newdata=T->data[2*d];
		int tdata[2*d];
		bdnode *tptr[2*d+1];    //for storing data and pointers into temp arrays
		for(i=0;i<2*d+1;i++)
		{
			temp[i]=T->data[i];
		}
		Sort(temp,2*d+1);    //Sorting temp array
		for(i=0;i<2*d;i++)
		{
			tdata[i]=T->data[i];
			tptr[i]=T->ptr[i];
		}
		tptr[i]=T->ptr[i];
		T->c=0;               //deleting all element of Node
		/*putting data into corresponding nodes*/
		
		for(i=0;i<d;i++)
		T->data[T->c++]=temp[i];
		median=temp[d];
		for(i=d+1;i<2*d+1;i++)
		N->data[N->c++]=temp[i];
		
		/*adjusting pointers*/
		int index;
		for(i=0;i<d;i++)
		{
			if(T->data[i]==Newdata)
			{
				T->ptr[i+1]=New;
			}
			else
			{
				index=Find(tdata,T->data[i]);
				T->ptr[i+1]=tptr[index+1];
			}
		}
		if(Newdata==median)
		N->ptr[0]=New;
		else
		{
			index=Find(tdata,median);
			N->ptr[0]=tptr[index+1];
		}
		for(i=0;i<d;i++)
		{
			if(N->data[i]==Newdata)
			{
				N->ptr[i+1]=New;
			}
			else
			{
				index=Find(tdata,N->data[i]);
				N->ptr[i+1]=tptr[index+1];
			}
		}
	}
}

void Overflow(bdnode *B,int added_into)
{
	bdnode *T=B->ptr[added_into];
	bdnode *N=NULL;
	int median;
	Node_split(T,N,median);
	
	if(B->c<2*d)
	{
		B->ptr[B->c+1]=N;
		Insert_and_Sort(B,median);
	}
	else
	{
		B->data[B->c++]=median;
		B->ptr[B->c]=N;
	}
}

void Add(bdnode* &B,int k)
{
	if(B==NULL)
	{
		B=new bdnode;
		B->data[B->c++]=k;
	}
	else
	{
		if(check_leafnode(B))
		{
			if(B->c<2*d)
			{
				Insert_and_Sort(B,k);
			}
			else
			{
				B->data[B->c++]=k;
			}
		}
		else
		{	
			int added_into=0;
			if(k<B->data[0])
			{
				Add(B->ptr[0],k);
				added_into=0;
			}
			else if(k>B->data[B->c-1])
			{
				Add(B->ptr[B->c],k);
				added_into=B->c;
			}
			else
			{
				for(int i=1;i<B->c;i++)
				{
					if(k>B->data[i-1]&&k<B->data[i])
					{
						Add(B->ptr[i],k);
						added_into=i;
						break;
					}
				}
			}
			if(B->ptr[added_into]->c>2*d)
			{
				Overflow(B,added_into);
			}
		}
		
	}
}

int main()
{
	bdnode *B=NULL;
	int k;
	cout<<"Enter data for the tree\n";
	do
	{
	   cout<<"Enter -1 to stop\n";
	   cin>>k;
	   cout<<endl;
	   if(k==-1)
	   break;
	   Add(B,k);
	   if(B->c>2*d)
	   {
	   	  bdnode *T=B;
	   	  bdnode *N=NULL;
	   	  int median;
	   	  Node_split(T,N,median);
	   	  B=new bdnode;
	   	  B->data[B->c++]=median;
	   	  B->ptr[0]=T;
	   	  B->ptr[1]=N;
	   	  T=NULL;
	   }
	   Level_order(B);
	}while(k!=-1);
}
