//
// Created by PJ Samuels on 3/29/21.
//
#include "rpn.h"
#include "errors.h"
#include "stack.h"
#include "node.h"
#include <string.h>
#include <stdio.h>

typedef enum{op,num} TYPE;
typedef struct node {
//    union{
//        double value;
//        char operator;
//    }contents;
    double value;
    TYPE type; //either operator or numerator 0 = op 1 = num
    int precedence;
    node *next;
} node;

double evaluate (char* input, int* status) {
    double number;
    *status = 0;
    char *token = strtok(input," ");
    if(token){
        if(sscanf(token,"%lf", &number) == 1) {
            //printf("number: %f\n", number);
            node* node = createNode(number,1,NULL);
            push(node);
        }
        else{
            *status = NONUM;
            return(0.0);
        }
   }
    while(token = strtok(NULL, " ")){
        if(sscanf(token,"%lf", &number) == 1) {
            //printf("number: %f\n", number);
            node* node = createNode(number,1,NULL);
            push(node);
        }
        else{
            double num1,num2,val;
            node* answer;
            node* temp;
            switch(*token) {
                case '+':
                    temp = pop();
                    val = temp->value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->value;
                    num2 = val;
                    val = (num2+num1);
                    answer = createNode(val, 1, NULL);
                    push(answer);
                    break;
                case '-':
                    temp = pop();
                    val = temp->value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->value;
                    num2 = val;
                    val = (num2-num1);
                    answer = createNode(val, 1, NULL);
                    push(answer);
                    break;
                case '*':
                    temp = pop();
                    val = temp->value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->value;
                    num2 = val;
                    val= (num2*num1);
                    answer = createNode(val, 1, NULL);
                    push(answer);
                    break;
                case '/':
                    temp = pop();
                    val = temp->value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->value;
                    num2 = val;
                    if(num1 == 0 && num2 == 0) {
                        *status = DZERO;
                        return 0.0;
                    }
                    answer = createNode((num2/num1), 1, NULL);
                    push(answer);
                    break;
                case '^':
                    temp = pop();
                    val = temp->value;
                    num1 = val;
                    temp = pop();
                    if(temp == NULL){
                        *status = ERROROPERATOR;
                        return 0.0;
                    }
                    val = temp->value;
                    num2 = val;
                    answer = createNode(pow(num2,num1), 1, NULL);
                    push(answer);
                    break;
            }
        }
    }
    node* temp = head;
    if(head == NULL || head->next != NULL ) {
        *status = ERRNULLPOINTER;
        return 0.0;
    }
    *status = SUCCESS;
    return head->value;
}
double pow(double num1, double num2){
    double ans = 1;
    for(int i = 0; i < num2;i++){
        ans*=num1;
    }
    return ans;
}