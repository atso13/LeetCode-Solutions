#include <stdio.h>

typedef struct {
    int* secret_arr;
    int actual_size;
} ArrayReader;

int reader_get(ArrayReader* reader, int index) {
    if (index < 0 || index >= reader->actual_size) {
        return 2147483647; // 2^31 - 1
    }
    return reader->secret_arr[index];
}

int search(ArrayReader* reader, int target) {
    int high = 1;
    // Exponential search to find the upper bound
    while (reader_get(reader, high) < target) {
        high = high * 2;
    }
    
    int low2 = 0;
    int high2 = high;
    
    // Standard Binary Search within the found range
    while (low2 <= high2) {
        int mid = low2 + (high2 - low2) / 2;
        int val = reader_get(reader, mid);
        
        if (val == target) {
            return mid;
        } else if (val < target) {
            low2 = mid + 1;
        } else {
            high2 = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int secret1[] = {-1, 0, 3, 5, 9, 12};
    ArrayReader reader1 = { .secret_arr = secret1, .actual_size = 6 };
    printf("Test 1 (Target 9): Result = %d (Expected: 4)\n", search(&reader1, 9));
    printf("Test 2 (Target 2): Result = %d (Expected: -1)\n", search(&reader1, 2));

    int secret2[] = {5, 10, 15, 20};
    ArrayReader reader2 = { .secret_arr = secret2, .actual_size = 4 };
    printf("Test 3 (Target 5): Result = %d (Expected: 0)\n", search(&reader2, 5));
    printf("Test 4 (Target 20): Result = %d (Expected: 3)\n", search(&reader2, 20));

    int secret3[] = {42};
    ArrayReader reader3 = { .secret_arr = secret3, .actual_size = 1 };
    printf("Test 5 (Target 42): Result = %d (Expected: 0)\n", search(&reader3, 42));
    printf("Test 6 (Target 7): Result = %d (Expected: -1)\n", search(&reader3, 7));

    return 0;
}