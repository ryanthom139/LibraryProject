#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "listFunc.h"

// Lists all the book nodes that have been created
void listBooks(bookNode* head){

    if(head->next == NULL){
        printf("Book Name: %s\n", head->bookInfo);
        printf("Book ID: %i\n", head->bookId);
        if(head->isBorrowed == 0){
            printf("Borrowed: No\n\n", head->isBorrowed);
        }
        else{printf("Borrowed: Yes\n\n", head->isBorrowed);}
    }
    else{
        printf("Book Name: %s\n", head->bookInfo);
        printf("Book ID: %i\n", head->bookId);
        if(head->isBorrowed == 0){
            printf("Borrowed: No\n\n", head->isBorrowed);
        }
        else{printf("Borrowed: Yes\n\n", head->isBorrowed);}
        listBooks(head->next);
        
    }
}

// Lists all the student nodes that have been created
void listStudents(studentNode* head){
    
        if(head->next == NULL){
            printf("Student Username: %s\n", head->studentUsern);
            printf("Student Password: %s\n", head->studentPass);
            printf("Student ID: %i\n\n", head->studentId);
            
        }
        else{
            printf("Student Username: %s\n", head->studentUsern);
            printf("Student Password: %s\n", head->studentPass);
            printf("Student ID: %i\n\n", head->studentId);
            listStudents(head->next);
        }
    }



