//
// Created by Ignorant on 2025/1/8.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    string s1;
    string s2;
    cin >> s1 >> s2;
    auto **dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[m + 1];
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}
