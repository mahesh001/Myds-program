#include<iostream>
#include<cstring>
using namespace std;
union data
{
	char name[15];
	int age;
	float cgpa;
};
struct stack
{
		int tag;
		int size;int top;
		data stu[10],p;
		stack()
		{
			top=0;	
		}
		int isFull(){
			if(top==10)
			return 1;
			else
			return 0;
		}
		int isEmpty(){
			if(top==0)
			return 1;
			else
			return 0;
		}
		void push(char name[]){
			if(isFull()){
			   cout<<"Stack overflow\n";
		    }
	        strcpy (stu[top++].name,name);
		}

		void push(int age)
		{    if(isFull()){
			   cout<<"Stack overflow\n";
		    }
			stu[top++].age=age;
		}
		void push(float cgpa){
			if(isFull()){
			   cout<<"Stack overflow\n";
		    }
			stu[top++].cgpa=cgpa;
		}
		char* pop(){
			if(isEmpty())
			cout<<"Stack underflow\n";
			else
			return stu[--top].name;
		}
		void show(int tag,int l)
		{
			if(tag==1)
			cout<<stu[--top].name<<endl;
			if(tag==2)
			cout<<stu[--top].age<<endl;
			if(tag==3)
			cout<<stu[--top].cgpa<<endl;
			
		}
		
	
};
int main()
{
	stack s;
	int n,i,tag[10];
	int l=0;
	cout<<"how many records\n";
	cin>>n;
	cout<<"Enter tag then Enter item i.e(for name tag=1,for age tag=2,for cgpa tag=3\n";
	for(i=0;i<n;i++)
	{
		cin>>s.tag;
		if(s.tag==1){
		tag[l++]=s.tag;
		cin>>s.stu[i].name;
		s.push(s.stu[i].name);
	    }
		else if(s.tag==2){
		tag[l++]=s.tag;
		cin>>s.stu[i].age;
		s.push(s.stu[i].age);
	    }
		else if(s.tag==3){
		tag[l++]=s.tag;
		cin>>s.stu[i].cgpa;
		s.push(s.stu[i].cgpa);
	    }
	}
	s.show(tag,l);
}
