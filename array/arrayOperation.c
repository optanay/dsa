#include <stdio.h>

#define MAX 100  

void display(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n, int pos, int value) {
    if (*n >= MAX) {
        printf("Error: array is full\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Error: invalid position\n");
        return;
    }
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Error: invalid position\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

int main() {
    int arr[MAX];
    int n = 0;  
    int i, pos, val;

    // Create: user inputs initial array
    printf("Enter initial number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    display(arr, n);

    // Insert demonstration
    printf("\nInsert operation:\n");
    printf("Enter position and value to insert: ");
    scanf("%d %d", &pos, &val);
    insert(arr, &n, pos, val);
    display(arr, n);

    // Delete demonstration
    printf("\nDelete operation:\n");
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    delete(arr, &n, pos);
    display(arr, n);

    return 0;
}
