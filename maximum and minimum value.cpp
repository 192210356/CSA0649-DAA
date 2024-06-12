#include <stdio.h>

int main() {
    int arr[] = {4, 2, 7, 1, 3, 9, 6, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    return 0;
}
