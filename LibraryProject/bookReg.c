#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"



bookNode* createBook(char *bookName){

    bookNode* newBook = (bookNode*)malloc(sizeof(bookNode) +  sizeof(bookName)+1);

    
    newBook->bookInfo = strdup(bookName);
    newBook->isBorrowed = 0;
    newBook->next = NULL;
    newBook-> bookId++;
    FILE *file = fopen("books.csv", "a");
    fprintf(file, "%s\n", &newBook->bookInfo);
    fclose(file);
    return newBook;
}

void makeBook(bookNode* parent, char* bookName)
{
    int isBorrowedTmp = parent->isBorrowed;
    char* bookInfoTmp = strdup(parent->bookInfo);
    int bookIdTmp = parent->bookId;
    parent->next = createBook(bookInfoTmp);
    free(bookInfoTmp);
    return;
}

void destroyTree(bookNode *head){
    
          if( head->next == NULL ){
              free(head);
          }
          else
          {
            destroyTree(head->next);
                  
            free(head);
          }
          
      }
    

/*
void removeBook(int valueTmp){
    
    listDelete(bookNode_t, valueTmp);
    

}

bookNode_t *listDelete(bookNode_t *current, bookNode_t value){
    if (current == NULL){
        return NULL;
    }
    
    if(current->bookId == value){
    bookNode_t *tmpNext;
    
    tmpNext = current->next;

    free(current);
    return tmpNext;
    }

    current->next = listDelete(current->next, value);
    return current;
}
*/
