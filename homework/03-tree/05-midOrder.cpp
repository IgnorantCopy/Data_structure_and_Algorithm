//
// Created by Ignorant on 2024/11/16.
//

#include <iostream>
using namespace std;

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int result = 1;
    for (int i = 0; i < s1.length() - 1; i++) {
        int index1 = s2.find(s1[i]);
        int index2 = s2.find(s1[i + 1]);
        if (index1 == index2 + 1) {
            result *= 2;
        }
    }
    cout << result << endl;
    return 0;
}
