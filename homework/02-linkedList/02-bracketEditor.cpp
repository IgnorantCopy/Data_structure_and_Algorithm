//
// Created by Ignorant on 2024/9/29.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    int index;
};

int main() {
    int n = 0;
    int m = 0;
    int p = 0;
    cin >> n >> m >> p;
    string brackets;
    cin >> brackets;
    auto indexes = vector<int>(n, -1);
    vector<Node> stack;
    for (int i = 0; i < n; i++) {
        Node node{};
        switch (brackets[i]) {
            case '(':
                stack.push_back({brackets[i], i});
                break;
            case ')':
                node = stack.back();
                indexes[node.index] = i;
                indexes[i] = node.index;
                stack.pop_back();
                break;
            default:
                break;
        }
    }
    
    string operations;
    cin >> operations;
    for (int i = 0; i < m; i++) {
        int left;
        int right;
        switch (operations[i]) {
            case 'L':
                p--;
                break;
            case 'R':
                p++;
                break;
            case 'D':
                if (brackets[p - 1] == '(') {
                    left = p - 1;
                    right = indexes[p - 1];
                } else {
                    left = indexes[p - 1];
                    right = p - 1;
                }
                brackets.erase(left, right - left + 1);
                indexes.erase(indexes.begin() + left, indexes.begin() + right + 1);
                p = left + 1;
                for (int j = 0; j < indexes.size(); j++) {
                    if (indexes[j] > p - 1) {
                        indexes[j] -= right - left + 1;
                    }
                }
                if (p > brackets.length()) {
                    p = brackets.length();
                }
                break;
            default:
                break;
        }
    }
    cout << brackets << endl;
    return 0;
}
