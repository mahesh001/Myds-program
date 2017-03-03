#include<iostream>
using namespace std;

class bnode{  public:
    bnode *header;
    bnode *lchild;
    bnode *rchild;
    int freq;
    int type;
    char ch;
    int depth;
    char leaf;
    };
    
bnode combine(bnode node_i, bnode node_j)
{
    bnode *temp, *root,*newnode;
    newnode = new bnode;
    (newnode->lchild)=(node_i.header);
    cout<<"Address of left child of newnode: "<<newnode->lchild<<endl;
    (newnode->rchild)=(node_j.header);
    cout<<"Address of right child of newnode: "<<newnode->rchild<<endl;
    cout<<"Address of root node: "<<newnode->header<<endl;
    return *newnode;
}

int  main()
{
    const int LEFT_CHILD=0, RIGHT_CHILD=1, ROOT=-1;
    int chars,i,j,k,temp1,temp2,min1,min2;
    int frequency;
    cout<<"how many characters do you have?"<<endl;
    cin>>chars;
    bnode node[2*chars-1],tempnode, *temp, *root, *newnode;
    for(i=0;i<chars;i++)
    {
        node[i].lchild=NULL;
        node[i].rchild=NULL;
    }
    for(i=0;i<chars;i++)
    {
        cout<<"Enter symbol:"<<endl;
        cin>>node[i].ch;
        cout<<"Enter the frequency of the symbol"<<endl;
        cin>>node[i].freq;

    }
    for(i=0;i<chars;i++)
    {
        for(j=i;j<chars;j++)
        {
            if(node[i].freq>node[j].freq)
            {
                tempnode=node[i];
                node[i]=node[j];
                node[j]=tempnode;
            }
        }
    }
    for(i=chars-1;i>=0;i--)
    {
        cout<<"Symbol: "<<node[i].ch<<"  and   Frequency: "<<node[i].freq<<endl;
    }
    for(i=0;i<chars;i++)
    {
        temp1=node[i].freq;
        temp2=node[i].freq;
        for(k=i;k<chars+i;k++)
        {
            {
                if(temp1>node[k].freq)
                {
                    temp1=node[k].freq;
                    min1=k;
                }
            }
            {
                if( (temp2>=node[k].freq) && (temp2>temp1) )
                {
                    temp2=node[k].freq;
                    min2=k;
                }
            }
        }
        node[chars+i]=combine(node[min1], node[min2]);
    }
    return 0;
}

	



