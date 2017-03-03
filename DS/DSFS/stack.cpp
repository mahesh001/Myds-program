
struct node
{
    int data;
    node* next;
};

class stack
{
public:
    node *top;
    node *T;
    int pop();
    void push(int);
    int isempty();
    stack()
    {
        top=NULL;
    }
};

int stack::isempty()
{
    if(top==NULL)return 1;
    return 0;
}

int stack::pop()
{
    if(isempty()) {cout<<"empty stack\n";return 0;}
    int x=top->data;
    top=top->next;
    return x;
}

void stack::push(int f1)
{
    T=new node;
    T->data=f1;
    T->next=top;
    top=T;
}

class queue
{
    public:
    node *L,*f=NULL,*r=NULL;
    int delq();
    int isempty();
    void enq(int);
    queue()
    {
        L=new node;
    }
};

int queue::isempty()
{
    if(f==NULL)
        return 1;

    return 0;
}

int queue::delq()
{
    if(isempty()) {cout<<"queue empty\n";return 0;}
    else
    {
        cout<<f->data<<endl;
        if(f->next!=NULL)f=f->next;
        else f=NULL;
    }
}

void queue::enq(int a)
{

        L->next=new node;
        L=L->next;
        L->data=a;
        L->next=NULL;
        r=L;
        if(f==NULL)f=L;
}