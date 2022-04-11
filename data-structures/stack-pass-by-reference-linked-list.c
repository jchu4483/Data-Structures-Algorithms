#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int number;
    struct node* next;
} node;

void push(int num, node** top);
int pop(node** top);
void peek(node** top);
bool isEmpty(node** top);
void printStack(node** top);

int main() {
    int data;
    node* top = NULL;
    node* top1 = NULL;
    push(1, &top);
    push(2, &top);
    push(3, &top);
    push(18, &top1);
    push(20, &top1);
    data = pop(&top);
    printStack(&top);
    printStack(&top1);
    return 0;
}

void push(int num, node** top) {
    node *temp = malloc(sizeof(node));
    if (temp == NULL) {
        printf("No memory!\n");
        exit(1);
    }
    temp->number = num;
    temp->next = *top;
    *top = temp;
}

void printStack(node** top) {
    if (isEmpty(top) == false) {
        node *temp = *top;
        while (temp != NULL) {
            printf("%i ", temp->number);
            temp = temp->next;
        }
        printf("\n");
    }
}

int pop(node** top) {
    if (isEmpty(top) == false) {
        int val;
        node* temp = *top;
        val = temp->number;
        *top = (*top)->next;
        free(temp);
        temp = NULL;
        return val;
    }
    return 1;
}

bool isEmpty(node** top) {
    if (top == NULL) {
        printf("Stack not created!\n");
        return 1;
    }
    return 0;
}

void peek(node** top) {
    if (isEmpty(top) == false) {
        printf("top element is %i \n", (*top)->number);
    }
}