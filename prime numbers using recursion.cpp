#include <stdio.h>

bool isPrime(int num, int i) {
    if (num <= 2) {
        if (num == 2) return true;
        else return false;
    }
    if (num % i == 0) return false;
    if (i * i > num) return true;
    return isPrime(num, i + 1);
}

void printPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (isPrime(i, 2)) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Prime numbers up to %d: ", n);
    printPrimes(n);
    return 0;
}
