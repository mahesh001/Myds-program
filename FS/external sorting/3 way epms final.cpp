#include<iostream>
#include<fstream>
using namespace std;
char a[4][20]; int h; int final,finals;
struct sd
{
	int p[10];
	int size[10];
}s[4];
void swap(int& a,int& b)
 {
     int t;
     t=a;
     a=b;
     b=t;
 }
void sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {j=i;
        while(j>0 && a[j]<a[j-1])
        {
            swap(a[j],a[j-1]);
            j=j-1;
        }

    }
}
int findmin(int m[],int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(m[i]<m[j])
          {
             j=i;
          }
    }
    return j;
}
int mind(int t)
{
     int des=999; int d;
   for(int i=0;i<4;i++)
   {
   	if(s[i].p[t]==0) 
   	finals=i;
   	if(s[i].p[t]!=0) 
   	if(s[i].p[t]<des)
   	{
   		des=s[i].p[t]; 
   		d=i;
   	}
   }
   return d;
}
int min(int t)
{
   int des=999;
   for(int i=0;i<4;i++)
   {
   	if(s[i].p[t]==0) 
   	final=i;
   	if(s[i].p[t]!=0) 
   	if(s[i].p[t]<des)
   	{
   		des=s[i].p[t]; 
   	}
   }
   cout<<"\nvvvvvvvvvvv"<<des<<" "<<final<<"spppppp\n";
   return des;
}
void polyphase(fstream f[],int t)
{
	int pos;
	h=min(t); 
	cout<<final<<"   \n";
	for(int i=0;i<h;i++)
	{
		int m[4]={0,0,0,0},c[4]={0,0,0,0};
		for(int j=0;j<4;j++)
		{
			if(j!=final)
			f[j]>>m[j];
			cout<<m[j]<<"\n";
		}
		m[final]=999;
		while(1)
		{
			pos=findmin(m,4);
			cout<<"\nposition="<<a[final]<<"\n";
			if(m[pos]>=999) break;
			cout<<"\n element="<<m[pos]<<"\n";
			f[final]<<m[pos]<<endl;
		//	f[pos]>>m[pos];
			c[pos]++;
			if(c[pos]==s[pos].size[t])
			{
				m[pos]=m[pos]+999;
			}
			else
			{
				f[pos]>>m[pos];
			}
		}
    }
	for(int k=0;k<4;k++)
	{
		if(k!=final)
		{
			s[k].p[t+1]=s[k].p[t]-h;
			if(s[k].p[t+1]==0)
			 s[k].size[t+1]=0;
			else
			s[k].size[t+1]=s[k].size[t];
		}
		s[final].size[t+1]+=s[k].size[t];
	}
	s[final].p[t+1]=h;
	
	
	for(int k=0;k<4;k++)
	{
		{
			cout<<s[k].p[t+1]<<"  ";
			cout<<s[k].size[t+1]<<endl;
		}
	}	
		h=mind(t+1); 
	cout<<"\n 2nd ...."<<finals<<"   \n";
	if(s[final].size[t+1]!=68)
	{
	    {
			f[final].close();
			f[finals].close();
	    }
	    f[final].open(a[final],ios::in);
	    f[finals].open(a[finals],ios::out);
		polyphase(f,t+1);
	}
	else
	return;
	
}
int main()
{
	fstream f[4];
	for(int i=0;i<4;i++)
	{
		cout<<"enter the file names:";
		cin>>a[i];
		f[i].open(a[i],ios::out);
	}
	fstream F;
	F.open("data3.txt",ios::in);
	int ch,b[4],j,k;
//	for(int i=0;i<68;i++)
//	{
		cout<<"\n1st.......\n";
	    for( k=0;k<7;k++)
	    {
		for( j=0;j<4;j++)
		{
			F>>ch;
			if(ch==-1) break;
			else b[j]=ch;
		}
		sort(b,j);
		for( j=0;j<4;j++)
		{
			f[0]<<b[j]<<endl;
		}
	    }
	    s[0].p[0]=k; 
	    s[0].size[0]=j;
	    cout<<"\n2nd .....\n";
	    for( k=0;k<6;k++)
	    {
		for(j=0;j<4;j++)
		{
			F>>ch;
			if(ch==-1) break;
			else b[j]=ch;
		}
		sort(b,j);
		for( j=0;j<4;j++)
		{
			f[1]<<b[j]<<endl;
		}
	    }
	    s[1].p[0]=k; 
	    s[1].size[0]=j;
	    cout<<"\n3rd....\n";
	    for(k=0;k<4;k++)
	    {
		for(j=0;j<4;j++)
		{
			F>>ch;
			if(ch==-1) break;
			else b[j]=ch;
		}
		sort(b,j);
		for(j=0;j<4;j++)
		{
			f[2]<<b[j]<<endl;
		}
	    }
	    s[2].p[0]=k; 
	    s[2].size[0]=j;
	    s[3].p[0]=0; 
	    s[3].size[0]=0;
	    for(int i=0;i<4;i++)
	    {
	    	s[i].p[0];
	    }
	    for(int i=0;i<4;i++)
	    {
			f[i].close();
	    }
	    for(int i=0;i<3;i++)
	    {
	    	f[i].open(a[i],ios::in);
	    }
	    f[3].open(a[3],ios::out);
	    polyphase(f,0);
//	}
}
