#include "Ejercicio03.h"
#include <stack>


int Ejercicio03::calculate(string s)
{
    std::stack<int> numbers;
    std::stack<char> operators;
    int num = 0;

    for (char c : s) {
        if (std::isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else if (c != ' ') {
            if (c == '+' || c == '-') {
                while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
                    char op = operators.top();
                    operators.pop();
                    int operand2 = numbers.top();
                    numbers.pop();
                    int operand1 = numbers.top();
                    numbers.pop();
                    if (op == '*') {
                        numbers.push(operand1 * operand2);
                    }
                    else if (op == '/') {
                        numbers.push(operand1 / operand2);
                    }
                }
            }
            operators.push(c);
            num = 0;
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        int operand2 = numbers.top();
        numbers.pop();
        int operand1 = numbers.top();
        numbers.pop();
        if (op == '+') {
            numbers.push(operand1 + operand2);
        }
        else if (op == '-') {
            numbers.push(operand1 - operand2);
        }
    }

    return numbers.top();
}
