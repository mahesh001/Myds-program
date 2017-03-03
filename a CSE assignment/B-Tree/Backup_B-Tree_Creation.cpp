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

void showarray(int *a,int size)
{
	for(int i=0;i<size;i++)
	cout<<a[i]<<" ";
}

int* Add(bdnode* &B,int k)
{
	int *a=new int[2*d+1];
	if(B==NULL)
	{
		B=new bdnode;
		B->data[B->c++]=k;
	}
	else
	{
		int i,ln=0;
		for(i=0;i<B->c;i++)
		{
			if(B->ptr[i]!=NULL)
			break;
		}
		if(i==B->c&&B->ptr[i]==NULL)
		ln=1;
		else
		ln=0;
		if(ln==1)
		{
			cout<<"inside leaf node\n";
			if(B->c<2*d)
			{
				Insert_and_Sort(B,k);
				return NULL;
			}
			else if(B->c==2*d)
			{
				for(i=0;i<2*d;i++)
				a[i]=B->data[i];
				a[i]=k;
				Sort(a,2*d+1);
				return a;
				/*bdnode* T=new bdnode;
				int med=a[d+1];
				for(i=0;i<d;i++)
				{
					B->data[i]=a[i];
					T->data[i]=a[d+1+i];
				}
				bdnode *P=new bdnode;
				P->data[P->c++]=med;
				P->ptr[0]=B;
				P->ptr[1]=T;
				B=P;*/
			}
		}
		else
		{
			if(k<B->data[0])
			{
				a=Add(B->ptr[0],k);
				i=0;
			}
			else if(k>B->data[B->c-1])
			{
				a=Add(B->ptr[B->c],k);
				i=B->c;
			}
			else
			{
				for(i=1;i<B->c;i++)
				{
					if(k>B->data[i-1]&&k<B->data[i])
					{
						a=Add(B->ptr[i],k);
						break;
					}
				}
			}
			if(a!=NULL)
		    {
				cout<<"inside add spitfunction\n";
				showarray(a,2*d+1);
				bdnode *T=new bdnode;
				int med=a[d];
				B->ptr[i]->c=0;
				for(int j=0;j<d;j++)
				{
				   B->ptr[i]->data[B->ptr[i]->c++]=a[j];
				   T->data[T->c++]=a[d+1+j];
				}
			    if(B->c<2*d)
				{
					cout<<"inside B->c<d\n";
					B->ptr[B->c+1]=T;
					Insert_and_Sort(B,med);
					cout<<"Returning NULL\n";
					return NULL;
				}
				else if(B->c==2*d)
				{
					cout<<"inside B->c==d\n";
					int j;
					for(j=0;j<2*d;i++)
					a[j]=B->data[j];
					a[j]=med;
				    Sort(a,(2*d+1));
					return a;
				}
			}
			else
			return NULL;
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

int main()
{
	bdnode *B=NULL;
	cout<<"Enter the element for B-Tree\n";
	int k;
	int *a;
	while(1)
	{
		cout<<"Enter value -1 to stop\n";
		cin>>k;
		if(k==-1)
		break;
		a=Add(B,k);
		if(a!=NULL)
		{
			cout<<"Inside main split \n";
			showarray(a,2*d+1);
			bdnode *T=new bdnode;
			B->c=0;
			for(int i=0;i<d;i++)
			{
				B->data[B->c++]=a[i];
				T->data[T->c++]=a[d+1+i];
			}
			bdnode *P=new bdnode;
			P->data[P->c++]=a[d];
			P->ptr[0]=B;
			P->ptr[1]=T;
			B=P;
		}
		cout<<endl;
		cout<<"Print :";
		print(B);
		cout<<endl;
	}
	cout<<"Print :";
	print(B);
}
