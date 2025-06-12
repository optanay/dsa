#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;  // found!
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int idx = binarySearch(arr, 0, n - 1, key);
    if (idx != -1)
        printf("Found %d at index %d\n", key, idx);
    else
        printf("%d not found\n", key);
    return 0;
}
