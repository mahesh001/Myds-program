#include<iostream>
#include<cstdlib>

using namespace std;

int hash(int key,int size)
{
   return  key%size;
}
int search(int h[],int key,int size)
{
    int i;
    int ind=hash(key,size);
    for(i=ind;i<size;i++)
    {
        if(h[i]==key)
        {
            return key;
        }
    }
    for(i=0;i<ind;i++)
    {
        if(h[i]==key)
        {
            return key;
        }
    }
    return -1;
}
int deletekey(int h[],int key,int size)
{
    int i;
    int ind=hash(key,size);
    for(i=ind;i<size;i++)
    {
        if(h[i]==key)
        {
            h[i]=-1;
            return 0;
        }
    }
    for(i=0;i<ind;i++)
    {
        if(h[i]==key)
        {
             h[i]=-1;
            return 0;
        }
    }
    return -1;
}

int initialize(int h[],int size)
{
     for(int i=0;i<size;i++)
    {
        h[i]=-1;
    }
}
void print(int h[],int size)
{
    cout<<"index\tkey\n";
    for(int i=0;i<size;i++)
    {
        cout<<i<<"\t"<<h[i]<<"\n";
    }
}
int main()
{
    int h[11],i,k,index,n=0,ch;
    int size=11;
    initialize(h,size);
    while(1)
    {
        cout<<"1.Enter\t2.print\t3.search\t4.delete\t5.Exit\n";
        cin>>ch;
        switch(ch)
         {

            case 1:cout<<"Enter element:\n";
                    cin>>k;
                    index=hash(k,size);
                    i=index;
                    if(n!=size)
                    {while(n<size)
                    {
                        if(h[i]==-1)
                        {
                            h[i]=k;n++;
                            break;
                        }
                        i=(i+1)%size;

                    }
                    }
                    else
                    cout<<"Table full!\n";
                    break;
            case 2 :print(h,size);
                    break;
            case 3:cout<<"Enter key:\n";
                    cin>>k;
                    i=search(h,k,size);
                    if(i!=-1)
                    {
                        cout<<"key found\n";
                    }
                    else
                        cout<<"key not found\n";
                    break;
            case 4:cout<<"Enter key:\n";
                    cin>>k;
                    i=deletekey(h,k,size);
                    if(i==0)
                        cout<<"key deleted\n";
                    else
                        cout<<"Key not found\n";
                    break;

            case 5:exit(1);

         }
    }






return 0;
}
