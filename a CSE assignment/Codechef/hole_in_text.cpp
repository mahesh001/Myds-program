#include<iostream>
using namespace std;

int main()
{
	int i,t,c;
	int no[26]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
	scanf("%d",&t);
	
	char ch;
	scanf("%c",&ch);
	
	for(i=0;i<t;i++)
	{
		c=0;
		scanf("%c",&ch);
		while(ch!='\n')
		{
			c=c+no[ch-'A'];
			scanf("%c",&ch);
		}
		printf("%d\n",c);
	}
}
