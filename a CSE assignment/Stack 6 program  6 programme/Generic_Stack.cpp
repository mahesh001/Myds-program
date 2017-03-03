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
		int size;
		int top;
		int tag[10];
		data stu[10];
		stack()
		{
			top=0;	
		}
		int isFull(){
			if(top==9)
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
	        strcpy(stu[top++].name,name);
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
		void show()
		{   
	        if(isEmpty())
			{
	        cout<<"Stack underflow\n";
	        }
	        else
			{
			 if(tag[top]==1)
			 cout<<stu[--top].age;
			 if(tag[top]==2)
			 cout<<stu[--top].age;
			 if(tag[top]==3)
			 cout<<stu[--top].cgpa;
		   }
		}
		
	
};
int main()
{
	stack s;
	int n,i,tag;
	int l=0;
	cout<<"how many records\n";
	cin>>n;
	cout<<"Enter tag then Enter item i.e(for name tag=1,for age tag=2,for cgpa tag=3\n";
	for(i=0;i<n;i++)
	{
		cin>>tag;
		if(tag==1)
		{
		s.tag[s.top]=tag;
		cin>>s.stu[i].name;
		s.push(s.stu[i].name);
	    }
		else if(tag==2)
		{
		s.tag[s.top]=tag;
		cin>>s.stu[i].age;
		s.push(s.stu[i].age);
	    }
		else if(tag==3)
		{
		s.tag[s.top]=tag;
		cin>>s.stu[i].cgpa;
		s.push(s.stu[i].cgpa);
	    }
	}
	cout<<"Your Records is \n";
	for(i=0;i<n;i++)
	s.show();
}
