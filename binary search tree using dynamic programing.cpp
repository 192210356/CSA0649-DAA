#include <stdio.h>
#include <limits.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node* optimalBST(int keys[], int freq[], int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }
    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int cost = (r == i)? 0 : dp[i][r - 1];
                cost += (r == j)? 0 : dp[r + 1][j];
                cost += freq[r];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    Node* root = newNode(keys[0]);
    for (int i = 1; i < n; i++) {
        Node* node = newNode(keys[i]);
        Node* temp = root;
        while (temp!= NULL) {
            if (node->key < temp->key) {
                if (temp->left == NULL) {
                    temp->left = node;
                    break;
                }
                temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = node;
                    break;
                }
                temp = temp->right;
            }
        }
    }
    return root;
}

void printBST(Node* node, int indent) {
    if (node!= NULL) {
        printBST(node->right, indent + 4);
        for (int i = 0; i < indent; i++) {
            printf(" ");
        }
        printf("%d\n", node->key);
        printBST(node->left, indent + 4);
    }
}

int main() {
    int keys[] = { 10, 20, 30, 40, 50 };
    int freq[] = { 5, 10, 15, 20, 25 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* root = optimalBST(keys, freq, n);
    printf("Optimal BST:\n");
    printBST(root, 0);

    return 0;
}
