
# include <iostream>
using namespace std;
int no,key,level=0,flag=1;
struct bstree
{
 int no;
 struct bstree *left;
 struct bstree *right;
}*list,*head;


class bst
{
 struct bstree *list;
 public:
    struct bstree *root;
    bst()
    {
     list=NULL;
     root=NULL;
    }
    void create_bstree(struct bstree *list);
    void display_bstree(struct bstree *list);
    void search_bstree(struct bstree *list);
};

void bst :: search_bstree(struct bstree *list)
{
 if(list!=NULL)
 {

 if(key == list->no)
 {
    cout<<"Key Found at Level :" <<level;
    flag=0;
    return;
 }


 if(key < list->no)
 {
    level++;
    search_bstree(list->left);
 }

 if(key > list->no)
 {
    level++;
    search_bstree(list->right);
 }
 }
 else
 {
  return;
 }
}

void bst :: display_bstree(struct bstree *list)
{

   if(list->left!=NULL)
   {
     display_bstree(list->left);
   }

   cout<<list->no<<"\t";

   if(list->right!=NULL)
   {
    display_bstree(list->right);
   }
   return;
}



void bst :: create_bstree(struct bstree *list)
{
  if(root==NULL)
  {
   cout<<endl<<"Enter -1 to Stop ..."<<endl;
   cout<<"Enter Number :";
   cin>>no;
    if(no==-1)
    {
         return;
    }
    else
    {
        list=new bstree;
        list->left=NULL;
        list->right=NULL;
        root=list;
        list->no=no;
    }
  }
  else
  {
     if(no==-1)
     {
      return;
     }
     if(no < list->no)
     {
       if(list->left!=NULL)
       {
        create_bstree(list->left);

       }
       else
       {
     list->left=new bstree;
     list=list->left;
     list->left=NULL;
     list->right=NULL;
     list->no=no;
       }
       if(no==-1)
       return;


     }

     if(no>list->no)
     {
    if(list->right!=NULL)
    {
          create_bstree(list->right);
    }
    else
    {
      list->right=new bstree;
      list=list->right;
      list->left=NULL;
      list->right=NULL;
      list->no=no;
    }
    if(no==-1)
    return;
     }
  }
    cout<<endl<<"Enter -1 to Stop ..."<<endl;
    cout<<"Enter Number :";
    cin>>no;
    if(no==-1)
    {
    return;
    }
    else
    {
    create_bstree(root);
    }
}
int main()
{
   
   bst bst1;
   bst1.create_bstree(bst1.root);
   cout<<endl;
   cout<<"Inorder"<<endl;
   bst1.display_bstree(bst1.root);
   cout<<endl<<"Enter Number to search :";
   cin>>key;
   bst1.search_bstree(bst1.root);
   if(flag==1)
   {
    cout<<endl<<"Search key not Found in the tree"<<endl;
   }
   return 0;
}
