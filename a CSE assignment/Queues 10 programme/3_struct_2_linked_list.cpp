#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct gnode;
struct snode
{
	char *name;
	gnode* cptr;
	snode* next;
};
struct cnode
{
	char* course;
	gnode* sptr;
	cnode* next;
};
union u1
{
	gnode* down;
	cnode* back;
};
union u2
{
	gnode* right;
	snode* back;
};
struct gnode
{
	int tagc,tags;
	u1 c1;
	u2 s2;
};

void add(cnode* c,snode* s)
{
	gnode* T;
	T=new (gnode);
	if(s->cptr==NULL&&c->sptr==NULL)
	{
		c->sptr=T;
		T->tagc=2;
		T->c1.back=c;
		s->cptr=T;
		T->tags=2;
		T->s2.back=s;
	}
	else if(s->cptr==NULL)
	{
		s->cptr=T;
		T->s2.back=s;
		T->tags=2;
		gnode* temp=c->sptr;
		while(temp->tagc==1)
			temp=temp->c1.down;
		temp->c1.down=T;
		temp->tagc=1;
		T->tagc=2;
		T->c1.back=c;
	}
	else if(c->sptr==NULL)
	{
		c->sptr=T;
		T->tagc=2;
		T->c1.back=c;
		gnode* temp=s->cptr;
		while(temp->tags==1)
			temp=temp->s2.right;
		temp->s2.right=T;
		temp->tags=1;
		T->tags=2;
		T->s2.back=s;
	}
	else
	{
		gnode* temp=c->sptr;
		while(temp->tagc==1)
			temp=temp->c1.down;
		temp->c1.down=T;
		temp->tagc=1;
		T->tagc=2;
		T->c1.back=c;
		temp=s->cptr;
		while(temp->tags==1)
			temp=temp->s2.right;
		temp->s2.right=T;
		temp->tags=1;
		T->tags=2;
		T->s2.back=s;
	}
}
void show(snode* s)
{
	cout<<"Courses taken by roll no "<<s->name<<" are : ";
	gnode* temp=s->cptr,*temp2;
	while(temp->tags!=2)
	{
		temp2=temp;
		while(temp2->tagc!=2)
			temp2=temp2->c1.down;
		cout<<temp2->c1.back->course<<"\t";
		temp=temp->s2.right;
	}
	temp2=temp;
	while(temp2->tagc!=2)
		temp2=temp2->c1.down;
	cout<<temp2->c1.back->course<<"\t"<<endl;
}
void show(cnode* c)
{
	cout<<"Roll numbers who took the course "<<c->course<<" are : ";
	gnode*temp=c->sptr,*temp2;
	while(temp->tagc!=2)
	{
		temp2=temp;
		while(temp2->tags!=2)
			temp2=temp2->s2.right;
		cout<<temp2->s2.back->name<<"\t";
		temp=temp->c1.down;
	}
	temp2=temp;
	while(temp2->tags!=2)
		temp2=temp2->s2.right;
	cout<<temp2->s2.back->name<<"\t"<<endl;
}
int main()
{
	int k,i,j,no;
	char name[10],course[10];
	cnode* C;
	snode* S;
	S=new snode;
	C=new cnode;
	S->next=NULL;
	C->next=NULL;
	cout<<"Enter the no of students\n";
	cin>>no;
	cout<<"Enter the Name of students\n";
	cin>>name;
	strcpy(S->name,name);
	for(i=1;i<no;i++)
	{
		cin>>name;
		snode *T;
		T=new snode;
		strcpy(T->name,name);
		T->next=NULL;
		while(S->next=NULL)
		  S=S->next;
		S->next=T;
	}
	cout<<"Enter the no of courses\n";
	cin>>no;
	cout<<"Enter the Name of courses\n";
	cin>>name;
	strcpy(C->course,name);
	for(i=1;i<no;i++)
	{
		cin>>name;
		cnode *T;
		T=new cnode;
		strcpy(T->course,name);
		T->next=NULL;
		while(C->next=NULL)
		  C=C->next;
		C->next=T;
	}
	cout<<"Enter\n\n1 if you want to enter courses opted by each student\n\n";
	cout<<"2 if you want to enter roll numbers of students who opted each course\n";
	
	cin>>k;
	char f;
	snode* temps;
	cnode* tempc;
	switch(k)
	{
		case 1:cin.ignore();
				temps=S;
				while(temps!=NULL)
				{
					cout<<"Enter the courses opted by roll no "<<temps->name<<endl;
					char b[15];
					cout<<"Press / when you are finished\n";
					tempc=C;
					while(1)
					{
						cin.getline(b,15);
						if(strcmp(b,"/")==0)
							break;
						while(tempc!=NULL)
						{
							if(strcmp(tempc->course,b)==0)
								break;
							tempc=tempc->next;
						}
						add(tempc,temps);
					}
					temps=temps->next;
				}
				break;
		case 2:tempc=C;
				while(tempc!=NULL)
				{
					cout<<"Enter the roll numbers of students who opted for course "<<tempc->course<<endl;
					char d[10];
					cout<<"Enter / when you are finished\n";
					while(1)
					{
						cin>>d;
						if(!strcmp(d,"/"))
							break;
						temps=S;
						while(temps!=NULL)
						{
							if(!strcmp(temps->name,d))
								break;
							temps=temps->next;
						}
						add(tempc,temps);
					}
					tempc=tempc->next;
				}
		default:cout<<"Invalid choice\n";
				break;
	}
	do
	{
		cout<<"Now enter\n\n1 if you would like to know the courses taken by a student\n\n";
		cout<<"2 if you would like to know the students who took a course\n\n3 to exit\n";
		cin>>k;
	    char g[10];
		char h[15];
		switch(k)
		{
			case 1:cout<<"Enter the roll no of the student : ";
					cin>>g;
					temps=S;
					while(temps!=NULL)
					{
						if(!strcmp(temps->name,g))
							break;
						temps=temps->next;
					}
					show(temps);
					break;
			case 2:cout<<"Enter the course name : ";
					cin.ignore();
					cin.getline(h,15);
					cout<<"The entered course is"<<h<<" right\n";
					tempc=C;
					while(tempc!=NULL)
					{
						if(strcmp(tempc->course,h)==0)
							break;
						tempc=tempc->next;
					}
					show(tempc);
					break;
			default:cout<<"Invalid choice\n";
					break;
		}
	}while(k==1||k==2);
	cout<<endl;
	return 0;
}
