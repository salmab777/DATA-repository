#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct queue {
    char* array;
    int first;
    int last;
    int size;
};

void createQueue(struct queue* q, int firstSize) {
    q->array = (char*) malloc(firstSize * sizeof(char));
    q->first = 0;
    q->last = -1;
    q->size = firstSize;
}

char push(struct queue* q, char element) {
    if (q->last == q->size - 1) {
        char* newArray = (char*) malloc(2 * q->size * sizeof(char));
        for (char i = q->first; i <= q->last; i++) {
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

char pop(struct queue* q) {
    if (q->first > q->last) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->array[q->first++];
    }
}

char peek(struct queue* q) {
    if (q->first > q->last) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->array[q->first];
    }
}

int main() {
    struct queue q;
    createQueue(&q, MAX_QUEUE_SIZE)
    
    while (q.first <= q.last) {
        printf("%d ", pop(&q));
    }

    return 0;
}
