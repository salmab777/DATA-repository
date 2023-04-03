#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} List;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <num_nodes> <num_edges>", argv[0]);
        return 1;
    }

    int num_nodes = atoi(argv[1]);
    int num_edges = atoi(argv[2]);

    List* adj_list = (List*) malloc(num_nodes * sizeof(List));
    for (int i = 0; i < num_nodes; i++) {
        adj_list[i].head = NULL;
    }

    printf("Enter the edges:");
    int src, dest;
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &src, &dest);

        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->val = dest;
        new_node->next = adj_list[src].head;
        adj_list[src].head = new_node;

        new_node = (Node*) malloc(sizeof(Node));
        new_node->val = src;
        new_node->next = adj_list[dest].head;
        adj_list[dest].head = new_node;
    }

    printf("Adjacency list:");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: ", i);
        Node* current = adj_list[i].head;
        while (current != NULL) {
            printf("%d ", current->val);
            current = current->next;
        }
    }

    free(adj_list);

    return 0;
}
