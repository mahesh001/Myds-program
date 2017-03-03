#include<iostream>
#include<cstring>
using namespace std;
union u{
	int k;
	char *str;
};
struct lnode{
	lnode(){
		next=NULL;
	}
	int tag;
	u data;
	lnode *next;
};
void addendint(lnode *L,int tag,int k)
{
	lnode *T;
	T=new lnode;
	T->tag=tag;
	T->data.k=k;
	while(L->next!=NULL)
	  L=L->next;
	L->next=T;
}

void addendstr(lnode *L,int tag,char *str)
{
	lnode *T;
	T=new lnode;
	T->tag=tag;
	strcpy(T->data.str,str);
	while(L->next!=NULL)
	 L=L->next;
	L->next=T;
}

void printList(lnode *L)
{
	while(L!=NULL)
	{
		if(L->tag==1)
		 cout<<L->data.k<<" ";
		else if(L->tag==2)
		 cout<<L->data.str<<" ";
		L=L->next;
	}
	cout<<endl;
}

int main()
{
	int size,k,tag,i;
	lnode *L;
	char  temp[10];
	L=new lnode;
	/*size of list*/
	cout<<"Enter the no of terms\n";
	cin>>size;
	/*Taking input no*/
	cout<<"Enter tag and no (1 for int and 2 for string)\n";
	cin>>tag;
	L->tag=tag;
	if(tag==1)
	{
		cin>>k;
		L->data.k=k;
	}
	else if(tag==2)
	{
		cin>>temp;
		L->data.str=temp;
	}
	for(i=1;i<size;i++)
	{
	  cin>>tag;
	  if(tag==1){
	  	cin>>k;
	    addendint(L,tag,k);
	  }
	  else if(tag==2){
	  	cin>>temp;
	  	addendstr(L,tag,temp);
	  }
	}
	cout<<"Your List is \n";
	printList(L);
	return 0;
}
