#include "dataStructures.h"
#include "string.h"
#include "bookReg.h"
#include "unity/unity.h"

void createBookTest(){
       
        bookNode* test;
        test = createBook("Book");
        TEST_ASSERT_EQUAL_STRING ("Book", test-> bookInfo);
        TEST_ASSERT_EQUAL_INT (1, test-> bookId);
        TEST_ASSERT_EQUAL_INT (0, test-> borrowedBy);
        TEST_ASSERT_EQUAL_INT (0, test-> isBorrowed);
        TEST_ASSERT_NULL (test -> next);
}
    
void removeBookTest(){
    bookNode* test;
    test = createBook("Book");
    test = removeBook(test, 1);
    TEST_ASSERT_NULL(test);
}

void checkBookDupTest(){
    bookNode* test;
    test = createBook("Book");
    TEST_ASSERT_EQUAL_INT (1, checkBookDup(test, "Book"));
    TEST_ASSERT_EQUAL_INT (0, checkBookDup(test, "BookDIF"));
    
}


void setUp(void){}
    
void tearDown(void){}
    
int main(void){
    UNITY_BEGIN();

    RUN_TEST(createBookTest);
    RUN_TEST(removeBookTest);
    RUN_TEST(checkBookDupTest);
    return UNITY_END();
}