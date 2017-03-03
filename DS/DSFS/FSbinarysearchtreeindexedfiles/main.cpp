#include <iostream>
#include <fstream>

using namespace std;

struct tree
{
    int l,r,roll,index;
};

struct student
{
    string name;
    int roll;
    tree t;
};
struct bstnode
{
    student s;
    bstnode *lchild,*rchild;
};


ifstream &operator>>(ifstream &f, student &s)
{
    f>>s.name;
    f>>s.roll;
    return f;
}
ofstream &operator<<(ofstream &fo, student s)
{
     fo<<s.t.index<<" "<<s.t.roll<<" "<<s.t.l<<" "<<s.t.r<<endl;
     return fo;
}
ostream &operator<<(ostream &f, student &s)
{
     f<<s.name<<" "<<s.t.index<<" "<<s.t.roll<<" l:"<<s.t.l<<" r:"<<s.t.r<<endl;
     return f;
}
void getd(student s[],ifstream &fin)
{
    for(int i=0;!fin.eof();i++)
    {
        fin>>s[i];

        s[i].t.roll=s[i].roll;
        s[i].t.index=i;
        s[i].t.l=s[i].t.r=NULL;
    }
}

void create(bstnode *&T,student s[],int i)
{
    if(s[i].t.roll==0)return;
    if(T==NULL)
    {
        T=new bstnode;
        T->lchild=T->rchild=NULL;
        T->s=s[i];
    }
    else if(s[i].t.roll>T->s.t.roll)
        create(T->rchild,s,i);

    else
        create(T->lchild,s,i);
}
void print(bstnode *T)
{
    if(T==NULL)return;
    cout<<T->s;
    print(T->lchild);
    print(T->rchild);

}

void settree(bstnode *&T,student s[])
{
    if(T==NULL)return;
    if(T->lchild!=NULL)
    {
        T->s.t.l=T->lchild->s.t.index;
        s[T->s.t.index].t.l=T->lchild->s.t.index;
    }

    if(T->rchild!=NULL)
    {
        T->s.t.r=T->rchild->s.t.index;
        s[T->s.t.index].t.r=T->rchild->s.t.index;
    }
    settree(T->lchild,s);
    settree(T->rchild,s);
}

int main()
{
    ifstream fin;ofstream fout;
    fout.open("index.txt");
    fin.open("a.txt");
    int x;fin>>x;
    student s[10];
    getd(s,fin);
    s[x].t.roll=0;
    bstnode *T=NULL;int i=0;
    while(i!=x)
    create(T,s,i++);
    settree(T,s);
    print(T);i=0;
    while(i!=x)
    fout<<s[i++];
    cout << "Hello world!" << endl;
    return 0;
}
