

#include <iostream>
using namespace std;

class linklist
{
	private :

		struct node
		{
			int data ;
			node * link ;
		} *p ;

	public :

		linklist( ) ;
		void append ( int num ) ;
		void insert(int loc, int num);
		void display( ) ;
		int count( ) ;
		void del ( int num ) ;
        ~linklist( ) ;
} ;

linklist :: linklist( )
{
	p = NULL ;
}

void linklist :: append ( int num )
{
	node *temp, *r ;
	if ( p == NULL )
	{
		p = new node ;
		p -> data = num ;
		p -> link = NULL ;
	}
	else
	{
		temp = p ;
		while ( temp -> link != NULL )
			temp = temp -> link ;
		r = new node ;
		r -> data = num ;
		r -> link = NULL ;
		temp -> link = r ;
	}
}


void linklist :: insert ( int loc, int num )
{
	node *temp, *r ;
	temp = p ;
	
	if(loc==0)
	{
              r=new node;
              r -> data = num ;
            	r -> link = p ;
            	p = r ;
      }
      else 
      {
	for ( int i = 1 ; i < loc-- ; i++ )
	{
		temp = temp -> link ;
		if ( temp == NULL )
		{
			cout << "\nThere are less than " << loc << " elements in list" << endl ;
			return ;
		}
	}
	r = new node ;
	r -> data = num ;
	r -> link = temp -> link ;
	temp -> link = r ;
    }
}

void linklist :: display( )
{
	node *temp = p ;

	cout << endl ;
	while ( temp != NULL )
	{
		cout << temp -> data << "  " ;
		temp = temp -> link ;
	}
}

int linklist :: count( )
{
	node *temp = p ;
	int c = 0 ;

	while ( temp != NULL )
	{
		temp = temp -> link ;
		c++ ;
	}

	return c ;
}


void linklist :: del ( int num )
{
	node *old, *temp ;

	temp = p ;

	while ( temp != NULL )
	{
		for(int i=0;i<)
		if ( temp -> data == num )
		{
			if ( temp == p )
				p = temp -> link ;
			else
				old -> link = temp -> link ;
			delete temp ;
			return ;
		}
		else
		{
			old = temp ;
			temp = temp -> link ;
		}
	}

	cout << "\n\nElement " << num << " not found" ;
}

linklist :: ~linklist( )
{
	node *q ;

    while ( p != NULL )
    {
        q = p -> link ;
        delete p ;
    	p = q  ;
    }
}

int main( )
{
    linklist l ;
    int n,p,o;
    
    do
    {
        cout<<"\n\n\n1.Append\n2.Insert\n3.Delete\n4.Display\n0.Exit";
        cout<<"\n\nEnter Command: ";
        cin>>o;
        
        switch(o)
        {
                 case 1: cout<<"\n\nEnter a number: ";
                         cin>>n;
                         l.append(n);
                         l.display();
                         break;
                 case 2: cout<<"\n\nEnter number: ";
                         cin>>n;
                         cout<<"Enter position: ";
                         cin>>p;
                         l.insert(p,n);
                         l.display();
                         break;
                 case 3: cout<<"\n\nEnter number to delete: ";
                         cin>>n;
                         l.del(n);
                         l.display();
                         break;
                 case 4: l.display();
                         break;
                 case 0: break;
                 default: cout<<"\n\nIncorrect Command!";
        };
    }while(o!=0);
    return 0;
}
