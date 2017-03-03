	 
	#include <iostream>
	 
	using namespace std;
	 
	class gttree{
	    public:
	        struct gtnode{
	            int ID, child;
	            gtnode *ptr_nextChild;
	        };
	         
	        //initialize root
	        gtnode *root;
	 
	       gttree()
		   {
	            int child = 0;
	        }
	 
	        ~gttree(){
	            clear();
	        }
	 
	        void clear(){
	            //point to the node to be deleted
	            gtnode *tmp;
	            //used to visit each node in the tree.
	                        //We start with the first actual node off of "root"
	           gtnode *traverse = root->ptr_nextChild;
	             
	            //while the tree is not empty
	            while(traverse != NULL){
	                //store the current node
	                tmp = traverse;
	                //visit the next node
	                traverse = traverse->ptr_nextChild;
	                //free the memory taken up by the current node
	                delete tmp;
	            }
	        }
	 
	        void addChildren(int *tID, int cNo){
	            int child = cNo;
	            gtnode *gttree = new gtnode[child];
	 
	            for(int i=0; i<child; i++){
	                gttree->ID = tID[i];
	            }
	        }
	 
	        void PrintTree(gtnode *T) {	            /* .: Print all the items in the tree to which root points...the item in the root is printed first, followed by its children :: as long as the root is not empty :. */
	            if (T!= NULL){
	                cout << T->ID << " ::- " << T->child << endl;
	                // Print children
	                PrintTree(T->ptr_nextChild);
	            }
	        }
	 
	        void deleteChild(gtnode *ChildPtr){
	        }
	};
		int main(){
	    gttree *gtree = new gttree;
	    int tID ;
	    int Child;
	    cout<<"enter id and no of child\n";
	    cin>>tID;
	    cin>>Child;
	 
	    gtree->addChildren(&tID, Child);
	    gtree->PrintTree(gtree->root);
	 
	    return 0;
	}
