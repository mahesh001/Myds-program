int main()
{
	int i,g=0;
	char data[100];
	int j;
	ifstream fin1("f11.txt");
     while(!fin1.eof())
    {
    	fin1.getline(data[g],30);
    	g++;
    }
    ifstream a1( "em1.txt");
    ifstream a2("em2.txt");
    char t1,t2;
    while(!a1.eof())
    {
    	for(i=0;i<4;i++)
    	a1.getline(fin1[i],4);
    }
