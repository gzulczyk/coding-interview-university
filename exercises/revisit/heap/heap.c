#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct heap{
    int size;
    int data[MAX_SIZE];
} heap;

heap* sift_up(heap* h, int i){
    int parent = (i-1)/2;
    while (i>0){
        if(h->data[i] > h->data[parent]) {
            int temp = h->data[i];
            h->data[i] = h->data[parent];
            h->data[parent] = temp;
            i = parent;
            parent = (i-1) / 2;
        } else {
            return h;
        }
    }
    return h;
}

heap* insert(heap* h, int value){
    if (h == NULL) {
        h = malloc(sizeof(heap));
        h->size = 0;
    }  
    h->data[h->size] = value;
    h->size++;

    int i = h->size-1;
    return sift_up(h, i);
}