#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "bookReg.h"



int main(){
    
    int count = 0;    
    char* bookName; 
    bookNode* head = createBook("");

    int option;
    scanf("%i", &option);
    printf("%i", option);
    if (option == 0){
    
    bookName = "one123";
    makeBook(head, bookName);
    bookName = "two";
    makeBook(head, bookName);
    bookName = "three";
    makeBook(head, bookName);
    bookName = "four";
    makeBook(head, bookName);
    saveData(head);
    
    destroyTree(head);}

    else if (option == 1){
        loadData(head);
        printf("%s", head->next->bookInfo);
    }

    return 0;
}
