#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"
#include "studentReg.h"
#include "borrowFunc.h"
#include "listFunc.h"

int main(){

    // Declarations of counters and triggers needed throughout the program
    int inputL1 = 0;
    int inputL2 = 0;
    int count = 0;
    int i = 0;
    int librarianExists = 0;
    int nodeStudCount = 0;
    int getNodeCount = 0;
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

    // Declarations of both the linked lists
    studentNode* studentHead;
    bookNode* bookHead;
    
    int trig;
    int bookID;
    while(i == 0){

    // Prints out the main manu
    printf("Register as a student : 1\n");
    printf("Log in as a student : 2\n");
    printf("Register / log in as the librarian : 3\n");
    printf("Quit (warning all data will be lost) : 4\n\n");
   
    printf("What would you like to do?\n");
    scanf("%d", &inputL1);
    
    // If statement contains code for registering a student
    if (inputL1 == 1){
        
        printf("Please enter a username: ");
        scanf("%s", studUser);
        printf("Please enter a password: ");
        scanf("%s", studPass);
        if(studRegCount == 0){ // Need to give head node a value first
            studentHead = createStudent(studUser, studPass);
            printf("You have registered successfully!\n\n");
            studRegCount++;
        }
        // Adds a node to the end of the book linked list
        else{  
            makeStudent(studentHead, studUser, studPass);
            printf("You have registered successfully!\n\n");
            studRegCount++;
        }
    }
    
    // If statement that contains code for logging the student in
    else if(inputL1 == 2){
        
        if(studRegCount == 0){ // Checks if there are any students registered
            printf("No students are registered on the system!\n\n");
        }

        else{
            printf("Please enter a username: ");
            scanf("%s", studUser);
            printf("Please enter a password: ");
            scanf("%s", studPass);
            nodeStudCount = 0;
            trig = logInStudent(studentHead, studUser, studPass, &nodeStudCount);
            
            // Contains code for if the log in details are correct
            if(trig == 1){
                
                printf("You have logged in successfully.\n\n");
                    
                while(inputL2 != 5){

                    // Prints out the users menu system
                    printf("Borrow a book (need book ID) : 1\n");
                    printf("Return a book (need book ID) : 2\n");
                    printf("List all books : 3\n");
                    printf("Search for a book : 4\n");
                    printf("Back to main menu : 5\n\n");
                    printf("What would you like to do next?\n");
                    scanf("%d", &inputL2);
                
                    // If statement contains code for borrowing a book
                    if(inputL2 == 1){
                        if(bookAddCount == 0){
                            printf("\nThere are currently no books on the system!\n\n");
                        }
                        else{
                            printf("\nPlease enter the book ID\n");
                            scanf("%d", &bookID);
                            bookHead = borrowBook(bookHead, studentHead, bookID, nodeStudCount);
                        }
                    }

                    // If statement contains code for returning a book
                    else if (inputL2 == 2){
                        if(bookAddCount == 0){
                            printf("\nThere are currently no books on the system!\n\n");
                        }
                        else{
                           printf("\nPlease enter the book ID\n");
                            scanf("%d", &bookID);
                            bookHead = returnBook(bookHead, studentHead, bookID, nodeStudCount); 
                        }
                    }

                    // If statement contains code for listing every book
                    else if(inputL2 == 3){
                        if(bookAddCount == 0){
                            printf("\nThere are no books in the system!\n\n");
                        }
                        else{listBooks(bookHead);}
                    }

                    // If statement contains code for searching for a book
                    else if(inputL2 == 4){
                        if(bookAddCount == 0){
                            printf("\nThere are no books in the system!\n\n");
                        }
                        else{
                            saveDataBooks(bookHead);
                            printf("\nPlease enter a word that may be in the book title: ");
                            scanf("%s", nameOfBook);
                            searchBook(bookHead, nameOfBook);
                        }
                    }
                }
                inputL2 = 0;
            }
            else
            {
                printf("\nInvalid log in details! please try again.\n\n");
            }
            

        }
    }

    // Contains code for registering a librarian
    else if(inputL1 == 3){
        if(librarianExists == 0){
            printf("\nPlease enter a username to register with.\n");
            scanf("%s", LibUser);
            printf("Please enter a password to register with.\n");
            scanf("%s", LibPass);
            printf("\nYou can now log in!\n\n");
            librarianExists   
            ++;
        }

        // Once they have registered they will be able to log in
        // Contains code for the librarians functionality
        else{
            printf("\nPlease enter a username to log in with.\n");
            scanf("%s", LibUserTest);
            printf("Please enter a password to log in with.\n");
            scanf("%s", LibPassTest);

            // Checks if username and password are correct
            if(strcmp(LibPassTest, LibPass) == 0 && strcmp(LibUserTest, LibUser) == 0){
                while(inputL2 != 5){

                // Librarian menu system output
                printf("\nAdd a book to the library : 1\n");
                printf("Remove a book from the library : 2\n");
                printf("List all books : 3\n");
                printf("List all registered users : 4\n");
                printf("Go back to main menu : 5\n\n");
                
                scanf("%d", &inputL2);
                getc(stdin);
                
                // If statement contains code for adding a book to the library
                if(inputL2 == 1){
                        if(bookAddCount == 0){
                            printf("\nPlease enter a book name: ");
                            fgets(bookName, sizeof(bookName),stdin);
                            if ((strlen(bookName) > 0) && (bookName[strlen (bookName) - 1] == '\n'))
                                {bookName[strlen (bookName) - 1] = '\0';}
                            bookHead = createBook(bookName); 
                            bookAddCount++;
                        }
                        else{
                            printf("\nPlease enter a book name: ");
                            fgets(bookName, sizeof(bookName),stdin);
                            if ((strlen(bookName) > 0) && (bookName[strlen (bookName) - 1] == '\n'))
                                {bookName[strlen (bookName) - 1] = '\0';}
                            if(checkBookDup(bookHead, bookName) == 1){
                                printf("\nBook with that name has already been created!\n");
                            }
                            else{
                                makeBook(bookHead, bookName); 
                                bookAddCount++;
                            }
                            
                        }
                    }
                // If statement contains code for removing a book from the library
                else if(inputL2 == 2){
                    if(bookAddCount == 0){
                        printf("\nThere are no books in the system!\n\n");
                    }
                    else{
                        printf("\nPlease enter the book ID value: ");
                        scanf("%d", &bookID);
                        if(bookIdExists(bookHead, bookID) == 1){
                            bookHead = removeBook(bookHead, bookID); 
                            bookAddCount--;
                        }
                        else{
                            printf("\nBook ID does not exist!\n");
                        }
                    }
                    
                }
                // If statement contains code for listing all the books in the library
                else if(inputL2 == 3){
                    if(bookAddCount == 0){
                        printf("\nThere are no books on the system!\n");
                    }
                    else{listBooks(bookHead);}
                }
                // If statement contains code for listing all the students on the system
                else if(inputL2 == 4){
                    if(studRegCount == 0){
                        printf("\nThere are no registered students!\n");
                    }
                    else{listStudents(studentHead);}
                }
            }
            inputL2 = 0;
            }
            else{printf("\nUsername or Password was incorrect!\n\n");}

           
        }
    }

    // Quits the program
    else if(inputL1 == 4){
        i = 1;
    }
}   
    // Checks that will free all memory allocated to the linked lists
    if(studRegCount != 0){
        destroyTreeStudents(studentHead);
    }
    if(bookAddCount != 0){
        destroyTreeBooks(bookHead);
    }

    return 0;
}
