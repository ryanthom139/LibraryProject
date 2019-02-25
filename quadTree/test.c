#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "buildTree.h"
//#include "valueTree.h"
#include "writeTree.h"
#include "test.h"

void Task1(){

  destroyTree(head);

}

void Task2(){

  growTree( head, max_level );
  writeTree(head);
  destroyTree(head);

}

void Task3(){

max_level = 3;
growTree(head);

}