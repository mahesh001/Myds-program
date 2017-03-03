w#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class FixLengthBuffer
{
	public :
	int Init(int numfield,int fieldsize);
	int Addfield(int fieldsize);
	int Read(ifstream& fin);
	int Write(ofstream& fout);
	int Pack(char *field);
	int Unpack(char *field);
	private :
	char *Buffer;
	int Numfield;
	int Maxfield;
	int Maxbytes;
	int Buffersize;
	int Nextfield;
	int *Fieldsize;
	int NextCharacter;
};

int FixLengthBuffer::Init(int numfield,int fieldsize)
{
	Buffer=new char[fieldsize];
	Fieldsize=new int[numfield];
	Maxfield=numfield;
	Maxbytes=fieldsize;
	Buffersize=0;
	Nextfield=0;
	Numfield=0;
	NextCharacter=0;
	return 1;
}

int FixLengthBuffer::Addfield(int fieldsize)
{
	if(Numfield==Maxfield)
	return 0;
	if(Buffersize+fieldsize>=Maxbytes)
	return 0;
	Fieldsize[Numfield]=fieldsize;
	Numfield++;
	Buffersize+=fieldsize;
	return 1;
}

int FixLengthBuffer::Read(ifstream& fin)
{
	fin.read(Buffer,Buffersize);
	return 1;
}

int FixLengthBuffer::Write(ofstream& fout)
{
	fout.write(Buffer,Buffersize);
	return 1;
}

int FixLengthBuffer::Pack(char *field)
{
	if(Nextfield==Numfield)
	return 0;
	strcpy(Buffer,field);
	int len=strlen(field);
	int start=NextCharacter;
	int packsize=Fieldsize[Nextfield];
	NextCharacter+=packsize;
	for(int i=start+len;i<NextCharacter;i++)
	Buffer[i]=' ';
	Buffer[NextCharacter]=0;
	Nextfield++;
	if(Nextfield==Numfield)
	{
		Nextfield=NextCharacter=0;
	}
	return 1;
}

int FixLengthBuffer::Unpack(char *str)
{
	int start=NextCharacter;
	int packsize=Fieldsize[Nextfield];
	strncpy(str,&Buffer[start],packsize);
	str[packsize]=0;
	NextCharacter+=packsize;
	Nextfield++;
	return 1;
}

class student
{
	public :
		char Frist[11];
		char Last[11];
		char Rollno[6];
		char Branch[6];
};

int main()
{
   ofstream fout;
   fout.open("student.txt");
   FixLengthBuffer Buff;
   student S[3];
   
   Buff.Init(4,30);
   Buff.Addfield(10);
   Buff.Addfield(10);
   Buff.Addfield(5);
   Buff.Addfield(5);
   for(int i=0;i<3;i++)
   {
   	  cout<<"Enter the Details of "<<i+1<<" student\n";
   	  cout<<"Enter Frist\n";
   	  cin>>S[i].Frist;
   	  if(Buff.Pack(S[i].Frist))
	  cout<<"Frist added\n";;
   	  cout<<"Enter Last\n";
   	  cin>>S[i].Last;
   	  if(Buff.Pack(S[i].Last))
	  cout<<"Last added\n";;
   	  cout<<"Enter Rollno\n";
   	  cin>>S[i].Rollno;
   	  if(Buff.Pack(S[i].Rollno))
	  cout<<"Roll added\n";
   	  cout<<"Enter Branch\n";
   	  cin>>S[i].Branch;
   	  if(Buff.Pack(S[i].Branch))
	  cout<<"Branch added\n";;
   	  Buff.Write(fout);
   	  char fld[20];
   	  for(int j=0;j<4;j++)
   	  Buff.Unpack(fld);
   }
}


