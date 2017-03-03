#include<iostream>
using namespace std;

struct dnode{
	dnode *left;
	int data;
	dnode *right;
};

void addend(dnode *D,int k)
{
	dnode *T;
	T=new dnode;
	T->right=NULL;
	T->data=k;
	while(D->right!=NULL)
	   D=D->right;
	D->right=T;
	T->left=D;
}

void addafter(dnode *D,int x,int k)
{
	dnode *T;
	T=new dnode;
	T->data=k;
	while(D!=NULL)
	{
	   if(D->data==x&&D->right!=NULL)
	   {
	   	  T->right=D->right;
	   	  T->left=D;
	   	  D->right->left=T;
	   	  D->right=T;
	   }
	   else if(D->data==x)
	   {
	   	T->right=NULL;
	   	D->right=T;
	   	T->left=D;
	   }
	   D=D->right;
	}
}

void addbefor(dnode *D,int x,int k)
{
	dnode *T;
	T=new dnode;
	T->data=k;
	while(D!=NULL)
	{
		if(D->data==x)
		{
			D->left->right=T;
			T->right=D;
			T->left=D->left;
			D->left=T;
		}
		D=D->right;
	}
}

/*function to delete an element*/
void del(dnode *D,int k)
{
	while(D!=NULL)
	{
		if(D->data==k)
		break;
		D=D->right;
	}
	if(D==NULL)
	 cout<<"Element not present\n";
	else
	{
		D->left->right=D->right;
		D->right->left=D->left;
		delete(D);
	}
}
/*search function*/

int search(dnode *D,int k)
{
	while(D!=NULL)
	{
		if(D->data==k)
		break;
		D=D->right;
	}
	if(D==NULL)
	return 0;
	else
	return 1;
}
/*function to print linked list*/

void printList(dnode *D)
{
	while(D!=NULL)
	{
	   cout<<D->data<<" ";
	   D=D->right;	
	}
	cout<<endl;
}

/*this function remove frist element of list*/
void removefront(dnode* &D)
{
	D->right->left=NULL;
	D=D->right;
}

/*this function add an element to the list*/
void addfront(dnode* &D,int k)
{
	dnode *T;
	T=new dnode;
	T->left=NULL;
	T->data=k;
	T->right=D;
	D->left=T;
	D=T;
}

int main()
{
	int i,size,k,x;
	dnode *D;
	D=new dnode;
	D->left=NULL;
	D->right=NULL;
	/*taking size of linked list*/
	cout<<"Enter the no of no you want to enter\n";
	cin>>size;
	cout<<"Enter the no\n";
	cin>>k;
	D->data=k;
	/*taking the input */
	for(i=1;i<size;i++)
	{
		cin>>k;
		addend(D,k);
	}
	
	cout<<"You Entered :\n";
	printList(D);
	cout<<"Enter after which element you want to add element\n";
	cin>>x;
	cout<<"Enter the element to be added\n";
	cin>>k;
	/*calling addafter function*/
	addafter(D,x,k);
	
	cout<<"Now your list is :\n";
	printList(D);
	cout<<"Enter the no befor you want to add no\n";
	cin>>x;
	cout<<"Enter the no which is to be added\n";
	cin>>k;
	/*calling addbefor function*/
	addbefor(D,x,k);
	
	cout<<"Now the List is :\n";
	printList(D);
	
	cout<<"Enter the element to be search \n";
	cin>>k;
	if(search(D,k))
	cout<<"Element found\n";
	else
	cout<<"Element not found\n";
	
	cout<<"Enter the element you want to delete\n";
	cin>>k;
	/*calling delete function*/
	del(D,k);
	cout<<"Now the List is\n";
	printList(D);
	
	/*adding element to list*/
	cout<<"Enter the elment to be added at front\n";
	cin>>k;
	addfront(D,k);
	cout<<"Now the List is :\n";
	printList(D);
	/*remove element of front*/
	cout<<"Removing frist element \n";
	removefront(D);
	cout<<"Now the List is:\n";
	printList(D);
	return 0;
}
