#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"

int count = 0;
int lineTotal = 0;
int currLine = 0;
int *triggersArr = NULL;

bookNode* createBook(char *bookName){

    bookNode* newBook = (bookNode*)malloc(sizeof(bookNode) +  sizeof(bookName));

    newBook->bookInfo = strdup(bookName);
    newBook->isBorrowed = 0;
    newBook-> bookId = count;
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
        count++;
        makeBookTmp(head, bookName);
        
    }
    else{
        makeBook(head->next, bookName);
    }
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
    


bookNode* removeBook(bookNode* currPtr, int bookIdValue){

    if (currPtr == NULL){
        return NULL;
    }

    if(currPtr -> bookId == bookIdValue){

        bookNode* ptrNextTmp;
        ptrNextTmp = currPtr->next;
        free(currPtr);
        count--;

        return ptrNextTmp;
    }

    currPtr->next = removeBook(currPtr->next, bookIdValue);
    return currPtr;


}

void saveData(bookNode* head){
    if(head == NULL){
        
        saveOtherData();
        return;
    }
    else{
        FILE *file = fopen("books.csv", "a");
        fprintf(file, "%s\n", head->bookInfo);    
        saveData(head->next);
        fclose(file);
        
    }
}

void saveOtherData(){
    char numOfLine[50];
    sprintf(numOfLine, "%d", count);
    FILE *fileNum = fopen("NumOfBooks.csv", "w");
    fprintf(fileNum, "%s", numOfLine); 
    
    fclose(fileNum);
}

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

    while(triggersArr[i] == 0){

        fgets(c, 500, file);

        if ( c == NULL){
            return;
        }
    
        else if (triggersArr[i+1] != 0){
            fgets(c, 500, file);
            count++;
            head->bookInfo = strdup(c);
            head->isBorrowed = 0;
            head-> bookId = count;
            head->next = NULL;
            free(c);
            triggersArr[currLine] = 1;
            currLine++;
            loadData(head->next);
        }
    
    
    i++;
}
fclose(file);
}

