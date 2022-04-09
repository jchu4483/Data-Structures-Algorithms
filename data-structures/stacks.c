#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 125

void push(int num);
void pop();
void printStack();
bool isFull();
bool isEmpty();
void printTopElement();
void primeFactors(int num);
void printBinary(int num);

int stack[MAX];
int top = -1;

int main() {
    printBinary(77);
    printStack();
    return 0;
}

void push(int num) {
    if (isFull() == false) {
        top += 1;
        stack[top] = num;
    }
}

void pop() {
    if (isEmpty() == false) {
        int popped = top;
        top -= 1;
        printf("Deleted element is: %i\n", stack[popped]);
    }
}

void printStack() {
    if (isEmpty() == false) {
        for (int i = top; i >= 0; i--) {
            printf("%i ", stack[i]);
        }
    }
    printf("\n");
}

bool isFull() {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return true;
    }
    return false;
}

bool isEmpty() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return true;
    }
    return false;
}

void printTopElement() {
    printf("Top element is: %i\n", stack[top]);
}

void primeFactors(int num) {
    int i = 2;
    while (num != 1) {
        while (num % i == 0) {
            push(i);
            num = num / i;
        }
        i++;
    }
}

void printBinary(int num) {
    while (num != 0) {
        int remainder = num % 2;
        push(remainder);
        num = num / 2;
    }
}