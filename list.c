#include <stdio.h>
#include <stdlib.h>

struct list {
    int* array;
    int len;
};
void append(struct list *l, int element) {
    
    int* newArray = (int*) malloc(sizeof(int)*(l->len+1));
    for (int i = 0; i < l->len; i++) {
        newArray[i] = l->array[i];
    }
    free(l->array);
    l->array = newArray;
    l->array[l->len]=element;
    l->len += 1;
}


int main() {
    struct list mylist;
    mylist.len=0;
    mylist.array= (int*)malloc(sizeof(int)*0);
    append(&mylist, 5);
    append(&mylist, 12);
    append(&mylist, 100);

    for(int i=0;i<mylist.len;i++)
        printf("%d",mylist.array[i]);
   
    return 0;
}
