#include "unity/unity.h"
#include "dataStructures.h"
#include "string.h"
#include "bookReg.h"
#include "studentReg.h"
#include "borrowFunc.h"



void borrowBookTest(){
    int value = 0;
    bookNode* testBook;
    studentNode* testStudent;
    testBook = createBook("Book 1");
    testStudent = createStudent("user", "pass");
    
    logInStudent(testStudent, "user", "pass", &value);
    testBook = borrowBook(testBook, testStudent, 1, value);
    TEST_ASSERT_EQUAL_INT(1, testBook -> isBorrowed);

}

void returnBookTest(){
    int value = 0;
    bookNode* testBook;
    studentNode* testStudent;
    testBook = createBook("Book 1");
    testStudent = createStudent("user", "pass");
    
    logInStudent(testStudent, "user", "pass", &value);
    testBook = borrowBook(testBook, testStudent, 1, value);
    testBook = returnBook(testBook, testStudent, 1, value);
    TEST_ASSERT_EQUAL_INT(0, testBook -> isBorrowed);
}

void getStudentNodeTest(){
    int value = 0;
    studentNode* testStudent;
    testStudent = createStudent("user", "pass");
    makeStudent(testStudent, "user1", "pass1");
    logInStudent(testStudent, "user1", "pass1", &value);
    testStudent = getStudentNode(testStudent, value);
    TEST_ASSERT_EQUAL_INT (2, testStudent -> studentId);
}

void setUp(void){}

void tearDown(void){}

int main(void){
    UNITY_BEGIN();

    RUN_TEST(borrowBookTest);
    RUN_TEST(returnBookTest);
    RUN_TEST(getStudentNodeTest);
    return UNITY_END();
}