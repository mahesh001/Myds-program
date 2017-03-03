#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int& a,int& b)
{
    int t;
    t=a;
    a=b;
    b=t;
}
int min(int a[],int d,int i,int size)
{int j=1;
    int m=a[d*i +1];
     for(int p=2;p<=d && (d*i+p)<=size;p++)
      {
        if(m>a[d*i+p])
        {m=a[d*i+p];
           j=p;
        }
      }

      return j;
}
void create(int a[],int k,int& size,int d)
{

    a[size]=k;
    int i=size;

    while(a[(i-1)/d]>a[i] && i>0)
    {
        swap(a[(i-1)/d],a[i]);
        i=(i-1)/d;
    }
    size=size+1;

}
void heapsort(int a[],int& size,int d)
{
    int i=0,j=0,k=0;
    while(k<size)
    {
        size=size-1;
        cout<<a[0]<<" ";
        a[0]=a[size];
        i=0;j=0;
        while(i<size-1)
        {
           j=min(a,d,i,size);
            if(a[d*i+j]<a[i])
              {
                swap(a[d*i+j],a[i]);
              }
            i= d*i+j;
        }
    }
}

int main()
{
    int a[50],k,size=0,ch,d;
    cout<<"Enter d:";
    cin>>d;
    while(1)
    {
        cout<<"Enter choice:\n";
        cout<<"1.Add\t2.Heapsort\t3.Delete\t4.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    cout<<"Enter element:";
                    cin>>k;
                    create(a,k,size,d);
                    break;
            case 2:
                    cout<<"After heap sort:\n";
                   heapsort(a,size,d);
                    break;
            case 3:
                    //deleteh(a,size);
                    cout<<"Deleted element\n";
                    break;

            case 4:exit(1);

        }
    }






return 0;
}
