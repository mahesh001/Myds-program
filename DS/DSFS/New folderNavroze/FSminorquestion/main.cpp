#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct stud
{
    string a;
    int b[10];
    stud* next;
};

void create(stud *&s,string a,int i)
{
    if(s==NULL)
    {
        s=new stud;
        s->a=a;
        s->b[0]=1;
        s->b[1]=i;
        s->next=NULL;
    }
    else if(s->a==a)
    {
        s->b[0]++;
        s->b[s->b[0]]=i;
    }
    else if(s->a>a)
    {

        stud *t=new stud;

        if(s->next!=NULL || s->next->next!=NULL)
        {cout<<"HI";t->next=s->next->next;}
        else {cout<<"HI";cout<<"HI";t->next=NULL;}
        s->next=t;
        t->a=s->a;

        for(int d=0;d<=s->b[0];d++)
        t->b[d]=s->b[d];
        s->a=a;
        s->b[0]=1;
        s->b[1]=i;
    }
    else create(s->next,a,i);
}
void pint(stud *s)
{
    while(s!=NULL)
    {
        cout<<s->a<<" ";
        for(int i=1;i<=s->b[0];i++)
            cout<<s->b[i]<<" ";
        s=s->next;
        cout<<endl;
    }
}
int main()
{
    int j=0;
    stud *s=NULL,*t;
    char f[100],x;
    string jk;
    ifstream fin;
    fin.open("a.txt");
    while(!fin.eof())
    {
        string yz="";
        int i;
        for(i=0;i<16;i++)
        {
            fin.get(x);
        }
        for(i=0;i<2;i++)
        {
            fin.get(x);
            yz=yz+x;
        }
        cout<<yz;
        if(fin.eof())break;
        create(s,yz,j);
        j++;
    }
    cout<<endl;
    //pint(s);
    return 0;
}
