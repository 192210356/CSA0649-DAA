#include <stdio.h>

int isPerfect(int n, int sum) {
    if (n == 0) return sum == n;
    return isPerfect(n - 1, sum + n);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPerfect(num, 1)) printf("%d is a perfect number.\n", num);
    else printf("%d is not a perfect number.\n", num);
    return 0;
}
