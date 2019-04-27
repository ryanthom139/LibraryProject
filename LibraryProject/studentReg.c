#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "studentReg.h"

int studCount = 0;
int nodeStudCount = 0;

// Creates a student returns it as a node to the linked that contains the students
studentNode* createStudent(char studentUser[50], char studentPassw[50]){
    
    //Gives the variables in the node the correct value
    studentNode* newStudent = (studentNode*)malloc(sizeof(studentNode) + sizeof(studentUser) + sizeof(studentPassw));
    newStudent-> studentId = studCount + 1;
    strcpy(newStudent->studentUsern, studentUser);
    strcpy(newStudent->studentPass, studentPassw);
    newStudent->next = NULL;
        
    return newStudent;
}

// Used by makeBook to give nodes next value the correct value
void makeStudentTmp(studentNode* parent, char studentUser[50], char studentPassw[50])
{
    parent->next = createStudent(studentUser, studentPassw);
    return;
}

// Adds a student node to the end of the linked list
void makeStudent(studentNode* head, char studentUser[50], char studentPassw[50])
{
    if(head->next == NULL){
        studCount++;
        makeStudentTmp(head, studentUser, studentPassw);
    }
    else{
        makeStudent(head->next, studentUser, studentPassw);
    }
}

// Frees all the memory from the student linked list
void destroyTreeStudents(studentNode *head){
    
          if( head->next == NULL ){
              free(head);
          }
          else
          {
            destroyTreeStudents(head->next);
            free(head);
          }
          
      }

      
      
// A function that searches for a book from the csv file      
void saveDataStudents(studentNode* head){
    if(head == NULL){
        saveOtherDataStudents();
        return;
    }
    else{
        FILE *file = fopen("students.csv", "a");
        fprintf(file, "%s,%s\n", head->studentUsern, head->studentPass);    
        saveDataStudents(head->next);
        fclose(file);
        
    }
}

// Returns the correct pointer to the student currently logged in
int logInStudent(studentNode *head, char studentUser[50], char studentPassw[50], int *val){
    if(head == NULL)
    { 
        return 0;
    }
    if (strcmp(head->studentUsern, studentUser) == 0 && strcmp(head->studentPass, studentPassw) == 0) 
    {
        return 1;
    }
    (*val)++;
    logInStudent(head->next, studentUser, studentPassw, val);
    
}

void saveOtherDataStudents(){
    char numOfLine[50];
    sprintf(numOfLine, "%d", studCount);
    FILE *fileNum = fopen("NumOfStudents.csv", "w");
    fprintf(fileNum, "%s", numOfLine); 
    
    fclose(fileNum);
}