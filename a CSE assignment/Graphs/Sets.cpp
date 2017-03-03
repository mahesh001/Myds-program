#include<iostream>
using namespace std;

class set
{
	public:
		set(){
			v=7;
			for(int i=0;i<8;i++)
			a[i]=0;
		}
	private:
		int v;
		int a[8];
	public :
		void uni(int x,int y);
		int find(int x);
};

int set::find(int x)
{
	if(a[x]==0)
	return x;
	else
	return find(a[x]);
}

void set::uni(int x,int y)
{
	if(a[y]==0)
	a[y]=x;
	else if(a[x]==0)
	a[x]=y;
	else
	a[find(y)]=find(x);
} 

int main()
{
	set S;
	
	int a,b;
	cout<<"Enter the (a,b) -1 to stop\n";
	cin>>a>>b;
	while(a!=-1)
	{
		S.uni(a,b);
		cin>>a;
		if(a==-1)
		break;
		cin>>b;
	}
	
	char ans='y';
	while(ans=='y')
	{
		cout<<"Enter (a,b)\n";
		cin>>a>>b;
		
		if(S.find(a)==S.find(b))
		cout<<"Both are in same set\n";
		else
		cout<<"Both are in different set\n";
		
		cout<<"Want to enter more y or n";
		cin>>ans;
	}
}
