#include<iostream>

using namespace std;
struct hnode
{
    int key;
    hnode* fptr;
    hnode* bptr;
    hnode()
    {
        key=-1;
        fptr=NULL;
        bptr=NULL;
    }

};
int hash(int key,int size)
{
   return  key%size;
}

void add(hnode h[],int size)
{
    int i,k,index,n=0;
    cout<<"Enter element:\n";
    cin>>k;
    index=hash(k,size);
    i=index;
    hnode* T;
    T=NULL;
    cout<<"i"<<i<<endl;
    if(h[i].key!=-1)
    {cout<<"entered ";
        T=&h[i];
        while(T->fptr!=NULL)
        {
            cout<<"running ";
            cout<<T->key<<" ";
            T=T->fptr;
        }
    }

    if(n!=size)
    {
        while(n<size)
        {
            if(h[i].key==-1)
            {
                h[i].key=k;
                h[i].fptr=NULL;
                if(T!=NULL)
                {
                    T->fptr=&h[i];
                    cout<<"linked";
                }
                h[i].bptr=T;
                cout<<"added "<<h[i].key<<endl;
                n++;
                break;
            }
            i=(i+1)%size;

        }
    }
    else
    cout<<"Table full!\n";

}
int search(hnode h[],int k,int size)
{
    hnode* T;
    T=NULL;
    int i=hash(k,size);
    cout<<i;
    T=&h[i];
    while( T!=NULL && T->key!=k )
    {
        cout<<"searching ";
        cout<<T->key;
        T=T->fptr;
    }
    if(T!=NULL)
        cout<<"found\n";
    else
        cout<<"not found\n";

}
/*void printtable(htab H[],int n)
{
    cout<<H[i]->key<<"\t"<<H[]
}*/
int main()
{
    int size,ch;
    cout<<"Enter the size of the table:\n";
    cin>>size;
    hnode *h=new hnode[size];

    do
    {
        add(h,size);
        cout<<"Press 1 to continue..\n";
        cin>>ch;
    }while(ch==1);
    cout<<"enter the element:\n";
    cin>>ch;
    search(h,ch,size);


return 0;
}
