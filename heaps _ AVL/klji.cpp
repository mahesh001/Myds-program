void printlevelOrder(bstnode *T) {
  if (!root) return;
  queue<BinaryTree*> currentlevel, nextlevel;
  currentlevel.push(root);
  while (!currentlevel.empty()) {
    BinaryTree *currnode = currentlevel.front();
    currentlevel.pop();
    if (currnode) {
      cout << currnode->data << " ";
      nextlevel.push(currnode->left);
      nextlevel.push(currnode->right);
    }
    if (currentlevel.empty()) {
      cout << endl;
      swap(currentlevel, nextlevel);
    }
  }
}
