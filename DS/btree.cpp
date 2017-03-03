#include<iostream>
class node
{
   int keys[5];
   node * child[6];
   int fill;
   node *parent;
   friend class btree;
   public:
      node();
};
node::node()
{
   for(int i=0;i<4;i++)
   {
      keys[i]=0;
      child[i]=NULL;
   }
  // child[i]=NULL;
   fill=0;
   parent=NULL;
}
class btree
{
    node *root;
    public:
       btree();
	   node* find(node *,int );
       void checkoverflow(node *);
       void insert(node * ,int ,node *,node *);
       void sortins(node *,int,node *,node *);
       void accept();
       void rightredis(node *,node *,node *,int);
       void leftredis(node *,node *,node *,int);
	   void del(int key);
	   void checkunderflow(node *temp);
	   node* find_left(node *temp1,int i);
       void display(node *);
	   void menu();
}; 
 btree::btree()
       {
	  root=NULL;
       }
 void btree::sortins(node *t,int x,node * lc,node * rc)

       {
	  int i=0;
	  while(i<t->fill && t->keys[i]<x)
	      i++;
	  if(t->fill==i)
	  {
	      t->keys[i]=x;
	      t->child[i+1]=rc;
	      t->child[i]=lc;
	  }
	  else
	  {
	      for(int j=t->fill;j>i;j--)
	      
		  t->keys[j]=t->keys[j-1];
		  t->child[j+1]=t->child[j];
	      
	      t->keys[j]=x;
	      t->child[j+1]=rc;
	      t->child[j]=lc;
	  }
       }
 void btree::accept()
       {
	   int x;
	  cout<<"Enter the value to be inserted:";
	   cin>>x;
	   node * prev;
           node *tmp;
           int fil;
	   if(root!=NULL)
	   {
	       prev=root;
               tmp=prev;
	       while(tmp->child[0]!=NULL)
	       {
		    fil=0;
		    while(tmp->keys[fil]<x && fil< tmp->fill)
			     fil++;
		    prev=tmp->child[fil];
		    tmp=prev;
	       }
	   }
	   else
	   {
	       prev=new node;
	       root=prev;
	   }
	   insert(prev,x,NULL,NULL);
       }
void btree::leftredis(node* lbn,node* pare,node* tmp,int i)
       {
	    lbn->child[lbn->fill+1]=tmp->child[0];
	    lbn->keys[lbn->fill]=pare->keys[i-1];
	    pare->keys[i-1]=tmp->keys[0];
	    i=1;
	    while(i<tmp->fill)
	    {
	      tmp->keys[i-1]=tmp->keys[i];
	      tmp->child[i-1]=tmp->child[i];
	      i++;
	    }
	    tmp->child[i-1]=tmp->child[i];
	    tmp->fill--;
	    lbn->fill++;
       }
void btree::rightredis(node *tmp,node* pare,node* rbn,int j)
       {
	    int i=rbn->fill;
	    while(i>0)
	    {
		 rbn->child[i+1]=rbn->child[i];
		 rbn->keys[i]=rbn->keys[i-1];
		 i--;
	    }
	    rbn->child[i+1]=rbn->child[i];
	    rbn->keys[0]=pare->keys[j];
	    rbn->child[0]=tmp->child[tmp->fill];
	    tmp->fill--;
	    rbn->fill++;
	    pare->keys[j]=tmp->keys[tmp->fill];
       }
void btree::insert(node * tmp,int x,node * lc,node * rc)
       {
	    sortins(tmp,x,lc,rc);
	    tmp->fill=tmp->fill+1;
	    checkoverflow(tmp);
       }
