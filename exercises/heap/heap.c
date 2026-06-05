#include <stdio.h>

#define MAX_SIZE 20

typedef struct heap {
    int size;
    int data[MAX_SIZE];
} heap;

heap* sift_up(heap* h, int i){
    int parent = (i - 1) / 2; // Index of its parent
    while(i > 0) { // Until you reach 1st position on array
        if (h->data[i] > h->data[parent]) {

                // Swap logic
                int temp = h->data[i];
                h->data[i] = h->data[parent];
                h->data[parent] = temp;

                // Iterate through next value
                i = parent;
                parent = (i - 1) / 2;
            } else {
                return h;
            }
    }
    return h;
}

heap* insert(heap* h, int value){
    h->data[h->size] = value;
    h->size++;

    int i = h->size-1;  // Index of newly inserted value 
    return sift_up(h, i);
    
}

int get_max(heap* h) {
    if (h != NULL && h->size > 0) {
        return h->data[0];
    }
    return -1;   
}