/* Write a C program that uses functions to perform the following:
   i) Creating a Binary Tree of integers
   ii) Traversing the above binary tree in preorder, inorder and postorder. */

#include<stdio.h>
#include <stdlib.h>
#include<conio.h>

struct treenode
{
  int ele;
  struct treenode *l_child, *r_child;
};

struct treenode *insert_node(struct treenode *t,int a);
void TraverseInorder(struct treenode *t);
void TraversePreorder(struct treenode *t);
void TraversePostorder(struct treenode *t);

/*main function*/
void main()
{
  struct treenode *root_node = NULL;
  int num,value;
  int choice;

  clrscr();

  printf("----------------------------------------------------\n");
  printf("\t\t\tMENU\n");
  printf("-----------------------------------------------------\n");
  printf("[1] Create a Binary Tree and Use Inorder Traversal\n");
  printf("[2] Create a Binary Tree and Use Preorder Traversal\n");
  printf("[3] Create a Binary Tree and Use Postorder Traversal\n");
  printf("-----------------------------------------------------\n");
  printf("Enter your choice:");
  scanf("%d",&choice);

   if(choice>0 & choice<=3)
   {
     printf("\nEnter the number of nodes:");
     scanf("%d",&num);

      while(num-- > 0)
     {
	 printf("\n\nEnter the data value:");
	 scanf("%d",&value);
	 root_node = insert_node(root_node,value);
    }

     switch(choice)
     {
       case 1:
	    printf("\n\nBinary tree using Inorder Traversal : ");
	    TraverseInorder(root_node);
	    getch();
	    break;

       case 2:
	    printf("\n\nBinary tree using Preorder Traversal : ");
	    TraversePreorder(root_node);
	    getch();
	    break;

       case 3:
	    printf("\n\nBinary tree using Postorder Traversal : ");
	    TraversePostorder(root_node);
	    getch();
	    break;

	    default:
	    printf("Invalid Choice");
	    break;
     }
   }
}
/*end main*/

/* Function to create a Binary Tree of integers data */
struct treenode *insert_node(struct treenode *t,int a)
{
  struct treenode *temp_node1,*temp_node2;
  if(t == NULL)
   {
      t = (struct treenode *) malloc(sizeof(struct treenode));
      if(t == NULL)
      {
	printf("Value cannot be allocated.\n");
	exit(0);
      }
      t->ele = a;
      t->l_child=t->r_child=NULL;
    }
    else
    {
      temp_node1 = t;

      while(temp_node1 != NULL)
      {
	 temp_node2 = temp_node1;
	 if( temp_node1 ->ele > a)
	 temp_node1 = temp_node1->l_child;
	 else
	 temp_node1 = temp_node1->r_child;
      }
     if( temp_node2->ele > a)
     {
     temp_node2->l_child = (struct treenode*)malloc(sizeof(struct treenode));
     temp_node2 = temp_node2->l_child;
     if(temp_node2 == NULL)
     {
       printf("Value cannot be allocated.\n");
       exit(0);
     }
     temp_node2->ele = a;
     temp_node2->l_child=temp_node2->r_child = NULL;
  }
  else
  {
     temp_node2->r_child = (struct treenode*)malloc(sizeof(struct treenode));

     temp_node2 = temp_node2->r_child;
     if(temp_node2 == NULL)
     {
       printf("Value cannot be allocated.\n");
       exit(0);
     }
     temp_node2->ele = a;
     temp_node2->l_child=temp_node2->r_child = NULL;
}
}
return(t);
}

/* Function for Traversing the binary tree in inorder. */
void TraverseInorder(struct treenode *t)
{
 if(t != NULL)
 {
  TraverseInorder(t->l_child);
  printf("%d\t",t->ele);
  in_order(t->r_child);
 }
}

/* Function for Traversing the binary tree in preorder. */
void TraversePreorder(struct treenode *t)
{
  if(t != NULL)
  {
   printf("%d\t",t->ele);
   TraversePreorder(t->l_child);
   TraversePreorder(t->r_child);
  }
}

/* Function for Traversing the binary tree in postorder. */
void TraversePostorder(struct treenode *t)
{
 if(t != NULL)
 {
  TraversePostorder(t->l_child);
  TraversePostorder(t->r_child);
  printf("%d\t",t->ele);
 }
}

