#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int number;
    struct node *next;
    struct node *previous;
} node;


node* addToHead(node *head, int num);
node* addToBeginning(node *head, int num);
node* addToEnd(node *head, int num);
node* addAfterPosition(node *head, int num, int position);
node* addBeforePosition(node *head, int num, int position);
node* createListFromArray(int nodeArray[], int size);
node* insertNodeinOrder(node *head, int num);
node* deleteFirstNode(node *head);
node* deleteLastNode(node *head);
node* deleteNodeAtPosition(node *head, int position);
node* reverseDoublyLinkedList(node *head);
void printDoublyLinkedList(node *head);

int main() {
    node *head = NULL;
    head = addToHead(head, 17);
    head = addToBeginning(head, 28);
    head = addToEnd(head, 36);
    head = addToEnd(head, 45);
    head = addToEnd(head, 69);
    //head = addAfterPosition(head, 20, 5);
    //head = addBeforePosition(head, 7, 1);

    //int listsize[] = {35, 49, 17, 18, 77};
    //int sizeoflist = sizeof listsize / sizeof listsize[0];
    //node *head = createListFromArray(listsize, sizeoflist);
    //head = deleteLastNode(head);
    printDoublyLinkedList(head);
    printf("\n");
    head = deleteNodeAtPosition(head, 3);
    printDoublyLinkedList(head);
    
    return 0;
}

void printDoublyLinkedList(node *head) {
    if (head == NULL) {
        printf("No list!");
        exit(1);
    }
    node* ptr = head;
    while (ptr != NULL) {
        printf("%i ", ptr->number);
        ptr = ptr->next;
    }
}

node* addToHead(node *head, int num) {
    node *temp = malloc(sizeof(node));
    temp->number = num;
    temp->next = NULL;
    temp->previous = NULL;
    head = temp;
    return head;
}

node* addToBeginning(node *head, int num) {
    node *temp = malloc(sizeof(node));
    temp->number = num;
    temp->next = head;
    temp->previous = NULL;
    head->previous = temp;
    head = temp;
    return head;
}

node* addToEnd(node *head, int num) {
    node *temp = malloc(sizeof(node));
    node *ptr = head;
    temp->number = num;
    temp->next = NULL;
    temp->previous = NULL;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->previous = ptr;
    return head;
}

node* addAfterPosition(node *head, int num, int position) {
    node *temp = malloc(sizeof(node));
    node *ptr = head;
    temp->number = num;
    temp->next = NULL;
    temp->previous = NULL;
    int counter = 1;

    while (counter != position) {
        counter++;
        ptr = ptr->next;
    }

    // Check if the position was actually inserted at end of the linked list.
    if (temp->next == NULL) {
        ptr->next = temp;
        temp->previous = ptr;
    } else {
        temp->previous = ptr;
        temp->next = ptr->next; 
        ptr->next = temp;
    }

    return head;
}

node* addBeforePosition(node *head, int num, int position) {
    node *temp = malloc(sizeof(node));
    temp->number = num;
    temp->next = NULL;
    temp->previous = NULL;
    node *ptr = head;
    int counter = 1;

    // Check if node is being added to head
    if (position == 1) {
        head = addToBeginning(head, num);
    } else {
        while (counter != position) {
            ptr = ptr->next;
            counter++;
        }
        temp->previous = ptr->previous;
        temp->next = ptr;
        ptr->previous->next = temp;
    }
    return head;
}

node* insertNodeinOrder(node *head, int num) {
    node *temp = malloc(sizeof(node));
    temp->number = num;
    temp->next = NULL;
    temp->previous = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        temp->previous = ptr;
        ptr->next = temp;
    }

    return head;
}

node* createListFromArray(int nodeArray[], int size) {
    node *head = malloc(sizeof(node));
    head = NULL;
    for (int i = 0; i < size; i++) {
        head = insertNodeinOrder(head, nodeArray[i]);
    }
    return head;
}

node* deleteFirstNode(node *head) {
    if (head == NULL) {
        printf("No list!");
        exit(1);
    } else {
        head = head->next;
        free(head->previous);
        head->previous = NULL;
    }
    return head;
}

node* deleteLastNode(node *head) {
    if (head == NULL) {
        printf("No list!");
        exit(1);
    } else {
        node *ptr = head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->previous->next = NULL;
        free(ptr);
    }
    return head;
}

node* deleteNodeAtPosition(node *head, int position) {
    if (head == NULL) {
        printf("No list!");
        exit(1);
    } else if (position == 1) {
        head = deleteFirstNode(head);
    } else {
        int counter = 1;
        node *ptr = head;
        while(counter != position) {
            ptr = ptr->next;
            counter++;
        }
        ptr->next->previous = ptr->previous;
        ptr->previous->next = ptr->next;
        free(ptr);
    }
    return head;
}

/*
node* reverseDoublyLinkedList(node *head) {
    if (head == NULL) {
        printf("No list!");
        exit(1);
    } else {
        node *ptr = head;
        node* next_ptr = ptr->next;

        while (ptr != NULL) {
            ptr->next = NULL;
            ptr->previous = next_ptr;
            next_ptr->previous = next_ptr->next;
            next_ptr = ptr;
            ptr = ptr->next;
            next_ptr = ptr->next;
        }
    }
}
*/
