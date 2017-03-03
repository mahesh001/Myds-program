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
           int i,n;
           cout<<"enter the value of n\n";
           cin>>n;
           for(i=1;i<=n;i++)
           {
                            struct idcard b[i];
                            cout<<"enter the rollnumber of b[i]\n";
                            cin>>b[i].rollnumber;
                            cout<<"enter the name of b[i]\n";
                            cin>>b[i].name;
                            cout<<"enter the bg of b[i]\n";
                            cin>>b[i].bg;
                            cout<<b[i].rollnumber<<endl;
                            cout<<b[i].name<<endl;
                            cout<<b[i].bg<<endl;
                            }
                            system("pause");
                            }
