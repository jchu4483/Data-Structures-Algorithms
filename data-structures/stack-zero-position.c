#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int stack_arr[MAX];
int first = -1;

void push(int number);
void pop();
void print();
bool isEmpty();
bool isFull();
int peek();

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    isFull();
    peek();
    print();
    return 0;
}

void push(int number) {
    first += 1;
    for (int i = first; i > 0; i--) {
        stack_arr[i] = stack_arr[i - 1];
    }
    stack_arr[0] = number;
}

void print() {
    for (int i = 0; i <= first; i++) {
        printf("%i ", stack_arr[i]);
    }
}

void pop() {
    for (int i = 0; i < first; i++) {
        stack_arr[i] = stack_arr[i + 1];
    }
    first -= 1;
}

bool isEmpty() {
    if (first == -1) {
        printf("Empty!\n");
        return true;
    }
    printf("Not Empty!!\n");
    return false;
}

bool isFull() {
    if (first + 1 == MAX) {
        printf("full!\n");
        return true;
    }
    printf("not full!\n");
    return false;
}

int peek() {
    if (isEmpty() == false) {
        printf("top element of the stack is: %i\n", stack_arr[0]);
        return stack_arr[0];
    }
    return 1;
}