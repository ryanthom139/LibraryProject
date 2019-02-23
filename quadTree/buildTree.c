#include "stdio.h"
#include "math.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "stdlib.h"

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));  // Allocate special space for the node

  node->level = level;  // Accessing the level member of the node structure

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i ){
    node->child[i] = NULL;  // Setting all child pointers to NULL
  }
  return node;
}

void makeChildren( Node *parent ) {

  double x = parent->xy[0];  
  double y = parent->xy[1];

  
  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

 void growTree(Node *head, int max_level){

    if( head->child[0] == NULL && head->level < max_level){ 
            makeChildren(head);
            
        }
    else if(head->level < max_level) {
        for (int i=0; i<4; i++ ) {   
            growTree(head->child[i], max_level);
            }
        }
     
    }

void destroyTree(Node *head){

      if( head->child[0] == NULL ){
          free(head);
      }
      else
      {
          for ( int i=0; i<4; i++ ) {
              destroyTree(head->child[i]);
              
              }
              free(head);
      }
      
  }



    