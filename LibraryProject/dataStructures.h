typedef struct studentNode {
    
    char *studentInfo;
    int studentId;
    struct studentNode* next;
}studentNode;


typedef struct bookNode{

    int isBorrowed;
    int bookId;
    char *bookInfo;
    struct bookNode* next;
}bookNode;