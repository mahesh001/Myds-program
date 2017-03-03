#include<iostream>
using namespace std;
main()
{
      int a[10][10]={{0,3,0,0,0,1,1},{3,0,10,0,0,0,4},{0,10,0,2,0,0,1},{0,0,2,0,3,0,7},{0,0,0,3,0,8,5},{1,0,0,0,8,0,2},{1,4,1,7,5,2,0}},flag[10]={0},i,j,n,p[10][10]={0},e,min,x,y,k;
      cout<<"\nENTER THE SIZE OF THE LIST = ";
      cin>>n;
      cout<<"\nENTER THE ADJANCY MATRIX WITH WEIGHTS = \n ";
         //for(i=0;i<n;i++)
        //       for(j=0;j<n;j++)
       //          cin>>a[i][j];
      flag[0]=1;
      for(e=0;e<n-1;e++)
      {
                  min=0;
                  for(i=0;i<n;i++)
                          if(flag[i]==1)
                          {        
                               for(j=0;j<n;j++)
                               {
                                  if( (min > a[i][j] || min == 0) && a[i][j]!=0 && flag[j]!=1) 
                                  {
                                    min=a[i][j];
                                    x=i;y=j;
                                  }
                               }
                          }
                  if(min==0)
                  {
                                cout<<"\nTHE GRAPH IS UN-CONNECTED...";    
                                break;
                  }
                  else
                  {
                                flag[x]=flag[y]=1;
                                cout<<"\n"<<char(x+65)<<" -> "<<char(y+65)<<"\n";
                  }
        }
    cout<<"\nTHE GIVEN PRIM'S PATH IS :\n";
    for(i=0;i<n;i++)
     {
          for(j=0;j<n;j++)
                 cout<<p[i][j]<<"  ";
            cout<<"\n";
      }
      return 0;
}
