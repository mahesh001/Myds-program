#include<include>
#include<fstream>
using namespace std;
class btreenode
{
	
}
class btree
{ public:
	btree(int order,int keysize=sizeof(int),int unique=-1);
	~btree();
	int open(char*name,int mode);
   int 	create(char*name,int mode);
   int close();
   int insert( int key,int recadd);
   int remove( int key,int recadd=-1);
   int search( int key,int recadd=-1);
   void print(ostream&);
   void print(ostream&,int nodeadd,int level);
   protected:
   	btnode*findleaf(int key);
   	btnode*newnode();
   	btnode*fetch(int recadd);
   	int store(btnode*);
   	btnode root;
   	int height;//height of tree;
   	int order;//of tree;
   	int poolsize;
   	btnode**node;
   	fixedfieldbuffer buffer;
   }
   int maxheight=5;
   btree::btree(int order,int keysize,int unique)
   :buffer(1+2*order,sizeof(int)+order*keysize+order*sizeof(int)),
   btreefile(buffer),root(order)
   {
   	height=1;
   	order=order;
   	poolsize=maxheight*2;
   	node=new btnode*(poolsize);
   	btnode::buffer(buffer,order);
   	node[0]=&root;
   }
   btree::~btree()
   {
   	close();
   	delete node;
   }
   int btree::open( char*name,int mode)
   {
   	int result;
   	result=btreefile.open(name,mode);
   	if(!result)
   	return result;
   	btreefile.read(root);
   	height=1;
   	return 1;
   }
   int  btree::create(char*name.int mode) 
   {
   	int result;
   		result=btreefile.create(name,mode);
   	if(!result)
   	return result;
   	btreefile.write(root);
   	root.recadd=result;
   	return result!=-1;
   	
   }
   int btree::close()
   {
   	int result;
   	result=btreefile.rewind();
   	if(!result)
   	return result;
   	result=btreefile.write(root);
   	if(result==-1)
   	return 0;
   	return btreefile.close();
   }
   int btree::insert( int key,int recadd)
   {
   	int result;
   	int level=height-1;
   	int newlarg=0,prevkey,largkey;
   	btnode*thisnode,*newnode,*parentnode;
   	thisnode=findleaf(key);
   	if(key>thisnode->largkey())
   	{
   		newlarg=1;
   		prevkey=thisnode->largkey();
   	}
   	result=thisnode->insert(key,recadd);
   	if(newlarg)
   	for(int i=0;i<height-1;i++)
	{
   	nodes[i]->updatekey(prevkey,key);
   	if(i>0)
   	store(nodes[i]);
   }
   while(result==-1)
   {
   	largkey=thisnode->largkey();
   	
   	newnode=new node();
   	thisnode->split(newnode)
   	level--;
   	if(level<0)
   	break;
   	parentnode=nodes[level];
   	result=parentnode->updatekey(largkey,thisnode->largkey());
   	result=parentnode->insert(newnode->largkey().newnode->recadd);
   	thisnode=parentnode;
   }
   store(thisnode);
   if(level>=0)
   return 1;
   int newadd=btreefile.append(root);
   root.key[0]=thisnode->largkey();
   root.key[0]=newadd;
   root.key[1]=newnode->largkey();
   root.recadd[1]=newnode->recadd;
   root.numkey=2;
   height++;
   return 1;
   }
   int btree::remove(int key,int recadd)
   {
   	return -1;
   }
   int btree::search(int key,int recadd)
   {
   	btnode*leafnode;
   	leafnode=findleaf(key);
   	return leafnode->search(key,recadd);
   }
   void btree::print(ostream& stream)
   {
   	stream<<"btree of height"<<height<<"is"<<endl;
   	root.print(stream);
   	if(height>1)
   	for(int i=0;i<root.numkey();i++)
   	{
   		print(stream,root.recadd[i],2);
   	}
   	stream<<"end of tree"<<endl;
   }
   void btree::print(ostream& stream,int nodeadd,int level)
   {
   	btnode*thisnode=fetch(nodeadd);
   	stream<<" node at level "<<level<<" address"<<nodeadd<<'';
   	thisnode->print(stream);
   	if(height>level)
   	{
   		level++;
   		for(int i=0;i<thisnode->numkey();i++)
   		{
   			print(stream,thisnode->recadd[i],level);
   		}
   		stream<<"end of level"<<level<<endl;
   	}
   }
   btreenode*btree::findleaf(int key)
   {
   	int recadd,level;
   	for(level;level<height;level++)
   	{
   		recadd=nodes[level-1]->search(key,-1,0);
   		nodes[level]=fetch(recadd);
   	}
   	return nodes[level-1];
   }
   btreenode*btree::newnode()
   {
   	btnode*newnode=new btnode(order);
   	int recadd=btreefile.append(*newnode);
   	newnode->recadd=recadd;
   	return newnode;
   }
   btreenode*btree::fetch(int recadd)
   {
   	int result;
   	btnode*newnode=new btnode(order);
   	result=btreefile.read(*newnode,recadd);
   	if(result==-1)
   	return NULL;
   	newnode->recadd=result;
   	return newnode;
   }
   int btree::store(btreenode*thisnode)
   {
   	return btreefile.write(*thisnode,thisnode->recadd);
   }
