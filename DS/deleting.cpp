#include<iostream>
#include<queue>
using namespace std;
const int d=2; 
struct node
{
	int a[2*d];
	node *p[2*d+1];
	int count;
	node *pptr;
	int spl;
}; 
node *w,*c,*abc,*temp=NULL; int *b; node **s; 
void print(node *t)
{
	if(t!=NULL)
	{		
	for(int i=0;i<2*d;i++)
	cout<<t->a[i]<<"  ";
	cout<<endl;
    }
}

void bubble(int *b,node **p,int k)
{
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if(b[i]>b[j])
			{
				int temp;   node*t;
			    temp=b[j];  t=p[j];
			    b[j]=b[i];  p[j]=p[i]; 
			    b[i]=temp;  p[i]=t;
			}
		}
	}
}
void sort(node *t,node **p2,int k)
{
	b=new int[k]; p2=new node*[k]; s=new node*[k]; int i;
	for(i=0;i<k;i++)
	{
	b[i]=t->a[i];
	p2[i]=t->p[i+1]; s[i]=t->p[i+1];
    }
	bubble(b,s,k);
}
void sort4(node*t,int h,int k )
{
	b=new int[h+1]; s=new node*[h+1]; int i;
	for(i=0;i<h;i++)
	{
	   b[i]=t->a[i];
	   //if(i!=pos)
	   s[i]=t->p[i+1];	
	}
	b[i]=k; //s[pos]=t1;
	s[i]=temp;
	bubble(b,s,2*d+1);
}
/*void sort2(node *t,int h,int k)
{
	int i;
    b=new int[h+1];  s=new node *[h+1];
	for( i=0;i<h;i++)
    {
	b[i]=t->a[i];
    s[i]=t->p[i+1];
    }
	b[i]=k; s[i]=t->p[i+1];
	bubble(b,s,2*d+1);	
	cout<<"sort2"<<endl;
}*/

