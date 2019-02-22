#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"


int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  makeChildren( head );


  for (int i = 0; i < 4; i++){
    
    makeChildren( head -> child[i] );
  }

  for (int i = 0; i < 4; i++){

    for (int j = 0; j < 4; j++){
    
    makeChildren( head -> child[i] -> child[j] );
    
    }

  }
  
  
  // print the tree for Gnuplot
	writeTree( head );

  return 0;
}