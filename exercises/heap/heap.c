#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#include <assert.h>

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
    if(h == NULL) {
        h = malloc(sizeof(heap));
        if (h == NULL) {
            return NULL;
        }
        h->size = 0;
    }
    
    if(h->size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return h;
    }

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

int get_size(heap *h){
    if (h == NULL) {
        return -1;
    } else {
        return h->size;
    }
}

int is_empty(heap* h){
    if(h == NULL || h->size == 0) {
        return true;
    } else {
        return false;
    }
}

heap* sift_down(heap* h, int i){  
    while(1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i; 
        
        // Define which one is larger
        if (left < h->size && h->data[i] < h->data[left]) {
            largest = left;
        } else if(right < h->size && h->data[largest] < h->data[right]) {
            largest = right;
        }
        if (largest == i) break;

        int temp = h->data[i];
        h->data[i] = h->data[largest];
        h->data[largest] = temp;
        i = largest;
    }
    return h;
}

int extract_max(heap* h){
    if(h == NULL || h->size == 0) {
        return -1;
    } else {
        int max = get_max(h);
        h->data[0] = h->data[h->size - 1];
        h->size--;

        sift_down(h, 0);

        return max;
    }
}


void remove_heap(heap* h, int i){
    if (h == NULL || h->size == 0 || h->size <= i) {
        exit(-1);
    }
    
    h->data[i] = h->data[h->size-1];
    h->size--;

    sift_up(h, i);
    sift_down(h,i);

}

heap* heapify(heap* h){
    if(h == NULL || h->size == 0) {
        return NULL;
    } else {
        int last_non_leaf = (h->size - 1) / 2;
        while(last_non_leaf >= 0) {
            sift_down(h, last_non_leaf); 
            last_non_leaf--;
        }
    }
    return h;
}

heap* heap_sort(heap* h) {
    if(h == NULL || h->size == 0) {
        return NULL;
    } else {
        h = heapify(h);
        while(0 < h->size){
            extract_max(h);
        }
    }

    return h;
}

int main(){
   
    // Test insert 
    heap* h = NULL;
    h = insert(h, 2);
    assert(h != NULL);
    assert(get_size(h) == 1);
    assert(h->data[0] == 2);
    assert(get_max(h) == 2);

    // is_empty test
    assert(is_empty(h) == false);
    remove_heap(h, 0);
    assert(is_empty(h) == true);

    // extract_max test
    h = insert(h,20);
    assert(extract_max(h) == 20);
    assert(is_empty(h) == true);

    // heapify test
    h = malloc(sizeof(heap));
    if (h != NULL){
        h->size = 5;
        h->data[0] = 1; 
        h->data[1] = 3;
        h->data[2] = 7;
        h->data[3] = 5;
        h->data[4] = 21;
        h = heapify(h);

        assert(get_max(h) == 21);
        assert(get_size(h) == 5);
    }
    
}