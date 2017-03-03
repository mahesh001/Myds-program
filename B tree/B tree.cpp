#include<iostream>
using namespace std;
struct bdnode
{
	int *key[9];  
    int d;      
    bdnode *C[10];
    int n;     
    bool node;
};
void bdnode(int d1, bool node1)
{
  //  d = d1;
 //   node = node1;
//    key = new int[2*d];
  //  C = new bdnodeode *[2*d+1];
  //  n = 0;
}
void traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (node == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }
    if (node == false)
        C[i]->traverse();
}
void splitChild(int i, bdnode *y)
{
   bdnode *z = new bdnode(y->d, y->node);
    z->n = d - 1;
    for (int j = 0; j < d-1; j++)
        z->keys[j] = y->keys[j+d];
    if (y->node == false)
    {
        for (int j = 0; j < d; j++)
            z->C[j] = y->C[j+d];
    }
    y->n = d - 1;
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];
    C[i+1] = z;
    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];
    keys[i] = y->keys[d-1];
    n = n + 1;
}
void insert(int k)
{ if (root == NULL)
    {
        root = new bdnode(d, true);
        root->keys[0] = k; 
        root->n = 1;  
    }
    else
    {
        if (root->n == 2*d-1)
        {
            bdtree *s = new bdtree(d, false);
            s->C[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);
            root = s;
        }
        else  
            root->insertNonFull(k);
    }
}
void bdtree::insertNonFull(int k)
{
    int i = n-1;
    if (node == true)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            i--;
        }
        keys[i+1] = k;
        n = n+1;
    }
    else 
    {
        while (i >= 0 && keys[i] > k)
            i--;
        if (C[i+1]->n == 2*d-1)
        {
            splitChild(i+1, C[i+1]);
 
            if (keys[i+1] < k)
                i++;
        }
        C[i+1]->insertNonFull(k);
    }
}
void search(int k)
{
    int i = 0;
    while (i < n && k > keys[i])
        i++;
    if (keys[i] == k)
        return this;
    if (node == true)
        return NULL;
    return C[i]->search(k);
}
int main ()
{
	int d,key;
	cout<<"enter the degree of tree \n":
		cin>>d;
		cout<<"enter the key of tree \n";
		cin>>key;
		cout<<"tree traversal is \n";
		traversal();
		return 0;
}
