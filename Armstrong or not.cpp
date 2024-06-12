#include <stdio.h>

int countDigit(int n) {
    if (n == 0) return 0;
    return 1 + countDigit(n / 10);
}

int power(int n, int r) {
    if (r == 0) return 1;
    return n * power(n, r - 1);
}

int armstrong(int n, int temp, int sum) {
    if (n == 0) return sum;
    int digit = n % 10;
    sum += power(digit, temp);
    return armstrong(n / 10, temp, sum);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int temp = num;
    int digitCount = countDigit(num);
    int result = armstrong(num, digitCount, 0);
    if (result == temp) printf("%d is an Armstrong number.\n", num);
    else printf("%d is not an Armstrong number.\n", num);
    return 0;
}
