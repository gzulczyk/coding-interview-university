#include <stdio.h>

struct stack {
    int *stack_array;
    int size;
    int capacity;
};

struct stack *create_stack(int capacity) {
    struct stack *newStack = malloc(sizeof(struct stack));
    
    if (newStack != NULL) {
        newStack->capacity = capacity;
        newStack->size = 0;
        newStack->stack_array = malloc(capacity * sizeof(int));
        return newStack;
    }
    
    exit(-1);
}

void push(int value, struct stack *array) {
    if (array-> size < array->capacity) {
        array->stack_array[array->size] = value;
        array->size++;
        return;
    }
    exit(-1);
}