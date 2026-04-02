#include <stdbool.h>

struct Vector{
    int *data;
    int size;
    int capacity;
};

struct Vector* vector_new(int capacity){
    struct Vector *vector_ptr = (struct Vector *)malloc(sizeof(struct Vector));
    int true_capacity = 16;

    while (capacity>true_capacity){
        true_capacity *= 2;
    }
    
    int *data_ptr = (int*)malloc(true_capacity * sizeof(int));

    vector_ptr -> size = 0;
    vector_ptr -> capacity = true_capacity;
    vector_ptr -> data = data_ptr;

    return vector_ptr;
}

int vector_size(struct Vector* vector_ptr) {
    return vector_ptr -> size; 
}

int vector_capacity(struct Vector* vector_ptr) {
    return vector_ptr -> capacity;
}

int vector_is_empty(struct Vector* vector_ptr) {
    if (vector_ptr -> size == 0) {
        return true;
    } else {
        return false;
    }
}
