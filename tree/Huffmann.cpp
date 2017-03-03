#include<iostream>
using namespace std;
int g=100;
struct node
{
	char tag;
	int fq;
	node* left;
	node* right;
	int mark;
};
class stack
{
	public:
	node* c[50];
	int size;
	int top;
	stack()
	{
		top=-1;
		size=50;
	}
	int isempty()
	{
		if(top==-1)
		return 1;
		else 
		return 0;
	}
	void push(node* ch)
	{
		top++;
		c[top]=ch;
	}
	node* pop()
	{
		return c[top--];
	}
node*	peek()
	{
		return c[top];
	}
};



node** bsort(node** root,int n)
{
	node* temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(root[i]->fq < root[j]->fq)
			{
				temp->fq=root[i]->fq;temp->tag=root[i]->tag;
				root[i]->fq=root[j]->fq;root[i]->tag=root[j]->tag;
				root[j]->fq=temp->fq;root[j]->tag=temp->tag;
			}
		}
	}
	return root;

}
void findcode(node* temp,int val)
{
	if(temp==NULL)
	return;
	else if(val<temp->mark)
	{
	cout<<"0";	
	findcode(temp->left,val);
   }
   else if(val>temp->mark)
   {
   	cout<<"1";
   	findcode(temp->right,val);
   }
   else
   return;
}
void inorder(node* temp)
{
	if(temp==NULL)
	return ;
	else
	{
		inorder(temp->left);
		temp->mark=g++;
		inorder(temp->right);
	}
}

int main()
{
	int i,n,j,f,k;
	char ch;
	stack s1,s2;
	
	cout<<"how many type of characters does the file has?\n";
	cin>>n;
	node** root;
	root=new node*[n];
	for(i=0;i<n;i++)
	{
		cout<<"enter character\n";
		cin>>ch;
		cout<<"what is the frequncy of the character "<<ch<<" \n";
		cin>>f;
		node* temp=new node;
		temp->tag=ch;
		temp->fq=f;
		temp->left=NULL;temp->right=NULL;
		//q.enq(temp);
		root[i]=temp;
		//s1.push(temp);
	}
root=bsort(root,n);
//for(i=0;i<5;i++)
//{
//	cout<<root[i]->fq<<" "<<root[i]->tag<<endl;
//}
for(i=0;i<n;i++)
{  cout<<root[i]->fq<<" ";
	s1.push(root[i]);
}

   	for(j=0;j<n-1;j++)
    {
    k=0;
	
	node* temp1=s1.pop();
	node* temp2=s1.pop();
	node* tem=new node;
	tem->left=temp1;
	tem->right=temp2;
	tem->fq = temp1->fq + temp2->fq;
	tem->tag='#';
s1.push(tem);cout<<endl;
	
while(!s1.isempty()) { 
node* tmp = s1.pop(); 
while(!s2.isempty() && s2.peek()->fq > tmp->fq) { 
s1.push(s2.pop()); 
} 
s2.push(tmp); 
} 
i=0;
while(!s2.isempty())
{
	
	s1.push(s2.pop());
	}

}

node* temp=s1.pop();
inorder(temp);
int intcode;
char code;
cout<<"enter the character to find its code\n";
cin>>code;
for(i=0;i<n;i++)
{
	if(code==root[i]->tag)
	intcode=root[i]->mark;
}
//cout<<intcode<<endl;
findcode(temp,intcode);

}

