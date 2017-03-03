#include<iostream>
using namespace std;
struct idcard
{
       int rollnumber;
       char name[10];
       char bg;
       };
       int main()
       {
           struct idcard b1;
           cout<<"enter the rollnumber\n";
           cin>>b1.rollnumber;
           cout<<"enter the name\n";
           cin>>b1.name;
           cout<<"enter the bg\n";
           cin>>b1.bg;
           cout<<b1.rollnumber<<endl;
           cout<<b1.name<<endl;
           cout<<b1.bg<<endl;
           return 0;
           }
