//
// Created by Ignorant on 2025/1/8.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    auto *scale = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        cin >> scale[i];
    }
    auto **dp = new int *[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
        dp[i][i] = 0;
    }
    for (int d = 1; d <= n - 1; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = i + d;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j] + scale[i] * scale[k] * scale[j + 1]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    for (int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] scale;
    return 0;
}
