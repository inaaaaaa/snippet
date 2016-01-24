#include <iostream>

const int MAX_N = 100;
const int MAX_W = 100;

const int n = 4;
const int w[] = {2, 1, 3, 2};
const int v[] = {3, 2, 4, 2};
const int W = 5;

int dp[MAX_N + 1][MAX_W + 1];

int solve() {
  for(int i = n - 1; i >= 0; i--) {
    for(int j = 0; j <= W; j++) {
      if(j < w[i]) {
        dp[i][j] = dp[i + 1][j];
      } else {
        dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  return dp[0][W];
}

int main() {
  std::cout << solve() << std::endl;
}
