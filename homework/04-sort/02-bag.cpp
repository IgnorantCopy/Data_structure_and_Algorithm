//
// Created by Ignorant on 2024/12/25.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int volume = 0;
    cin >> n >> volume;
    auto *vs = new int[n];
    auto *ws = new int[n];
    auto *ss = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> vs[i] >> ws[i] >> ss[i];
    }
    auto **dp = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new int[volume + 1];
        for (int j = 0; j <= volume; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= volume; j++) {
            for (int k = 0; k <= ss[i - 1]; k++) {
                if (j >= k * vs[i - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * vs[i - 1]] + k * ws[i - 1]);
                }
            }
        }
    }
    cout << dp[n][volume] << endl;
    for (int i = 0; i < n + 1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] vs;
    delete[] ws;
    delete[] ss;
    return 0;
}
