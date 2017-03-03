#include "Bucket.cpp"
#include<math.h>
using namespace std;
class HashedTable
{
      public:
               
               void find(int x)
               {
                    int n=findHash(x);
                    
               }
      private:
              int size;
               Bucket *buckets;
      public:
               HashedTable()
               {
                     
                     size=0;
                     buckets=NULL;
               }
               //Hash Function...
      private:
               int findHash(int no)
               {
                   int temp=1;
                   for(int i=0;i<size;i++)
                   {
                        temp*=2;
                   }               
                
                return (no%temp);
               }
               //Function calling the insert function of the Bucket class...
               bool insert(Bucket& bucket,int& no)
               {
                    return (bucket.insert(no));
               }
      public:
             void insert(int no)
             {
                       int n=findHash(no);
                       
                       bool TorF=insert(buckets[n],no);
                       if(!TorF)
                       {
                                extend(n,buckets);
                                insert(no);
                       }
             }     
      private:
              void extend(int& n,Bucket*  bucket)
              {
                   
                   size++;
                   //Creating the new Hash table thing and copying the pointers as required....
                   Bucket *buckets1 =new Bucket[(int)pow(2,size)];
                   for(int i=0;i<((int)pow(2,size-1));i++)
                   {
                           if(i!=n)
                           {
                                  buckets1[2*i]=this->buckets[i];
                                  buckets1[2*i+1]=this->buckets[i];
                           }
                           else
                           {
                               buckets1[2*i]=this->buckets[i];                              
                           } 
                   }
                   //Deleting the original hash table and making the new table the orginal one....
                   delete buckets;
                   buckets=new Bucket[(int)pow(2,size)];
                   for(int i=0;i<((int)pow(2,size));i++)
                   {
                           buckets[i]=buckets1[i];
                   }  
                   //Transfer the elements that donot belong to this(2n+1) Bucket to the new Bucket.....    
                   Node *temp=buckets[2*n].root;
                   while(temp!=NULL)
                   {
                             findHash(temp->element);
                             if(temp->element!=(2*n))
                             {
                                   insert(temp->element);
                                   if(temp->next!=NULL)
                                   {
                                         Node *temp1=temp->next;
                                         temp->element=temp->next->element;
                                         temp->next=temp->next->next;
                                         delete temp1;
                                   }
                                   else
                                   {
                                        delete temp;    
                                   }
                                   temp=temp->next;
                             }
                   }
              }
};
int main()
{
    HashedTable *hsdtbl=new HashedTable();
    while(1)
    {
    cout<<"\n Please specify the operation that you want to do";
    cout<<"\n 1-Inserting element..";
    cout<<"\n 2-Finding elememt..";
    cout<<"\n 3-Exit...";
    int k;
    cin>>k;
    switch(k)
    {
             case 1:
                  {
                        cout<<"\nEnter the number that you want to insert";
                        int l;
                        cin>>l;
                        hsdtbl->insert(l);
                        cout<<endl;
                        break;
                  }
             case 2:
                  {
                        cout<<"\nEnter the element that you want to find";
                        int m;
                        cin>>m;
                        hsdtbl->find(m);
                        cout<<endl;
                  }
            
             default: cout<<"\nPlease specify a valid option\n";
     }
     }
     return 0;
}
