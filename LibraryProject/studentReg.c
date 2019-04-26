#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "studentReg.h"

int studCount = 0;
int nodeStudCount = 0;

studentNode* createStudent(char studentUser[50], char studentPassw[50]){
    
        studentNode* newStudent = (studentNode*)malloc(sizeof(studentNode) + sizeof(studentUser) + sizeof(studentPassw));
        newStudent-> studentId = studCount;
        strcpy(newStudent->studentUsern, studentUser);
        strcpy(newStudent->studentPass, studentPassw);
        newStudent->next = NULL;
        
        return newStudent;
    }

void makeStudentTmp(studentNode* parent, char studentUser[50], char studentPassw[50])
{
    parent->next = createStudent(studentUser, studentPassw);
    return;
}

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

int logInStudent(studentNode *head, char studentUser[50], char studentPassw[50], int nodeStudCount){
    if(head == NULL)
    { 
        return 0;
    }
    if (strcmp(head->studentUsern, studentUser) == 0 && strcmp(head->studentPass, studentPassw) == 0) 
    {
        return 1;
    }
    logInStudent(head->next, studentUser, studentPassw, nodeStudCount);
    nodeStudCount++;
    printf("%i", nodeStudCount);
}

void saveOtherDataStudents(){
    char numOfLine[50];
    sprintf(numOfLine, "%d", studCount);
    FILE *fileNum = fopen("NumOfStudents.csv", "w");
    fprintf(fileNum, "%s", numOfLine); 
    
    fclose(fileNum);
}