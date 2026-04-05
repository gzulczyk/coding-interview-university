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

int vector_at(int index, struct Vector* vector_ptr) {
    if(vector_ptr -> size - 1 < index || index < 0) {
        exit(-1);
    } else {
        return *(vector_ptr -> data + index);
    }
}

void vector_resize(struct Vector* vector_ptr, int units_to_update) {
    vector_ptr -> capacity = vector_ptr -> capacity + units_to_update;
    vector_ptr -> data = (int*)realloc(vector_ptr->data, vector_ptr->capacity * sizeof(int));
}

void vector_push(int new_data, struct Vector* vector_ptr) {
    if (vector_ptr -> capacity == vector_ptr -> size) {
        vector_resize(vector_ptr, vector_ptr -> capacity);
    }

    vector_ptr -> size = vector_ptr -> size+1;
    *(vector_ptr -> data + vector_ptr -> size - 1) = new_data;
}

void vector_insert(int index, int new_data, struct Vector* vector_ptr){
    if (vector_ptr -> capacity == vector_ptr -> size) {
        vector_resize(vector_ptr, vector_ptr -> capacity);
    }

    for(int i = vector_ptr -> size; i > index+1; i--) {
        *(vector_ptr -> data + i) = *(vector_ptr -> data + i - 1);
    }

    *(vector_ptr -> data + index) = new_data;

    vector_ptr -> size = vector_ptr -> size+1;
}

void vector_prepend(int new_data, struct Vector* vector_ptr) {
    vector_insert(0, new_data, vector_ptr);
}