#include <stdio.h>
#include "add.h"
#include "divide.h"
#include "multiply.h"
#include "substract.h"

int main(void) {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", d, b, substract(d, b));
    printf("%d * %d = %d\n", a, c, multiply(a, c));
    printf("%d / %d = %d\n", d, b, divide(d, b));

    return 0;
}
