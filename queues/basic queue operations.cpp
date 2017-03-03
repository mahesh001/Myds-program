#include<iostream>
#include<process.h>
using namespace std;
struct queue{
	int front;
	int rear;
	int size;
	int ele[20];
	queue(){
		rear=-1;
		front=-1;
		size=20;
	}
};
int isfull(queue Q){
	if(((Q.rear+1)%(Q.size))==(Q.front)){
		return 1;
	}
	else{
	return 0;
	}
}
int isempty(queue Q){
	if(Q.front==-1 && Q.rear==-1){
		return 1;
	}
	else{
		return 0;
	}
}
void enque(queue &Q,int k){
	if(isfull(Q)==1){
		cout<<"Queue is full";
	}
	else{
		if(Q.front==-1 && Q.rear==-1){
			Q.front=0;
			Q.rear=0;
		}
		else{
			Q.rear=(Q.rear+1)%Q.size;
		}
		Q.ele[Q.rear]=k;
	}
}
int deque(queue &Q){
	int t;
	if(isempty(Q)==1){
		cout<<"Queue is empty ";
		return -1;
	}
	else{
		if(Q.front==Q.rear){
			t=Q.ele[Q.front];
			Q.front=-1;
			Q.rear=-1;
		}
		else{
			t=Q.ele[Q.front];
			Q.front=(Q.front+1)%Q.size;
		}
	return t;
	}
}
int main(){
	queue Q;
	int n,k,i;
	cout<<"enter the no. of elements to be enqueued(max. 20)\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
	cout<<"\n Enter numbers to be entered in queue \n ";
	cin>>k;
	enque(Q,k);
	}
	for(i=0;i<n;i++){
		k=deque(Q);
		cout<<k<<"-";
	}
	int p;
	while(1){
	
	cout<<"\nselect the operation to be performed\n(-1 to stop)\n";
	cout<<"1. enque\n";
	cout<<"2. deque\n";
	
	cin>>p;
	if(p==-1) break;
	switch(p){
		case 1: cout<<"Enter the element \n";
		cin>>k;
		enque(Q,k);
		break;
		case 2: cout<<"the element entered was: ";
		cout<<deque(Q)<<"\t";
		break;
	}
}
return 0;
}
