#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "dataStructures.h"
#include "studentReg.h"

int studCount = 0;

studentNode* createStudent(char *studentName){
    
        studentNode* newStudent = (studentNode*)malloc(sizeof(studentNode) +  sizeof(studentName));
        newStudent->studentInfo = strdup(studentName);
        newStudent-> studentId = studCount;
        newStudent->next = NULL;
        
        return newStudent;
    }

void makeStudentTmp(studentNode* parent, char* studentName)
{
    parent->next = createStudent(studentName);
    return;
}

void makeStudent(studentNode* head, char* studentName)
{
    if(head->next == NULL){
        studCount++;
        makeStudentTmp(head, studentName);
        
    }
    else{
        makeStudent(head->next, studentName);
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
        fprintf(file, "%s\n", head->studentInfo);    
        saveDataStudents(head->next);
        fclose(file);
        
    }
}

void saveOtherDataStudents(){
    char numOfLine[50];
    sprintf(numOfLine, "%d", studCount);
    FILE *fileNum = fopen("NumOfStudents.csv", "w");
    fprintf(fileNum, "%s", numOfLine); 
    
    fclose(fileNum);
}