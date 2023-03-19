#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

struct stack {
    int* array;
    int top;
    int size;
};

void createStack(struct stack* s, int firstSize) {
    s->array = (int*) malloc(firstSize * sizeof(int));
    s->top = -1;
    s->size = firstSize;
}

void push(struct stack* s, int element) {
    if (s->top == s->size - 1) {
        int* newArray = (int*) malloc(2 * s->size * sizeof(int));
        for (int i = 0; i < s->size; i++) {
            newArray[i] = s->array[i];
        }
        free(s->array);
        s->array = newArray;
        s->size *= 2;
    }
    s->array[++s->top] = element;
}

int pop(struct stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->array[s->top--];
    }
}
int peek(struct stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->array[s->top];
    }
}

int main() {
    struct stack s;
    createStack(&s, MAX_STACK_SIZE);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("%d\n", pop(&s));
    

    return 0;
}