void sort3(node *t,node **p2,int k)
{
	b=new int[k]; p2=new node*[k]; s=new node*[k]; int i;
	for(i=0;i<k;i++)
	{
	b[i]=t->a[i];
	p2[i]=t->p[i+1]; s[i]=t->p[i+1];
    }
	bubble(b,s,k);
}
int sorting (node *&t,int i)
{
	int g[5]; int k;
	for( k=0;k<4;k++)
	{
		g[k]=t->a[k];
	}
	g[k]=i;
	for( k=0;k<5;k++)
	{
		cout<<g[k]<<" ; ";
	}
	
		for(int f=0;f<5;f++)
	{
		for(int j=f+1;j<5;j++)
		{
			if(g[f]>g[j])
			{
				int temp;  
			    temp=g[j]; 
			    g[j]=g[f]; 
			    g[f]=temp;  
			}
		}
	}
	for( k=0;k<5;k++)
	{
		cout<<g[k]<<" ; ";
	}
	for(int f=0;f<4;f++)
	{
		t->a[f]=g[f];
	}
	return g[4];
	
}
void sorting2 (node *&t,int i)
{
	cout<<"\n..... sorting 2......\n";
	int g[i];
	for(int k=0;k<t->count;k++)
	{
		g[k]=t->a[k];
	}
	
	
		for(int f=0;f<i;f++)
	{
		for(int j=f+1;j<i;j++)
		{
			if(g[f]>g[j])
			{
				int temp;  
			    temp=g[j]; 
			    g[j]=g[f]; 
			    g[f]=temp;  
			}
		}
	}
	for(int f=0;f<i;f++)
	{
		t->a[f]=g[f];
	}
	
}
int right(node *l,node *t,int i,int j)
{
	cout<<"ur in key distribution ..... type 1\n";
    	if(l->p[j+1]->count<4)
    	{
    		node *s=l->p[1];
    		s->a[s->count]=l->a[j]; s->count++;
    		//rvalue=sorting(t,i);
    		l->a[j]=sorting(t,i);
    		sorting2(s,s->count);
    		return 1;
    	}
    	return 0;
}
int left(node *l,node *t,int i,int j)
{
	cout<<"ur in key distribution .....type2\n";
    	if(l->p[j-1]->count<4)
    	{
    		node *s=l->p[j-1];
    		s->a[s->count]=l->a[j-1]; s->count++;
    		if(i<t->a[0])
    		l->a[j-1]=i;
    		else
    		{
    		l->a[j-1]=t->a[0];
    		t->a[0]=i;
    		sorting2(t,t->count);
    	    }
    	    return 1;
    	}
    	return 0;
}
int keydistribute(node *&t,int i)
{
	cout<<"ur in key distribution .....\n"; int ret;
      node *l=t->pptr; int rvalue; int j;
      for( j=0;j<5;j++)
       {
       	
       	if(l->p[j]==t)
       	{
       		break;
       	}
       }
  
    {
    	cout<<"ur in key distribution .....type3\n";
    	int min=10; int pos2=-1,x;
    	
    	for(int val=0;val<=l->count;val++)
		{
			if(l->p[val]->count<4)
    		{
    			cout<<"nnnnnnnnnnnnnnn";
    			if(val<j) x=j-val;
				else x=val-j;
				if(x<min)
				{
					pos2=val;
					min=x;
				}	
    		}
    	}
    	cout<<"\n.....position 2......="<<pos2<<"..."<<j<<endl;
       if(pos2!=-1)
       {
       
    	if(pos2<j)
    	{
    		int f;
		    for( f=pos2;f<j-1;f++)
			{
				node *s=l->p[f];
				node *s2=l->p[f+1];
				s->a[s->count]=l->a[f]; s->count++;
				l->a[f]=s2->a[0]; 
				s2->a[0]=s2->a[3]; s2->a[3]=0; s2->count--;
				sorting2(s2,s2->count);
			}	
			int re=left(l,t,i,f+1);
			if(re==0) return 0;
			else return 1;
    	}
    		if(pos2>j)
    	{
    		int f;
		    for( f=pos2;f>j+1;f--)
			{
				node *s=l->p[f];
				node *s2=l->p[f-1];
				s->a[s->count]=l->a[f-1]; s->count++; sorting2(s,s->count);
				l->a[f-1]=s2->a[3]; 
			    s2->a[3]=0; s2->count--;
				sorting2(s2,s2->count);
			}	
			int re=right(l,t,i,f-1);
			if(re==0) return 0;
			else return 1;
    	}
}
   
    return 0;
	
}
}

