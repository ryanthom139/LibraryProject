#include "unity.h"

void myTest(){

}

void setUp(void){}

void tearDown(void){}

int main(void){
    UNITY_BEGIN();

    RUN_TEST(myTest);

    return UNITY_END();
}