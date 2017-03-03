#include<iostream>
using namespace std;

int main()
{
	int temp;
	
	scanf("%d",&temp);
	
	while(temp!=42)
	{
		printf("%d\n",temp);
		scanf("%d",&temp);
	}
	return 0;
}
