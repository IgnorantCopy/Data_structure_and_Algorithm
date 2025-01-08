//
// Created by Ignorant on 2025/1/8.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int capacity = 0;
    cin >> n >> capacity;
    auto *ws = new int[n];
    auto *vs = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ws[i];
        cin >> vs[i];
    }
    auto **dp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new int[capacity + 1];
        for (int j = 0; j < capacity + 1; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= ws[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - ws[i - 1]] + vs[i - 1]);
            }
        }
    }
    cout << dp[n][capacity] << endl;
    for (int i = 0; i < n + 1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] ws;
    delete[] vs;
    return 0;
}
