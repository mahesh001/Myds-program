#include<iostream>
using namespace std;
struct bdnode
{   
     
	int key[20];
	bdnode*bdptr[21];
};
void findmid(int key[])
{ int d;
    int	mid=key[d+1];
   // return mid;
}
void splitnode(bdnode*T,int key)
{
bdnode*p;
    p=new bdnode;
	if(key<findmid)
	T->key;
	else
	P->key;
	T=p;
}
void check(bdnode*T)
{  int n;
	if(n>2*d)
	cout<<"overflow \n";
	splitnode(T);
	break;
	else 
	cout<<"under flow \n";
}
void sort(bdnode*T)
{
	int i,temp;
	for(i=0;i<=2*d;i++))
	{
		if(T->key[i]>t->key[i+1])
		temp=T->key[i];
		T->key[i]=T->key[i+1];
		T->key[i+1]=temp;
	}
}

void add(bdnode*T,int k)
{
	
	if(T==NULL)
 {
  T=new bdnode;
  T->key=k;
  T->bdptr=NULL;
 }
	else
	 {
      if(T->key>k)
      add(T->key,k);
      check(T);
      sort(T);
      
      
     }
}
int main()
{
	int i,j,k,d,key[100];
	cout<<"enter the size of aaray \n"
	cin>>d;
	cout<<"enter key \n";
	for(i=0;i<2*d;i++)
	cin>>key[i];
	add(root,key);
}
