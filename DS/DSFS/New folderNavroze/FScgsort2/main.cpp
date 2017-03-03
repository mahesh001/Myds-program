#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
int i;int x=0;
class student
{public:
    int index;
    char name[10];
    char cgpa[6];
    char roll[7];
};
ofstream &operator<<(ofstream &f, student &s)
{
    f<<s.name;
    for(i=strlen(s.name);i<10;i++)
    f<<"#";
    f<<s.cgpa;
    for(i=strlen(s.cgpa);i<6;i++)
    f<<"#";
    f<<s.roll;
    for(i=strlen(s.roll);i<6;i++)
    f<<"#";

}
ifstream &operator>>(ifstream &f, student &s)
{
    if(x==0){
    char a;int i=0;
    for(i=0;i<10;i++)
    {
        f>>a;
        if(a=='#')
        {
            s.name[i]='\0';continue;
        }
        s.name[i]=a;
    }cout<<endl;
    for(i=0;i<6;i++)
    {
        f>>a;
        if(a=='#')
        {
            s.cgpa[i]='\0';continue;
        }
        s.cgpa[i]=a;
    }cout<<endl;
    for(i=0;i<6;i++)
    {
        f>>a;
        if(a=='#')
        {
            s.roll[i]='\0';continue;
        }
        s.roll[i]=a;
    }cout<<endl;}
    else{
        f>>s.name;
    f>>s.roll;
    f>>s.cgpa;
    }
}
istream &operator>>(istream &i, student &s)
{
    cout<<"enter name: ";i>>s.name;
    cout<<"roll no: ";i>>s.roll;
    cout<<"cgpa :";i>>s.cgpa;
}

ostream &operator<<(ostream &f, student &s)
{
    cout<<"\n\n\nname: ";f<<s.name;
    cout<<"\nroll no: ";f<<s.roll;
    cout<<"\ncgpa :";f<<s.cgpa;
}



int main()
{
    ifstream fin,f;
    fin.open("original.txt");
    student s[10],s1;
    cout<<"enter the no. of nos. to sort\n";
    int y;cin>>y;x=1;ofstream fout2;
    fout2.open("data.txt");
    for(int i=0;i<y;i++)
    {
        fin>>s[i];
        s[i].index=i+1;
        fout2<<s[i];
    }
    x=0;
    int k,l;
    for(k=0;k<y;k++)
    {
        for(l=k+1;l<y;l++)
        {
            if(atof(s[k].cgpa)<=atof(s[l].cgpa))
            {
                s1=s[k];s[k]=s[l];s[l]=s1;
            }
        }
    }
    fin.close();fout2.close();
    fout2.open("sort.txt");
    for(int i=0;i<y;i++)
    {
        fout2<<s[i].index<<" "<<s[i].cgpa<<endl;
    }
    fout2.close();
    fin.open("sort.txt");
    float ff,f1;
    fin>>ff>>f1;i=0;
    for(int i=0;i<5;i++)
    {
        ff--;
        f.open("data.txt");char a;
        int d=ff*22;
        for(int i=0;i<d;i++){
        f>>a;}
        cout<<endl;
        f>>s1;cout<<s1;
        fin>>ff>>f1;
        f.close();
    }



    return 0;
}
