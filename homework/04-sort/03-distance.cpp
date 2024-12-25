//
// Created by Ignorant on 2024/9/24.
//

#include <iostream>
using namespace std;

bool query(string target, string src, int threshold) {
    size_t len1 = target.length();
    size_t len2 = src.length();
    auto **dp = new int*[len1 + 1];
    for (int i = 0; i <= len1; i++) {
        dp[i] = new int[len2 + 1];
        for (int j = 0; j <= len2; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < len1 + 1; i++) {
        for (int j = 0; j < len2 + 1; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (target[i - 1] == src[j - 1]) {
                dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1]);
            } else{
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }
    bool result = (dp[len1][len2] <= threshold);
    for (int i = 0; i <= len1; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return result;
}

int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    auto *str = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < m; i++) {
        int result = 0;
        string target;
        int threshold;
        cin >> target >> threshold;
        for (int j = 0; j < n; j++) {
            if (query(target, str[j], threshold)) {
                result++;
            }
        }
        cout << result << endl;
    }
    delete[] str;
    return 0;
}
