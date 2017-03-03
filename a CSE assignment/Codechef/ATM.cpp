#include<iostream>
using namespace std;

int main()
{
	int t;
	float b,ans;
	scanf("%d %f",&t,&b);
	
	if(t%5==0 && b>=(t+0.50))
	{
		ans=b-t-0.50;
		printf("%0.2f",ans);
	}
	else
	printf("%0.2f",b);
}
