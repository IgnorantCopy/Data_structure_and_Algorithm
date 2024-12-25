//
// Created by Ignorant on 2024/12/25.
//

#include <iostream>
using namespace std;

const int INF = INT_MAX;

int main() {
    int n = 0;
    cin >> n;
    auto *a = new int[n + 1];
    a[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        int temp = 0;
        cin >> temp;
        a[i] = temp + a[i - 1];
    }
    auto **dp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < n + 1; i++) {
        dp[i][i] = 0;
    }
    for (int length = 1; length <= n; length++) {
        for (int left = 1; left + length - 1 <= n; left++) {
            int right = left + length - 1;
            for (int i = left; i < right; i++) {
                dp[left][right] = min(dp[left][right], dp[left][i] + dp[i + 1][right] + a[right] - a[left - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    for (int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] a;
    return 0;
}
