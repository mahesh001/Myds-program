#include<iostream>
#include<cmath>
class directory
{
	private:
		struct bucket
		{
			int data[10];
			int size,dp;
			bucket(int s,int d)
			{
				size=s;
				dp=d;
			}
		};
		struct node
		{
			int info;
			node *link;
		}*front,*rear;
		int depth;
		bucket *table[100];
	public:
		directory()
		{
			depth=0;
			table[0]=new bucket(0,0);
			front=NULL;
			rear=NULL;
		}
		void addq(int i)
		{
			node *temp=new node;
			temp->info=i;
			temp->link=NULL;
			if(!rear)
			{
				rear=temp;
				front=temp;
			}
			else
			{
				rear->link=temp;
				rear=temp;
			}
		}
		int delq()
		{
			int temp=front->info;
			front=front->link;
			return temp;
		}
		void insert(int record)
		{
			int i;
			if(search(record,i)==0)
				insert(record,table[i]);
			else
				cout<<"\nElement already exists";
		}
		int search(int record,int& z)
		{
			int key=H(record,depth);
			z=key;

			bucket *temp=table[key];
			if(temp==NULL)
				return 0;
			else
			{
				for(int i=0;i<temp->size;i++)
					if(record==temp->data[i])
						return 1;
				return 0;
			}
		}
		void insert(int record,bucket* t)
		{
			if(t->size<10)
				{
				t->data[t->size++]=record;
				}
			else
			{
				split(t);
				insert(record);
			}
		}
		void split(bucket *t)
		{
			int h;
			if(t->dp==depth)
				expand();
			bucket *temp=new bucket(0,t->dp+1);
			int first=findindex(t);
			int last=first+(int)pow(2,depth-t->dp)-1;
			//change first for new bucket
			first=first+(last-first+1)/2;
			for(int i=first;i<=last;i++)
				table[i]=temp;
			for(i=0;i<t->size;i++)
			{
				h=H(t->data[i],depth);
				if(h>=first && h<=last)
				{
					temp->data[temp->size++]=t->data[i];
					t->data[i]=t->data[t->size-1];
					t->size--;
					i--;
				}
			}
			t->dp=t->dp+1;
		}
		int findindex(bucket *t)
		{
			for(int i=0;i<(int)pow(2,depth);i++)
			{
				if(table[i]==t)
					return i;
			}
			return 0;
		}
		void expand()
		{
			for(int i=(int)pow(2,depth)-1;i>=0;i--)
			{
				table[2*i+1]=table[i];
				table[2*i]=table[i];
			}
			depth=depth+1;
		}
		int H(int r,int d)
		{
			r=r%100;
			int k=0,sum=0;
			while(r>0)
			{
				addq(r%2);
				r=r/2;
				k++;
			}
			while(k<=8)
			{
				addq(0);
				k++;
			}
			while(d>0)
			{
				sum=sum+delq()*(int)pow(2,d-1);
				d--;
			}
			front=0;
			rear=0;
			return sum;
		}
		void remove(int record)
		{
			int i;
			if(search(record,i)==1)
				remove(record,table[i]);
			else
				cout<<"\nelement is not there";
		}
		void remove(int record,bucket*& t)
		{
			int i,flag=0;
			for(i=0;i<t->size;i++)
			{
				if(t->data[i]==record)
				{
					t->data[i]=t->data[t->size-1];
					t->size--;
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				if(t->size<5)
				{
					int first=findindex(t);
					int last=first+(int)pow(2,depth-t->dp)-1;
					//check previous bucket
					int p=first-1,z=0;
					if(p>=0)
						test(p,z); //if test fails z=0; else z=1;
					int k=pow(2.0,depth);
					if(z==0 && last<(k-1))
					{
						//check next bucket
						p=last;
						test(p,z);
						p=p+1;
					}
					if(z==1)
					{
						//join the buckets
						join(t,table[p]);
						table[p]=t;
						contract();
					}
				}
			}
		}
		void test(int p,int& z)
		{
			int d1=table[p]->dp;
			if(table[p]->size<5 && table[p+1]->size<5)
			{
				if(table[p]->dp==table[p+1]->dp)
				{
					if(H(table[p]->data[0],d1-1)==H(table[p+1]->data[0],d1-1))
						z=1;
				}
			}
		}
		void join(bucket* t1,bucket* t2)
		{
			int k=t1->size;
			for(int i=k;i<(k+t2->size);i++)
			{
				t1->data[i]=t2->data[i-k];
				t1->size++;
			}
			t1->dp=t1->dp-1;
		}
		void contract()
		{
			int i=0,error=0;
			while(i<(int)pow(2,depth) && error==0)
			{
				if(table[i]!=table[i+1])
				{
					 return;
				}
				i=i+2;
			}
			if(error==0)
			{
				depth=depth-1;
				for(i=1;i<=(int)pow(2,depth)-1;i++)
					table[i]=table[2*i];
			}
		}
		void display()
		{
		int k=1;
		for(int i=0;i<(int)pow(2,depth);i++)
		{
			int first=i;
			int last=first+(int)pow(2,depth-table[i]->dp)-1;
			cout<<"\n\nbucket-"<<k<<endl;
			for(int j=0;j<table[i]->size;j++)
				cout<<table[i]->data[j]<<" ";
			i=last;
			k++;
		}
		}
		void search(int h)
		{
			int k;
			if(search(h,k)==1)
				cout<<"\nElement is present at "<<k<<" th index bucket\n";
			else
				cout<<"\nElement is not there\n";
		}
};
int main()
{
	directory dd;int n,x;
	while(1)
	{
		cout<<"\n1.insert\n2.delete\n3.search\n4.display\n";
		cin>>n;
		switch(n)
		{
			case 1:cout<<"\nEnter number: ";
						cin>>x;
						dd.insert(x);break;
			case 2:cout<<"\nEnter number to be deleted: ";
						cin>>x;
						dd.remove(x);break;
			case 3:cout<<"\nEnter number to be searched: ";
						cin>>x;dd.search(x);break;
			case 4:dd.display();break;
			default:cout<<"\n\nthank you";exit(1);
		}
	}
	return 0;
}









