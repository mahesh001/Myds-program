#include <iostream>
using namespace std;

const int INFINITY = 999;

class graph
{
    class vertex
    {
      public:
      
        int vnum;
        int topnum;
        int weight;
        int dist;
        
        bool known;

        vertex *next;
        vertex *path;
      
        vertex( int v = 0 )
              : vnum( v ), topnum( 0 ), weight( 0 ), dist( INFINITY ), known( false ), next( NULL ), path( NULL )
        { }
    };
    
    vertex *v[ 20 ];
    
    const int num_vertices;
    
    void dijkstra( vertex *u );
    vertex* unknownvertex( );
    void shortestpath( vertex *u );
    
  public:
  
    graph( int n ): num_vertices( n )
    {
      for ( int i = 0; i < num_vertices; i++ )
        v[ i ] = new vertex( i + 1 );
    }
    
    void creategraph( );
    void dijkstra( int i );
    void shortestpath( int i );
    void display( );
    
   // friend class queue<vertex *>;
};


void graph::creategraph( )
{
  int m, n, p;
  
  vertex *x;

  for ( int i = 0; i < num_vertices; i++ )
    v[ i ]->vnum = i + 1;
  
  for ( int i = 0; i < num_vertices; i++ )
  {
    cout << "\n\n  Enter the number of vertices adjacent to vertex " << i + 1 << ": ";
    cin >> n;
    
    for ( int j = 0; j < n; j++ )
    {
      cout << "\n\n    Enter the vertex number: ";
      cin >> m;
      cout << "\n\n    Enter the weight of the edge: ";
      cin >> p;
      
      x = v[ i ];

      while ( x->next != NULL )
        x = x->next;

      x->next = new vertex( m );
      x->next->weight = p;
    }
  }
}


graph::vertex*
graph::unknownvertex( )
{
  vertex *p = NULL;
   for ( int i = 0; i < num_vertices; i++ )
  {
    if ( !v[ i ]->known )
    {
      if ( !p )
        p = v[ i ];
      
      else if ( p->dist > v[ i ]->dist )
        p = v[ i ];
    }
  }
    
  return p;
}


void graph::dijkstra( int i )
{
  dijkstra( v[ i ] );
}


void graph::dijkstra( vertex *u )
{
  vertex *w, *x, *y;
  
  u->dist = 0;
  
  for ( ; ; )
  {
    w = unknownvertex( );
    
    if ( !w )
      break;
    
    w->known = true;
    
    for ( x = w->next; x != NULL; x = x->next )
    {
      y = v[ x->vnum - 1 ];
      
      if ( !y->known )
        if ( w->dist + x->weight < y->dist )
        {
          y->dist = w->dist + x->weight;
          y->path = w;
        }
    }
  }
}


void graph::display( )
{
  for ( int i = 0; i < num_vertices; i++ )
    cout << "    Vertex " << v[ i ]->vnum << ": " << v[ i ]->dist << "\n";
}


void graph::shortestpath( int i )
{
  shortestpath( v[ i - 1 ] );
}


void graph::shortestpath( vertex *u )
{
  if ( u->path )
  {
    shortestpath( u->path );
    cout << " to ";
  }
  
  cout << u->vnum;
}


int main( )
{
  int m, n;
  
  cout << "\n  Enter the number of vertices: ";
  cin >> n;

  graph g( n );
  
  g.creategraph( );
  
  cout << "\n\n  Enter the vertex from which shortest distance is to be calculated: ";
  cin >> m;
  
  g.dijkstra( m - 1 );
  
  cout << "\n\n";
  
  g.display( );
  
  cout << "\n\nEnter the vertex whose shortest path from the given vertex is to be determined: ";
  cin >> m;
  
  //g.shortestpath( );

  cin.get( );
  cin.get( );
  
  return 0;
}
