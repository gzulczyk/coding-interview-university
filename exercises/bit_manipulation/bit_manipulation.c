#include <stdbool.h>

bool is_even(int n){
    return (n & 1) == 0;
}

bool is_bit_set(int n, int k){
    return ((n >> k) & 1) == 1;
}

int left_shift(int n, int k){
    return (n << k);
}

unsigned int right_shift(unsigned int n, int k){
    return (n >> k);
}

int set_bit(int n, int k){
    int mask = 1 << k;
    return n | mask;
}

int clear_bit(int n, int k){
    int mask = ~(1 << k);
    return n & mask; 
}

int flip_bit(int n, int k){
    int mask = (1 << k);
    return n ^ mask;
}

int modify_bit(int n, int k, int v){
    if (v == 1){
        return set_bit(n, k);
    } else if (v == 0) {
        return clear_bit(n, k);
    } else {
        return -1;
    }
}

bool is_power_of_two(int n){
    if (n == 0) {
        return false;
    }

    return (n & (n-1)) == 0; 
}

int count_set_bits(int n){
    int counter = 0;
    
    while(n != 0) {
        n = (n & (n-1));
        counter++;
    }
    
    return counter;
}

void swap(int* a, int* b){
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

int abs_value(int n){
   int mask = n >> 31;
   return (n + mask) ^ mask;
}

int count_different_bits(int a, int b){
    int counter; 
    int diffs = a ^ b;
    counter = count_set_bits(diffs);
    return counter;
}