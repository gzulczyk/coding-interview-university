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
    return -1; // There'll be some tests later. 
}