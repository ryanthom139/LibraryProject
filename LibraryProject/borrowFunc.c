#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"
#include "borrowFunc.h"

int getNodeCount = 0;

// Changes the value of the book node ID so it is now borrowed by a user
bookNode* borrowBook(bookNode* currPtr, studentNode* studentPtr, int bookIdValue, int nodeCount){

    if(getNodeCount == 0){
        studentPtr = getStudentNode(studentPtr, nodeCount);
        getNodeCount++;
    }
    
    if(currPtr == NULL){
        return NULL;
    }
    if(currPtr -> bookId == bookIdValue){
        if(currPtr->isBorrowed == 1){
            printf("This book is already borrowed!\n\n");
            return currPtr;
        }
        else{
            currPtr->isBorrowed = 1;
            currPtr->borrowedBy = studentPtr->studentId;
            return currPtr;
        }
    }
    
    currPtr->next = borrowBook(currPtr->next, studentPtr, bookIdValue, nodeCount); 
    getNodeCount = 0;
    
    return currPtr;
}

// Changes back the value of the book node ID so it has been returned
bookNode* returnBook(bookNode* currPtr, studentNode* studentPtr, int bookIdValue, int nodeCount){
    
    if(getNodeCount == 0){
        studentPtr = getStudentNode(studentPtr, nodeCount);
        getNodeCount++;
    }
        if(currPtr == NULL){
            return NULL;
        }
        if(currPtr -> bookId == bookIdValue && currPtr->borrowedBy == studentPtr->studentId){
    
            currPtr->isBorrowed = 0;
            currPtr->borrowedBy = 0;
            return currPtr;
        }
        else if (currPtr -> bookId = bookIdValue && currPtr->borrowedBy != studentPtr->studentId){
            printf("This isn't a book you borrowed!\n\n");
            return currPtr;
        }
        currPtr->next = returnBook(currPtr->next, studentPtr, bookIdValue, nodeCount); 
        getNodeCount = 0;
        return currPtr;
    }
    
// Gets the current student node of the student that has logged in
studentNode* getStudentNode(studentNode* curPtr, int nodeCount){
    if (nodeCount != 0){
        nodeCount--;
        getStudentNode(curPtr->next, nodeCount);
    }
    else{
        nodeCount = 0;
        return curPtr;
    }
}
    