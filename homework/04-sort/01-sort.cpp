//
// Created by Ignorant on 2024/12/25.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n = 0;
    int p = 0;
    int q = 0;
    cin >> n >> p >> q;
    p--;
    q--;
    auto *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int left = arr[p];
    int right = arr[q];
    int result = right - left;
    priority_queue<int> q1; // 最大堆
    priority_queue<int, vector<int>, greater<>> q2; // 最小堆
    for (int i = p; i < n; i++) {
        q1.push(arr[i]);
        left = min(left, arr[i]);
        if (q1.size() > q - p + 1) {
            q1.pop();
        }
        result = max(result, q1.top() - left);
    }
    for (int i = q; i >= 0; i--) {
        q2.push(arr[i]);
        right = max(right, arr[i]);
        if (q2.size() > q - p + 1) {
            q2.pop();
        }
        result = max(result, right - q2.top());
    }
    cout << result << endl;
    delete[] arr;
    return 0;
}
