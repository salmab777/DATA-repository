#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

struct stack {
    char* array;
    int top;
    int size;
};

void createStack(struct stack* s, char firstSize) {
    s->array = (char*) malloc(firstSize * sizeof(char));
    s->top = -1;
    s->size = firstSize;
}

void push(struct stack* s, char element) {
    if (s->top == s->size - 1) {
        char* newArray = (char*) malloc(2 * s->size * sizeof(char));
        for (char i = 0; i < s->size; i++) {
            newArray[i] = s->array[i];
        }
        free(s->array);
        s->array = newArray;
        s->size *= 2;
    }
    s->array[++s->top] = element;
}

char pop(struct stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->array[s->top--];
    }
}
char peek(struct stack* s) {
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

    push(&s,'M');
    push(&s, 'O');
    push(&s, 'M');
  
    printf("%d\n", pop(&s));
  

    for(char i=0 ;i<s.size;i++){
        printf("%c", s.array[i]);
    }

    return 0;
}
