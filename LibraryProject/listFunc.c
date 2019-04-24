#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "listFunc.h"

void listBooks(bookNode* head){

    if(head->next == NULL){
        printf("Book Name: %s\n", head->bookInfo);
        printf("Book ID: %i\n", head->bookId);
        printf("Borrowed: %i\n\n", head->isBorrowed);
    }
    else{
        printf("Book Name: %s\n", head->bookInfo);
        printf("Book ID: %i\n", head->bookId);
        printf("Borrowed: %i\n\n", head->isBorrowed);
        listBooks(head->next);
        
    }
}

void listStudents(studentNode* head){
    
        if(head->next == NULL){
            printf("Student Name: %s\n", head->studentInfo);
            printf("Student ID: %i\n\n", head->studentId);
        }
        else{
            listStudents(head->next);
        }
    }



