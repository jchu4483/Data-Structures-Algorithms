#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

void print_tree(node *tree);
node* create_new_node(int num);
node* insert_node(node* root, int num);
bool search_node(node* root, int num);

int main() {
    node *root = NULL;

    root = insert_node(root, 15);
    root = insert_node(root, 17);
    root = insert_node(root, 19);
    root = insert_node(root, 43);
    root = insert_node(root, 25);

    print_tree(root);
    return 0;
}

void print_tree(node *tree) {
    if (tree == NULL) {
        return;
    }
    printf("%i\n", tree->number);
    print_tree(tree->left);
    print_tree(tree->right);
}

node* create_new_node(int num) {
    node* newNode = malloc(sizeof(node));
    newNode->number = num;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert_node(node* root, int num) {
    if (root == NULL) {
        root = create_new_node(num);
        return root;
    } else if (num <= root->number) {
        root->left = insert_node(root->left, num);
    } else {
        root->right = insert_node(root->right, num);
    }
    return root;
}