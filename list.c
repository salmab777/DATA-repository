#include <stdio.h>
#include <stdlib.h>

struct list {
    int* array;
    int size;
    int capacity;
};

void createList(struct list* l, int initialCapacity) {
    l->array = (int*) malloc(initialCapacity * sizeof(int));
    l->size = 0;
    l->capacity = initialCapacity;
}

void append(struct list* l, int element) {
    if (l->size == l->capacity) {
        int newCapacity = l->capacity * 2;
        int* newArray = (int*) malloc(newCapacity * sizeof(int));
        for (int i = 0; i < l->size; i++) {
            newArray[i] = l->array[i];
        }
        free(l->array);
        l->array = newArray;
        l->capacity = newCapacity;
    }
    l->array[l->size++] = element;
}


int main() {
    struct list mylist;
    createList(&mylist, 5);
    append(&mylist, 1);
    append(&mylist, 2);
    append(&mylist, 3);
   
    return 0;
}
