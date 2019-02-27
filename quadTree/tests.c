#include "stdio.h"
#include "stdlib.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"
#include "valueTree.h"


void Task1(){
  Node *head;
  head = makeNode( 0.0,0.0, 0 );
  int max_level = 10;
  makeChildren(head);
  for (int i = 0; i < 4; i++){
  makeChildren(head->child[i]);
  }
  makeChildren(head->child[0]->child[0]);
  
  destroyTree(head);

}

void Task2(){
  Node *head;
  head = makeNode( 0.0,0.0, 0 );
  int max_level = 10;
  makeChildren(head);
  for (int i = 0; i < 4; i++){
  makeChildren(head->child[i]);
  }
  makeChildren(head->child[0]->child[0]);  
  growTree( head, max_level );
  writeTree(head);
  destroyTree(head);

}

void Task3(){
Node *head;
head = makeNode( 0.0,0.0, 0 );
makeChildren(head);
for (int i = 0; i < 4; i++){
makeChildren(head->child[i]);
}
makeChildren(head->child[0]->child[0]);
int max_level = 3;
growTree(head, max_level);
writeTree(head);
destroyTree(head);
}

void Task4(){
Node *head;
head = makeNode( 0.0,0.0, 0 );
makeChildren(head);
for (int i = 0; i < 4; i++){
makeChildren(head->child[i]);
}
int max_level = 10;
int choice = 1;
double tolerance = 0.2;
monitorChild(head, choice, tolerance);
writeTree(head);
destroyTree(head);
}

int main( int argc, char **argv ) {
  
    Task1();
    Task2();
    Task3();
    Task4();
    
    return 0;
  
  }