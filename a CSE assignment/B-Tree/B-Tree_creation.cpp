#include<iostream>
using namespace std;
const int d=2;

struct bdnode
{
	bdnode()
	{
		c=0;
		for(int i=0;i<2*d+1;i++)
		ptr[i]=NULL;
	}
	int data[2*d];
	bdnode* ptr[2*d+1];
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
	cout<<"inside Insert_and_Sort \n";
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

int Add(bdnode* &B,int k,bdnode* &N)
{
	int *a=new int[2*d+1];
	int i;
	if(B==NULL)
	{
		B=new bdnode;
		B->data[B->c++]=k;
		return -1;  //sucessfully added
	}
	else
	{
		if(check_leafnode(B))
		{
			cout<<"inside leaf node\n";
			if(B->c<2*d)
			{
				Insert_and_Sort(B,k);
				return -1;             //Sussesfully added
			}
			else           //condition of overflow
			{
				N=new bdnode;
				for(i=0;i<2*d;i++)    //storing node data into temp array for Node spliting
				a[i]=B->data[i];
				a[i]=k;
				Sort(a,2*d+1);   //sorting temp array
				int median=a[d];  //storing median
				B->c=0;       //deleting data in the B node;
				for(i=0;i<d;i++)         
				{
					B->data[B->c++]=a[i];    //storing data < then median into node
					N->data[N->c++]=a[d+1+i];  //and data > then median are stored into new node
				}
				return median;    //Condition of overflow
			}
		}
		else                    //search for leafnode
		{
			int add_into_parent,added=0,added_into=0;
			if(k<B->data[0])
			{
				added=Add(B->ptr[0],k,N);
			}
			else if(k>B->data[B->c-1])
			{
				added=Add(B->ptr[B->c],k,N);
			}
			else
			{
				for(i=1;i<B->c;i++)
				{
					if(k>B->data[i-1]&&k<B->data[i])
					{
						added=Add(B->ptr[i],k,N);
						break;
					}
				}
			}
			if(added!=-1)
			{
				bdnode *New=N;
				int tdata[2*d];
				int index;
				bdnode *tptr[2*d+1];
				cout<<"added="<<added<<endl;
				cout<<"B->c="<<B->c<<endl;
				if(B->c<2*d)
				{
					B->ptr[B->c+1]=New;  //adjusting new pointer
					Insert_and_Sort(B,added);  //add median into parent.
					return -1;
				}
				else
				{
				   N=new bdnode;
				   int i;
				   for(i=0;i<2*d;i++)    //storing node data into temp array for Node spliting
				   a[i]=B->data[i];
				   a[i]=added;
				   Sort(a,2*d+1);   //sorting temp array
				   int median=a[d];  //storing median
				   /*copying data and ptr into temp arrays*/
				   for(i=0;i<2*d;i++)
				   {
				   	 tdata[i]=B->data[i];
				   	 tptr[i]=B->ptr[i];
				   }
				   tptr[i]=B->ptr[i];
				   /*adjusting ptr for i<d */
				   for(i=0;i<d;i++)
				   {
				   	 if(a[i]==added)
				   	 B->ptr[i+1]=New;
				   	 else
					 {
					 	index=Find(B->data,a[i]);
					 	B->ptr[i+1]=tptr[index+1];
				   	 }
				   }
				   if(a[d]==added)
				   N->ptr[0]=New;
				   else
				   {
				   	 index=Find(B->data,a[d]);
				   	 N->ptr[0]=tptr[index+1];
				   }
				   for(i=d+1;i<=2*d;i++)
				   {
				   	  if(a[i]==added)
				   	  N->ptr[i-d]=New;
				   	  else
					  {
					  	index=Find(B->data,a[i]);
					  	N->ptr[i-d]=tptr[index+1];
				   	  }
				   }
				   
				   B->c=0;       //deleting data in the B node;
				   for(i=0;i<d;i++)         
				   {
					 B->data[B->c++]=a[i];    //storing data < then median into node
					 N->data[N->c++]=a[d+1+i];  //and data > then median are stored into new node
				   }
				   return median;    //Condition of overflow
				}
			}
			else
			return -1;
		}
	}
}


void print(bdnode *B)
{
	if(B!=NULL)
	{
		int i;
		for(i=0;i<B->c;i++)
		{
			print(B->ptr[i]);
			cout<<B->data[i]<<" ";
		}
		print(B->ptr[i]);
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

int main()
{
	bdnode *B=NULL;
	bdnode *N=NULL;
	bdnode *P;
	cout<<"Enter the element for B-Tree\n";
	int k;
	int added;
	while(1)
	{
		cout<<"Enter value -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		added=Add(B,k,N);
		if(added!=-1)
		{
			P=new bdnode;
		   	P->data[P->c++]=added;
		   	P->ptr[0]=B;
		   	P->ptr[1]=N;
		   	B=P;
		}
		cout<<endl;
		Level_order(B);
		cout<<endl;
	}
}
