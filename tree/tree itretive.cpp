Inorder(Tree *p)
{
    stack < Tree* > S;
    do
    { 
        while (p!=NULL)                      
        { 
            // store a node in the stack and visit it's left child
            S.push(p);
            p=p->left; 
        }

        // If there are nodes in the stack to which we can move up
        // then pop it
        if (!S.empty())
        { 
            p=S.top();
            S.pop();

            // print the nodes value
            cout << p->ele << "-";

            // vistit the right child now
            p=p->right; 
        }

    // while the stack is not empty or there is a valid node
    }while(!S.empty()||p!=NULL);
}Preorder(Tree *p)    
{ 
    stack < Tree* > S;
    do
    {     
        while (p!=NULL)
        { 
            // storea node in stack and print it's value
            S.push(p);
            cout << p->ele << "-";
            // visit the left child
            p = p->left; 
        }

        // visit the right child
        if (!S.empty())
        {
            p=S.top();
            S.pop();
            p = p->right; 
        }
 Postorder(Tree *p)  
{
    stack < Tree* > S;
    Tree *prev = NULL;
    do
    { 
        while (p!=NULL)
        { 
            S.push(p);
            p=p->left;
        }
        if(!S.empty())
        {
            while(p==NULL && !S.empty())
            {
                p=S.top();
                if(p->right!=NULL)
                {
                    if(p->right == prev)
                    {
                        cout << p->ele  <<  "-";
                        S.pop();
                        prev = p;
                        p = NULL;
                    }
                    else
                        p = p->right;
                }
                else
                {
                    cout << p->ele  <<  "-";
                    S.pop();
                    prev = p;
                    p = NULL;
                }
            }
        }    
    }while(!S.empty());
    } while(!S.empty()||p!=NULL);
    
