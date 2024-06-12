#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

int knapsack(int wt[], int val[], int W, int n) {
    int i, w;
    float vw[MAX_ITEMS];

    // Calculate value-to-weight ratio for each item
    for (i = 0; i < n; i++) {
        vw[i] = (float)val[i] / wt[i];
    }

    // Sort items based on value-to-weight ratio in descending order
    for (i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vw[i] < vw[j]) {
                int temp = vw[i];
                vw[i] = vw[j];
                vw[j] = temp;

                temp = wt[i];
                wt[i] = wt[j];
                wt[j] = temp;

                temp = val[i];
                val[i] = val[j];
                val[j] = temp;
            }
        }
    }

    // Greedy selection of items
    int total_val = 0;
    for (i = 0; i < n; i++) {
        if (W >= wt[i]) {
            W -= wt[i];
            total_val += val[i];
        } else {
            break;
        }
    }

    return total_val;
}

int main() {
    int wt[MAX_ITEMS], val[MAX_ITEMS], W, n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights and values of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);

    int max_val = knapsack(wt, val, W, n);
    printf("Maximum value that can be put in the knapsack: %d\n", max_val);

    return 0;
}
