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

int main() {
    return -1; // There'll be some tests later. 
}