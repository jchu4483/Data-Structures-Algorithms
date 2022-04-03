#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct word {
    char text[256];
    struct word *next;
} word;

word* hash_table[TABLE_SIZE];

void init_hash_table();
void print_hash_table();
bool insert_word(char *text);
word* lookup_word(char *word);
word* delete_word(char *word);

int hash(char *word);

int main() {
    init_hash_table();
    insert_word("dick");
    insert_word("fun");
    insert_word("killer");
    insert_word("dad");
    insert_word("hate");
    insert_word("sexy");
    insert_word("mountain");
    insert_word("address");
    insert_word("house");
    insert_word("ass");
    insert_word("boobs");
    insert_word("makeshift");
    insert_word("fountain");
    insert_word("usually");
    insert_word("usually");
    insert_word("usually");
    insert_word("usually");
    //delete_word("hate");
    print_hash_table();
    //lookup_word("sexy");
    //lookup_word("hate");
    return 0;
}

int hash(char *word) {
    int length = strlen(word);
    int hash_sum = 0;
    for (int i = 0; i < length; i++) {
       hash_sum += word[i];
       hash_sum *= word[i];
    }
    return abs(hash_sum % TABLE_SIZE);
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
       if (hash_table[i] == NULL) {
           printf("%i - NULL\n", i);
       }
       else {
           printf("%i ", i);
           word *tmp = malloc(sizeof(word));
           tmp = hash_table[i];
           while (tmp != NULL) {
                printf("- %s ", tmp->text);
                tmp = tmp->next;
           }
           printf("\n");
       }
    }
}

bool insert_word(char *text) {
    int index = hash(text);
    word *head = malloc(sizeof(word));
    word *word = malloc(sizeof(word));
    strcpy(word->text, text);
    word->next = NULL;

    if (hash_table[index] != NULL) {
        head = hash_table[index];
        word->next = hash_table[index];
        head = word;
    }
    hash_table[index] = word;
    return true;
}

word* lookup_word(char *word) {
    int index = hash(word);
    if (hash_table[index] != NULL && strcmp(hash_table[index]->text, word) == 0) {
        printf("%s exists!\n", word);
        return hash_table[index];
    } else {
        printf("%s doesnt exist!\n", word);
        return false;
    }
}

word* delete_word(char *text) {
    int index = hash(text);
    if (hash_table[index] != NULL && strcmp(hash_table[index]->text, text) == 0) {
        word *temp= malloc(sizeof(word));
        temp = hash_table[index];
        hash_table[index] = NULL;
        return temp;
    } else {
        printf("%s doesnt exist!\n", text);
        return false;
    }
}