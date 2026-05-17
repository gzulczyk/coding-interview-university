#include <stdlib.h>
#define CAPACITY 5

int array[CAPACITY];
int front = 0;
int tail = 0;
int count = 0;

int enqueue(int value) {
    if(count != CAPACITY) {
        array[tail] = value;
        tail = (tail + 1) % CAPACITY;
        count++;
        return 0;
    } else {
        return -1;
    }
}

