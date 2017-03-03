#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;
struct student
{
  int key;
  string name;
  int year;
};

struct hf
{
  int record_no;
  student s;
};
istream & operator>> (istream & stream, student s)
{
  stream >> s.key;
  stream >> s.name;
  stream >> s.year;
  return stream;
}
ostream & operator<< (ostream & stream1, student s)
{
  stream1 << s.key;
  stream1 << s.name;
  stream1 << s.year;
  return stream1;
}
int sirec;
vector < student > vstu;//student vstu[];
void search(int i,vector<hf> v)
{
ifstream fin;
fin.open("b.txt");
int r=i%sirec;
if(v[r].s.key==i)
cout<<v[r].s<<endl;
else
{
r=(r+1)%sirec;
while(v[r].s.key!=i)
r=(r+1)%sirec;
cout<<v[r].s<<endl;
}
fin.close();
}
void addstu ()
{
  char c;
  student s;
  do
    {
      cout << "ENtere the details of the student \n";
      cin >> s.key;
      cin >> s.name;
      cin >> s.year;
      vstu.push_back (s);
      cout << "Do you want to continue \n";
      cin >> c;
    }
  while (c == 'y');
}

void addrec (vector < hf > &v, student s)
{
  int siz = vstu.size ();
  int sid = siz;
  int k = s.key;
  int r = k % sirec;
  while (sid > 0)
    {
      if (v[r].s.key == 0)
	{
	  v[r].s = s;
	  break;
	}
      else
	r = (r + 1) % sirec;
      sid--;
    }
}

void printrec (vector < hf > v)
{
  ofstream fout;
  fout.open ("b.txt");
  for (int i = 0; i < sirec; i++)
    {
      fout << v[i].record_no << " ";
      fout << v[i].s.key << "\n";
    }
  fout.close ();
  for (int i = 0; i < sirec; i++)
    cout << v[i].s.key << " ";
}

int main ()
{
char c;
int i;
  cout << "Enter the size of the file \n";
  cin >> sirec;
  vector < hf > vrec (sirec);
  addstu ();
  for (int i = 0; i < sirec; i++)
    {
      vrec[i].record_no = i;
      vrec[i].s.key = 0;
      cout << vstu[i].key << " ";
    }
  for (int i = 0; i < vstu.size (); i++)
    addrec (vrec, vstu[i]);
  cout << "The record has finished printing \n";
  printrec (vrec);
  do
  {
  cout<<"Enter the roll no of the student to get the details \n";
  cin>>i;
  search(i,vrec);
  cout<<"Do you want to continue \n";
  cin>>c;
  }while(c=='y');
  return 0;
}
