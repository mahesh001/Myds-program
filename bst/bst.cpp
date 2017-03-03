# include <iostream>
using namespace std;
struct bstnode
       {
        int data;
        bstnode *T;
        bstnode *rchild;
        bstnode *lchild;
       }*root=NULL;

       
 void insert(bstnode*&T,int k)
{
 if(T==NULL)
 {
  T=new bstnode;
  T->data=k;
  T->rchild=NULL;
  return;
 }
 else
     {
      if(T->data>k)
      insert(T->lchild,k);
      else insert(T->rchild,k);
     }
}
void search(bstnode*T, int k,  int &found)
{

 
 found=0;
 while(T!=NULL)
 {
  if(T->data==k)
  {
   found=1;
   return;
  }
  if(T->data<k)
  T=T->rchild;
  else T=T->lchild;
 }
}
 
void inorder(bstnode*T)
{
	int data;
	
 if(T!=NULL)
 if(T->data!=NULL)
 {
  inorder(T->lchild);
  cout<<T->data;
  inorder(T->rchild);
 }
 else return;
}

void  preorder(bstnode*T)
{ 
 if(T!=NULL)
 if(T->data!=NULL)
 {
  cout<<T->data;
  preorder(T->lchild);
  preorder(T->rchild);
 }
 else return;
}

void postorder(bstnode*T)
{ 
 if(T!=NULL)
 if(T->data!=NULL)
 {
  postorder(T->lchild);
  postorder(T->rchild);
  cout<<T->data;
 }
 else return;
}

void display(bstnode *T, int level)

{
    int i;

    if (T != NULL)

    {

        display(T->rchild, level+1);

        cout<<endl;

        if (T == root)

            cout<<"Root->:  ";

        else

        {

            for (i = 0;i < level;i++)

                cout<<"       ";

	}

        cout<<T->data;

        display(T->lchild, level+1);

    }

}
 
int main()
{
//	bstnode*T;
char ch;
int x,k;
do
{
cout<<"\nPress: "<<endl;
cout<<"      1 for inserting"<<endl;
cout<<"      2 for inorder traversal"<<endl;
cout<<"      3 for preorder traversal"<<endl;
cout<<"      4 for postorder traversal"<<endl;
cout<<"      5 for display bst"<<endl;
cin>>x;
switch(x)
{
 case 1: 
        cout<<"Enter value to insert: ";
         cin>>k;
         insert(root,k);
         break;
 case 2: 
         inorder(root);
         break;
 case 3: 
         preorder(root);
         break;
 case 4: 
         postorder(root);
         break;
 
}
cout<<"you want to continue \n";
cin>>ch;
}
while(ch=='y');

   return 0;
     
     
 }
