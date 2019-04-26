typedef struct studentNode {
    
    char studentUsern[50];
    char studentPass[50];
    int studentId;
    struct studentNode* next;

}studentNode;


typedef struct bookNode{

    int isBorrowed;
    int borrowedBy;
    int bookId;
    char bookInfo[100];
    struct bookNode* next;

}bookNode;