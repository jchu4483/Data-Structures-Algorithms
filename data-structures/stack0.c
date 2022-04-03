#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int stack_arr[MAX];
int first = -1;

void push(int number);
void print();

int main() {
    push(1);
    push(2);
    push(3);
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
    for (int i = first; i >= 0; i--) {
        printf("%i ", stack_arr[i]);
    }
}