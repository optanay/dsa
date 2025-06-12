#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;  // found at index i
    }
    return -1;  // not found
}

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;
    int idx = linearSearch(arr, n, key);
    if (idx != -1)
        printf("Found %d at index %d\n", key, idx);
    else
        printf("%d not found\n", key);
    return 0;
}
