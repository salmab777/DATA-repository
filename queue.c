#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct queue {
    int* array;
    int first;
    int last;
    int size;
};

void createQueue(struct queue* q, int firstSize) {
    q->array = (int*) malloc(firstSize * sizeof(int));
    q->first = 0;
    q->last = -1;
    q->size = firstSize;
}

void push(struct queue* q, int element) {
    if (q->last == q->size - 1) {
        int* newArray = (int*) malloc(2 * q->size * sizeof(int));
        for (int i = q->first; i <= q->last; i++) {
            newArray[i - q->first] = q->array[i];
        }
        free(q->array);
        q->array = newArray;
        q->last -= q->first;
        q->first = 0;
        q->size *= 2;
    }
    q->array[++q->last] = element;
}

int pop(struct queue* q) {
    if (q->first > q->last) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->array[q->first++];
    }
}

int peek(struct queue* q) {
    if (q->first > q->last) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->array[q->first];
    }
}

int main() {
    struct queue q;
    createQueue(&q, MAX_QUEUE_SIZE);
    
    for (int i = 0; i < 10; i++) {
        push(&q, i);
    }
    
    while (q.first <= q.last) {
        printf("%d ", pop(&q));
    }
    printf("\n");

    return 0;
}
