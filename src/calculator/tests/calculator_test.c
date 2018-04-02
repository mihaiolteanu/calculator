#include "unity.h"
#include "calculator.h"

void test_adding() {
    char *str = "1 + 2";
    int res = calculate(str);
    TEST_ASSERT_EQUAL_INT(res, 3);
}

void test_substracting() {
    char *str = "10 - 2";
    int res = calculate(str);
    TEST_ASSERT_EQUAL_INT(res, 8);    
}

void test_substracting_negative() {
    char *str = "2 - 10";
    int res = calculate(str);
    TEST_ASSERT_EQUAL_INT(res, -8);
}

