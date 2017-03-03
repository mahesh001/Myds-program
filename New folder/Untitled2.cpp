
void printlevelrderbst(bstnode *root)
{

    if (root == NULL)  return;

    q.push(root);
 
    while (1)
    {
       
        int bstnodeCount = q.size();
        if bst(nodeCount == 0)
            break;
 
        
        while (bstnodeCount > 0)
        {
           bstnode *T = q.front();
            cout << T->data << " ";
            q.pop();
            if (T->lchild != NULL)
                q.push(T->lchild);
            if (T->right != NULL)
                q.push(T->rchild);
            bstnodeCount--;
        }
        cout << endl;
    }
}
