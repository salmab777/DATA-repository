#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void append(Node** valref, int data) {
    Node* node = createNode(data);
    if (*valref == NULL) {
        *valref = node;
        return;
    }
    Node* current = *valref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

void delete(Node** valref, int data) {
    Node* current = *valref;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                *valref = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printList(Node* val) {
    printf("[ ");
    Node* current = val;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main() {
    Node* val = NULL;
    append(&val, 1);
    append(&val, 2);
    append(&val, 3);
    append(&val, 4);
    delete(&val, 3);
    printList(val);
    return 0;
}
