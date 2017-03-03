#include<iostream>
using namespace std;

int main()
{
	int i,N,p1=0,p2=0,s1,s2,lead,max=0,w;
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d" "%d",&s1,&s2);
		p1=s1+p1;
		p2=s2+p2;
		
		if(p1>p2)
		{
			lead=p1-p2;
			if(lead>max)
			{
				max=lead;
				w=1;
			}
		}
		else
		{
			lead=p2-p1;
			if(lead>max)
			{
				max=lead;
				w=2;
			}
		}
	}
	printf("%d %d\n",w,max);
	
}
