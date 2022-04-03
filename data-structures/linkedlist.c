#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

void check_headNode_null(node *headNode);
void count_nodes(node *headNode);
void print_data(node *headNode);
void insert_at_start(node **headNode, int num);
node* insert_at_end(node *temp, int num);
void insert_at_position(node *headNode, int num, int position);
node* delete_first_node(node *headNode);
void delete_last_node(node *headNode);
void delete_at_position(node **headNode, int position);
node* delete_entire_list(node *headNode);
node* reverse_linked_list(node *headNode);
void print_nodes_recursively(node *headNode);
void insert_sorted_node(node **headNode, int num);

int main()
{
    node *headNode = NULL;
    headNode = malloc(sizeof(node));
    headNode->number = 1;
    headNode->next = NULL;

    node *temp = headNode;
    insert_sorted_node(&headNode, 2);
    insert_sorted_node(&headNode, 11);
    insert_sorted_node(&headNode, 17);
    insert_sorted_node(&headNode, 9);
    insert_sorted_node(&headNode, 9);
    insert_sorted_node(&headNode, 17);
    //temp = insert_at_end(temp, 17);
    //temp = insert_at_end(temp, 149);
    //temp = insert_at_end(temp, 378);
    //insert_at_start(&headNode, 45);
    //temp = insert_at_end(temp, 99999);
    //insert_at_position(headNode, 879, 3);
    //headNode = delete_first_node(headNode);
    //delete_last_node(headNode);
    //delete_at_position(&headNode, 4);
    //headNode = reverse_linked_list(headNode);
    //headNode = delete_entire_list(headNode);

    temp = headNode;
    count_nodes(headNode);
    print_data(headNode);
    //print_nodes_recursively(headNode);
    free(headNode);
    return 0;
}

void check_headNode_null(node *headNode) {
    if (headNode == NULL) {
        printf("Linked List empty!\n");
        exit(1);
    }
}

void count_nodes(node *headNode) {
    check_headNode_null(headNode);
    int total = 0;
    for (node *tmp = headNode; tmp != NULL; tmp = tmp->next)
    {
        total+= 1;
    }
    printf("total number of nodes: %i\n", total);
}

node* insert_at_end(node *temp, int num) {
    node *tmp = malloc(sizeof(node));
    tmp->number = num;
    tmp->next = NULL;
    temp->next = tmp;
    return tmp;
}

void insert_at_position(node *headNode, int num, int position) {
    node *ptr = headNode;
    node *tmp = malloc(sizeof(node));
    tmp->number = num;
    tmp->next = NULL;

    for (int i = 1; i < position - 1; i++) {
        ptr = ptr->next;
    }

    tmp->next = ptr->next;
    ptr->next = tmp;
}

node* delete_first_node(node *headNode) {
    if (headNode ==  NULL) {
        printf("List is already empty!\n");
    } else {
        node *tmp = malloc(sizeof(node));
        tmp = headNode;
        headNode = headNode->next;
        free(tmp);
        tmp = NULL;
    }
    return headNode;
}

void delete_last_node(node *headNode) {
    if (headNode == NULL) {
        printf("List is already empty!\n");
    } else if (headNode->next == NULL) {
        free(headNode);
        headNode = NULL;
    } else {
        node* tmp = malloc(sizeof(node));
        tmp = headNode;

        while (tmp->next->next != NULL) {
            tmp = tmp->next;
        }
        free(tmp->next);
        tmp->next = NULL;
    }
}

void delete_at_position(node **headNode, int position) {
    node *previous = *headNode;
    node *current = *headNode;

    if (*headNode == NULL) {
        printf("List is already empty!\n");
    } else if (position == 1) {
        *headNode = current->next;
        free(current);
        current = NULL;
    } else {
        for (int i = 1; i < position - 1; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

node* delete_entire_list(node *headNode) {
    node *temp = headNode;
    while (temp != NULL) {
        temp = temp->next;
        free(headNode);
        headNode = temp;
    }
    return headNode;
}

node* reverse_linked_list(node *headNode) {
    node *current = NULL, *next = NULL;
    while (headNode != NULL) {
        next = headNode->next;
        headNode->next = current;
        current = headNode;
        headNode = next;
    }
    headNode = current;
    return headNode;
}

void print_nodes_recursively(node *headNode) {
    node *temp = headNode;
    if (temp == NULL) {
        exit(0);
    }

    while (temp!= NULL) {
        printf("%d\n", temp->number);
        temp = temp->next;
        print_nodes_recursively(temp);
    }
}

void print_data(node *headNode) {
    check_headNode_null(headNode);
    struct node *ptr = NULL;
    ptr = headNode;
    while (ptr != NULL) {
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }
}

void insert_at_start(node **headNode, int num) {
    node *tmp = malloc(sizeof(node));
    tmp->number = num;
    tmp->next = *headNode;
    *headNode = tmp;
}

void insert_sorted_node(node **headNode, int num) {
    node *temp = malloc(sizeof(node));
    temp->number = num;
    temp->next = NULL;

    if ((*headNode)->number >= num || (*headNode) == NULL) {
        temp->next = (*headNode);
        (*headNode) = temp;
    } else {
        node *current = *headNode;
        // iterate through the list until node is null or number is greater than num
        while (current->next != NULL && current->next->number < num) {
            // set the current node to the next node
            current = current->next;
        }
        // Now we found the position of the nodes, so connect temp's node to the next node
        // and the current node to temp, effectively inserting it in sorted place.
        temp->next = current->next;
        current->next = temp;
    }
}