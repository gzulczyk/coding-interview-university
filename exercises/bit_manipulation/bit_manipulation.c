#include <stdbool.h>

bool is_even(int n){
    return (n & 1) == 0;
}

bool is_bit_set(int n, int k){
    return ((n >> k) & 1) == 1;
}