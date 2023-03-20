#include <stdio.h>
#include <stdlib.h>

struct list {
    char* array;
    int len;
};
void append(struct list *l, char element) {
    
    char* newArray = (char*) malloc(sizeof(char)*(l->len+1));
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
    mylist.array= (char*)malloc(sizeof(char)*0);
    append(&mylist, 'm');
    append(&mylist, 'o');
    append(&mylist, 'm');

    for(char i=0;i<mylist.len;i++)
        printf("%c",mylist.array[i]);
   
    return 0;
}
