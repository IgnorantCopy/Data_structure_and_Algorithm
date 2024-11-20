//
// Created by Ignorant on 2024/11/15.
//

#include <iostream>
#include <vector>
using namespace std;

void snakeLevelOrder(vector<string> tree) {
    int depth = 0;
    int length = tree.size();
    int left = 0;
    int right = 0;
    while (left < length) {
        int count = 0;
        if (depth % 2 == 0) {
            for (int i = left; i <= min(length - 1, right); i++) {
                if (tree[i] != "null") {
                    cout << tree[i] << " ";
                    count++;
                }
            }
        } else {
            for (int i = min(length - 1, right); i >= left; i--) {
                if (tree[i] != "null") {
                    cout << tree[i] << " ";
                    count++;
                }
            }
        }
        if (count == 0) {
            cout << endl;
            break;
        }
        cout << endl;
        left = right + 1;
        right += 2 * count;
        depth++;
    }
}

int main() {
    vector<string> tree;
    while (cin.peek() != EOF) {
        string temp;
        cin >> temp;
        tree.push_back(temp);
    }
    snakeLevelOrder(tree);
    return 0;
}
