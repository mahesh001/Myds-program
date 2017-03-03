	#include <iostream>
	#include <fstream>
	using namespace std;
	 
	//function declaration
	int HashAddress (int PartNumber, char Algorithm);
	 
	// global variables
  int array[41];
	 
	int main()
	{
	 
	  int i = 0;
	  int max_read = 41;
	  int amountRead = 0;
	  int PartNumber, Index;
	  char Algorithm;
	 
	  // set array elements to -1
	  for(i = 0; i < 41; i++)
	  {
	 
	  	array[i] = -1;
	 
	  }  
	 
	  std::ifstream inputfile("part.txt",std::ios::in |std::ios::binary);
	 
	  if(!inputfile)
	  {
	 
	    std::cout<<"Could not open file"<<std::endl;
	    return 1;
	 
	  }
	 // prompt for input from user to choose algorithm
	 
		cout<<"Please select Algorithm\n";
		cout<<"1. Modulo Division using linear probing \n";
		cout<<"2. Modulo Division using key offset \n";
		cout<<"3. PsuedoRandom using linear probing \n";
		cout<<"4. Rotation using linear probing \n";
		cin >> Algorithm;
	 
	 
	 
	  //this is where we are reading in the information into our array
	  for(i = 0; i < 41; i++)
	  {
	 
	    // as you read each part number in the file
	    inputfile >>  PartNumber;
	 
		// HashAddress function returns array index and it is assigned to variable Index
		Index = HashAddress(PartNumber,Algorithm); 
	 
		// put part number in array 
		array[Index] = PartNumber;
	 
	  }
	 
  return 0; 
	 
	}	 
 
	// function HashAddress returns location for hash table
	int HashAddress(int PartNumber, char Algorithm)
	{
	 
	  int x, y, z,Index,count;
	 
	 
	  // use algorithms to hash address
	  switch(Algorithm)
  {
	  case '1': // first algorithm, Modulo Division with linear probing
   Index = PartNumber % 41;  
 
	 
	  break;
	 
	  case '2': // second algorithm, Modulo Division with key offset
   Index = PartNumber % 41;  
 
	  break;
	 
  case '3':  // third algorithm, Psuedorandom with linear probing
  Index = (17 * PartNumber + 7) % 41;
	 
	  break;
 
	  case '4':  // fourth algorithm, Rotation with linear probing
  x = PartNumber % 10;
	  y = PartNumber / 10;
	  z = x * 10;
	  Index = (z+y) % 41; 
	 
	  break;
	 
	  default:
	  cout << "Invalid Selection\n"; //invalid choice 
	  }  
	 
	   cout << "\nPart Number: " << " " << PartNumber << " " << "Index: " << Index;
	 
	  // check to see if array element is occupied 
	  if(array[Index] < 0)
	 
		 // array element is available so return the address/location
		 return Index;
	 
	  else //collision, part number is already in that spot
	    {
	        count = 0; // use count to stop if table is full
	 
	        do 
	        {  
	 
	             switch(Algorithm)
	             {
				 case '1':
		 	 	 Index = (Index + 1) % 41; // % 41 allows for wrap around
				 break;
	 
				 case '2':
	 
	             Index = (PartNumber / 41) % 41;			 
	 
	             case '3':
		 	 	 Index = (Index + 1) % 41; // % 41 allows for wrap around
				 break;
	 
	             case '4':
		 	 	 Index = (Index + 1) % 41; // % 41 allows for wrap around
				 break;
	 
				 default:
				   cout << "Invalid Selection\n"; //invalid choice
	             }  
	             count ++; 
	         }  while ((array[Index] > 0) && (count < 41)); 
	 
	 
	 
	 
	        if (count == 41)
	        {    
				//print ERROR hash table is full
	           cout << "Hash table is full. Can not insert part number.";
			}	           
			else 
				 cout << "\nCollision count:" << " " << count << " "<< "New Index:" << " " << Index;
	 
			   return Index;
			   cout<<"enter a no\n";
			   cin>>count;
	 return 0;
	    }}
