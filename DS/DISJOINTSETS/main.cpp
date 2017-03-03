#include <iostream>
#include <cmath>


using namespace std;
int s[20];

int find(int x)
{
    if(s[x]<=0)return x;
    find(s[x]);
}

void unio(int x,int y)
{
    if(s[y]<s[x])s[x]=y;
    else
    {
        if(s[x]==s[y])
            s[x]--;
        s[y]=x;
    }
}

int main()
{
    int n=19;
    for(int i=0;i<n;i++)
        s[i]=0;
    int x=1,y;
    while(true)
    {
        cout<<"enter the unions u wish to form\n";
        cin>>x;if(x==0)break;
        cin>>y;
        unio(x,y);
        cout<<endl;
        for(int i=1;i<n;i++)cout<<i<<" "<<s[i]<<endl;
        cout<<endl;
        cout<<"enter the point to start printing\n";
        cin>>x;
        while(x>0)
        {
            cout<<x<<"->";
            x=s[x];
        }
    }

    cout << "Hello world!" << endl;
    return 0;
}
