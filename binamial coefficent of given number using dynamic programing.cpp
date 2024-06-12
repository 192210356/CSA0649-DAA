#include <stdio.h>

int binomial_coefficient(int n, int k) {
    int dp[n + 1][k + 1];

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the dp table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() {
    int n = 5;
    int k = 2;
    printf("Binomial coefficient of %d and %d is %d\n", n, k, binomial_coefficient(n, k));
    return 0;
}
