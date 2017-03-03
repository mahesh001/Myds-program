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
   	 break;
   }
   if(i<2*d)
   return i;
   else
   return -1;
}

void Node_split(bdnode *T,bdnode* &N,int &median)
{
	cout<<"inside_node_sppliting\n";
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

int Key_Redis(bdnode *B,int added_into)
{
	bdnode *T=B->ptr[added_into];
	int temp[2*d+1];
	int i;
	if(added_into==0)
	{
		if(B->ptr[1]->c<2*d)
		{
			int max;
			for(i=0;i<2*d+1;i++)
			temp[i]=T->data[i];
			T->c=0;             //deleting element from node
			Sort(temp,2*d+1);
			max=temp[2*d];
			for(i=0;i<2*d;i++)
			T->data[T->c++]=temp[i];
			Insert_and_Sort(B->ptr[1],B->data[0]);
			B->data[0]=max;
			return 1;
		}
		else
		return 0;
	}
	if(added_into==B->c)
	{
		if(B->ptr[added_into-1]->c<2*d)
		{
			int min;
			for(i=0;i<2*d+1;i++)
			temp[i]=T->data[i];
			T->c=0;             //deleting element from node
			Sort(temp,2*d+1);
			min=temp[0];
			for(i=0;i<2*d;i++)
			T->data[T->c++]=temp[i+1];
			Insert_and_Sort(B->ptr[added_into-1],B->data[added_into-1]);
			B->data[added_into-1]=min;
			return 1;
		}
		else
		return 0;
	}
	if(B->ptr[added_into+1]->c<2*d)
	{
		int max;
		for(i=0;i<2*d+1;i++)
		temp[i]=T->data[i];
		T->c=0;             //deleting element from node
		Sort(temp,2*d+1);
		max=temp[2*d];
		for(i=0;i<2*d;i++)
		T->data[T->c++]=temp[i];
		Insert_and_Sort(B->ptr[added_into+1],B->data[added_into]);
		B->data[added_into]=max;
		return 1;
	}
	else if(B->ptr[added_into-1]->c<2*d)
	{
		int min;
		for(i=0;i<2*d+1;i++)
		temp[i]=T->data[i];
		T->c=0;             //deleting element from node
		Sort(temp,2*d+1);
		min=temp[0];
		for(i=0;i<2*d;i++)
		T->data[T->c++]=temp[i+1];
		Insert_and_Sort(B->ptr[added_into-1],B->data[added_into-1]);
		B->data[added_into-1]=min;
		return 1;
	}
	else
	return 0;
}

void Overflow(bdnode *B,int added_into)
{
	bdnode *T=B->ptr[added_into];
	bdnode *N=NULL;
	int median;
	int success=0;
	
	if(check_leafnode(T))
	{
		success=Key_Redis(B,added_into);
		cout<<"Success="<<success<<endl;
	}
	
	if(success)
	return;
	
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

void Shift_right(bdnode *B)
{
	int i;
	for(i=0;i<B->c;i++)  //shifting pointers
	{
		B->ptr[i]=B->ptr[i+1];
	}
	for(i=0;i<(B->c-1);i++)  //shifting data
	{
		B->data[i]=B->data[i+1];
	}
}

void Shift_left(bdnode *B)
{
	int i;
	for(i=(B->c+1);i>0;i--)   //shifting pointers
	{
		B->ptr[i]=B->ptr[i-1];
	}
	for(i=B->c;i>0;i--)       //shifting data
	{
		B->data[i]=B->data[i-1];
	}
}

int Key_Redis_del(bdnode *B,int remove_into)
{
	bdnode *T=B->ptr[remove_into];
	int i;
	if(remove_into==0)
	{
		bdnode *temp=B->ptr[1];
		if(temp->c>d)
		{
			int min=temp->data[0];
			bdnode *left_subtree=temp->ptr[0];
			Shift_left(temp);  //store frist element into min and shift ele to left
			temp->c--;         //We have deleted min from ptr[1]
			T->data[T->c++]=B->data[0];
			B->data[0]=min;
			T->ptr[B->c]=left_subtree;
			return 1;
		}
		else
		return 0;
	}
	else if(remove_into==B->c)
	{
		bdnode *temp=B->ptr[remove_into-1];
		if(temp->c>d)
		{
			bdnode *right_subtree=temp->ptr[temp->c]; 
			int max=temp->data[--(temp->c)];     //delete and store it in max
			Shift_right(T);
			T->data[0]=B->data[B->c-1];
			B->data[B->c-1]=max;
			T->ptr[0]=right_subtree;
			return 1;
		}
		else
		return 0;
	}
	bdnode *temp_left=B->ptr[remove_into-1];
	bdnode *temp_right=B->ptr[remove_into+1];
	
	if(temp_right->c>d)
	{
		bdnode *left_subtree=temp_right->ptr[0];
		int min=temp_right->data[0];
		Shift_left(temp_right);
		temp_right->c--;            //delete and store it into min
		T->data[T->c++]=B->data[remove_into];
		B->data[remove_into]=min;
		T->ptr[T->c]=left_subtree;
		return 1;
	}
	else if(temp_left->c>d)
	{
		bdnode *right_subtree=temp_left->ptr[temp_left->c];
		int max=temp_left->data[temp_left->c-1];  //delete and store into max
		temp_left->c--;
		Shift_right(T);
		T->data[0]=B->data[remove_into];
		B->data[remove_into]=max;
		T->ptr[0]=right_subtree;
		return 1;
	}
	else
	return 0;
}

void Merge_Nodes(bdnode *B,int index)  //index of data which side node are to be merge
{
	int i;
	int median=B->data[index];
	bdnode *left_node=B->ptr[index];
	bdnode *right_node=B->ptr[index+1];  //left_node is our final node
	bdnode *right_subtree=right_node->ptr[0];
	
	left_node->data[left_node->c++]=median;
	left_node->ptr[left_node->c]=right_subtree;
	
	for(i=0;i<d;i++)  //fill data of right_node into leftnode space
	{
		left_node->data[left_node->c++]=right_node->data[i];  //filling data
		left_node->ptr[left_node->c]=right_node->ptr[i+1];      //adjusting pointers
	}
	B->ptr[index+1]=NULL;   //deleting the remaining node
	delete right_node;
}

int Predecer(bdnode *B)  //index where data found
{
	if(check_leafnode(B))
	{
		return B->data[B->c-1];
	}
	else
	return Predecer(B->ptr[B->c]);
}

int Succ(bdnode *B)
{
	if(check_leafnode(B))
	{
		return B->data[0];
	}
	else
	return Succ(B->ptr[0]);
}

int Both_node_minimal(bdnode *B,int index)
{
	if(B->ptr[index]->c==d && B->ptr[index+1]->c==d)
	return 1;
	else
	return 0;
}

void del(bdnode *B,int k)
{
	int i;
	if(check_leafnode(B))
	{
		int found=Find(B->data,k);
		if(found==-1)
		{
			cout<<"Key Not present\n";
			return;
		}
		else
		{
			for(i=found;i<(B->c-1);i++)
			B->data[i]=B->data[i+1];
			B->c--;
		}
	}
	else
	{
		int found=Find(B->data,k);
		bdnode *T=B->ptr[found];
		if(found!=-1)             //node is internal node.
		{
			if(T->c==d && B->ptr[found+1]->c==d)
			{
				Merge_Nodes(B,found);
				for(i=found;i<(B->c-1);i++)   //shift data and pointer to left
				{
					B->data[i]=B->data[i+1];
					B->ptr[i+1]=B->ptr[i+2];
				}
				B->c--;                        //one element is reduced
				del(B->ptr[found],k);
			}
			else if(B->ptr[found]->c>d)
			{
				int pre=Predecer(T);         //Find it Predecer and store it.
				del(T,pre);                   //delete Predecer.
				B->data[found]=pre;           //assigne data with predecer.
			}
			else
			{
				int suc=Succ(T);
				del(T,suc);
				B->data[found]=suc;
			}
		}
		else
		{
			int remove_into;
			if(k<B->data[0])
			{
				remove_into=0;
			}
			else if(k>B->data[B->c-1])
			{
				remove_into=B->c;
			}
			else
			{
				for(i=0;i<(B->c-2);i++)
				{
					if(k>B->data[i]&&k<B->data[i+1])
					{
						remove_into=B->c;
						break;
					}
				}
			}
			if(B->ptr[remove_into]->c>d)   //if node has more then minimum element then only we step into it.
			{
				del(B->ptr[remove_into],k);
			}
			else if(Key_Redis_del(B,remove_into))
			{
				del(B->ptr[remove_into],k);
				if(B->c>2*d)
				{
					int median;
					bdnode *N=new bdnode;
					Node_split(B,N,median);
					bdnode *P=new bdnode;
					P->data[P->c++]=median;
					P->ptr[0]=B;
					P->ptr[1]=N;
					B=P;
				}
				
			}
			else           //Last option is merge it with any of it sibling as value to be delete as median
			{
				int index;             //it index of data which side node are to merge
				if(remove_into==0)
				index=0;
				else
				index=remove_into-1;
				
				Merge_Nodes(B,index);        //it merge both side nodes of (remove_into-1)th node with median as that data 
				for(i=index;i<(B->c-1);i++)   //shift data and pointer to left
				{
					B->data[i]=B->data[i+1];
					B->ptr[i+1]=B->ptr[i+2];
				}
				B->c--;                 //one element is reduced
				del(B->ptr[index],k);  //delete from merged node
			}
		}
	}
}

int main()
{
	bdnode *B=NULL;
	bdnode *N=NULL;
	bdnode *T;
	int k,median;
	cout<<"Enter data for the tree\n";
	do
	{
	   cout<<"Enter -1 to stop\n";
	   cin>>k;
	   if(k==-1)
	   break;
	   Add(B,k);
	   if(B->c>2*d)
	   {
	   	  T=B;
	   	  Node_split(T,N,median);
	   	  B=new bdnode;
	   	  B->data[B->c++]=median;
	   	  B->ptr[0]=T;
	   	  B->ptr[1]=N;
	   	  T=NULL;
	   }
	   Level_order(B);
	}while(k!=-1);
	
	cout<<"Enter the element you want to delete\n";
	do
	{
		cout<<"Enter -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		del(B,k);
		if(B->c==0)
		{
			bdnode *temp=B;
			B=B->ptr[0];
			temp->ptr[0]=NULL;
			delete temp;
		}
		Level_order(B);
	}while(k!=-1);
}
