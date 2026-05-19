#include <stdlib.h>

typedef struct key_value {
    char* key;
    char* value;
    struct key_value* next;
} key_value;

typedef struct hash_table {
    key_value** data; // It points to a list of array. One * points to a first element in the array, and key_value itself to a linked list node. 
    int size;
} hash_table;

int hash(const char* k, int m) {
    int result = 0;
    for(int i=0; k[i] != '\0'; i++) {
        result = result * 31 + k[i]; // 31 is used because we wanna spread these ASCII numbers. 
                                     // That 31 prime number gonna matter char order. 
                                     // It returns diff value when you paste a set of chars like 'abc' vs 'bca'.
    }

    return abs(result % m);
}

hash_table* create_table(int size) {
    hash_table* new_hash_table = malloc(sizeof(hash_table));
    
    if (new_hash_table == 0) {
        return NULL;
    }

    new_hash_table->data = malloc(sizeof(key_value*) * size); // Allocating an array of pointers [bucket], each one is a chain head.

    if(new_hash_table->data == 0) {
        return NULL;
    }

    for(int i=0; i<size; i++) {
        new_hash_table->data[i] = NULL;
    }

    new_hash_table->size = size;

    return new_hash_table;

}