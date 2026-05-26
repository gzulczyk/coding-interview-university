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