#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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

key_value* get(hash_table* table, const char* key) {
    int index = hash(key, table->size);
    key_value* kv = table->data[index];

    while(kv) {
        if(strcmp(kv->key, key) == 0) return kv;
        kv = kv->next;
    }

    return NULL;
}

void add(hash_table* table, const char *key, const char* value){
    key_value* kv = get(table, key);

    if (kv != NULL) {
        free(kv->value);
        kv->value = strdup(value);
    }

    if (kv == NULL) {
        int index = hash(key, table->size);
        key_value* new_kv = malloc(sizeof(key_value));
        
        if(new_kv != NULL) {
        new_kv->value = strdup(value);
        new_kv->key = strdup(key);
        new_kv->next = table->data[index];
        table->data[index] = new_kv;
        } else {
            exit(-1);
        }
    }
}

bool exists(hash_table* table, const char* key) {
    return get(table,key) != NULL;
}

void remove_entry(hash_table* table, const char* key) {
    key_value* kv = get(table, key);
    
    if (kv == NULL) {
        exit(-1); // It's impossible to remove a thing that doesn't exist! 
    }

    if (kv != NULL) {
        int index = hash(key, table->size);
        
        key_value* prev = NULL;
        key_value* current = NULL;
        key_value* head = table->data[index];

        while(head) {
            if (strcmp(head->key, key) == 0) {
            current = head;
            break;
        }
            prev = head;
            head = head->next;
        }
        
        if (prev != NULL) prev->next = current->next;
        if (prev == NULL) table->data[index] = current->next;

        free(kv->value);
        free(kv->key);
        free(kv);
    }
}

void destroy_table(hash_table* table) {
    for (int i=0; i < table->size; i++) {
        key_value* current = table->data[i];
        key_value* next = NULL;
        
        while(current) {
            next = current->next;
            free(current->key);
            free(current->value);
            free(current);
            current = next;
        }   
    }

    free(table->data);
    free(table);
}

int main() {
    hash_table* table = create_table(5);
    
    add(table, "A", "Test");
    add(table, "Z", "Test2");

    printf("%d\n", exists(table, "A"));
    printf("%d\n", exists(table, "K"));

    printf("%s\n", get(table, "A")->value);
    
    add(table, "A", "Test2");
    remove_entry(table, "A");
    
    destroy_table(table);
}