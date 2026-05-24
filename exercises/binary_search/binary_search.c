#include <assert.h>

int binary_search(int target, int array[], int size){
    int low = 0;
    int high = size - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;
        
        if (target > array[mid]) {
            low = mid + 1;
        } else if (target < array[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }  
    }

    return -1;
}

int binary_search_recursive(int target, int array[], int low, int high) {
    if (low > high) {
        return -1; // The searched value isn't inside the array.
    }
    
    int mid = (low + high) / 2;
    
    if(target > array[mid]) {
        return binary_search_recursive(target, array, mid + 1, high);
    } else if(target < array[mid]) {
        return binary_search_recursive(target, array, low, mid - 1);
    } else {
        return mid;
    }
}

int main() {
    int size1 = 6;
    int array1[] = {0, 1, 2, 3, 7, 9};
    assert(binary_search(1, array1, size1) == 1);
    assert(binary_search(23, array1, size1) == -1);
    assert(binary_search(9, array1, size1) == 5);

    int size2 = 6;
    int array2[] = {21, 53, 60, 66, 69, 420};
    assert(binary_search_recursive(21, array2, 0, size2-1) == 0);
    assert(binary_search_recursive(543, array2, 0, size2-1) == -1);
    assert(binary_search_recursive(69, array2, 0, size2-1) == 4);

    const int size3 = 1;
    int array3[size3] = {123};
    assert(binary_search(123, array3, size3) == 0);
    assert(binary_search(1, array3, size3) == -1);
    assert(binary_search(-45, array3, size3) == -1);

    const int size4 = 5;
    int array4[size4] = {5, 10, 15, 20, 25};
    assert(binary_search(5, array4, size4) == 0);
    assert(binary_search(25, array4, size4) == 4);
    assert(binary_search(0, array4, size4) == -1);
    assert(binary_search(30, array4, size4) == -1);

    const int size5 = 1;
    int array5[size5] = {123};
    assert(binary_search_recursive(123, array5, 0, size5-1) == 0);
    assert(binary_search_recursive(1, array5, 0, size5-1) == -1);
    assert(binary_search_recursive(-45, array5, 0, size5-1) == -1);

    const int size6 = 5;
    int array6[size6] = {5, 10, 15, 20, 25};
    assert(binary_search_recursive(5, array6, 0, size6-1) == 0);
    assert(binary_search_recursive(25, array6, 0, size6-1) == 4);
    assert(binary_search_recursive(0, array6, 0, size6-1) == -1);
    assert(binary_search_recursive(30, array6, 0, size6-1) == -1);

}