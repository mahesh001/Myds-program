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
		size=200;
	}
	private:
		int front;
		int rear;
		int size;
		bdnode* element[200];
		
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
	if(B==NULL)
	{
		cout<<"TREE IS EMPTY\n";
		return;
	}
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
			cout<<"|";
			for(i=0;i<T->c;i++)
			cout<<T->data[i]<<" ";
			for(i;i<2*d;i++)
			cout<<"* ";
			cout<<"|  ";
			
			for(i=0;i<=T->c;i++)
			{
			   if(T->ptr[i]!=NULL)
			   Q.enqueue(T->ptr[i]);
			}
		}
	}
}

void Add(bdnode* &B,int k);

void Sort(bdnode *B)
{
	int i=0,j=0,temp,size=B->c;
	int *a=B->data;
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
	if(B->ptr[0]==NULL)
	return 1;
	else
	return 0;
}

int Tree_overflow(bdnode *B,int k)
{
	if(check_leafnode(B))
	{
		if(B->c>2*d)
		return 1;
		else
		return 0;
	}
	else
	{
		int i;
		for(i=0;i<B->c;i++)
		{
			if(k<B->data[i])
			break;
		}
		return Tree_overflow(B->ptr[i],k);
	}
}

int Tree_full(bdnode *B)
{
	if(check_leafnode(B))
	{
		if(B->c<2*d)
		return 0;
		else
		return 1;
	}
	else
	{
		int i,full=1;
		for(i=0;i<=B->c;i++)
		{
			if(!Tree_full(B->ptr[i]))
			full=full&&0;
		}
		return  full;
	}
}

void Insert(bdnode *B,int k)
{
	if(check_leafnode(B))
	Insert_and_Sort(B,k);
	else
	{
		int i;
		for(i=0;i<B->c;i++)
		{
			if(k<B->data[i])
			break;
		}
		Insert(B->ptr[i],k);
	}
}

int Precedere(bdnode *B)
{
	if(check_leafnode(B))
	return B->data[B->c-1];
	else
	return Precedere(B->ptr[B->c]);
}

int Succ(bdnode *B)
{
	if(check_leafnode(B))
	return B->data[0];
	else
	return Succ(B->ptr[0]);
}

void Del_precedere(bdnode *B)
{
	if(check_leafnode(B))
	B->c--;
	else
	Del_precedere(B->ptr[B->c]);
}

void Del_succ(bdnode *B)
{
	if(check_leafnode(B))
	{
		for(int i=0;i<B->c-1;i++)
		B->data[i]=B->data[i+1];
		B->c--;
	}
	else
	Del_succ(B->ptr[0]);
}

void Left_to_right_rotation(bdnode *B,int index)
{
	cout<<"Left_to_right_rotation\n";
	int pre=Precedere(B->ptr[index]);
	Del_precedere(B->ptr[index]);
	Add(B->ptr[index+1],B->data[index]);
	B->data[index]=pre;
}

void Right_to_left_rotation(bdnode *B,int index)
{
	cout<<"Right_to_left_rotation\n";
	int suc=Succ(B->ptr[index+1]);
	cout<<"succ="<<suc<<endl;
	Del_succ(B->ptr[index+1]);
	Add(B->ptr[index],B->data[index]);
	B->data[index]=suc;
}

void Convert_leftoverflow(bdnode *B,int k)
{
	if(check_leafnode(B));
	else
	{
		int i,added_into;
		for(i=0;i<B->c;i++)
		{
			if(k<B->data[i])
			break;
		}
		Convert_leftoverflow(B->ptr[i],k);
		added_into=i;
		for(i=added_into-1;i>=0;i--)
		Right_to_left_rotation(B,i);
	}
}

void Convert_rightoverflow(bdnode *B,int k)
{
	if(check_leafnode(B));
	else
	{
		int i,added_into;
		for(i=0;i<B->c;i++)
		{
			if(k<B->data[i])
			break;
		}
		Convert_rightoverflow(B->ptr[i],k);
		added_into=i;
		for(i=added_into;i<B->c;i++)
		Left_to_right_rotation(B,i);
	}
}

void Node_splite(bdnode *T,bdnode* &N,int &median)
{
	int i;
	median=T->data[d];
	for(i=d+1;i<2*d+1;i++)    //copying data and pointers into new node
	{
		N->ptr[N->c]=T->ptr[i];
		N->data[N->c++]=T->data[i];
	}
	N->ptr[N->c]=T->ptr[i];
	T->c=d;    //Now no of element are d
}

