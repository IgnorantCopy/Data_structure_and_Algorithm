//
// Created by Ignorant on 2024/9/26.
//

#include <iostream>
using namespace std;

int main() {
    int arr[500] = {0};
    int len = 0;
    while (true) {
        cin >> arr[len++];
        if (cin.get() == '\n') {
            break;
        }
    }
    int left = 0;
    int right = 0;
    cin >> left >> right;
    for (int i = left - 1, j = right - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