node* insert(node *&t,int i)
{
	cout<<"ur in insert.....";
	int kd=0;
	if(t!=NULL&&t->count==2*d&&t->pptr!=NULL)
	kd=keydistribute(t,i);
	
    if(kd==0)
    {
	if(t!=NULL&&t->count==2*d&& t->pptr==NULL&& t->p[0]!=NULL)
	{
		
    if(i<t->a[0])
	{
		cout<<endl<<"first end"<<endl;
		abc=insert(t->p[0],i);
		return abc;
	}
	else if(i>t->a[2*d-1])
	{
		cout<<endl<<"last end"<<endl;
		abc=insert(t->p[2*d],i);
		return abc;
	}
	else
        {
           for(int j=0;j<2*d-1;j++)
           {
           	   cout<<endl<<"middle.."<<endl;
               if(i>t->a[j]&&i<t->a[j+1])
                abc=insert(t->p[j+1],i);
                return abc;
           }
        }
    
		
		
		
		
	}
	
	
	
	else if(t!=NULL&&t->count==2*d)
	{
		cout<<"fullll"<<endl;
		
		node *t1=new node; t1->count=0; t1->pptr=t->pptr;
		node *t2=new node; t2->count=0; t2->pptr=t->pptr;
		node *t3=new node; t3->count=0; t3->pptr=NULL;
		for(int l=0;l<2*d;l++)
		{
			t1->a[l]=0; t1->p[l]=NULL;
			t2->a[l]=0; t2->p[l]=NULL;
			t3->a[l]=0; t3->p[l]=NULL;
		} 
		
		t1->p[2*d]=NULL;
		t2->p[2*d]=NULL;
		t3->p[2*d]=NULL;
		
		
		
		   if(t->spl!=1)
		   {
		   	sort4(t,4,i);
		   	 cout<<"\n.......special sort....";
		   }
		  
		   else 
		   // sort2(t,4,i);
		    if(t->spl==1)
		   {
		    sort4(t,4,i);
		    for(int i=0;i<5;i++)
		    {
		    	cout<<endl;
		    	if(s[i]!=NULL)
		    	print(s[i]);
		    	cout<<endl;
		    }
		   }
		    
		    
		    
			    int f=0;
		    int g=0;    //t1->p[0]=t->p[0];
		for( g=0;g<t->count/2;g++)
		{
			t1->a[g]=b[g]; //if(g!=0)
		//	t1->p[g]=s[f++];
		//	t1->count++;
		}
		t1->count=2;
		 //t1->p[g]=s[f++];
		 if(t->p[0]!=NULL)
		 t->p[0]->pptr=t1;
		 t1->p[0]=t->p[0]; 
		int d=0;
		 for( d=1;d<t->count/2+1;d++)
		 {
		 	t1->p[d]=s[d-1]; if(s[d-1]!=NULL)s[d-1]->pptr=t1;
		 }
		 
		 t1->p[3]=NULL;
		 
		 
		cout<<"\n\n\n";
		print(t1);  cout<<t1->count;
		cout<<"1111111111111111111111"<<endl;
		int l=0,m=0;
		for( g=(t->count/2)+1;g<2*d;g++)
		{
				t2->a[l++]=b[g]; //t2->p[m++]=s[f++];
					t2->count=2;
		}  
		l=0;
		for( m=(t->count/2)+1;m<2*d+2;m++)
		{
			t2->p[l++]=s[m-1]; 
			if(s[m-1]!=NULL&&m<4)
			s[m-1]->pptr=t2;
		}
		if(s[4]!=NULL)
		s[4]->pptr=t2;
	    t2->p[3]=NULL;
		cout<<"\n\n\n";
		print(t2); cout<<t2->count;
		cout<<"2222222222222222222222"<<endl;
	if(t->pptr==NULL||t->pptr->p[0]==NULL)
	{
		t3->a[0]=b[t->count/2];
		cout<<"33333333333333333333333"<<endl;
		t3->p[0]=t1;
		t3->p[1]=t2;
		t1->pptr=t3;
		t2->pptr=t3;
		t3->count++;
		cout<<"\n\n\n";
		print(t3);
		t=t3; return t3;
	}
	else if(t->pptr!=NULL)
	{
		node *l=t->pptr; int pos;
	 cout<<"sss"; cout<<endl<<l->a[0]<<endl; cout<<endl<<l->count<<endl; 
	
	cout<<endl<<t->a[0]<<endl;  cout<<endl<<t->count<<endl; 
	
	int x=l->count;  print(l->p[0]);
	
	for(int u=0;u<x;u++)
	{
		if(l->a[u]<b[2]&&l->a[u+1]>b[2])
		{
			pos=u;
		}
	}
	
	
	
	
	
	
	//l->p[x]=t1; cout<<endl<<l->count<<"    "<<x;
	//l->p[x+1]=t2;  cout<<endl<<l->count<<"    "<<x+1;
	if(l->a[x]==0)
	{
	l->a[x]=b[2]; 
	
	 cout<<endl<<l->count<<"    "<<x; 
	print(l); l->count++;
	
	if(b[2]<l->a[0])
	{
			l->a[x]=b[2];
		l->p[0]=t1;
		l->p[x+1]=t2; 
			for(int i=0;i<=x+1;i++)
		    {
		    	cout<<"#";
		    	
		    	print(l->p[i]);
		    }
		sort3(l,l->p,x+1);
		
		for(int h=0;h<x+1;h++)
			{
				cout<<"/";
				l->a[h]=b[h];
				l->p[h+1]=s[h];
			}
			return t;
	}
	
	
	
	else if(b[2]>l->a[x-1])
	  {
	  		l->a[x]=b[2];
	  	l->p[x]=t1; cout<<endl<<l->count<<"    "<<x;
	l->p[x+1]=t2;  cout<<endl<<l->count<<"    "<<x+1;
	for(int i=0;i<=x+1;i++)
		    {
		    	cout<<"#";
		    	
		    	print(l->p[i]);
		    }
	
	sort(l,l->p,x+1);
			for(int h=0;h<x+1;h++)
			{
				cout<<"/";
				l->a[h]=b[h];
				l->p[h+1]=s[h];
			}
			return t;
      }
      else 
      {
      	cout<<"last condition........"<<endl;
      		l->a[x]=b[2];
      	l->p[pos+1]=t1;  cout<<endl<<l->count<<"    "<<x;
      	l->p[x+1]=t2;  cout<<endl<<l->count<<"    "<<x+1;
      	
      	for(int i=0;i<=x+1;i++)
		    {
		    	cout<<"#";
		    	
		    	print(l->p[i]);
		    }
	
	sort(l,l->p,x+1);
			for(int h=0;h<x+1;h++)
			{
				cout<<"/";
				l->a[h]=b[h];
				l->p[h+1]=s[h];
			}
			return t;
      }
  }
  else
  {
  	cout<<"\n .... special....\n";
  	//node *c;
  	if(l->pptr==NULL)
  	l->pptr=t3;
  	l->p[pos+1]=t1; temp=t2;
  	//l->p[x+2]=t2;
  	l->spl=1;  
  	//print(l->p[x+2]);
  	c=insert(l,b[2]);
  	cout<<"xxxxxxxxxxxxxxx\n";
  	
  	cout<<"\n\n\nhiiiiii......\n\n"<<c->a[0];
  	
  	return c;
  	
  	
  	
  	
  	
  	
}
      }
	
	else
	{
		cout<<"do nothing......."; return t;
	}
    }
	else if(t==NULL)
	{
		t=new node;
			for(int j=0;j<2*d;j++)
		{
			t->a[j]=0;
		}
		t->count=0; 
		t->pptr=NULL;
		cout<<endl<<"new node created"<<endl;
		t->a[t->count]=i; t->count++;
		
		for(int j=0;j<2*d+1;j++)
		{
			t->p[j]=NULL;
		}
		return t;
	}
	
	else if(t!=NULL&&t->count<2*d)
	{
		if(t->p[0]!=NULL)
		{
			 if(i<t->a[0])
	          {
	          	cout<<"11first11\n";
	          	
	        	abc=insert(t->p[0],i); 
				cout<<"first";
				return abc;
	        	cout<<endl;
	          } 
			 
           /* else if(i>t->a[2*d-1])
	           {
	         	insert(t->p[2*d],i);
	         	cout<<"last\n";
	           }*/
	           else
		for(int j=0;j<2*d;j++)
		{
			   if(i>t->a[j]&&t->p[j+1]!=NULL&&t->a[j+1]==0)
			    {
			    	abc=insert(t->p[j+1],i);
					return abc; break;
			    }
	           
	           {
	           	if(i>t->a[j]&&i<t->a[j+1])
                {
                	abc=insert(t->p[j+1],i);
					return abc; break;
                }
	           }
		}
	    }
		else
		{
			
			t->a[t->count]=i; t->count++; sort(t,t->p,t->count); cout<<"xxxxxxxxxxx";
		for(int k=0;k<t->count;k++)
		     t->a[k]=b[k];
		}
		
	}
		else if(i<t->a[0])
	{
		cout<<endl<<"first end"<<endl;
		insert(t->p[0],i);
	}
	else if(i>t->a[2*d-1])
	{
		cout<<endl<<"last end"<<endl;
		insert(t->p[2*d],i);
	}
	else
        {
           for(int j=0;j<2*d-1;j++)
           {
           	   cout<<endl<<"middle.."<<endl;
               if(i>t->a[j]&&i<t->a[j+1])
                insert(t->p[j+1],i);
           }
        }
        return t;
}

   return t;
}









