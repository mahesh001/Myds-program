#include <iostream>

#include <cstdlib>

#include <cstdio>     

#include <cstring> 

using namespace std;

 



class etnode

{       

    public:

        char data;

        etnode *lchild, *rchild;

        etnode(char data)

        {

            this->data = data;

            this->lchild = NULL;

            this->rchild = NULL;

        }

}; 

 



class snode

{    

    public:

        etnode *T;

       snode *next;

        /** constructor **/ 

        snode(etnode*T)

        {

            this->T = T;

            next = NULL;

        }

};

 

 

class etree

{

    private:

       snode *top;

    public:

        /** constructor **/ 

        etree()

        {

            top = NULL;

        }

 

      

        void clear()

        {

            top = NULL;

        }

 

        

        void push(etnode *ptr)

        {

            if (top == NULL)

                top = new snode(ptr);

            else

            {

                snode *nptr = new snode(ptr);

                nptr->next = top;

                top = nptr;

            }

        }

 

     

        etnode*pop()

        {

            if (top == NULL)

            {

                cout<<"Underflow"<<endl;

            }

            else

            {

               etnode *ptr = top->T;

                top = top->next;

                return ptr;

            }

        }

 


        etnode *peek()

        {

            return top->T;

        }

 

 

      

        void insert(char val)

        {

            if (isDigit(val))

            {

              etnode *nptr = new etnode(val);

                push(nptr);

            }

            else if (isOperator(val))

            {

               etnode *nptr = new etnode(val);

                nptr->lchild = pop();

                nptr->rchild = pop();

                push(nptr);

            }

            else

            {

                cout<<"Invalid Expression"<<endl;

                return;

            }

        }

 

      

        bool isDigit(char ch)

        {

            return ch >= '0' && ch <= '9';

        }

 

       

        bool isOperator(char ch)

        {

            return ch == '+' || ch == '-' || ch == '*' || ch == '/';

        }

 

 

       

        int toDigit(char ch)

        {

            return ch - '0';

        }

 

        
 

        void buildTree(string eqn)

        {

            for (int i = eqn.length() - 1; i >= 0; i--)

                insert(eqn[i]);

        }

 

        

        double evaluate()

        {

            return evaluate(peek());

        }

 

      

        double evaluate(etnode *ptr)

        {

            if (ptr->lchild == NULL && ptr->rchild == NULL)

                return toDigit(ptr->data);

            else

            {

                double result = 0.0;

                double lchild = evaluate(ptr->lchild);

                double rchild = evaluate(ptr->rchild);

                char x = ptr->data;

                switch (x)

                {

                case '+': 

                    result = lchild + rchild; 

                    break;

                case '-': 

                    result = lchild-rchild; 

                    break;

                case '*': 

                    result = lchild * rchild; 

                    break;

                case '/': 

                    result = lchild / rchild; 

                    break;

                default: 

                    result = lchild + rchild; 

                    break;

                }

                return result;

            }

        }

 

       

        void postorder()

        {

            postOrder(peek());

        }

 

       

        void postOrder(etnode *ptr)

        {

            if (ptr != NULL)

            {

                postOrder(ptr->lchild);            

                postOrder(ptr->rchild);

                cout<<ptr->data;            

            }    

        }

 

      
        void inorder()

        {

            inOrder(peek());

        }

 

      

        void inOrder(etnode *ptr)

        {

            if (ptr != NULL)

            {

                inOrder(ptr->lchild);

                cout<<ptr->data;   

                inOrder(ptr->rchild);            

            }    

        }

 

       

        void preorder()

        {

            preOrder(peek());

        }

 

       
        void preOrder(etnode *ptr)

        {

            if (ptr != NULL)

            {

                cout<<ptr->data;

                preOrder(ptr->lchild);

                preOrder(ptr->rchild);            

            }    

        }

};

 

 

 



int main()

{

    string s;

    cout<<"Expression Tree Test"<<endl;

    etree et;

    cout<<"\nEnter equation in Prefix form: ";

    cin>>s;

    et.buildTree(s);

    cout<<"\nPreorder  : ";

    et.preorder();

    cout<<"\n\nInorder  : ";

    et.inorder();

    cout<<"\n\nPostorder: ";

    et.postorder();

    cout<<"\n\nEvaluated Result : "<<et.evaluate();

    return 0;

}
