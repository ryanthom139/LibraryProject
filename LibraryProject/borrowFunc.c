#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"
#include "borrowFunc.h"

bookNode* borrowBook(bookNode* currPtr, int bookIdValue){

    if(currPtr == NULL){
        return NULL;
    }
    if(currPtr -> bookId == bookIdValue){

        currPtr->isBorrowed = 1;
        return currPtr;
    }
    currPtr->next = borrowBook(currPtr->next, bookIdValue); 
    return currPtr;
}

bookNode* returnBook(bookNode* currPtr, int bookIdValue){
    
        if(currPtr == NULL){
            return NULL;
        }
        if(currPtr -> bookId == bookIdValue){
    
            currPtr->isBorrowed = 0;
            return currPtr;
        }
        currPtr->next = borrowBook(currPtr->next, bookIdValue); 
        return currPtr;
    }
    
    