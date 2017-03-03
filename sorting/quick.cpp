#include<iostream>
using namespace std;
void swap(int a[],int l,int r)
{
    int temp;
    temp=a[l];
    a[l]=a[r];
    a[r]=temp;
}

int partition(int a[],int low,int high)
{
    int l,r,p;
	p=a[low];
    l=low+1;
    r=high;
    cout<<"m";
    while(l<r)
    {
        while((a[l]<=p)&&(l<high))
        {
            l++;
        }
        while((p<=a[r]))
           {
           if((r>low))
            r--;
            else
                break;
           }
        if(l<r)
        {
            swap(a,l,r);
        }
    }
    a[low]=a[r];
    a[r]=p;
    return r;
}
void qsort(int a[],int low,int high)
{
    int p;
    cout<<"a";
    if(high<=low)
        return;
    if(high>low)
    {
        p=partition(a,low,high);
        cout<<" b";
        qsort(a,low,p-1);
        qsort(a,p+1,high);
    }
}
int main()
{
	int i=0,a[100],l=0;
    char ch;
    do
    {
        cout<<"Enter the data element number "<<(i+1)<<"\t";
        cin>>a[i++];
        cout<<"To continue press y or Y\n";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    cout<<" sorted array is \n";
    
    qsort(a,l,i-1);


	return 0;
}

