#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;
const int d=1;

struct record
{
	char rollno[6];
	char name[16];
};

struct bdnode;

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

class Fixlength_record
{
	public :
		Fixlength_record(){
			Currindex=Nextindex=0;
		}
		void Insert(char *buffer,char *rollno,char *name);
	private :
		int Currindex;
		int Nextindex;
};

void Fixlength_record::Insert(char *buffer,char *rollno,char *name)
{
	int i,len=strlen(rollno);
	
	strcpy(buffer,rollno);
	Currindex=len;
	Nextindex=6;
	
	for(i=Currindex;i<Nextindex;i++)
	buffer[i]=' ';
	
	len=strlen(name);
	strncpy(&buffer[5],name,len);
	Currindex=5+len;
	Nextindex=21;
	
	for(i=Currindex;i<Nextindex;i++)
	buffer[i]=' ';
	
	buffer[20]=0;
}

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
	int dataptr[2*d+1];
	int c;
};

void Sort(int a[],int b[],int size)
{
	int i=0,j=0,temp1,temp2;
	for(i=0;i<size;i++)
	{
		for(j=0;j<(size-1);j++)
		{
		   if(a[j]>a[j+1])
		   {
			  temp1=a[j];
			  a[j]=a[j+1];
			  a[j+1]=temp1;
			  
			  temp2=b[j];
			  b[j]=b[j+1];
			  b[j+1]=temp2;
		   }
		}
	}
}

void Insert_and_Sort(bdnode *B,int k,int offset)
{
	int i,j;
	B->dataptr[B->c]=offset;
	B->data[B->c++]=k;
	
	int t,tp,size=B->c;
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
				
				tp=B->dataptr[j];
				B->dataptr[j]=B->dataptr[j+1];
				B->data[j+1]=tp;
				
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

void Node_splite(bdnode *T,bdnode* &N,int &median,int &offset)
{
	int i;
	median=T->data[d];
	offset=T->dataptr[d];
	
	for(i=d+1;i<2*d+1;i++)    //copying data and pointers into new node
	{
		N->ptr[N->c]=T->ptr[i];
		N->dataptr[N->c]=T->dataptr[i];
		N->data[N->c++]=T->data[i];
	}
	N->ptr[N->c]=T->ptr[i];
	T->c=d;                   //Now no of element are d
}

void Overflow(bdnode *B,int added_into)
{
	bdnode *T=B->ptr[added_into];
	bdnode *N=new bdnode;
	int median,offset;
	
	Node_splite(T,N,median,offset);  //splting node N is new node median is separator
	
	B->ptr[B->c+1]=N;
	Insert_and_Sort(B,median,offset);
}

void Add(bdnode* &B,int k,int offset)
{
	int i;
	if(B==NULL)
	{
		B=new bdnode;
		B->dataptr[B->c]=offset;
		B->data[B->c++]=k;
		return;
	}
	if(check_leafnode(B))
	{
		B->dataptr[B->c]=offset;
		B->data[B->c++]=k;  					//Simply insert and sort into leafnode
		Sort(B->data,B->dataptr,B->c);
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
		
		Add(B->ptr[added_into],k,offset);
		
		if(B->ptr[added_into]->c>2*d)   //checking for Overflow
		{
			Overflow(B,added_into);
		}
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

int search(bdnode *B,int k)
{
	int i;
	for(i=0;i<B->c;i++)
	{
		if(k<B->data[i])
		break;
	}
	if(B->data[i-1]==k)
	return B->dataptr[i-1];
	else if(!check_leafnode(B))
	search(B->ptr[i],k);
	else
	return 0;
}

int main()
{
	Fixlength_record fixlen;
	bdnode *B=NULL;
	record R;
	char buffer[21];
	int index=0;
	
	ofstream fout;
	fout.open("datafile.txt");
	
	cout<<"Enter the record\n";
	char ans='y';
	while(ans=='y'||ans=='Y')
	{
		cin>>R.rollno>>R.name;
		fixlen.Insert(buffer,R.rollno,R.name);
		
		fout<<buffer;				//writing fixlenght record into files
		
		Add(B,atoi(R.rollno),index++);     //adding key into B-tree
		if(B->c>2*d)
	   {
	   	  bdnode *N=new bdnode;
	   	  int median;
	   	  int offset;
	   	  Node_splite(B,N,median,offset);
	   	  bdnode *P=new bdnode;
	   	  P->ptr[0]=B;
	   	  P->dataptr[P->c]=offset;
	   	  P->data[P->c++]=median;
	   	  P->ptr[P->c]=N;
	   	  B=P;
	   }
		
		Level_order(B);
		
		cout<<"Want to enter more y or n\n";
		cin>>ans;
	}
	
	fout.close();
	
	ifstream fin;
	fin.open("datafile.txt");
	
	int k,offset;
	cout<<"Enter key you want to search -1 to stop\n";
	cin>>k;
	while(k!=-1)
	{
		offset=search(B,k);
		fin.seekg(offset*20,ios::beg);
		
		fin.read(buffer,20);
		cout<<"buffer="<<buffer<<"thats_all\n";
		
		fin.seekg(0,ios::beg);
		
		cin>>k;
	}
	
	fin.close();
}
