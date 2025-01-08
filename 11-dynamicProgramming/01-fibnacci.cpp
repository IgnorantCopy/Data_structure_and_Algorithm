//
// Created by Ignorant on 2025/1/2.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    auto *arr = new int[n];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[n - 1] << endl;
    delete[] arr;
    return 0;
}
