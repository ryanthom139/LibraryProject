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

// Creates a book returns it as a node to the linked that contains the books
bookNode* createBook(char bookName[100]){

    bookNode* newBook = (bookNode*)malloc(sizeof(bookNode) +  sizeof(bookName)); // Allocates memory space for the node

    //Gives the variables in the node the correct value
    strcpy(newBook->bookInfo, bookName); 
    newBook->isBorrowed = 0;
    newBook-> bookId = bookCount + 1;
    newBook->next = NULL;
    newBook->borrowedBy = 0;
    
    return newBook;
}

// Used by makeBook to give nodes next value the correct value
void makeBookTmp(bookNode* parent, char bookName[100])
{
    parent->next = createBook(bookName);
    return;
}

// Adds a book node to the end of the linked list
void makeBook(bookNode* head, char bookName[100])
{
    if(head->next == NULL){
        bookCount++;
        makeBookTmp(head, bookName);
        
    }
    else{
        makeBook(head->next, bookName);
    }
}

// Frees all the memory from the book linked list
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

// Removes a node from the linked list depending on the book ID added
bookNode* removeBook(bookNode* currPtr, int bookIdValue){

    if (currPtr == NULL){
        return NULL;
    }
    if(currPtr -> bookId == bookIdValue){

        bookNode* ptrNextTmp;
        ptrNextTmp = currPtr->next;
        free(currPtr);
        return ptrNextTmp;
    }

    currPtr->next = removeBook(currPtr->next, bookIdValue);
    return currPtr;
}

// Saves the book data to a csv file so i can use the search function
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

// A function that searches for a book from the csv file
void searchBook(bookNode* head, char nameOfBook[100]){
    char strTmp[100];
    char bookRead[100];

    FILE *file = fopen("books.csv", "r+");
    
    while((fgets(strTmp, 100, file)) != NULL){

        sscanf(strTmp, "%s", &bookRead);
        if(strstr(bookRead, nameOfBook) != NULL){
            head = getBook(head, nameOfBook);
            return;
        }
    }

}

// Checks each book to see if it is in the csv file whilst comparing it to the word searched
bookNode* getBook(bookNode* currPtr, char bookPar[100]){
    
        if (currPtr == NULL){
            return NULL;
        }
    
        if(strstr(currPtr -> bookInfo, bookPar) != NULL){
            printf("Book Name: %s\n", currPtr->bookInfo);
            printf("Book ID: %i\n", currPtr->bookId);
            if(currPtr->isBorrowed == 0){
                printf("Borrowed: No\n\n", currPtr->isBorrowed);
            }
            else{printf("Borrowed: Yes\n\n", currPtr->isBorrowed);}
        }
        currPtr->next = getBook(currPtr->next, bookPar);
    
        return currPtr;
    }

// Checks if there is a duplicate book and returns 1 or 0 depending on the result
int checkBookDup(bookNode* currPtr, char bookPar[100]){

        if(currPtr == NULL){
            return 0;
        }
        if(strcmp(currPtr -> bookInfo, bookPar) == 0){
            return 1;
        }
        else if (currPtr->next == NULL){
            return 0;
        }
        
        checkBookDup(currPtr->next, bookPar);    
    }

int bookIdExists(bookNode* currPtr, int Id){
    if(currPtr == NULL){
        return 0;
    }
    if(currPtr->bookId == Id){
        return 1;
    }
    bookIdExists(currPtr->next, Id);
}


