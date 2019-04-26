#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"
#include "borrowFunc.h"

bookNode* borrowBook(bookNode* currPtr, studentNode* studentPtr, int bookIdValue, int nodeCount){
    studentPtr = getStudentNode(studentPtr, nodeCount);
    if(currPtr == NULL){
        return NULL;
    }
    if(currPtr -> bookId == bookIdValue){

        currPtr->isBorrowed = 1;
        printf("\n%i\n", studentPtr->studentId);
        currPtr->borrowedBy = studentPtr->studentId;
        return currPtr;
    }
    currPtr->next = borrowBook(currPtr->next, studentPtr, bookIdValue, nodeCount); 
    return currPtr;
}

bookNode* returnBook(bookNode* currPtr, studentNode* studentPtr, int bookIdValue, int nodeCount){
        studentPtr = getStudentNode(studentPtr, nodeCount);
        if(currPtr == NULL){
            return NULL;
        }
        if(currPtr -> bookId == bookIdValue && currPtr->borrowedBy == studentPtr->studentId){
    
            currPtr->isBorrowed = 0;
            currPtr->borrowedBy = 0;
            return currPtr;
        }
        currPtr->next = returnBook(currPtr->next, studentPtr, bookIdValue, nodeCount); 
        return currPtr;
    }
    
studentNode* getStudentNode(studentNode* curPtr, int nodeCount){
    if (nodeCount != 0){
        nodeCount--;
        getStudentNode(curPtr->next, nodeCount);
    }
    
    return curPtr;
}
    