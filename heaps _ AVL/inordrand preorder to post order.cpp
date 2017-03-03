 
#include <iostream>
using namespace std;
int search(int arr[], int x, int size)
{
    for (int i = 0; i < size; i++)
      if (arr[i] == x)
         return i;
    return -1;
}
void printPostOrder(int in[], int pre[], int size)
{
   int root = search(in, pre[0], size);
 
   // If left subtree is not empty, print left subtree
   if (root != 0)
      printPostOrder(in, pre+1, root);
 
   // If right subtree is not empty, print right subtree
   if (root != size-1)
      printPostOrder(in+root+1, pre+root+1, size-root-1);
 
   // Print root
   cout << pre[0] << " ";
}
 

int main()
{
   int in[20],n;
   int pre[20]; 
   cout<< "enter the size\n";
   cin>>n;
   cout<<" enter inorder \n";
   cin>>in[n];
   cout<<"enter preorde\n";
   cin>>pre[n];
   int size = n/sizeof(in[0]);
   cout << "Postorder traversal " << endl;
   printPostOrder(in, pre, size);
   return 0;
}
