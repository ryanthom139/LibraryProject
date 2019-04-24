#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"
#include "studentReg.h"
#include "listFunc.h"
#include "borrowFunc.h"


int main(){
    
    int count = 0;    
    
    //char* studentName;
    //studentNode* head = createStudent("");
    char* bookName; 
    bookNode* head;
    bookName = "one123";
    head = createBook(bookName);
    bookName = "two";
    makeBook(head, bookName);
    bookName = "three";
    makeBook(head, bookName);
    bookName = "four";
    makeBook(head, bookName);
    //head = borrowBook(head, 2);
    //head = borrowBook(head, 3);
    //head = returnBook(head, 3);
    //head = returnBook(head, 3);
    char* nameOfBook;
    nameOfBook = "one";
    
    saveDataBooks(head);
    searchBook(head, nameOfBook);
    //listBooks(head);
    destroyTreeBooks(head);

    /*
    studentName = "ryan thompson";
    makeStudent(head, studentName);
    saveDataStudents(head);
    listStudents(head);
    destroyTreeStudents(head);
*/

    return 0;
}
