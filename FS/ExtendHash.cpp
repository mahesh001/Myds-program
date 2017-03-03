#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int c2i(const char *c)
{
	 int n=0;
	 for(int i=0;c[i];i++)
		  n=n*10+c[i]-'0';
	 return n;
}
char * i2c(int x)
{
	 char *c=new char[10],*d=new char[10];
	 int i;
	 for(i=0;i<10;i++)
	 {
		  c[i]='\0';
		  d[i]='\0';
	 }
	 i=0;
	 while(x>0)
	 {
		  d[i++]=char(x%10+int('0'));
		  x/=10;
	 }
	 for(x=0;x<i;x++)
		  c[x]=d[i-x-1];
	 return c;
}
int pow(int n,int i)
{
	 int s=1;
	 while(i-->0)
		  s*=n;
	 return s;
}
template<class Etype>
void Swap(Etype &x,Etype &y)
{
	 Etype t;
	 t=x;
	 x=y;
	 y=t;
}
class Buffer
{
	 protected:
		  char *Buff;
		  char D;
		  int Size;
		  int Pos;
		  int Max;
	 public:
		  Buffer(int M=500,char Delim='|')
		  {
				D=Delim;
				Max=M;
				Buff=new char[Max];
		  }
		  void Clear();
	int Read(fstream &);
	int Write(fstream &);
	int UnPack(char *);
	int Pack(char *);
		  void Print();
};
void Buffer::Clear()
{
	 for(int i=0;i<Max;i++)
		  Buff[i]='\0';
	 Pos=0;
	 Size=0;

}
int Buffer::Read(fstream &f)
{
	 Buffer::Clear();
	 f>>Size;
	 f.read(Buff,Size);
	 return f.good();
}
int Buffer::Write(fstream &f)
{
	 f<<Size;
	 f.write(Buff,Size);
	 return f.good();
}
int  Buffer::UnPack(char *c)
{
	 int i;
	 if(Size==0)
	return 0;
	 for(i=0;Buff[Pos+1]!=D;i++,Pos++)
	c[i]=Buff[Pos+1];
	 c[i]='\0';
	 Pos++;
	 if(Pos>Size)
	return 0;
	 else
	return 1;
}
int Buffer::Pack(char *c)
{
	 int i;
	 if(Size==0)
	 {
	Buff[0]=D;
	Size=1;
	Pos=1;
	 }
	 for(i=0;c[i];i++,Pos++,Size++)
	Buff[Pos]=c[i];
	 Buff[Pos++]=D;
	 Size++;
	 if(Size>Max)
	return 0;
	 else
	return 1;
}
void Buffer::Print()
{
	 for(int i=0;i<Max;i++)
	cout<<Buff[i];
	 cout<<"\n";
}

