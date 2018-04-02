#include <stdio.h>
#include "calculator.h"

int main(void) {
    char *str = "1 + 2";
    int res = calculate(str);
    printf("%s = %d\n", str, res);
    
    return 0;
}
