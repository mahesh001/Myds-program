#include<iostream>
using namespace std;

int sum_max(int **a,int ic,int tl,int index)
{
	if(ic==(tl-1))
	return a[ic][index];
	else
	{
		int c,d;
		c=sum_max(a,ic+1,tl,index);
		d=sum_max(a,ic+1,tl,index+1);
		if(c>d)
		return a[ic][index]+c;
		else
		return a[ic][index]+d;
	}
}

int main()
{
	int i,j,k,N,tl,ans;
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&tl);
		int **a=new int*[tl];
		for(j=0;j<tl;j++)
		{
			a[j]=new int[j+1];
			
			for(k=0;k<=j;k++)
			scanf("%d",&a[j][k]);
		}
		
		ans=sum_max(a,0,tl,0);
		printf("%d\n",ans);
	}
}
