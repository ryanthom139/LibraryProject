void makeBookTmp(bookNode* parent, char* bookName);
bookNode* createBook(char *bookName);
void destroyTreeBooks(bookNode *head);
bookNode* removeBook(bookNode* currPtr, int bookIdValue);
void makeBook(bookNode* head, char* bookName);
void saveDataBooks(bookNode* head);
void saveOtherDataBooks();
bookNode* getBook(bookNode* currPtr, char bookPar[256]);
//void loadData(bookNode* head);