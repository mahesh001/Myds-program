#include<iostream>
using namespace std;
struct queue
{int front;
int rear;
int size;
int elements[5];
};
queue Q;
int Qis_full(queue Q)
{ 
if((Q.rear+1)%Q.size=Q.front)
return 1;
}
int Qis_empty(queue Q)
{if(Q.front=-1);
}
void enqueue(queue Q,int k)
{
	if(Qis_full(Q))
	cout<<"queue is overflow\n";
	else
	{
		if(Q.front==-1)
		{Q.front=0;
		Q.rear=0;
		Q.element[Q.front]=k;
		else
		{
			Q.rear=(Q.rear+1)%size;
			Q.element[Q.rear]=k;
		}
		}
	}
}
int dequeue(queueQ)
{int T;
if(Qis_empty(Q))
return -1;
else
{
	if(Q.front==Q.rear)
	{T=Q.element[Q.front]
	Q.front=-1;
	Q.rear=-1;
	else
	{
		T=Q.element[Q.front]
		front=(front+1)%size;
	}
	return T;
	
	}
}
}

void display(queueQ)
{
  int i;
  if(front==-1||front>rear)
  {
    cout<<"Queue is empty\n";
  }
  else
  {
   cout<<"Queue\n";
   for(i=front;i<=rear;i++)
   {
cout<<queue[i];
   }
  }
}
int main()
{
  int ch,i=0,size;
  while(i<100)
  cout<<"enter the size of queue\n";
  cin>>size;
cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
cout<<"\nChoose your option\n";
cin>>ch;
  switch(ch)
  {
   case 1: enqueue(queue Q,int k);
       break;
   case 2: dequeue(queue Q);
       break;
   case 3: display(queue Q);
       break;
   case 4: exit(0);
  }
  return 0;
}
