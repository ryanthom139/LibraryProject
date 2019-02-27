#include "stdbool.h"

double dataFunction( double x, double y, int choice );
bool indicator( Node *node, double tolerance, int choice );
int addChildren(Node *node, int choice, double tolerance);
void monitorChild (Node *node, int choice, double tolerance);
