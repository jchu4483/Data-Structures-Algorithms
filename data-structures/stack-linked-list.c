#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int number;
    struct node* next;
} node;

node *top = NULL;

void push(int num);
void pop();
void peek();
bool isEmpty();
void printStack();

int main() {
    push(1);
    push(2);
    push(3);
    pop();
    peek();
    printStack();
    return 0;
}

void push(int num) {
    node *temp = malloc(sizeof(node));
    if (temp == NULL) {
        printf("No memory!\n");
        exit(1);
    }
    temp->number = num;
    temp->next = top;
    top = temp;
}

void printStack() {
    if (isEmpty() == false) {
        node *temp = top;
        while (temp != NULL) {
            printf("%i ", temp->number);
            temp = temp->next;
        }
        printf("\n");
    }
}

void pop() {
    if (isEmpty() == false) {
        node* temp = top;
        top = top->next;
        free(temp);
        temp = NULL;
    }
}

bool isEmpty() {
    if (top == NULL) {
        printf("Stack not created!\n");
        return true;
    }
    return false;
}

void peek() {
    if (isEmpty() == false) {
        printf("top element is %i \n", top->number);
    }
}