#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "add.h"
#include "divide.h"
#include "multiply.h"
#include "substract.h"

typedef enum {
    add_op,
    substract_op,
    multiply_op,
    divide_op,
    undefined_op,
} operation;

typedef struct {
    int op_1;
    int op_2;
    operation op;
} expr;

/* Accept expressions of the form: "1 + 4" */
static expr *expr_from_str(char *str) {
    expr *e = malloc(sizeof(expr));
    char *tk;
    /* String has to be modifiable for strtok to work. */
    char *str_cpy = malloc(strlen(str));
    strcpy(str_cpy, str);
    
    tk = strtok(str_cpy, " ");
    e->op_1 = atoi(tk);
    tk = strtok(NULL, " ");
    if (strcmp(tk, "+") == 0)
        e->op = add_op;
    else if (strcmp(tk, "-") == 0)
        e->op = substract_op;
    else if (strcmp(tk, "*") == 0)
        e->op = multiply_op;
    else if (strcmp(tk, "/") == 0)
        e->op = divide_op;
    else
        e->op = undefined_op;
    tk = strtok(NULL, " ");
    e->op_2 = atoi(tk);
    return e;
}

int calculate(char *str) {
    expr *e = expr_from_str(str);
    int res;
    switch(e->op)
    {
    case add_op:
        res = add(e->op_1, e->op_2);
        break;
    case substract_op:
        res = substract(e->op_1, e->op_2);
        break;
    case multiply_op:
        res = multiply(e->op_1, e->op_2);
        break;
    case divide_op:
        res = divide(e->op_1, e->op_2);
        break;
    default:                    /* Undefined operation */
        res = 0;
        break;
    }
    free(e);
    return res;
}
