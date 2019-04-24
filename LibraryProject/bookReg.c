#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"

int bookCount = 0;
int lineTotal = 0;
int currLine = 0;
int saveDataCount = 0;
int *triggersArr = NULL;

bookNode* createBook(char *bookName){

    bookNode* newBook = (bookNode*)malloc(sizeof(bookNode) +  sizeof(bookName));

    newBook->bookInfo = strdup(bookName);
    newBook->isBorrowed = 0;
    newBook-> bookId = bookCount + 1;
    newBook->next = NULL;
    
    return newBook;
}

void makeBookTmp(bookNode* parent, char* bookName)
{
    parent->next = createBook(bookName);
    return;
}

void makeBook(bookNode* head, char* bookName)
{
    if(head->next == NULL){
        bookCount++;
        makeBookTmp(head, bookName);
        
    }
    else{
        makeBook(head->next, bookName);
    }
}
void destroyTreeBooks(bookNode *head){
    
          if( head->next == NULL ){
              free(head);
          }
          else
          {
            destroyTreeBooks(head->next);
            free(head);
          }
      }

bookNode* removeBook(bookNode* currPtr, int bookIdValue){

    if (currPtr == NULL){
        return NULL;
    }

    if(currPtr -> bookId == bookIdValue){

        bookNode* ptrNextTmp;
        ptrNextTmp = currPtr->next;
        free(currPtr);
        bookCount--;

        return ptrNextTmp;
    }
    currPtr->next = removeBook(currPtr->next, bookIdValue);

    return currPtr;
}

void saveDataBooks(bookNode* head){
    if (saveDataCount == 0 && head != NULL){
        FILE *file = fopen("books.csv", "w");
        fprintf(file, "%s\n", head->bookInfo);  
        saveDataCount++;
        fclose(file);
        saveDataBooks(head->next);
    }
    else{
        if(head == NULL){
            saveOtherDataBooks();
        }
        else {
            FILE *file = fopen("books.csv", "a");
            fprintf(file, "%s\n", head->bookInfo);  
            saveDataBooks(head->next);
            fclose(file);
        }
    }
    saveDataCount = 0;
}

void saveOtherDataBooks(){
    char numOfLine[50];
    sprintf(numOfLine, "%d", bookCount+1);
    FILE *fileNum = fopen("NumOfBooks.csv", "w");
    fprintf(fileNum, "%s", numOfLine); 
    
    fclose(fileNum);
}

void searchBook(bookNode* head, char* nameOfBook){
    char strTmp[strlen(nameOfBook)+1];
    char bookRead[256];

    FILE *file = fopen("books.csv", "r+");
    
    while((fgets(strTmp, 256, file)) != NULL){

        sscanf(strTmp, "%s", &bookRead);
        if(strstr(bookRead, nameOfBook) != NULL){
            head = getBook(head, nameOfBook);
            return;
        }
    }

}


bookNode* getBook(bookNode* currPtr, char bookPar[256]){
    
        if (currPtr == NULL){
            return NULL;
        }
    
        if(strstr(currPtr -> bookInfo, bookPar) != NULL){
            printf("Book Name: %s\n", currPtr->bookInfo);
            printf("Book ID: %i\n", currPtr->bookId);
            printf("Borrowed: %i\n\n", currPtr->isBorrowed);
        }
        currPtr->next = getBook(currPtr->next, bookPar);
    
        return currPtr;
    }


/*
void loadData(bookNode* head){
    
    FILE *fileNum = fopen("NumOfBooks.csv", "r");
    char tmp[] = "";
    fgets(tmp, 500, fileNum);
    lineTotal = atoi(tmp);
    
    if (count == 0){
        triggersArr = malloc(lineTotal * sizeof(int*));
       //remove("books.csv");   
    }
    
    char *c = (char*)malloc(500);
    FILE *file = fopen("books.csv", "r");
    int i = 0;

    while(triggersArr[i] == 0 ){

        fgets(c, 500, file);

        if ( c == NULL){
            return;
        }
    
        else if (triggersArr[i+1] != 1){
            fgets(c, 500, file);
            bookNode* newBook = (bookNode*)malloc(sizeof(bookNode) +  sizeof(c));
            count++;
            newBook->bookInfo = strdup(c);
            free(c);
            newBook->isBorrowed = 0;
            newBook-> bookId = count;
            newBook->next = NULL;
            triggersArr[currLine] = 1;
            currLine++;
            loadData(head->next);
        }
    i++;
}
fclose(file);
}
*/
