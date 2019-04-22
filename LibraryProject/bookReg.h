void makeBookTmp(bookNode* parent, char* bookName);
bookNode* createBook(char *bookName);
void destroyTree(bookNode *head);
bookNode* removeBook (bookNode* currPtr, int bookIdValue);
void makeBook(bookNode* head, char* bookName);
void saveData(bookNode* head);
void saveOtherData();
void loadData(bookNode* head);