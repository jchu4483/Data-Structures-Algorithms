#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

void push(int num);
void pop();
void printStack();
bool isFull();
bool isEmpty();
void printTopElement();

int stack[MAX];
int top = -1;

int main() {
    int choice, data;
    while (1) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements in the stack\n");
        printf("5. Quit\n");
        printf("Please enter your choice: \n");
        printf("\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(data);
            break;

            case 2:
                pop();
            break;

            case 3:
                printTopElement();
            break;

            case 4:
                printStack();
            break;

            case 5:
                exit(1);
            break;

            default:
                printf("Wrong choice, please enter a choice between 1 - 5\n");
            break;
        }
    }


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