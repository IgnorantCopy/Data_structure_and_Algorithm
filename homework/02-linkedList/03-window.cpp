//
// Created by Ignorant on 2024/9/29.
//

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int k = 0;
    scanf("%d%d", &n, &k);
    auto *numbers = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    auto *mins = new int[n - k + 1];
    auto *maxs = new int[n - k + 1];
    
    for (int i = 0; i < n - k + 1; i++) {
        int minimum = numbers[i + k - 1];
        int maximum = numbers[i + k - 1];
        if (i != 0) {
            if (mins[i - 1] != numbers[i - 1]) {
                minimum = min(minimum, mins[i - 1]);
            } else {
                for (int j = i; j < i + k; j++) {
                    if (numbers[j] < minimum) {
                        minimum = numbers[j];
                    }
                }
            }
            if (maxs[i - 1] != numbers[i - 1]) {
                maximum = max(maximum, maxs[i - 1]);
            } else {
                for (int j = i; j < i + k; j++) {
                    if (numbers[j] > maximum) {
                        maximum = numbers[j];
                    }
                }
            }
        } else {
            for (int j = i; j < i + k; j++) {
                if (numbers[j] < minimum) {
                    minimum = numbers[j];
                }
                if (numbers[j] > maximum) {
                    maximum = numbers[j];
                }
            }
        }
        mins[i] = minimum;
        maxs[i] = maximum;
    }
    
    for (int i = 0; i < n - k + 1; i++) {
        printf("%d ", mins[i]);
    }
    printf("\n");
    for (int i = 0; i < n - k + 1; i++) {
        printf("%d ", maxs[i]);
    }
    printf("\n");
    
    delete[] numbers;
    delete[] mins;
    delete[] maxs;
    return 0;
}