class BuffFile
{
	 protected:
		  Buffer Buff;
		  fstream f;
	 public:
		  BuffFile(Buffer B):Buff(B){};
	int Open(char *);
	int  Close();
		  void Rewind();
		  void End();
		  int Pos();
		  int Read(int);
		  int Write(int);
};
int BuffFile::Open(char *c)
{
	 f.open(c,ios::out|ios::app);
	 f.close();
	 f.open(c,ios::in|ios::out);
	 return f.good();
}
int BuffFile::Close()
{
	 f.close();
	 return f.good();
}
void BuffFile::Rewind()
{
	 f.seekp(0,ios::beg);
}
void BuffFile::End()
{
	 f.seekp(0,ios::end);
	 f.seekg(0,ios::end);
}
int BuffFile::Pos()
{
	 return f.tellp();
}
int BuffFile::Read(int add)
{
	 f.seekg(add,ios::beg);
	 if(f.fail())
	 {
		  f.clear();
		  return -1;
    }
    if(Buff.Read(f))
        return add;
    else 
    {
        f.clear();
        return -1;
    }
            
}
int BuffFile::Write(int add)
{
    f.seekp(add,ios::beg);
    if(Buff.Write(f))
        return add;
    else
        return -1;
}                
template<class Record>
class RecordFile:public BuffFile
{
    public:
        RecordFile(Buffer B):BuffFile(B){};
        int Write(Record &,int);
        int Read(Record &,int);
};
template<class Record>
int RecordFile<Record>::Write(Record &E,int add=0)
{
    if(E.Pack(Buff)==0)
        return -1;
    return BuffFile::Write(add);
}
template<class Record>
int RecordFile<Record>::Read(Record &E,int add=0)
{
    int i=BuffFile::Read(add);
    if(i==-1)
        return -1;
    if(E.UnPack(Buff))
        return i;
    else
        return -1;
}
template<class Record>
class RelFile:public RecordFile<Record>
{
    protected:
        int Size;
        int Address(int);
    public:
        RelFile(Buffer B,int S):RecordFile<Record>(B),Size(S){};
        int Read(Record &,int);
        int Write(Record &,int);
};
template<class Record>
int RelFile<Record>::Address(int i)
{
    return (i*Size);
}
template<class Record>
int RelFile<Record>::Read(Record &E,int i)
{
    return RecordFile<Record>::Read(E,Address(i));
}
template<class Record>
int RelFile<Record>::Write(Record &E,int i)
{
    return RecordFile<Record>::Write(E,Address(i));
}                
class Person
{
    protected:
        char *Name;
        char *Roll;
        char *Cg;
    public:
        Person()
        {
            Name=new char[10];
            Roll=new char[5];
            Cg=new char[5];
            Clear();
        }
        void Clear();
        void Input();
	int Pack(Buffer &);
	int UnPack(Buffer &);
        void Print();
        char * operator()()const;
};
void Person::Clear()
{
    int i;
    for(i=0;i<5;i++)
    {
        Name[i]='\0';
        Roll[i]='\0';
        Cg[i]='\0';
    }
    while(i<10)
        Name[i++]='\0';
}
void Person::Input()
{
    cout<<"Name: ";
    cin>>Name;
    cout<<"Roll: ";
    cin>>Roll;
    cout<<"Cg: ";
    cin>>Cg;
}        
int Person::Pack(Buffer &B)
{
    int r=1;
    r=r&&B.Pack(Name);
    r=r&&B.Pack(Roll);
    r=r&&B.Pack(Cg);
    return r;
}
int Person::UnPack(Buffer &B)
{
    int r=1;
    Clear();
    r=r&&B.UnPack(Name);
    r=r&&B.UnPack(Roll);
    r=r&&B.UnPack(Cg);
    return r;
}
void Person::Print()
{
    cout<<"Name: "<<Name<<" Roll: "<<Roll<<" Cg: "<<Cg<<endl;
}
char * Person::operator()()const
{
    return Roll;
}
                                           
