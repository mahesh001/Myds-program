#include<iostream>
using namespace std;
 
struct edge
    {
        int vs, vd, wt, visited;
    } s[ 20 ];
int g[ 20 ][ 20 ];
void kruskal( int n );
 
main()
{
    int n, i, j;
    cout<<"ENTER THE NO. OF VERTICES";
   cin>>n;
    cout<<"ENTER THE WEIGHTED ADJACENCY MATRIX\n";
 
    for ( i = 1;i <= n;i++ )
        for ( j = 1;j <= n;j++ )
            cin>>g[ i ][ j ];
 
    cout<<"THE ADJACENCY MATRIX IS\n";
 
    for ( i = 1;i <= n;i++ )
        {  cout<<endl;
            for ( j = 1;j <= n;j++ )
            
               cout<<"\t"<<g[ i ][ j ];
              
        }
 
    kruskal( n );
}
 
void kruskal( int n )
{
    int p, par[ 20 ], k = 0, i, j, q;
 
    struct edge t;
 
    for ( p = 1;p <= n;p++ )
        par[ p ] = p;
 
    for ( i = 1;i <= n;i++ )
        for ( j = 1;j <= n;j++ )
            {
                if ( g[ i ][ j ] > 0 )
                    {
                        k++;
                        s[ k ].vs = i;
                        s[ k ].vd = j;
                        s[ k ].wt = g[ i ][ j ];
                        s[ k ].visited = 0;
                    }
            }
 
    for ( i = 1;i <= k;i++ )
        for ( j = i + 1;j <= k;j++ )
            {
                if ( s[ i ].wt > s[ j ].wt )
                    {
                        t = s[ i ];
                        s[ i ] = s[ j ];
                        s[ j ] = t;
                    }
            }
 
    for ( i = 1;i <= k;i++ )
        {
            if ( par[ s[ i ].vs ] != par[ s[ i ].vd ] )
                {
                    s[ i ].visited = 1;
                    q = par[ s[ i ].vs ];
                    par[ s[ i ].vs ] = par[ s[ i ].vd ];
 
                    for ( j = 1;j <= k;j++ )
                        {
                            if ( par[ j ] == q )
                                par[ j ] = par[ s[ i ].vd ];
                        }
                }
        }
 
    for ( i = 1;i <= k;i++ )
        if ( s[ i ].visited == 1 )
            {
                cout<<" \nV"<<s[ i ].vs<<"->V"<<s[ i ].vd<<" ="<<s[ i ].wt;
            }
}
