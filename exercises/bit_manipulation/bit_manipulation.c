#include <stdbool.h>
#include <assert.h> 

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

int main (){
    // is_even tests
    assert(is_even(1) == false);
    assert(is_even(0) == true);
    assert(is_even(-1) == false);
    assert(is_even(-2) == true);
    assert(is_even(2) == true);

    // is_bit_set tests
    assert(is_bit_set(5,2) == true);
    assert(is_bit_set(5,1) == false);
    assert(is_bit_set(5,0) == true);
    assert(is_bit_set(0,0) == false);

    // left_shift tests
    assert(left_shift(1, 1) == 2);
    assert(left_shift(1, 3) == 8);
    assert(left_shift(3, 2) == 12);
    assert(left_shift(5,0) == 5);

    // right_shift tests
    assert(right_shift(1,1) == 0);
    assert(right_shift(8,1) == 4);
    assert(right_shift(16, 3) == 2);
    assert(right_shift(5,0) == 5);

    // set_bit tests
    assert(set_bit(5,1) == 7);
    assert(set_bit(5, 0) == 5);
    assert(set_bit(1, 3) == 9);
    assert(set_bit(0, 0) == 1);

    // clear_bit tests
    assert(clear_bit(5,2) == 1);
    assert(clear_bit(5,0) == 4);
    assert(clear_bit(5, 1) == 5);
    assert(clear_bit(0, 0) == 0);

    // flip_bit tests 
    assert(flip_bit(5,0) == 4);
    assert(flip_bit(5,2) == 1);
    assert(flip_bit(5, 1) == 7);

    // modify_bit tests
    assert(modify_bit(5, 0, 0) == 4);
    assert(modify_bit(5, 1, 1) == 7);
    assert(modify_bit(5, 0, 2) == -1);

    // is_power_of_two tests
    assert(is_power_of_two(4) == true);
    assert(is_power_of_two(1) == true);   
    assert(is_power_of_two(6) == false); 
    assert(is_power_of_two(0) == false); 

    // count_set_bits tests
    assert(count_set_bits(5) == 2);
    assert(count_set_bits(0) == 0);
    assert(count_set_bits(7) == 3);

    // swap test
    int a = 5, b = 4;
    swap(&a, &b);
    assert(a == 4);
    assert(b == 5);

    // abs_value tests
    assert(abs_value(-5) == 5);
    assert(abs_value(5) == 5);
    assert(abs_value(0) == 0);

    // count_different_bits tests 
    assert(count_different_bits(5, 4) == 1);
    assert(count_different_bits(5, 5) == 0);
    assert(count_different_bits(5, 2) == 3); 

    return 0;
}