#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"


int main( int argc, char **argv ) {

  Node *head;

  // make the head nodemakeChildren
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  makeChildren( head );

  growTree(head);

  writeTree(head);
  
 



  return 0;

}