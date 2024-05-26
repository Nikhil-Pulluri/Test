#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int dp[MAX_SIZE][MAX_SIZE];

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j) {
  // Base case: If i == j, no multiplication needed
  if (i == j) {
    return 0;
  }

  // Check if the value is already calculated (memoized)
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  // Initialize minimum cost with INT_MAX
  dp[i][j] = INT_MAX;

  // Try all possible partitions
  for (int k = i; k < j; k++) {
    int cost = matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j];
    dp[i][j] = (cost < dp[i][j]) ? cost : dp[i][j]; // Update minimum cost
  }

  return dp[i][j];
}

// Driver function to find minimum number of multiplications
int MatrixChainOrder(int* p, int n) {
  int i = 1;
  int j = n - 1;

  // Initialize the DP table with -1 (not calculated)
  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      dp[i][j] = -1;
    }
  }

  return matrixChainMemoised(p, i, j);
}

int main() {
  int arr[] = {1, 2, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, n));

  return 0;
}
