//
// Created by Ignorant on 2024/10/10.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> asteroids;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        if (asteroids.empty()) {
            asteroids.push(num);
        } else {
            int top = asteroids.top();
            if ((num > 0 && top > 0) || (num < 0 && top < 0)) {
                asteroids.push(num);
            } else if (top < 0){
                bool isBroken = false;
                while (!asteroids.empty() && asteroids.top() < 0) {
                    if (abs(num) > abs(asteroids.top())) {
                        asteroids.pop();
                    } else if (abs(num) == abs(asteroids.top())) {
                        asteroids.pop();
                        isBroken = true;
                        break;
                    } else {
                        isBroken = true;
                        break;
                    }
                }
                if (!isBroken) {
                    asteroids.push(num);
                }
            } else if (top > 0) {
                bool isBroken = false;
                while (!asteroids.empty() && asteroids.top() > 0) {
                    if (abs(num) > abs(asteroids.top())) {
                        asteroids.pop();
                    } else if (abs(num) == abs(asteroids.top())) {
                        asteroids.pop();
                        isBroken = true;
                        break;
                    } else {
                        isBroken = true;
                        break;
                    }
                }
                if (!isBroken) {
                    asteroids.push(num);
                }
            }
        }
    }
    int size = asteroids.size();
    for (int i = 0; i < size; i++) {
        cout << asteroids.top() << " ";
        asteroids.pop();
    }
    return 0;
}