template<class Record>
class ExtendHash;
template<class Record>
class Bucket
{
    protected:
        Record * Elem;
        int Num;
        int Max;
        int D;
        char *Flag;
    public:
        Bucket(int m=10,int d=0)
        {
            Max=m;
            Elem=new Record[Max];
            Num=0;
            D=d;
            Flag=new char [3];
            Flag[0]='0';
            Flag[1]='\0';
            Flag[2]='\0';
        }
        ~Bucket()
        {
            delete Elem;
        }
	int Full();
	int Pack(Buffer &);
	int UnPack(Buffer &);
	int Insert(const Record &);
	int Delete(const char *);
        void Delete();
	int Find(const char *);
        void Sort();
        void Print();
        friend class ExtendHash<Record>;
};
template<class Record>
int Bucket<Record>::Full()
{
    return (Num==Max);
}    
template<class Record>
int Bucket<Record>::Pack(Buffer &B)
{
    int r=1;
    B.Clear();
    r=r&&B.Pack(i2c(Num));
    r=r&&B.Pack(i2c(D));
    r=r&&B.Pack(Flag);
    for(int i=0;i<Num;i++)
    {
        r=r&&Elem[i].Pack(B);
    }
    return r;
}
template<class Record>
int Bucket<Record>::UnPack(Buffer &B)
{
    int r=1,i;
    char *c=new char[5];
    
    for(i=0;i<5;i++)
        c[i]='\0';
    r=r&&B.UnPack(c);
    Num=c2i(c);
    
    for(i=0;i<5;i++)
        c[i]='\0';
    r=r&&B.UnPack(c);
    D=c2i(c);
    
    r=r&&B.UnPack(Flag);
    
    for(i=0;i<Num;i++)
        r=r&&Elem[i].UnPack(B);
    return r;
}
template<class Record>
int Bucket<Record>::Insert(const Record &R)
{
    if(Num==Max)
        return 0;
    Elem[Num++]=R;
    Sort();
    return 1;
}
template<class Record>
int Bucket<Record>::Delete(const char *c)
{
    int i;
    for(i=0;i<Num;i++)
        if(strcmp(Elem[i](),c)==0)
            break;
    if(i==Num)
        return 0;
    while(++i<Num)
           Elem[i-1]=Elem[i];
    Num--;
    return 1;
}         
template<class Record>
int Bucket<Record>::Find(const char *c)
{
    for(int i=0;i<Num;i++)
        if(strcmp(Elem[i](),c)==0)
        {
            cout<<"\n";
            Elem[i].Print();
            return 1;
        }
    return 0;
}
template<class Record>
void Bucket<Record>::Sort()
{
    for(int i=0;i<Num-1;i++)
        for(int j=i+1;j<Num;j++)
            if(strcmp(Elem[i](),Elem[j]())>0)
					 Swap(Elem[i],Elem[j]);
}        
template<class Record>
void Bucket<Record>::Print()
{
    for(int i=0;i<Num;i++)
        Elem[i].Print();
    cout<<"------------------------------------------\n";
}
template<class Record>   
class DNode
{
    protected:
        int Pos;
        int D;
    public:
        DNode(int P=0,int d=0):Pos(P),D(d){};
	int Pack(Buffer &);
	int UnPack(Buffer &);
        void Print();
        friend class ExtendHash<Record>;
};
template<class Record>
int DNode<Record>::UnPack(Buffer &B)
{
    int r=1;
    char *c=new char [5];
    for(int j=0;j<5;j++)
	c[j]='\0';
    r=r&&B.UnPack(c);
    D=c2i(c);
    for(int i=0;i<5;i++)
        c[i]='\0';
    r=r&&B.UnPack(c);
    Pos=c2i(c);
    return 1;
}
template<class Record>
int DNode<Record>::Pack(Buffer &B)
{
    int r=1;
    B.Clear();
    r=r&&B.Pack(i2c(D));
    r=r&&B.Pack(i2c(Pos));
    return 1;
}
template<class Record>
void DNode<Record>::Print()
{
    cout<<"Pos: "<<Pos<<" D: "<<D<<endl;
}                    
template<class Record>
class ExtendHash
{
    protected:
        RelFile<DNode<Record> > Dir;
        RelFile<Bucket<Record> > Data;
        int BSize;
        int Num;
        int D;
        
        int H;
        int Hash(const char *);
        int Key(int);
        
	int Insert(const Record &,int);
	int SplitBucket(const Record &,int);
        void ExpandDir();
        int Space();
        
	int Delete(const char *,int);
	int CombineBucket(int);
        void CollapseDir();
	int Check();
        
	int Find(const char *,int);
                
