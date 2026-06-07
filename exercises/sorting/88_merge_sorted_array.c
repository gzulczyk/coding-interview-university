void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int last_index_nums1 = m-1;
    int last_index_nums2 = n-1;

    for (int i = m + n - 1; i >= 0; i--){
        if(last_index_nums2 < 0 || (last_index_nums1 >= 0 && nums1[last_index_nums1] > nums2[last_index_nums2])) {
            nums1[i] = nums1[last_index_nums1];
            last_index_nums1--;
        } else {
                nums1[i] = nums2[last_index_nums2];
                last_index_nums2--;
        }
    }
}