void Overflow(bdnode *B,int added_into,int k)
{
	/*checking for redistrubution*/
	int i,success=0,index;
	if(added_into==0)
	{
		for(i=1;i<=B->c;i++)
		{
			if(!Tree_full(B->ptr[i]))
			{
				cout<<"success+added_into="<<i<<endl;
				success=1;
				break;
			}
		}
		if(i<=B->c)
		{
			Convert_rightoverflow(B->ptr[added_into],k);
			for(index=i-1;index>=0;index--)  //index about which rotation takes place 
			Left_to_right_rotation(B,index);
		}
	}
	else if(added_into==B->c)
	{
		for(i=B->c-1;i>=0;i--)
		{
			if(!Tree_full(B->ptr[i]))
			{
				success=1;
				break;
			}
		}
		if(i>=0)
		{
			cout<<"Not overflow i="<<i<<endl;
			Convert_leftoverflow(B->ptr[added_into],k);
			for(index=i;index<B->c;index++)
			Right_to_left_rotation(B,index);
		}
	}
	else
	{
		for(i=added_into-1;i>=0;i--)
		{
			if(!Tree_full(B->ptr[i]))
			{
				success=1;
				break;
			}
		}
		if(i>=0)
		{
			Convert_leftoverflow(B->ptr[added_into],k);
			for(index=i;index<added_into;index++)
			Right_to_left_rotation(B,index);
		}
		if(success==0)
		{
			for(i=added_into;i<=B->c;i++)
			{
				if(!Tree_full(B->ptr[i]))
				{
					success=1;
					break;
				}
			}
			if(i<=B->c)
			{
				Convert_rightoverflow(B,k);
				for(index=i-1;index>added_into;index--)
				Left_to_right_rotation(B,index);
			}
		}
	}
	/*if(success==0)       //if key redis. not possible then node spliting
	{
		bdnode *T=B->ptr[added_into];
		bdnode *N=new bdnode;
		int median;
		Node_splite(T,N,median);  //splting node N is new node median is separator
		B->ptr[B->c+1]=N;
		Insert_and_Sort(B,median);
	}*/
}

void Add(bdnode* &B,int k)
{
	int i;
	if(B==NULL)
	{
		B=new bdnode;
		B->data[B->c++]=k;
		return;
	}
	if(check_leafnode(B))
	{
		Insert_and_Sort(B,k);
	}
	else
	{
		int added_into;
		for(i=0;i<B->c;i++)
		{
			if(k<B->data[i])
			break;
		}
		added_into=i;
		Add(B->ptr[added_into],k);
		cout<<"Add+added_into="<<added_into<<endl;
		if(Tree_overflow(B->ptr[added_into],k))
		{
			cout<<"overflow\n";
			Overflow(B,added_into,k);
		}
	}
}

void Increase_level(bdnode *B)
{
	if(check_leafnode(B));
	else
	{
		Increase_level(B->ptr[B->c]);
		int median;
		bdnode *N=new bdnode;
		Node_splite(B->ptr[B->c],N,median);
		B->data[B->c++]=median;
		B->ptr[B->c]=N;
	}
}

void Root_overflow(bdnode *B,int k)
{
	if(check_leafnode(B));
	else
	{
		int i,added_into;
		for(i=0;i<B->c;i++)
		{
			if(k<B->data[i])
			break;
		}
		added_into=i;
		Root_overflow(B->ptr[added_into],k);
		if(B->ptr[added_into]->c>2*d)
		{
			int median;
			bdnode *N=new bdnode;
			Node_splite(B->ptr[added_into],N,median);
			B->ptr[B->c+1]=N;
			Insert_and_Sort(B,median);
		}
	}
}

int main()
{
	bdnode *B=NULL;
	int k;
	cout<<"Enter data for the tree\n";
	//for(int i=1;i<=100;i++)
	do
	{
	   cout<<"Enter -1 to stop\n";
	   cin>>k;
	   if(k==-1)
	   break;
	   Add(B,k);
	   if(Tree_overflow(B,k))
	   {
	   	 cout<<"IN_root-overflow\n";
	   	 Root_overflow(B,k);  
	   }
	   if(B->c>2*d)
	   {
	   	  bdnode *N=new bdnode;
	   	  int median;
	   	  Node_splite(B,N,median);
	   	  bdnode *P=new bdnode;
	   	  P->ptr[0]=B;
	   	  P->data[P->c++]=median;
	   	  P->ptr[P->c]=N;
	   	  B=P;
	   }
	   cout<<"Level_order\n";
	   Level_order(B);
	}while(k!=-1);
	//Level_order(B);
}
