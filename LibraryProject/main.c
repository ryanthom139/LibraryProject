#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"
#include "studentReg.h"
#include "borrowFunc.h"
#include "listFunc.h"

int main(){
    int inputL1 = 0;
    int inputL2 = 0;
    int count = 0;
    int librarianExists = 0;
    int nodeStudCount = 0;
    int studRegCount = 0;
    int bookAddCount = 0;
    char nameOfBook[100];
    char studUser[50];
    char studPass[50];
    char LibUser[50];
    char LibPass[50];
    char LibPassTest[50];
    char LibUserTest[50];
    char bookName[100];
    studentNode* studentHead;
    bookNode* bookHead;
    int i = 0;
    int trig;
    int bookID;
    while(i == 0){

    printf("Register as a student : 0\n");
    printf("Log in as a student : 1\n");
    printf("Register / log in as the librarian : 2\n");
    printf("Quit (warning all data will be lost) : 3\n\n");
   
    printf("What would you like to do?\n");
    scanf("%d", &inputL1);

    if (inputL1 == 0){
        
        printf("Please enter a username: ");
        scanf("%s", studUser);
        printf("Please enter a password: ");
        scanf("%s", studPass);
        if(studRegCount == 0){
            studentHead = createStudent(studUser, studPass);
            printf("You have registered successfully!\n\n");
            studRegCount++;
        }
        else{
            makeStudent(studentHead, studUser, studPass);
            printf("You have registered successfully!\n\n");
            studRegCount++;
        }
    }
    
    else if(inputL1 == 1){
        
        if(studRegCount == 0){
            printf("No students are registered on the system!\n\n");
        }
        else{
            printf("Please enter a username: ");
            scanf("%s", studUser);
            printf("Please enter a password: ");
            scanf("%s", studPass);
            trig = logInStudent(studentHead, studUser, studPass, nodeStudCount);
            
            if(trig == 1){
                
                printf("You have logged in successfully.\n\n");
                
                while(inputL2 != 4){
                    printf("Borrow a book (need book ID) : 0\n");
                    printf("Return a book (need book ID) : 1\n");
                    printf("List all books : 2\n");
                    printf("Search for a book : 3\n");
                    printf("Back to main menu : 4\n\n");
                    printf("What would you like to do next?\n");
                    scanf("%d", &inputL2);
                
                    if(inputL2 == 0){
                        printf("Please enter the book ID\n");
                        scanf("%d", &bookID);
                        borrowBook(bookHead, studentHead, bookID, nodeStudCount);
                    }
                    else if (inputL2 == 1){
                        printf("Please enter the book ID\n");
                        scanf("%d", &bookID);
                        returnBook(bookHead, studentHead, bookID, nodeStudCount);
                    }
                    else if(inputL2 == 2){
                        if(bookAddCount == 0){
                            printf("There are no books in the system!\n\n");
                        }
                        else{listBooks(bookHead);}
                    }
                    else if(inputL2 == 3){
                        if(bookAddCount == 0){
                            printf("There are no books in the system!\n\n");
                        }
                        else{
                            printf("Please enter a word that may be in the book title: ");
                            scanf("%s", nameOfBook);
                            searchBook(bookHead, nameOfBook);
                        }
                    }
                }
                inputL2 = 0;
            }
            else
            {
                printf("Invalid log in details! please try again.\n\n");
            }
            

        }
    }
    else if(inputL1 == 2){
        if(librarianExists == 0){
            printf("Please enter a username to register with.\n");
            scanf("%s", LibUser);
            printf("Please enter a password to register with.\n");
            scanf("%s", LibPass);
            printf("You can now log in!\n\n");
            librarianExists++;
        }
        else{
            printf("Please enter a username to log in with.\n");
            scanf("%s", LibUserTest);
            printf("Please enter a password to log in with.\n");
            scanf("%s", LibPassTest);

            if(strcmp(LibPassTest, LibPass) == 0 && strcmp(LibUserTest, LibUser) == 0){
                while(inputL2 != 4){
                printf("\nAdd a book to the library : 0\n");
                printf("Remove a book from the library : 1\n");
                printf("List all books : 2\n");
                printf("List all registered users : 3\n");
                printf("Go back to main menu : 4\n\n");
                scanf("%d", &inputL2);
                    
                if(inputL2 == 0){
                        if(bookAddCount == 0){
                            printf("\nPlease enter a book name: ");
                            scanf("%s", bookName);
                            bookHead = createBook(bookName); 
                            bookAddCount++;
                        }
                        else{
                            printf("\nPlease enter a book name: ");
                            scanf("%s", bookName);
                            makeBook(bookHead, bookName); 
                            bookAddCount++;
                        }
                    }
                else if(inputL2 == 1){
                    if(bookAddCount == 0){
                        printf("There are no books in the system!\n\n");
                    }
                    else{
                        printf("Please enter the book ID value: ");
                        scanf("%d", &bookID);
                        removeBook(bookHead, bookID); 
                        bookAddCount--;
                    }
                    
                }
                else if(inputL2 == 2){
                    if(bookAddCount == 0){
                        printf("There are no books on the system!\n");
                    }
                    else{listBooks(bookHead);}
                }
                else if(inputL2 == 3){
                    if(studRegCount == 0){
                        printf("There are no registered students!\n");
                    }
                    else{listStudents(studentHead);}
                }
            }
            inputL2 = 0;
            }
            else{printf("\nUsername or Password was incorrect!\n\n");}

           
        }
    }
    else if(inputL1 == 3){
        i = 1;
    }
}
     destroyTreeStudents(studentHead);
     destroyTreeBooks(bookHead);
    /*
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
