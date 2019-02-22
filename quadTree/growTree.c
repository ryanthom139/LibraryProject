#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "growTree.h"
#include "buildTree.h"
#include "writeTree.h"

void growTree(Node *head){

    int i;
    
        if( head->child[0] == NULL ){
            for ( i=0; i<4; i++ ) {   
                makeChildren(head->child[i]);
            }
        }
        else {
            for ( i=0; i<4; i++ ) {   
                growTree(head->child[i]);
            }
        }
}