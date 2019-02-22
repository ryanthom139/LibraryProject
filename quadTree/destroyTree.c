#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "treeChanges.h"
#include "buildTree.h"
#include "writeTree.h"

void destroyTree(Node *head){

    int i;

    if( head->child[0] == NULL ){
        free(head);
    }
    else
    {
        for ( i=0; i<4; i++ ) {
            destroyTree(head->child[i]);
            
            }
    }
    free(head);
    
    return;
}