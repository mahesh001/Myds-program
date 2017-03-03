#include<iostream>
#include<fstream>
class FixedTextBuffer
{
	public :
		FixedTextBuffer(int maxfield,int maxbytes=1000);
		int Addfield(int fieldsize);
		int Read(ifstream& fin);
		int Write(ofstream& fout);
		int Pack(char *field);
		int Unpack(char *field);
		int Init(int numfield,int maxchars=1000);
		int Init(int numfield,int *fieldsize);
	private :
		char *buffer;
		int Maxbytes;
		int Nextbyte;
		int *fieldsize;
		int Maxfield;
		int Numfield;
		int Nextfield;
};
