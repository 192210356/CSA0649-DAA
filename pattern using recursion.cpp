#include <stdio.h>

void pattern(int n, int i) {
    if (i > n) return;
    for (int j = 1; j <= i; j++) {
        printf("%d ", j);
    }
    printf("\n");
    pattern(n, i + 1);
}

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    pattern(n, 1);
    return 0;
}
