#include <iostream>
#include <fstream>
#include <cstdlib>
#include<string>
using namespace std;

class child
{public:
    char cname[10];
    int age;
};

union scale
{
    char sa[8];
    char sb[20];
};

class emp
{public:
    int empno;
    char name[20];
    char type[10];
    scale u;
    int count;
    child c[10];
};

ofstream& operator<<(ofstream& o,emp& d)
{
         o<<d.empno<<"$"<<d.name<<"$"<<d.type;
         if(d.type[0]=='p')
         {
             o<<"$"<<d.u.sb<<"$";
         }
         else
         {
             o<<"$";
             o<<d.u.sa<<"$";
         }
         o<<"#$"<<d.count;
         int y=d.count;
         for(int j=0;j<y;j++)
         {
             o<<"$"<<d.c[j].cname<<"$";
             o<<d.c[j].age<<"$";

         }
         o<<"!$";


    return o;
}

ostream& operator<<(ostream& o,emp& d)
{
         o<<d.empno<<"$"<<d.name<<"$"<<d.type;
         if(d.type[0]=='p')
         {
             o<<"$"<<d.u.sb<<"$";
         }
         else
         {
             o<<"$";
             o<<d.u.sa<<"$";
         }
         o<<"#$"<<d.count;
         int y=d.count;
         for(int j=0;j<y;j++)
         {
             o<<"$"<<d.c[j].cname<<"$";
             o<<d.c[j].age<<"$";

         }
         o<<"!";


    return o;
}

istream &operator>>( istream  &i, emp &d )
      {

         cout<<"Number:";
         i>>d.empno;
         cout<<"\nName:";
         i>>d.name;
         cout<<"\nType:";
         i>>d.type;
         if(d.type[0]=='p')
         {
             cout<<"\nEnter permanent type salary:";
             i>>d.u.sb;
         }
         else
         {
             cout<<"\nEnter temporary type salary:";
             i>>d.u.sa;
         }
         cout<<"\nEnter no. of children:";
         i>>d.count;
         int y=d.count;
         for(int j=0;j<y;j++)
         {
             int x=j+1;
             cout<<"\nFor child "<<x<<" Enter child name and age:";
             i>>d.c[j].cname;
             i>>d.c[j].age;
         }
         cout<<"\n\n\n";
         return i;
      }

int main()
{
    emp e;
    cin>>e;
    ofstream fout;
    fout.open("lsjo.txt");
    fout<<e;
    cout<<e;
    fout.close();
    ifstream fin,fin2;
    fin.open("lsjo.txt");
    string a;int c;
    while(!fin.eof())
    {
        getline(fin,a,'$');
        if(a=="#")
        {
            cout<<"Childrens details\n";
            fin>>c;cout<<"c is :"<<c;
            for(int i=0;i<c;i++)
            {
                getline(fin,a,'$');
                cout<<a<<" ";
                getline(fin,a,'$');
                cout<<endl<<a;
            }

           break;
        }
        if(a=="!"){cout<<"\n\nRECORD OVER";}
        cout<<a<<endl;
    }
    fin.close();
    fin2.open("lsjo.txt");

    cout << "Hello world!" << endl;
    return 0;
}