int keydis(node *&t)
{
	cout<<"ur in key distribution .....\n"; int ret;
      node *l=t->pptr; int rvalue; int j;
      for( j=0;j<5;j++)
       {
       	
       	if(l->p[j]==t)
       	{
       		break;
       	}
       }
  
    {
    	cout<<"ur in key distribution .....type3\n";
    	int min=10; int pos2=-1,x;
    	
    	for(int val=0;val<=l->count;val++)
		{
			if(j!=val)
			if(l->p[val]->count>2)
    		{
    			cout<<"nnnnnnnnnnnnnnn";
    			if(val<j) x=j-val;
				else x=val-j;
				if(x<min)
				{
					pos2=val;
					min=x;
				}	
    		}
    	}
    	cout<<"\n.....position 2......="<<pos2<<"..."<<j<<endl;
       if(pos2!=-1)
       {
       
    	if(pos2>j)
    	{
    		int f;
		    for( f=j;f<pos2;f++)
			{
				node *s=l->p[f];
				node *s2=l->p[f+1];
				s->a[s->count]=l->a[f]; s->count++;
				l->a[f]=s2->a[0]; 
				s2->a[0]=s2->a[s2->count-1]; s2->a[s2->count-1]=0; s2->count--;
				sorting2(s2,s2->count);
			}	
		/*	int re=left(l,t,f+1);
			if(re==0) return 0;
			else return 1;*/
			return 1;
    	}
    		if(pos2<j)
    	{
    		int f;
		    for( f=j;f>pos2;f--)
			{
				node *s=l->p[f];
				node *s2=l->p[f-1];
				s->a[s->count]=l->a[f-1]; s->count++; sorting2(s,s->count);
				l->a[f-1]=s2->a[s2->count-1]; 
			    s2->a[s2->count-1]=0; s2->count--;
				//sorting2(s2,s2->count);
			}	
		/*	int re=right(l,t,f-1);
			if(re==0) return 0;
			else return 1;*/
			return 1;
    	}
}
   
    return 0;
	
}
}





