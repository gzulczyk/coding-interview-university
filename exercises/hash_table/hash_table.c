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
        result = result * 31 + k[i]; // 31 is used because we wanna spread these ASCII numbers. That 31 prime number gonna matter char order. It returns diff value when you paste a set of chars like 'abc' vs 'bca'.
    }

    return abs(result % m);
}