/*struct student {
    char *studentName;
    char *borrowed;
    int studentId;
};
*/

typedef struct bookNode{

    int isBorrowed;
    int bookId;
    char *bookInfo;
    struct bookNode* next;
    
    
}bookNode;