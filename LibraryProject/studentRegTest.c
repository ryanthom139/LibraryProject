#include "dataStructures.h"
#include "string.h"
#include "studentReg.h"
#include "unity/unity.h"

void createStudentTest(){
       
    studentNode* test;
    test = createStudent("usertest", "passtest");
    TEST_ASSERT_EQUAL_STRING ("usertest", test-> studentUsern);
    TEST_ASSERT_EQUAL_STRING ("passtest", test-> studentPass);
    TEST_ASSERT_EQUAL_INT (1, test-> studentId);
    TEST_ASSERT_NULL (test -> next);
}
    
void logInStudentTest(){
    studentNode* test;
    int value = 0;
    test = createStudent("usertest", "passtest");
    makeStudent(test, "usertest1", "passtest1");
    makeStudent(test, "usertest2", "passtest2");

    TEST_ASSERT_EQUAL_INT (1, logInStudent(test, "usertest", "passtest", &value));
    TEST_ASSERT_EQUAL_INT (0, logInStudent(test, "userWRONG", "passWRONG", &value));

}


void setUp(void){}
    
void tearDown(void){}
    
int main(void){
    UNITY_BEGIN();

    RUN_TEST(createStudentTest);
    RUN_TEST(logInStudentTest);
    return UNITY_END();
}