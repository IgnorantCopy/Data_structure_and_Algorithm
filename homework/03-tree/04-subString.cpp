//
// Created by Ignorant on 2024/11/16.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n = 0;
    int m = 0;
    cin >> n;
    auto *S = new string[n];
    map<string, int> mapS;
    int numOfType = 0;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
        mapS[S[i]] = 1;
    }
    
    cin >> m;
    auto *A = new string[m];
    map<string, int> mapA;
    for (int i = 0; i < m; i++) {
        cin >> A[i];
        if (mapA.find(A[i]) == mapA.end()) {
            mapA[A[i]] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mapA.find(S[i]) != mapA.end()) {
            numOfType++;
        }
    }
    int count = 0;
    int minLen = 1e9;
    int start = -1;
    for (int left = 0, right = 0; right < m; right++) {
        string strr = A[right];
        mapA[strr]++;
        if (mapS.find(strr) != mapS.end() && mapS[strr] == mapA[strr]) {
            count++;
        }
        while (count == numOfType) {
            if (minLen > right - left + 1) {
                start = left;
                minLen = right - left + 1;
            }
            string strl = A[left];
            if (mapS.find(strl) != mapS.end() && mapA[strl] == mapS[strl]) {
                count--;
            }
            mapA[strl]--;
            left++;
        }
    }
    if (start == -1) {
        cout << 0 << endl << 0 << endl;
    } else {
        cout << numOfType << endl << minLen << endl;
    }
    delete[] S;
    delete[] A;
    return 0;
}
