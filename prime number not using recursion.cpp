#include<stdio.h>

int isPrime(int n, int i) {
    if (i == 1) return 1;
    if (n % i == 0) return 0;
    return isPrime(n, i-1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPrime(num, num/2)) printf("%d is prime\n", num);
    else printf("%d is not prime\n", num);
    return 0;
}