void btree::checkoverflow(node *tmp)
       {
	   if(tmp->fill<5)
	       return;
	   else
	   {
		  int lb,rb;
		  int check=0;
		  int i;
		  node *tmp1;
		  node *rbn,*lbn;
		  if(tmp->parent!=NULL)
		  {
			 tmp1=tmp->parent;
			 i=0;
			 while(tmp1->child[i]!=tmp)
			     i++;
			 lb=i-1;
			 rb=i+1;
			 if(lb!=-1)
			 {
			      lbn=tmp1->child[i-1];
			      if(lbn->fill<4)
			      {
				 check=1;
				 leftredis(lbn,tmp1,tmp,i);
			      }
			 }
			 if(!check && rb<(tmp1->fill+1))
			 {
			      rbn=tmp1->child[i+1];
			      if(rbn->fill<4)
			      {
				  check=1;
				  rightredis(tmp,tmp1,rbn,i);
			      }
			 }
		  }
		  if(!check)
		  {
		      rbn=new node;
		      rbn->keys[0]=tmp->keys[3];
		      rbn->keys[1]=tmp->keys[4];
		      rbn->child[0]=tmp->child[3];
		      rbn->child[1]=tmp->child[4];
		      rbn->child[2]=tmp->child[5];
		      for(int m=0;m<3;m++)
		      {
			 if(rbn->child[m]!=NULL)
			 {
			     lbn=rbn->child[m];
			     lbn->parent=rbn;
			 }
		       }
		       rbn->fill=2;
		       tmp->fill=2;
		       if(tmp!=root)
		       {
				check=1;
				rbn->parent=tmp->parent;
				for(int j=tmp1->fill;j>i;j--)
				{
				     tmp1->keys[j]=tmp1->keys[j-1];
				     tmp1->child[j+1]=tmp1->child[j];
				}
				tmp1->child[j+1]=tmp1->child[j];
				tmp1->keys[i]=tmp->keys[2];
				tmp1->child[i]=tmp;
				tmp1->child[i+1]=rbn;
				tmp1->fill++;
				checkoverflow(tmp->parent);
		       }
		       else
		       {
			     node *pare;
			     pare=new node;
			     root=pare;
			     pare->child[0]=tmp;
			     pare->child[1]=rbn;
			     pare->fill=1;
			     pare->keys[0]=tmp->keys[2];
			     pare->parent=NULL;
			     rbn->parent=tmp->parent=root;
		       }
		  }

	   }
       }
