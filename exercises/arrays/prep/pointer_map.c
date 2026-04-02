#include <stdio.h>

int main() {
    int arr[5] = {10,20,30,40,50};
    int *p = arr;
    int arr_len = sizeof(arr) / sizeof(*(p + 0)); // total bytes / bytes per element = count
    
    // print all numbers using pointer math - *(p + i)
    for (int i=0; i<arr_len; i++){
        printf("%d\n", *(p + i));
    }

    // overwrite number using pointer math 
    *(p + 2) = 99;

    // read updated array
    printf("#################\n");

    for (int i=0; i<arr_len; i++){
        printf("%d\n", *(p + i));
    }

    return 0;
}