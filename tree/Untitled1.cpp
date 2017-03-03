#include<iostream>


 using namespace std;

 struct TreeNode
 {
int value;
    TreeNode* left;
TreeNode* right;
 };


struct TreeType
 {
TreeNode* root;

void insert(TreeNode* tree, int item);

void insertItem(int value)
   {

       insert(root, value);

   }

};

   void TreeType::insert(TreeNode* tree, int number)
   {
 if (tree == NULL)
  {
    tree = new TreeNode;
    tree->left = NULL;
    tree->right = NULL;
    tree->value = number;
    cout << "DONE";
}

else if (number < tree->value)
{
    insert(tree->left, number);
}

else
{
    insert(tree->right, number);
}
 }


 int main()
 {
TreeType* MyTree =new TreeType;

MyTree->insertItem(8);

    return 0;

 }
