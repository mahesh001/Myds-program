#include<iostream>
using namespace std;
void Merge(int a[],int l,int m,int h);
void MergeSort(int a[],int l,int h){
	if(l<h){
		int m=(l+h)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,h);
		Merge(a,l,m,h);
	}
}
void Merge(int a[],int l,int m,int h){
	int b[h-l+1],i=l,j=m+1,k=0;
	while(i<=m&&j<=h){
		if(a[i]<=a[j]){
			b[k]=a[i];
			k++;
			i++;
		}
		else{
			b[k]=a[j];
			k++;
			j++;
		}
	}
	if(i>m){
		while(j<=h){
			b[k]=a[j];
			k++;
			j++;
		}
	}
	else{
		while(i<=m){
			b[k]=a[i];
			k++;
			i++;
		}
	}
	for(int c=0;c<(h-l+1);c++){
		a[l]=b[c];
		l++;
	}
}
int main(){
	int a[10],i;
	cout<<"Enter the 5 Intergers\n";
	for(i=0;i<5;i++){
		cin>>a[i];
	}
	MergeSort(a,0,4);
	cout<<"The Sorted no are\n";
	for(i=0;i<5;i++){
		cout<<a[i]<<endl;
		
	}
	return 0;
}
