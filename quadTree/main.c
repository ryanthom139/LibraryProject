#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "buildTree.h"

#include "writeTree.h"
#include "valueTree.h"

int main( int argc, char **argv ) {

  Node *head;
  double tolerance = 0.2;
  int choice = 1;
  int max_level = 1000;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
 
  growTree( head, max_level );
  growTree( head, max_level );
  
  monitorChild(head, choice, tolerance);




  writeTree( head );

  destroyTree( head );


  return 0;

}