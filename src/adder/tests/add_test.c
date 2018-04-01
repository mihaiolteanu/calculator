#include "add.h"
#include "unity.h"

void test_add_positive_numbers() {
    TEST_ASSERT_EQUAL(10, add(4, 6));
    TEST_ASSERT_EQUAL(20, add(14, 6));
}

void test_add_to_zero() {
    TEST_ASSERT_EQUAL(5, add(0, 5));
}

/* int main(void) { */
/*     int a = 2; */
/*     int b = 3; */
/*     int res; */
/*     res = add(a, b); */
/*     if (res == 5) */
/*         return 0; */
/*     return 1; */
/* } */
