#include<iostream>
#include<string>
#include<cstring>
#include<conio.h>
using namespace std;
class qsort
{
    char a[20];
public:
    void getexp();
    void qusort(char a[],int low,int high);
    int partitiona( char a[],int low,int high);
    void display();
    void swapele(char a[],int left,int right);
};
void qsort::getexp()
{
    int i=0;
    char ch;
    do
    {
        cout<<"Enter the data element number "<<(i+1)<<"\t";
        cin>>a[i++];
        cout<<"To continue press y or Y\n";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    qusort(a,0,i-1);
}
//****************************************************************
void qsort::qusort(char a[],int low,int high)
{
    cout<<"Entered into qusort\n";
    int pivot;
    if(high<=low)
        return;
    if(high>low)
    {
        cout<<"entered??????????????????????\n";
        pivot=partitiona(a,low,high);
        cout<<"pivot is made????????\n";
        qusort(a,low,pivot-1);
        qusort(a,pivot+1,high);
        cout<<"sucessfully made?????\n";
    }
}
//***************************************************
int qsort::partitiona(char a[],int low,int high)
{
    cout<<"entered into partition?????\n";
    int left,right,pivotele=a[low];
    left=low;
    right=high;
    while(left<right)
    {
        //cout<<"call is made to partitoin?????\n";
        while((a[left]<=pivotele)&&(left<high))
            left++;
        cout<<"first while loop isexecuted?????\n";
        cout<<"the elements are\n";
        display();
        cout<<"\t"<<left<<endl;
        while((pivotele<=a[right]))
           {
           if((right>low))
            right--;
            else
                break;
           }
        cout<<"second while loop is executed?????\n";
        cout<<"teh elements are\n";
        display();
        cout<<"\t"<<right<<endl;
        if(left<right)
        {
            swapele(a,left,right);
            cout<<"call is made to swap?????????\n";
        }
    }
    cout<<"pivot element is\t";
    cout<<pivotele<<endl;
    cout<<"the elenment tobe replaced\t";
    cout<<a[right]<<endl;
    a[low]=a[right];
    a[right]=pivotele;
    cout<<"pivot is replaced??\n";
    return right;
}
void qsort::swapele(char a[],int left,int right)
{
    int temp;
    temp=a[left];
    a[left]=a[right];
    a[right]=temp;
    display();
}
void qsort::display()
{
    //char a[10];
    cout<<"The sorted list is\n";

    for(int i=0;i<strlen(a);i++)
    {
        cout<<a[i]<<"   ";
    }
}
int main()
{
    class qsort q;
    q.getexp();
    q.display();
    //getchar();
    return 0;

}