    public:
        ExtendHash(Buffer B,Buffer Bd,int Bs=10):Dir(B,10),Data(Bd,300)
        {
            Num=0;
            D=0;
            BSize=Bs;
            cout<<"\n\nEnter the Hashing No.: ";
            cin>>H;
            char c[10];
            cout<<"Enter The Name of The Data File: ";
            cin>>c;
            DataOpen(c);
            cout<<"Enter The Name of The Directory File: ";
            cin>>c;
            DirOpen(c);
            Initialize();
        };
        void DataOpen(char *);
        void DirOpen(char *);
        void DataClose();
        void DirClose();
        void Initialize();
        
        
        void Insert(const Record &);
        void Delete(const char *);
        void Find(const char *);
        void Print();
};
template<class Record>
void ExtendHash<Record>::DataOpen(char *c)
{
    Data.Open(c);
}
template<class Record>
void ExtendHash<Record>::DirOpen(char *c)
{
    Dir.Open(c);
}
template<class Record>
void ExtendHash<Record>::DataClose()
{
    Data.Close();
}
template<class Record>
void ExtendHash<Record>::DirClose()
{
    Dir.Close();
}
template<class Record>
void ExtendHash<Record>::Initialize()
{
    DNode<Record> Dn;
    Bucket<Record> B(BSize);
    Dir.Read(Dn,0);
    D=Dn.D;
    int p=0;
    for(int i=pow(2,D);i>0;i--)
    {
        Dir.Read(Dn,i-1);
        if(Dn.Pos>p)
            p=Dn.Pos;
    }
    Num=p+1;
}    
template<class Record>
void ExtendHash<Record>::Insert(const Record &R)
{
    Insert(R,Key(Hash(R())));
}
template<class Record>
void ExtendHash<Record>::Delete(const char *c)
{
    if(Delete(c,Key(Hash(c))))
        cout<<"\nElement Deleted\n";
    else
        cout<<"\nElement Not Found\n";
}
template<class Record>
void ExtendHash<Record>::Find(const char *c)
{
    if(Find(c,Key(Hash(c))))
        cout<<"\nElement Found\n";
    else
        cout<<"\nElement Not Found\n";
}
template<class Record>
void ExtendHash<Record>::Print()
{
    cout<<"\n\n";
    DNode<Record> Dn1,Dn2;
    Bucket<Record> B(BSize);
    Dir.Read(Dn1,0);
    Data.Read(B,Dn1.Pos);
    B.Print();
    for(int i=1;i<pow(2,D);i++)
    {
        Dir.Read(Dn2,i);
        if(Dn2.Pos!=Dn1.Pos)
        {
            Dn1=Dn2;
            Data.Read(B,Dn2.Pos);
            B.Print();
        }
    }
}
                                      
template<class Record>
int ExtendHash<Record>::Hash(const char *c)
{
    return c2i(c)%H;
}
template<class Record>
int ExtendHash<Record>::Key(int x)
{
    int ans=0;
    for(int j=0;j<D;j++)
    {
        ans=ans<<1;
        ans=ans|(x&1);
        x=x>>1;
    }
    return ans;    
}

template<class Record>
int ExtendHash<Record>::Insert(const Record &R,int i)
{
    DNode<Record> Dn;
    if(Dir.Read(Dn,i)==-1)
    {
        Dn.Pos=0;
        Dir.Write(Dn,0);
        Num++;
    }    
    Bucket<Record> B(BSize);
    Data.Read(B,Dn.Pos);
    if(B.Full())
    {
        if(!SplitBucket(R,i))
        {
            ExpandDir();
            Insert(R);
        }    
    }    
    else
    {
        B.Insert(R);
        Data.Write(B,i);
     }    
    B.Print();
}
template<class Record>
int ExtendHash<Record>::SplitBucket(const Record &R,int i)
{
    Bucket<Record> B(BSize);
    DNode<Record> Dn;
    Dir.Read(Dn,i);
    Data.Read(B,Dn.Pos);
    if(B.D==D)
        return 0;
    
    Bucket<Record> B1(BSize,B.D+1),B2(BSize,B.D+1);
    int s=Space();
    Data.Write(B1,Dn.Pos);
    Data.Write(B2,s);
    if(s==Num)
        Num++;
    
    int j=i;
    j=j>>(D-B.D);
    j=j<<(D-B.D);
    int k=pow(2,D-B.D-1);
    j=j+k;
    while(k>0)
    {
        k--;
        Dir.Read(Dn,j+k);
        Dn.Pos=(s);
        Dir.Write(Dn,j+k);
    }
    int m;
    for(m=0;m<B.Num;m++)
    {
        Insert(B.Elem[m]);
     }
    Insert(R);                    
    return 1;
}
template<class Record>
void ExtendHash<Record>::ExpandDir()
{
    DNode<Record> Dn;
    int i=pow(2,D++);
    for(int k=i;k>0;k--)
    {
        Dir.Read(Dn,k-1);
        Dn.D=D;
        Dir.Write(Dn,2*(k-1));
        Dir.Write(Dn,(2*k)-1);
    }
}
template<class Record>
int ExtendHash<Record>::Space()
{
    Bucket<Record> B(BSize);
    int i;
    for(i=0;i<Num;i++)
    {
        Data.Read(B,i);
        if(B.Flag[0]=='1')
            break;
    }
    return i;     
}    

