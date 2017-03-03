// Program that sorts an array using merge sort

#include <iostream>
using namespace std;

const int MAX = 10 ;

class array
{

	private :

		int *arr ;
		int size ;
		int count ;

	public :

		array( ) ;
		array ( int sz ) ;
		void add ( int num ) ;
		void display( ) ;
		static void sort ( int *a, int sz ) ;
		void merge ( array &a, array &b ) ;
		~array( ) ;
} ;

// initializes data member
array :: array( )
{
	count = size = 0 ;
	arr = NULL ;
}

// initialises data member
array :: array( int sz )
{
	count = 0 ;
	size = sz ;
	arr = new int[sz] ;
}

// adds a new element to the array
void array :: add ( int num )
{
	if ( count < size )
	{
		arr[count] = num ;
		count++ ;
	}
	else
		cout << "\nArray is full" << endl ;
}

// displays elements in an array
void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "\t" ;
	cout << endl ;
}

// merges two arrays
void array :: merge ( array &a, array &b )
{
	sort ( a.arr, a.size ) ;
	sort ( b.arr, b.size ) ;

	size = a.count + b.count ;
	arr = new int[size] ;

	int i, j, k ;
	for ( i = j = k = 0 ; j < a.count || k < b.count ; )
	{
		if ( a.arr[j] <= b.arr[k] )
			arr[i++] = a.arr[j++] ;
		else
			arr[i++] = b.arr[k++] ;
		count++ ;

		if ( j == a.count || k == b.count )
			break ;
	}

	for ( ; j < a.count ; )
	{
		arr[i++] = a.arr[j++] ;
		count++ ;
	}

	for ( ; k < b.count ; )
	{
		arr[i++] = b.arr[k++] ;
		count++ ;
	}
}

// sorts an array
void array :: sort ( int *a, int sz )
{
	int temp ;
	for ( int i = 0 ; i <= sz - 2 ; i++ )
	{
		for ( int j = i + 1 ; j <= sz - 1 ; j++ )
		{
			if ( a[i] > a[j] )
			{
				temp = a[i] ;
				a[i] = a[j] ;
				a[j] = temp ;
			}
		}
	}
}

// deallocates memory
array :: ~array( )
{
	delete arr ;
}

int main( )
{
	array a ( MAX ) ;
	cout << "\nMerge sort.\n" ;
int choice;
    cout<<"Enter number of elements - array 1 : ";
    cin>>choice;
    cout<<"Enter "<<choice<<" numbers:\n";
    for(int i=0;i<choice;i++)
    {
            int num;
            cin>>num;
            a.add(num);
    }


	cout << "\nFirst array: " << endl ;
	a.display( ) ;

	array b ( MAX ) ;

    cout<<"Enter number of elements - array 2 : ";
    cin>>choice;
    cout<<"Enter "<<choice<<" numbers:\n";
    for(int i=0;i<choice;i++)
    {
            int num;
            cin>>num;
            b.add(num);
    }

	cout << "\nSecond array: " << endl ;
	b.display( ) ;

	array c;
	c.merge ( a, b ) ;

	cout << "\nArray after sorting: " <<endl;
	c.display( ) ;
	return 0;
}
