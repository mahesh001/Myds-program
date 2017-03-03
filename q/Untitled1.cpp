/*level wise printing of binary tree*/
void levelwise(btnode *B)
{
	double i=0,k=1;
	btnode *T=B,*T1;
	T1=new btnode;
	T1->data='*';
	Queue Q;
	Q.enqueue(T);
	Q.enqueue(T1);
	while(!Q.isempty())
	{
		T=Q.dequeue();
		if(T->data=='*')
		{
		  cout<<endl;
		  i=0;
	    }
		else
		{
		  cout<<T->data<<" ";
		  if(T->lchild!=NULL)
		  Q.enqueue(T->lchild);
		  if(T->rchild!=NULL)
		  Q.enqueue(T->rchild);
		  i=i+2;
		  if(i==pow(2,k)){
		  	k=k+1;
		  	Q.enqueue(T1);
		  }
	    }
	}
}
