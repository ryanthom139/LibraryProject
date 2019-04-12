#include "stdio.h"
#include "stdlib.h"
#include "dataStructures.h"
#include "bookReg.h"
#include "string.h"



int main(){

    
    bookNode* head;
    head = createBook("");
    char bookNameTmp[] = "Hello,hfhv,uie";
    char* bookName = strdup(bookNameTmp);
    makeBook(head, bookName);

    free(bookName);
    
    destroyTree(head);
    
    return 0;
}
