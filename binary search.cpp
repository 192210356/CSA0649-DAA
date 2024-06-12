#include <stdio.h>

int binarySearch(int arr[], int target, int low, int high) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearch(arr, target, mid + 1, high);
    return binarySearch(arr, target, low, mid - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, target, 0, n - 1);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
