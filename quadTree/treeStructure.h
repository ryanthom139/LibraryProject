struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];  // Array of 4 pointers inside node
};
typedef struct qnode Node;  // Node is a type in the program
