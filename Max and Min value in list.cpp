#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int* max, int* min) {
    if (low == high) {
        *max = *min = arr[low];
    } else if (low + 1 == high) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int max1, min1, max2, min2;

        findMaxMin(arr, low, mid, &max1, &min1);
        findMaxMin(arr, mid + 1, high, &max2, &min2);

        *max = (max1 > max2)? max1 : max2;
        *min = (min1 < min2)? min1 : min2;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);

    return 0;
}
