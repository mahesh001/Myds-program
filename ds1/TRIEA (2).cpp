#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
 using namespace std;
class Node
{
public:
    char value;             
    bool end;               
    Node * child[26];    
    Node(char value);
    ~Node();
};
Node::Node(char value)
{
    this->value = value;
    for (int i = 0; i < 26; ++i)
        child[i] = NULL;
}
Node::~Node()
{
}
class Trie
{
public:
    Trie();
    ~Trie();
    void add(string word);
    bool search(string word);
    void delet(string word);
    Node * getRoot();
private:
  Node * root;
};
Trie::Trie()
{
    root = new Node(' ');
    root->end = true;
}
Node * Trie::getRoot()
{
    return root;
}
void Trie::add(string word)
{
    Node * currentNode = root;
 
    for (int i = 0; i < word.size(); ++i)
    {
        char currentChar = tolower(word.at(i));
        int index = currentChar - 'a';
        assert(index >= 0);  
        if (currentNode->child[index] != NULL)
        {
            currentNode = currentNode->child[index];
        }
        else
        {
            Node * newNode = new Node(currentChar);
            currentNode->child[index] = newNode;
            currentNode = newNode;
        }
        if (i == word.size() - 1)
        {
            currentNode->end = true;
        }
    }
}
bool Trie::search(string word)
{
    Node * currentNode = root;
    for (int i = 0; i < word.size(); ++i)
    {
        char currentChar = tolower(word.at(i));
        int index = currentChar - 'a';
        assert(index >= 0);
        if (currentNode->child[index] != NULL)
            currentNode = currentNode->child[index];
        else
            return false;
        if (i == word.size() - 1 && !currentNode->end)
            return false;
    }
    return true;
}
void Trie::delet(string word)
{
    Node * currentNode = root;
    Node * lastWord = root;
    for (int i = 0; i < word.size(); ++i)
    {
        char currentChar = tolower(word.at(i));
        int index = currentChar - 'a';
        assert(index >= 0);
        if (currentNode->child[index] != NULL)
            currentNode = currentNode->child[index];
        else
            return;
        if (i == word.size() - 1 && currentNode->end)
            currentNode->end = false;
    }
}
void alphabetize(Node * node, string prefix = "")
{
    if (node->end)
        cout << prefix << endl;
    for (int i = 0; i < 26; ++i)
    {
        if (node->child[i] != NULL)
        {
            string currentString = prefix + node->child[i]->value;
            alphabetize(node->child[i], currentString);
        }
    }
}
 
int main()
{
    Trie * t = new Trie();
    Node*root;
    char a[20],word[20],x;
    int n, j, s;
    cout<<"1.add \n"<<"2.delete \n";
    cin>>j;
    switch(j)
    {
    case 1:
    cout<<"enter size of word \n";
    cin>>n;
    cout<<"enter the word u want to add \n";
   // cin>>a[n];
    for(int i = 0; i <n; i++)
    cin>>a[i];
    t->add(a);
 //  alphabetize(t->getRoot());
   case 2:
   	cout<<"enter the size of word \n";
   	cin>>s;
   	cout<<"enter the word u want to delete \n";
   	cin>>word[s];
   	t->delet(word);
   }
   cout<<"u want to continue press y else press n\n";
   cin>>x;
   while(x=='y')
   {
   	cout<<endl;
   }
   	
    return 0;
}
