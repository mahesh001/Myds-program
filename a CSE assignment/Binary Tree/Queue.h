

class Queue
{
	public:
	Queue(){
		front=-1;
		rear=-1;
		size=6;
	}
	private:
		int front;
		int rear;
		int size;
		hnode* element[6];
		
	public:
		int isfull();
		int isempty();
		void enqueue(hnode* k);
		hnode* dequeue();
};
