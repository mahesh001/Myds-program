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
     f<<s.t.index<<" "<<s.name<<" "<<s.t.roll<<endl;
     return f;
}
void getd(student s[],ifstream &fin)
{
    for(int i=1;!fin.eof();i++)
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

}/*
void createitree(bstnode *T,int l,int r,int roll,int in)
{
    if(T==NULL)
    {
        T=new bstnode;
        T->lchild=T->rchild=NULL;
        T->s.t.roll=roll;
        T->s.t.index=in;
        T->s.t.l=l;
        T->s.t.r=r;
    }
    else if()
}*/
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

void printtodata(ofstream &f,student s)
{
    f<<s.name<<"$"<<s.roll<<"$";
}
int findtree(bstnode *T,int i)
{
    if(T==NULL)return 0;
    else if(T->s.roll==i)return T->s.t.index;
    else if(T->s.roll>i) findtree(T->lchild,i);
    else findtree(T->rchild,i);
}
int main()
{
    ifstream fin,f;ofstream fout,fout2;
    fout2.open("data.txt");
    fout.open("index.txt");
    fin.open("a.txt");
    int x;fin>>x;
    student s[10];
    getd(s,fin);
    int xx=1;
    while(xx<=x)
    printtodata(fout2,s[xx++]);
    s[x+1].t.roll=0;
    bstnode *T=NULL;int i=1;
    while(i<=x)
    create(T,s,i++);
    settree(T,s);
    print(T);i=1;
    while(i<=x)
    fout<<s[i++];
    delete s;fout.close();fout2.close();
    cout << "\nEnter the roll number which you wish to search" << endl;
    cin>>i;
    x=findtree(T,i);
    if(x==0)
    {
        cout<<"\nrecord not found!\n";
        return 0;
    }
    f.open("data.txt");
    char aa[100];x=(x-1)*2;
    i=0;
    while(i<x)
    {
        f.getline(aa,10,'$');
        i++;
    }
    f.getline(aa,10,'$');
    cout<<endl<<"Your Record is:\n"<<aa;
    f.getline(aa,10,'$');
    cout<<endl<<aa;
    return 0;

}
