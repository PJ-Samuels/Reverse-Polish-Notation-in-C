#include <stdio.h>
#include "node.h"
#include "stack.h"
#include "rpn.h"
#include "errors.h"
typedef enum{op,num} TYPE;
typedef struct node {
    union {
        double value;
        char operator;
    } contents;
    TYPE type; //either operator or numerator 0 = op 1 = num
    int precedence;
    node *next;
} node;

int main() {
    int num = 2;
    node *nodetest = createNode(30, 1, NULL);
    push(nodetest);
    node *nodetest2 = pop();
    nodetest = createNode(2, 1, NULL);
    push(nodetest);
    node *nodetest3 = createNode(40, 1, NULL);
    push(nodetest3);
    node *head = peek();

    clearStack();
    bool ans = stackEmpty();
    char expression[] = "24.2 12 / 3 / 17 + +";
    char *input = &(expression[0]);
    int stat = 1;
    int *status = &stat;
    double result = evaluate(input, status);
    if (result == 0.0)
        errorMessage(*status);
    else {
        errorMessage(*status);
        printf("Result is %.2lf", result, "\n");
    }
    printf("\n");
//
    clearStack();
    char expression2[] = "+";
    input = &(expression2[0]);
    stat = 1;
    status = &stat;
    result = evaluate(input, status);
    if (result == 0.0)
        errorMessage(*status);
    else {
        errorMessage(*status);
        printf("Result is %.2lf", result, "\n");
    }
    printf("\n");

    clearStack();
    char expression3[] = "17 22 / 4 * 16 -";
    input = &(expression3[0]);
    stat = 1;
    status = &stat;
    result = evaluate(input, status);
    if (result == 0.0)
        errorMessage(*status);
    else {
        errorMessage(*status);
        printf("Result is %.2lf", result, "\n");
    }
    printf("\n");

    clearStack();
    char expression4[] = "2 8 ^ 3 /";
    input = &(expression4[0]);
    result = evaluate(input, status);
    if (result == 0.0)
        errorMessage(*status);
    else {
        errorMessage(*status);
        printf("Result is %.2lf", result, "\n");
    }
    printf("\n");

    clearStack();
    char expression5[] = "17 22 33 / 4 + 2";
    input = &(expression5[0]);
    result = evaluate(input, status);
    if (result == 0.0)
        errorMessage(*status);
    else {
        errorMessage(*status);
        printf("Result is %.2lf", result, "\n");
    }
    printf("\n");

    clearStack();
    char expression6[] = "";
    input = &(expression6[0]);
    result = evaluate(input, status);
    if (result == 0.0)
        errorMessage(*status);
    else {
        errorMessage(*status);
        printf("Result is %.2lf", result, "\n");
    }
    printf("\n");

    clearStack();
    char expression7[] = "8 7 + 6 - 5 / 4 * 3 ^";
    input = &(expression7[0]);
    result = evaluate(input, status);
    if (result == 0.0)
        errorMessage(*status);
    else {
        errorMessage(*status);
        printf("Result is %.2lf", result, "\n");
    }
    printf("\n");
}