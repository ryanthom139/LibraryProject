#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "buildTree.h"
//#include "valueTree.h"
#include "writeTree.h"


int main( int argc, char **argv ) {

  Node *head;
  int max_level = 2;
  int choice;
  int tolerance;
  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
 
  growTree( head, max_level );
  growTree( head, max_level );
  growTree( head->child[0]->child[0], max_level );
 


  writeTree( head );

  destroyTree( head );


  return 0;

}