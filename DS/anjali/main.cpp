#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int count=0;
class player
{
char fnm[15],snm[15];
int runs,sixes,fours;
float strike_rate;
public:
player()
{
strcpy(fnm,"abcd");
strcpy(snm,"pqrs");
runs=sixes=fours=0;
strike_rate=0;
}
~player()
{
cout<<"destructing...";
}
void enter()
{
cout<<"\nEnter the first name of the player : ";
gets(fnm);
cout<<"\nEnter the surname of the player : ";
gets(snm);
cout<<"\nEnter the no. of runs made : ";
cin>>runs;
cout<<"\nEnter the no. of sixes hit : ";
cin>>sixes;
cout<<"\nEnter the no. of fours hit : ";
cin>>fours;
cout<<"\nEnter the strike rate : ";
cin>>strike_rate;
}
void display()
{
cout<<"\nFirst name : ";
puts(fnm);
cout<<"\nSurname : ";
puts(snm);
cout<<"\nRuns : ";
cout<<runs;
cout<<"\nSixes : ";
cout<<sixes;
cout<<"\nFours : ";
cout<<fours;
cout<<"\nStrike rate : ";
cout<<strike_rate;
}
int getruns()
{
return runs;
}
};
int main()
{
player *p[10];
int ch,i;
char cho;
do
{
cout<<"\nMain Menu";
cout<<"\n1. Enter a players details ";
cout<<"\n2. Display details of all players ";
cout<<"\n3. Display the details of the player scoring highest runs ";
cout<<"\nEnter your choice : ";
cin>>ch;
switch(ch)
{
case 1: p[count++]->enter();
break;
case 2: for(i=0;i<count;i++)
p[i]->display();
break;
case 3: int max,pos=0;
max=p[0]->getruns();
for(i=1;i<count;i++)
{
if(p[i]->getruns() > max)
{
max=p[i]->getruns();
pos=i;
}
p[pos]->display();
break;
default : cout<<"\nWrong choice !!!! ";
}
cout<<"\nContinue(y/n) : ";
cin>>cho;
}while(cho!='n' && cho!='N' );
return 0;
}

/*
====OUTPUT====

Main Menu
1. Enter a players details
2. Display details of all players
3. Display the details of the player scoring highest runs
Enter your choice : 1

Enter the first name of the player : annsh

Enter the surname of the player : chawla

Enter the no. of runs made : 149

Enter the no. of sixes hit : 14

Enter the no. of fours hit : 12

Enter the strike rate : 200

Continue(y/n) : y

Main Menu
1. Enter a players details
2. Display details of all players
3. Display the details of the player scoring highest runs
Enter your choice : 1

Enter the first name of the player : chawla

Enter the surname of the player : annsh

Enter the no. of runs made : 150

Enter the no. of sixes hit : 12

Enter the no. of fours hit : 14

Enter the strike rate : 199

Continue(y/n) : y

Main Menu
1. Enter a players details
2. Display details of all players
3. Display the details of the player scoring highest runs
Enter your choice : 2

First name : annsh

Surname : chawla

Runs : 149
Sixes : 14
Fours : 12
Strike rate : 200
First name : chawla

Surname : annsh

Runs : 150
Sixes : 12
Fours : 14
Strike rate : 199
Continue(y/n) : y

Main Menu
1. Enter a players details
2. Display details of all players
3. Display the details of the player scoring highest runs
Enter your choice : 3

First name : chawla

Surname : annsh

Runs : 150
Sixes : 12
Fours : 14
Strike rate : 199
Continue(y/n) :n
*/
