// Postfix evaluation

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;
    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            switch (c) {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix = "23+4*";
    cout << "Postfix expression: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}