void btree::display(node *T)
{
	int i;
	for(i=0;i<T->fill;i++)
	{
		if(T->child[i]!=NULL)
			display(T->child[i]);
		cout<<"    "<<T->keys[i];
	}
	if(T->child[T->fill])
		display(T->child[T->fill]);
}	
void btree::menu()
{
	int key;
	char choice='y',ch='y';
	while(choice!='n')
	{
		cout<<"Enter any element into the tree"<<endl;
		accept();
		cout<<"Want to enter more (y/n):"<<endl;
		cin>>choice;
	}
	cout<<"The tree is given by "<<endl;
	display(root);
	cout<<endl;
	while(ch!='n')
	{
		cout<<"Enter the number to delete "<<endl;
		cin>>key;
		del(key);
		cout<<endl;
		cout<<"The tree after deletion is "<<endl;
		display(root);
		cout<<endl;
		cout<<"Want to delete more (y/n):"<<endl;
		cin>>ch;
	}
}
node* btree::find(node *T,int key)
{
	int flag=0,i=0;
	while((key>=T->keys[i])&&(i<T->fill))
	{
		if(key==T->keys[i])
		{
			flag=1;
			break;
		}
		i++;
	}
	if((T->child[i]==NULL)&&(flag==0))
		//cout<<"The number is not found "<<endl;
		return NULL;
	else if(flag==1)
		//cout<<"FOUND"<<endl;
		return T;
	else
		return find(T->child[i],key);
}
void btree::checkunderflow(node *tmp)
       {
	       if(tmp->fill>1)
		    return;
	       else
	       {
		    node *tmp1;
		    node *lbn,*rbn;
		    int lb,rb;
		    int i=0;
		    if(tmp->parent!=NULL)
		    {
                         tmp1=tmp->parent;
			 while(tmp1->child[i]!=tmp)
			     i++;
			 lb=i-1;
			 rb=i+1;
			 int check=0;
			 if(lb!=-1)
			 {
			      lbn=tmp1->child[lb];
			      if(lbn->fill>2)
			      {
				     check=1;
				     rightredis(lbn,tmp->parent,tmp,i-1);
			      }
			 }
			 if(!check && rb<(tmp1->fill+1))
			 {
			      rbn=tmp1->child[rb];
			      if(rbn->fill>2)
			      {
				   check=1;
				   leftredis(tmp,tmp->parent,rbn,i+1);
			      }
			 }
			 if(!check)
			 {
			       if(lb!=-1)
			       {
                                    lbn=tmp1->child[lb];
				    lbn->keys[lbn->fill]=tmp1->keys[i-1];
				    lbn->keys[3]=tmp->keys[0];
				    lbn->child[3]=tmp->child[0];
				    lbn->child[4]=tmp->child[1];
				    if(tmp->child[0]!=NULL)
				    {
				      node *ch;
				      for(int k=0;k<2;k++)
				      {
				         ch=tmp->child[k];	
						ch->parent=lbn;
				      }
				    }
                                    delete tmp;
				    for(int j=i-1;j<tmp1->fill;j++)
				    {
				       tmp1->keys[j]=tmp1->keys[j+1];
				       if(j!=i-1)
					  tmp1->child[j]=tmp1->child[j+1];
				    }
				   tmp1->child[j]=tmp1->child[j+1];
				   tmp1->fill--;
				   lbn->fill=4;
                                   if(tmp->parent==root && tmp1->fill==0)
                                          root=lbn;
                                   else
				          checkunderflow(tmp->parent);
			       }
			       else
			       {
                                   rbn=tmp1->child[rb];
				   tmp->keys[tmp->fill]=tmp1->keys[i];
				   for(int k=0;k<rbn->fill;k++)
				   {
					 tmp->keys[k+2]=rbn->keys[k];
					 tmp->child[k+2]=rbn->child[k];
				   }
				   tmp->child[k+2]=rbn->child[k];
				   if(rbn->child[0]!=NULL)
				   {
				      node *ch;
				      for(int k=0;k<2;k++)
				      {
                                         ch=rbn->child[k];
					 ch->parent=tmp;
				      }
				   }
                                    delete rbn;
				    for(int j=i;j<tmp1->fill;j++)
				    {
				       tmp1->keys[j]=tmp1->keys[j+1];
				       if(j!=i)
					  tmp1->child[j]=tmp1->child[j+1];
				    }
				   tmp1->child[j]=tmp1->child[j+1];
				   tmp1->fill--;
				   tmp->fill=4;
				   checkunderflow(tmp->parent);
			       }
			 }
		    }
		    else  if(tmp->fill==0 && tmp==root)
		    {
			  root=tmp->child[0];
                          delete tmp;
		    }
	       }
       }
	   void btree::del(int key)
	   {
		   node *temp1=find(root,key);
		   int i=0,j;
		   while(key!=temp1->keys[i]&&i<temp1->fill)
			   i++;
		   if(temp1->child[0]==NULL)
		   {
			   temp1->fill--;
			   for(j=i;j<temp1->fill;j++)
				   temp1->keys[j]=temp1->keys[j+1];
			   if(temp1!=root)
				   checkunderflow(temp1);
		   }
		   else
		   {
			   node *temp2;
			   temp2=find_left(temp1,i);
			   temp1->keys[i]=temp2->keys[--temp2->fill];
			   checkunderflow(temp2);
		   }
	   }
	   node* btree::find_left(node *temp1,int i)
	   {
		   node *temp=temp1->child[i];
		   while(temp->child[0]!=NULL)
			   temp=temp->child[temp->fill];
		   return temp;
	   }

int main()
{
	btree b;
	b.menu();
	return 0;
}



