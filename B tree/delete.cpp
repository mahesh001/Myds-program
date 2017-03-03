#include<iostream>
#define d 2
using namespace std;
struct Bnode
{
	int cnt;
	int key[2*d+1];
	Bnode *ptr[2*d+2];
};

Bnode *search(Bnode *T,int n)
{
	int flag,i;
	Bnode *par='\0';
	do
    {
		flag=0;
	    for(i=0;i<=T->cnt;i++)
	    {
		   if(T->ptr[i]!='\0')
		   flag=1;
	    }
	    if(flag==1)
	    {
		    par=T;
		 	i=0;
		 	while(i<T->cnt&&n>T->key[i])
		 	i++;
		 	T=T->ptr[i];
	    }
    }while(flag);
    return par;
}
void swap(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
void sort(Bnode *T)
{
	for(int i=0;i<T->cnt;i++)
	for(int j=0;j<T->cnt-1;j++)
	{
		if(T->key[j]>T->key[j+1])
		swap(T->key[j],T->key[j+1]);
	}
}
Bnode *parentnode(Bnode *T,Bnode *par)
{
	if(T==par)
	return '\0';
	int i,n=par->key[0];
	while(T->key[0]!=n)
	{
		par=T;
		i=0;
		while(i<T->cnt&&n>T->key[i])
		i++;
		T=T->ptr[i];
	}
	return par;
}
void onerightshift(Bnode *T,int i)
{
	for(int j=T->cnt;j>i;j--)
    {
 		T->key[j]=T->key[j-1];
    	T->ptr[j+1]=T->ptr[j];
	}
	T->cnt++;
}
void frontshiftptr(Bnode *par,int i)
{
	onerightshift(par->ptr[i+1],0);
	par->ptr[i+1]->ptr[1]=par->ptr[i+1]->ptr[0];
	par->ptr[i+1]->ptr[0]=par->ptr[i]->ptr[2*d+1];
	par->ptr[i]->ptr[2*d+1]='\0';
	par->ptr[i+1]->key[0]=par->key[i];
	par->key[i]=par->ptr[i]->key[--par->ptr[i]->cnt];
}
void backshiftptr(Bnode *par,int i)
{
	par->ptr[i-1]->key[par->ptr[i-1]->cnt]=par->key[i-1];
	par->ptr[i-1]->cnt++;
	par->ptr[i-1]->ptr[par->ptr[i-1]->cnt]=par->ptr[i]->ptr[0];
	par->key[i-1]=par->ptr[i]->key[0];par->ptr[i]->cnt--;
	for(int j=0;j<par->ptr[i]->cnt;j++)
	{
    	par->ptr[i]->key[j]=par->ptr[i]->key[j+1];
    	par->ptr[i]->ptr[j]=par->ptr[i]->ptr[j+1];
    }
    par->ptr[i]->ptr[2*d]=par->ptr[i]->ptr[2*d+1];
    par->ptr[i]->ptr[2*d+1]='\0';
}
int keyDistribution(Bnode *par,int i)
{
	if(i==0&&i<par->cnt&&par->ptr[1]->cnt<2*d)
	{
		frontshiftptr(par,i);
        return 1;
    }
    else if(i==2*d&&par->ptr[2*d-1]->cnt<2*d)
	{
		backshiftptr(par,i);
	    return 1;
	}
	else if(i>0&&i<2*d)
	{
		if(par->ptr[i-1]->cnt<2*d)
		{
		   backshiftptr(par,i);
		   return 1;
	    }
		if(i<par->cnt&&par->ptr[i+1]->cnt<2*d)
		{
			frontshiftptr(par,i);
			return 1;
		}
	}
	return 0;
}
void splitting(Bnode *&T,Bnode *par)
{
	if(par->cnt<2*d+1)
	 return;
	Bnode *tmp1=par;
	par=parentnode(T,par);
	int i,k=0;
	for(i=0;par&&tmp1!=par->ptr[i];i++);
	if(par)
	k=keyDistribution(par,i);
	if(k==0)
	{
	  Bnode *tmp2=new Bnode;
	  tmp2->cnt=0;
	  for(int j=d+1;j<2*d+1;j++)
   {
		   tmp2->key[tmp2->cnt]=tmp1->key[j];
	    tmp2->ptr[tmp2->cnt++]=tmp1->ptr[j];
	    tmp1->ptr[j]='\0';
	  }
	  tmp2->ptr[tmp2->cnt]=tmp1->ptr[2*d+1];
	  tmp1->ptr[2*d+1]='\0';
	  tmp1->cnt=d;
   if(par=='\0')
	  {
		  Bnode *tmp=new Bnode;
		  tmp->cnt=0;
	     tmp->key[tmp->cnt]=tmp1->key[d];
	     tmp->ptr[tmp->cnt++]=tmp1;
	     tmp->ptr[tmp->cnt]=tmp2;
	     T=tmp;
	  }
	  else
	  {
		   onerightshift(par,i);
		   par->key[i]=tmp1->key[d];
	    par->ptr[i+1]=tmp2;
	    splitting(T,par);
	  }
	 }
}
void add(Bnode *&T,int n)
{
	if(T=='\0')
	{
		Bnode *tmp=new Bnode;
		tmp->cnt=0;
		tmp->key[tmp->cnt]=n;
		tmp->ptr[tmp->cnt++]='\0';
		tmp->ptr[tmp->cnt]='\0';
		T=tmp;
	}
	else
	{
		Bnode *par,*tmp=T;
		par=search(T,n);
		int flag=0,i;
	    if(par)
	    {
	    	tmp=par;
		 	i=0;
		 	while(i<tmp->cnt&&n>tmp->key[i])
		 	i++;
		 	tmp=tmp->ptr[i];
	    }
	    tmp->key[tmp->cnt++]=n;
	    tmp->ptr[tmp->cnt]='\0';
	    sort(tmp);
	    if(tmp->cnt==2*d+1)
	    {
	    	int k=0;
	    	if(par!='\0')
	    	 k=keyDistribution(par,i);
	    	if(par=='\0'||k==0)
	    	{
	    	    Bnode *tmp2=new Bnode;
	        	tmp2->cnt=0;
	        	for(int j=d+1;j<2*d+1;j++)
     	    	{
	        		tmp2->key[tmp2->cnt]=tmp->key[j];
	        		tmp2->ptr[tmp2->cnt++]='\0';
    	    	}
	        	tmp2->ptr[tmp2->cnt]='\0';
	        	tmp->cnt=d;
     	    	if(par=='\0')
	        	{
	         		Bnode *tmp1=new Bnode;
	    	    	tmp1->cnt=0;
    	    		tmp1->key[tmp1->cnt]=tmp->key[d];
	        		tmp1->ptr[tmp1->cnt++]=tmp;
	        		tmp1->ptr[tmp1->cnt]=tmp2;
	    	    	T=tmp1;
    	    	}
	        	else
	        	{
	    	    	onerightshift(par,i);
	    	    	par->key[i]=tmp->key[d];
	    		    par->ptr[i+1]=tmp2;
    	    		if(par->cnt==2*d+1)
	        	    splitting(T,par);
	        	}
	        }
	    }
	}
}
void deleteno(Bnode *&T,int pos,int key)
{
	cout<<"ur in delete........\n";
	Bnode l=T->ptr[0];
	if(T->ptr[0]==NULL)
	{
		cout<<"leaf condition............\n";
		for(int i=0;i<T->cnt;i++)
		{
			if(T->a[i]==key)
			{
				T->cnt--; int j;
				for(j=i;j<T->cnt;j++)
				{
					T->a[j]=T->a[j+1];
				}
				T->a[j]=0;
			}
		}
	if(T->cnt<d)
	{
		int value;
		value=keydis(T);
		if(value==0)
		{
		if(pos==0)
		{
		node *s=l->ptr[pos+1];
		T->a[T->cnt]=l->a[pos]; T->cnt++; int k;
		for( k=0;k<s->cnt;k++)
		{
			T->a[T->cnt]=s->a[k];
			T->ptr[T->cnt]=s->ptr[k];
			T->cnt++;
		}
		T->ptr[T->cnt]=s->ptr[k]; int i;
		for( i=pos;i<l->cnt-1;i++)
		{
			l->a[i]=l->a[i+1];
			l->ptr[i+1]=l->ptr[i+2];
		}
		l->cnt--; 
		
		if(l->cnt==0)
		{
		/*	for(int f=0;f<T->cnt;f++)
			{
				l->a[f]=T->a[f];
				l->cnt++;
			}*/
			w=T;
			 l->ptr[0]=NULL; l->ptr[i+1]=NULL;
		}
		else
		{
		    l->ptr[i+1]=NULL;
		    l->a[i]=0;
	    }
	    }
		else
		{
			node *s=l->ptr[pos-1];
			s->a[s->cnt]=l->a[pos-1]; s->cnt++; int k;
			for( k=0;k<T->cnt;k++)
			{
				s->a[s->cnt]=T->a[k];
				s->ptr[s->cnt]=T->ptr[k];
				s->cnt++;
			}
			s->ptr[s->cnt]=T->ptr[k]; int i;
			for( i=pos-1;i<l->cnt-1;i++)
		    {
			    l->a[i]=l->a[i+1];
			    l->ptr[i+1]=l->ptr[i+2];
		    }
		    l->cnt--;
		    if(l->cnt==0)
	     	{
	
			w=T;
			 l->ptr[0]=NULL; l->ptr[i+1]=NULL;
		    }
		    else
		    {
		    	l->a[l->cnt]=0; l->ptr[l->cnt+1]=NULL;
		    }
		
		}
	    }
		
	}
	
}
else
{
	cout<<"non leaf condition............\n";
	int h;
	for(h=0;h<T->cnt;h++)
	{
		if(T->a[h]==key)
		{
			pos=h;
		}
	}
	
	T->a[pos]=T->ptr[pos]->a[T->ptr[pos]->cnt-1];
	deleteno(T->ptr[pos],pos,T->ptr[pos]->a[T->ptr[pos]->count-1]);
}
}
int getHeight(Bnode *T)
{
   if(T=='\0')
   return 0;
   return getHeight(T->ptr[0])+1;
}
void printLevel(Bnode *T,int l)
{
	if(T=='\0')
	return;
	if(l==0)
	{
		cout<<"{";
		for(int j=0;j<T->cnt;j++)
		cout<<T->key[j]<<" ";
		cout<<"}";
	}
	else
	{
		for(int j=0;j<=T->cnt;j++)
		printLevel(T->ptr[j],l-1);
	}
}
void print(Bnode *T)
{
	int h=getHeight(T);
	for(int i=0;i<h;i++)
	{
	    printLevel(T,i);
	    cout<<endl;
	}
}
int main()
{
	int n;
	char ch;
	Bnode *BT='\0';
	do
	{
		cout<<"Enter a number : ";
		cin>>n;
		add(BT,n);
		cout<<"do u want more?(y/n) : ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	print(BT);
	return 0;
}
