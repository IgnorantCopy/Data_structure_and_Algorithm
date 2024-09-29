//
// Created by Ignorant on 2024/9/29.
//

#include <iostream>
#include <stack>
#include <vector>
#include <valarray>
using namespace std;

class Element {
public:
    char op = 0;
    int number = 0;
    
    explicit Element(char op = 0, int number = 0) : op(op), number(number) {}
};

int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void printExpression(const vector<Element>& expression) {
    for (const auto &elem: expression) {
        if (elem.op == 0) {
            cout << elem.number << " ";
        } else {
            cout << elem.op << " ";
        }
    }
    cout << endl;
}

int main() {
    string expressionMid;
    cin >> expressionMid;
    stack<char> operators;
    vector<Element> expressionRight;
    for (const auto &key: expressionMid) {
        if (isdigit(key)) {
            expressionRight.emplace_back(0, key - '0');
        } else if (operators.empty() || key == '(') {
            operators.push(key);
        } else if (key == ')') {
            while (operators.top() != '(') {
                expressionRight.emplace_back(operators.top());
                operators.pop();
            }
            operators.pop();
        } else {
            int priority = getPriority(key);
            if (priority > getPriority(operators.top()) ||
                (priority == getPriority(operators.top()) && key == '^')) {
                operators.push(key);
            } else {
                while (!operators.empty() && priority <= getPriority(operators.top())) {
                    expressionRight.emplace_back(operators.top());
                    operators.pop();
                }
                operators.push(key);
            }
        }
    }
    while (!operators.empty()) {
        expressionRight.emplace_back(operators.top());
        operators.pop();
    }
    while (expressionRight.size() > 1) {
        printExpression(expressionRight);
        for (int i = 0; i < expressionRight.size(); i++) {
            if (expressionRight[i].op != 0) {
                char op = expressionRight[i].op;
                int num1 = expressionRight[i - 2].number;
                int num2 = expressionRight[i - 1].number;
                int result = 0;
                switch (op) {
                    case '+':
                        result = num1 + num2;
                        break;
                    case '-':
                        result = num1 - num2;
                        break;
                    case '*':
                        result = num1 * num2;
                        break;
                    case '/':
                        result = num1 / num2;
                        break;
                    case '^':
                        result = pow(num1, num2);
                        break;
                    default:
                        break;
                }
                expressionRight.erase(expressionRight.begin() + i - 2, expressionRight.begin() + i + 1);
                expressionRight.insert(expressionRight.begin() + i - 2, Element(0, result));
                break;
            }
        }
    }
    printExpression(expressionRight);
    return 0;
}