void deleteno(node *&t,int pos,int key)
{
	cout<<"ur in delete........\n";
	node *l=t->pptr;
	if(t->p[0]==NULL)
	{
		cout<<"leaf condition............\n";
		for(int i=0;i<t->count;i++)
		{
			if(t->a[i]==key)
			{
				t->count--; int j;
				for(j=i;j<t->count;j++)
				{
					t->a[j]=t->a[j+1];
				}
				t->a[j]=0;
			}
		}
	if(t->count<d)
	{
		int value;
		value=keydis(t);
		if(value==0)
		{
		if(pos==0)
		{
		node *s=l->p[pos+1];
		t->a[t->count]=l->a[pos]; t->count++; int k;
		for( k=0;k<s->count;k++)
		{
			t->a[t->count]=s->a[k];
			t->p[t->count]=s->p[k];
			t->count++;
		}
		t->p[t->count]=s->p[k]; int i;
		for( i=pos;i<l->count-1;i++)
		{
			l->a[i]=l->a[i+1];
			l->p[i+1]=l->p[i+2];
		}
		l->count--; 
		
		if(l->count==0)
		{
		/*	for(int f=0;f<t->count;f++)
			{
				l->a[f]=t->a[f];
				l->count++;
			}*/
			w=t;
			 l->p[0]=NULL; l->p[i+1]=NULL;
		}
		else
		{
		    l->p[i+1]=NULL;
		    l->a[i]=0;
	    }
	    }
		else
		{
			node *s=l->p[pos-1];
			s->a[s->count]=l->a[pos-1]; s->count++; int k;
			for( k=0;k<t->count;k++)
			{
				s->a[s->count]=t->a[k];
				s->p[s->count]=t->p[k];
				s->count++;
			}
			s->p[s->count]=t->p[k]; int i;
			for( i=pos-1;i<l->count-1;i++)
		    {
			    l->a[i]=l->a[i+1];
			    l->p[i+1]=l->p[i+2];
		    }
		    l->count--;
		    if(l->count==0)
	     	{
	
			w=t;
			 l->p[0]=NULL; l->p[i+1]=NULL;
		    }
		    else
		    {
		    	l->a[l->count]=0; l->p[l->count+1]=NULL;
		    }
		
		}
	    }
		
	}
	
}
else
{
	cout<<"non leaf condition............\n";
	int h;
	for(h=0;h<t->count;h++)
	{
		if(t->a[h]==key)
		{
			pos=h;
		}
	}
	
	t->a[pos]=t->p[pos]->a[t->p[pos]->count-1];
	deleteno(t->p[pos],pos,t->p[pos]->a[t->p[pos]->count-1]);
}
}

