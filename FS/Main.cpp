#include "HashedTable.cpp"
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
             case 3:exit(1);
             default: cout<<"\nPlease specify a valid option\n";
     }
     }
     return 0;
}
    
