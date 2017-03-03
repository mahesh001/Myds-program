#include<iostream>
using namespace std;

int main()
{
	int i,j,t,no;
	scanf("%d",&t);
	
	int five,floor,temp;
	
	for(i=0;i<t;i++)
	{
		scanf("%d",&no);
		
		floor=(no/5)*5;
		temp=floor;
		
		five=0;
		while(temp>0 && temp/5!=0)
		{
			five=five+(temp/5);
			temp=temp/5;
		}
		printf("%d\n",five);
	}
}