void traverse(node *&t,int pos,int key)
{
	cout<<"ur in traverse.........\n";
	for(int i=0;i<t->count;i++)
	{
		if(t->a[i]>key)
		{
			traverse(t->p[i],i,key);
		}
		else if(t->a[i]==key)
		{
			
			deleteno(t,i,key);
			break;
		}
		else
		{
			if(t->a[i+1]==0)
			{
				if(key>t->a[i])
				traverse(t->p[i+1],i+1,key);
			}
			if(key>t->a[i]&&key<t->a[i+1])
			{
				traverse(t->p[i+1],i+1,key);
			}
		}
	}
}

void levelorder(node *r)
{
	queue<node *>q;
	

    q.push(r); node *s=new node; s->a[0]='*';   q.push(s);
    while(!q.empty()&&q.front()->a[0]!='*')
    {
    while(q.front()->a[0]!='*')
    {
    	
    	node* c=q.front();
    	q.pop();
    	for(int value=0;value<4;value++)
    	{
    		cout<<c->a[value]<<"  ";
    	}
    	for(int v=0;v<5;v++)
    	{
    		if(c->p[v]!=NULL)
    		q.push(c->p[v]);
    	}
    	//if(c->lchild!=NULL) q.enque(c->lchild);
    	//if(c->rchild!=NULL) q.enque(c->rchild);
    	
    	
    }
    cout<<endl;
    q.pop();
    q.push(s);
    }
}




int main()
{
	int i,j,s,k=0; node *t; t=NULL; w=NULL;
	do
	{
	cout<<"enter the elements:";
	k++;
	cin>>i;
	if(c!=NULL) 
	{
		cout<<"\n........hhhhhhhhhh............\n";
	t=insert(c,i);
    }
	else
	t=insert(w,i); //cout<<endl;print(w); cout<<endl;
	if(k==1) w=t;
	if(c!=NULL) w=c;
	cout<<endl;print(w); cout<<endl;
	cout<<".............."; cin>>s;
    }while(s==1); int key;
    do
    {
    cout<<"enter number:"; cin>>key;
    traverse(w,0,key); cin>>s;
    }while(s==1);
    levelorder(w);
   /* print(w);
    for(int q=0;q<5;q++)
    {
    	cout<<endl;
    if(	w->p[q]!=NULL)
    	print(w->p[q]); cout<<"  count="<<w->p[q]->count;
    }
    cout<<"ur in main function\n";
   // w=c;*/
   
  /*  for(int q=0;q<5;q++)
    {
    	cout<<endl;
    	if(w->p[0]->p[q]!=NULL)
    	print(w->p[0]->p[q]);
    }
    cout<<"\njjjjjjjjjjjjjj\n";
     for(int q=0;q<5;q++)
    {
    	cout<<endl;
    	if(w->p[1]->p[q]!=NULL)
    	print(w->p[1]->p[q]);
    }*/
}
   
