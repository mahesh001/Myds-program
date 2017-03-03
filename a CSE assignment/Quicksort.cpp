#include<iostream>
using namespace std;
void swap(int* x,int* y){
	int* t;
	*t=*x;
	*x=*y;
	*y=*t;
}
void quicksort(int a[],int f,int l){
	int j=f+1,i=l+1,left=f;
	if(f<l){
	for(j=l;j>=(f+1);j++){
		if(a[j]>=a[left]){
			i--;
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[i-1],&a[f]);
	quicksort(a,f,i-2);
	quicksort(a,i,l);
    }
}
int main(){
	int i,a[10];
	cout<<"Enter array of 10 no\n";
	for(i=0;i<10;i++)
	cin>>a[i];
	quicksort(a,0,9);
	cout<<"Sorted no are: "                                      ;
	for(i=0;i<10;i++)
	cout<<a[i]<<" ";
	return 0;
}
