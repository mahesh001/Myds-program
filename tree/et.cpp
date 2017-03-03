#include <iostream>
using namespace std;

struct etnode{
    char data;
    etnode *lchild;
    etnode *rchild;
};

char postfix[35];
int t=-1;
etnode *a[35];


int  r(char inputchar){ //for checking symbol is operand or operatorif(inputchar=='+' || inputchar=='-' || inputchar=='*' || inputchar=='/')
      return(-1);
    
	 if(inputchar>='a' || inputchar<='z')
      return(1);
     else
	 if(inputchar>='A' || inputchar<='Z')
      return(1);
     else
	 return(-99);  //for error
}

//it is used for inseting an single element in//a tree, i.e. is pushing of single element.void push(node *tree){
  void push(etnode*T)
  {
    t++;
    a[t]=T;

}
 etnode  *pop()
{
    t--;
    return(a[t+1])
	;
}


void create_expr_tree(char *suffix)
{
    char symbol;
    int i;
    etnode *newl,*ptr1,*ptr2;
    int flag; //flag=-1 when operator and flag=1 when operand
    symbol = suffix[0]; //Read the first symbol from the postfix expr.for(int i=1;symbol!=NULL;i++){ //continue till end of the expr.
        flag=r(symbol); 
        if(flag==1)
        {
            newl = new etnode;
            newl->data = symbol;
            newl->lchild = NULL;
            newl->rchild = NULL;
            push(newl);
        }
        else{    //If the symbol is operator//pop two top elements.
            ptr1=pop();
            ptr2=pop();
            newl = new etnode;
            newl->data = symbol;
            newl->lchild = ptr2;
            newl->rchild = ptr1;
            push(newl);
        }
        symbol=suffix[i];
    }
 
void inorder(etnode*T)
{
	int data;
	
 if(T!=NULL)

 {
  inorder(T->lchild);
  cout<<T->data;
  inorder(T->rchild);
 }
 else return;
}

void  preorder(etnode*T)
{ 
 if(T!=NULL)
 
 {
  cout<<T->data;
  preorder(T->lchild);
  preorder(T->rchild);
 }
 else return;
}

void postorder(etnode*T)
{ 
 if(T!=NULL)
 
 {
  postorder(T->lchild);
  postorder(T->rchild);
  cout<<T->data;
 }
 else return;
}

int main()
{
    cout<<"*****Expression Tree*****\n";
    cout<<"Enter Postfix Expression : ";
    cin>>postfix;

    //Creation of Expression Tree
    create_expr_tree(postfix);

    //Traversal Operation on expression tree
    cout<<"\nIn-Order Traversal :   ";
    inorder(a[0]);

    cout<<"\nPre-Order Traversal :  ";
    preorder(a[0]);

    cout<<"\nPost-Order Traversal : ";
    postorder(a[0]);
    return 0;
}
