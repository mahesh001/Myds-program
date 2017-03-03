//multi way tree

#include<iostream>
using namespace std;

struct m_way_node{
	int* data;
	m_way_node** child;
};

int* insrt_sort(int a[],int n){
        for(int i=1;i<n;i++){
                int j=i-1,k=a[i];
                for(;j>=0&&a[j]>k;j--){
                                a[j+1]=a[j];
                        }
                a[j+1]=k;
                }
return a;
}

void make_tree(m_way_node* &tree,int m){
	int *a=new int[m];
		tree=new m_way_node;
		tree->data=new int[m];
		tree->child=new m_way_node*[m+1];
		cout<<"enter "<<m<<" data\n";
		for(int i=0;i<m;i++)
			cin>>a[i];
		a=insrt_sort(a,m);
		for(int i=0;i<m;i++){
			tree->data[i]=a[i];
			tree->child[i]=NULL;
		}
		tree->child[m]=NULL;
		for(int i=0;i<m+1;i++){
			char ch;
			cout<<"do you want to enter more data? press y or n\n";
			cin>>ch;
			if(ch=='y'){
				make_tree(tree->child[i],m);
			}
			else
			return;
		}
}
		

void print_tree(m_way_node* tree,int m){
	if(tree!=NULL){
	for(int j=0;j<m+1;j++){
		for(int i=0;i<m;i++)
			cout<<tree->data[i]<<" ";
		print_tree(tree->child[j],m);
	}
	cout<<endl;
	}
}

int main(){
	int m;
	m_way_node* tree=NULL;
	cout<<"enter m\n";
	cin>>m;
	make_tree(tree,m);
	print_tree(tree,m);
return 0;
}
