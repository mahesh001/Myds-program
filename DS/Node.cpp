#include<iostream>
using namespace std;

class Node
{
      public:
     int element;
     Node *next;
     friend class HashedTable;
     friend class Bucket;
     Node()
     {
            next=NULL;
     }
};
