# include <iostream>
using namespace std;
struct kdtnode
       {
        int data[];
        kdtnode *T;
        kdtnode *rchild;
        kdtnode *lchild;
       }*root=NULL;
 void insert(kdtnode*&T,int k,int v[],int l)
{ //if(root==NULL)
 if(T==NULL)
 {
  T=new kdtnode;
  T->data[l]=v[l];
  T->lchild=NULL;
  T->rchild=NULL;
  return;
 }
 else
     {
      if(T->data[l]>v[l])
      insert(T->lchild,k,v,(l+1)%k);
      else insert(T->rchild,k,v,(l+1)%k);
     }
}
        

    

   
void search(kdtnode*T, int k,int v[],int l,  int &found)
{

 
 found=0;
 while(T!=NULL)
 {
  if(T->data[l]==v[l])
  {
   found=1;
   return;
  }
  if(T->data[l]<v[l])
  T=T->rchild;
  else T=T->lchild;
 }
}
 
void inorder(kdtnode*T)
{
	int l;
 if(T!=NULL)
 //if(T->data!=NULL)
 {
  inorder(T->lchild);
  cout<<T->data[l];
  inorder(T->rchild);
 }
// else return;
}

void preorder(kdtnode*T)
{
	int l;
 if(T!=NULL)
 //if(T->data!=NULL)
 {
  cout<<T->data;
  preorder(T->lchild);
  preorder(T->rchild);
 }
 //else return;
}

void postorder(kdtnode*T)
{
 if(T!=NULL)
// if(T->data!=NULL)
 {
  postorder(T->lchild);
  postorder(T->rchild);
  cout<<T->data;
 }
 else return;
}
void print (kdtnode * T, int & p)
{
    if (!T) return;

    print (T->lchild,p);

    p++;
    cout << p << ' ' << T->data << endl;

    print (T->rchild,p);
}


int main()
{
//	bstnode*T;
	char ch;
int x,k,p,v[20],l;
do{

cout<<"\nPress: "<<endl;
cout<<"      1 for inserting"<<endl;
cout<<"      2 for inorder traversal"<<endl;
cout<<"      3 for preorder traversal"<<endl;
cout<<"      4 for postorder traversal"<<endl;
cout<<"      6 for print tree"<<endl;
cin>>x;
switch(x)
{
 case 1:
        
        cout<<"Enter size of array\n ";
         cin>>k;
         cout<<"enter the level of tree \n";
         cin>>l;
         cout<<"insert the  array element \n";
         cin>>v[k];
        insert(root,v[20],&k,l);
         break;
 case 2: inorder(root);
         break;
 case 3: preorder(root);
         break;
 case 4: postorder(root);
         break;
 case 6:
 	     cout<<"enter the value";
 	     cin>>p;
         print(root,p);         
		 default: cout<<"Wrong Choice"<<endl;
}
cout<<"you want to continue \n";
cin>>ch;
}
while(ch=='y');
   return 0;
     

     
     
 }
