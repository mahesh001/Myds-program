#include<iostream>
using namespace std;
struct stu
{public:
       int rolno;
       int marks;
       void read();
};
void stu::read()
{
      cout<<"enter the rollno";
    cin>>rolno;
    cout<<"enter the marks";
    cin>>marks;
}
     
int main()
{
    stu s;
    s.read(); 
    cout<<s.marks<<s.rolno;
    system("pause");
    return(0);
}
       