template<class Record>
int ExtendHash<Record>::Delete(const char *c,int i)
{
    DNode<Record> Dn;
    Bucket<Record> B(BSize);
    Dir.Read(Dn,i);
    Data.Read(B,Dn.Pos);
    if(!B.Delete(c))
        return 0;
    Data.Write(B,Dn.Pos);
    if(CombineBucket(i))
    {
        if(Check())
            CollapseDir();
    }
    return 1;    
}
template<class Record>
int ExtendHash<Record>::CombineBucket(int i)
{
    DNode<Record> Dn;
    Bucket<Record> B(BSize);
    Dir.Read(Dn,i);
    Data.Read(B,Dn.Pos);
    int j=i;
    j=j>>(D-B.D+1);
    j=j<<(D-B.D+1);
    int p=pow(2,D-B.D);
    Bucket<Record> B1(BSize),B2(BSize);
    Dir.Read(Dn,j);
    Data.Read(B1,Dn.Pos);
    Dir.Read(Dn,j+p);
    Data.Read(B2,Dn.Pos);
    if(B1.D!=B2.D)
        return 0;
    if(B1.Num+B2.Num>BSize)
        return 0;
    
    while(B2.Num>0)
        B1.Elem[B1.Num++]=B2.Elem[--B2.Num];
    B1.D--;
    B1.Sort();
    B2.Flag[0]='1';
    Dir.Read(Dn,j+p);
    Data.Write(B2,Dn.Pos);
    
    Dir.Read(Dn,j);
    Data.Write(B1,Dn.Pos);
    int t=Dn.Pos;
    for(int k=(j+(2*p));k>(j+p);k--)
    {
        Dir.Read(Dn,k-1);
        Dn.Pos=t;
        Dir.Write(Dn,k-1);
    }    
    return 1; 
}
template<class Record>
void ExtendHash<Record>::CollapseDir()
{
    DNode<Record> Dn;
    int i=pow(2,--D);
    for(int k=0;k<i;k++)
    {
        Dir.Read(Dn,(2*k));
        Dn.D=D;
        Dir.Write(Dn,k);
    }    
}
template<class Record>
int ExtendHash<Record>::Check()
{
    DNode<Record> Dn;
    Bucket<Record> B(BSize);
    for(int i=pow(2,D);i>0;i--)
    {
        Dir.Read(Dn,i-1);
        Data.Read(B,Dn.Pos);
        if(B.D==D)
            return 0;
    }
    return 1;        
}             

template<class Record>
int ExtendHash<Record>::Find(const char *c,int i)
{
    DNode<Record> Dn;
    Bucket<Record> B(BSize);
    Dir.Read(Dn,i);
    Data.Read(B,Dn.Pos);
    return B.Find(c);
}
int Menu()
{
  
    cout<<"\n\n\t\tOPERATONS";
	 cout<<"\n\t1.) Insert a Record";
	 cout<<"\n\t2.) Delete a Record";
	 cout<<"\n\t3.) Find a Record";
	 cout<<"\n\t4.) Display The File";
	 cout<<"\n\t5.) Exit The Program";
	 cout<<"\n\t    Enter Your Choice: ";
	 int i;
	 cin>>i;
	 return i;
}
main()
{
	 Buffer B(10),Bd(150);
	 ExtendHash<Person> E(B,Bd);
	 char r[10];
	 Person P;
	 while(1)
	 {
		  switch(Menu())
		  {
				case 1:
					 P.Input();
					 E.Insert(P);
					 break;
				case 2:
					 cout<<"Enter The Roll No.: ";
					 cin>>r;
					 E.Delete(r);
					 break;
				case 3:
					 cout<<"Enter The Roll No.: ";
					 cin>>r;
					 E.Find(r);
					 cout<<"\nPress Any Key to Continue...";
					 cin>>r;
					 break;
				case 4:
					 E.Print();
					 cout<<"\nPress Any Key to Continue...";
					 cin>>r;
					 break;
				case 5:
					 break;
		  }
	 }
}
