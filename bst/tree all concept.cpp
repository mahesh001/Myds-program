
#include <iostream>
using namespace std;

struct bstnode{
    int data;
    bstnode *lchild;
    bstnode *rchild;
};

class BST{
    public:
    bstnode *T;
    BST(){
        T=NULL;
    }
    void create(bstnode *&,int k);   
    void postorder(bstnode *);
    void inorder(bstnode*);
    void preorder(bstnode*);
    void determineHeight(bstnode *,int *);
    int totalNodes(bstnode *);
    int internalNodes(bstnode *); 
    int externalNodes(bstnode*);
    void remove(bstnode*);
    bstnode searchElement(bstnode *,int);
    void findSmallestNode(bstnode *);
    void findLargestNode(bstnode *);
};

void BST :: create(bstnode *&T,int k){
    if(T == NULL){
        T = new bstnode;
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else{
        if( T->data > k)
            create( T->lchild,k);
        else
            create( T->rchild,k);
    }
}

void BST::inorder(bstnode*T)
{
	int data;
 if(T!=NULL)
// if(T->data!=NULL)
 {
  inorder(T->lchild);
  cout<<T->data;
  inorder(T->rchild);
 }
 //else return;
}

void BST::preorder(bstnode*T)
{
 if(T!=NULL)
 //if(T->data!=NULL)
 {
  cout<<T->data;
  preorder(T->lchild);
  preorder(T->rchild);
 }
 else return;
}

void BST::postorder(bstnode*T)
{
 if(T!=NULL)
 //if(T->data!=NULL)
 {
  postorder(T->lchild);
  postorder(T->rchild);
  cout<<T->data;
 }
 else return;
}


void BST :: determineHeight(bstnode *T, int *height){
    int left_height, right_height;
    if( T == NULL)
        *height = 0;
    else{
        determineHeight(T->lchild, &left_height);
        determineHeight(T->rchild, &right_height);
        if( left_height > right_height)
            *height = left_height + 1;
        else
            *height = right_height + 1;
    }
}


int BST :: totalNodes(bstnode *T){
    if( T == NULL)
        return 0;
    else
	return( totalNodes(T->lchild) + totalNodes(T->rchild) + 1 );
}

int BST :: internalNodes(bstnode *T){
    if( (T==NULL)  || (T->lchild==NULL  && T->rchild==NULL))
        return 0;
    else
	return( internalNodes(T->lchild) + internalNodes(T->rchild) + 1 );
}

int BST :: externalNodes(bstnode *T){
    if( T==NULL )
        return 0;
    else
	if( T->lchild==NULL  && T->rchild==NULL)
        return 1;
    else 
	return( externalNodes(T->lchild) + externalNodes(T->rchild));
}

void BST :: remove(bstnode *T){
    if( T!= NULL){
        remove( T->lchild );
        remove( T->rchild );
        delete( T );
    }
}

bstnode  BST :: searchElement(bstnode *T, int k){
    if( (T->data == k) || ( T == NULL) );
       // return T ;
    else
	if( k < T->data)
        return searchElement( T->lchild, k);
    else
	return searchElement( T->rchild, k);
}

void BST :: findSmallestNode(bstnode *T){
    if( T==NULL || T->lchild==NULL)
        cout<< T->data;
    else
        findSmallestNode( T->lchild);
}




void BST :: findLargestNode(bstnode *T){
    if( T==NULL || T->rchild==NULL)
        cout<<T->data;
    else
        findLargestNode(T->rchild);
}




int main()
{
    BST obj;
    int choice;
    int height=0,total=0,n,k;
    bstnode **a;

    while(1)
	{
    
        cout<<"\n*****BINARY SEARCH TREE OPERATIONS*****\n";
        cout<<"--Binary Tree and Binary Search Tree common operations--\n";
        cout<<"1) Create Tree\n";
        cout<<"2) Traversal\n";
        cout<<"3) Height of Tree\n";
        cout<<"4) Total Nodes\n";
        cout<<"5) Internal Nodes \n";
        cout<<"6) External Nodes \n";
        cout<<"7) Remove Tree\n";
        cout<<"\n--Only Binary Search Tree Operations--\n";
        cout<<"8)  Insert Node\n";
        cout<<"9)  Search Node\n";
        cout<<"10) Find Smallest Node\n";
        cout<<"11) Find Largest Node\n";
        
        cout<<"13) Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1 : //Create Tree
                cout<<"\n\n--Creating Tree--";
                cout<<"\nHow many nodes u want to enter : ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"Enter value : ";
                    cin>>k;
                    obj.create(obj.T,k);
                }
                break;

            case 2 : 
                cout<<"\n\nInorder Traversal : ";
                obj.inorder(obj.T);

                cout<<"\n\nPre-order Traversal : ";
                obj.preorder(obj.T);

                cout<<"\n\nPost-order Traversal : ";
                obj.postorder(obj.T);
                
                break;

            case 3 : //Determining Height of Tree
                obj.determineHeight(obj.T,&height);
                cout<<"\n\nHeight of Tree : "<<height;
                
                break;

            case 4 : //Total nodes in a tree
                total=obj.totalNodes(obj.T);
                cout<<"\n\nTotal Nodes : "<<total;
                
                break;

            case 5 : //Internal nodes in a tree
                total=obj.internalNodes(obj.T);
                cout<<"\n\nInternal Nodes : "<<total;
                
                break;

            case 6 : //External nodes in a tree
                total=obj.externalNodes(obj.T);
                cout<<"\n\nExternal Nodes : "<<total;
                
                break;

            case 7 : //Remove Tree from memory
                obj.remove(obj.T);
                cout<<"\n\nTree is removed from Memory";
                
                break;

            case 8 : //Inserting a node in a tree
                cout<<"\n\n--Inserting Node in a tree--\n";
                cout<<"Enter value : ";
                cin>>k;
                obj.create(obj.T,k);
                cout<<"\nItem is inserted\n";
                
                break;

            case 9 : //Search element
                cout<<"\n\n--Search Element--\n";
                cout<<"Enter item to searched : ";
                cin>>k;
               obj.searchElement(obj.T,k);
                    cout<<"\nSearch Element was Found";
                
                break;

            case 10 : //Find Smallest Node
                cout<<"\n\nSmallest Node is :  ";
                obj.findSmallestNode(obj.T);
                
                break;

            case 11 : //Find Largest Node
                cout<<"\n\nLargest Node is :  ";
                obj.findLargestNode(obj.T);
                
                break;
            default : cout<<"wrong choice";
        }//end of switch
    }
    return 0;
}
