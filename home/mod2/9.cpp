#include <iostream>
#include <stack>
#include <string>


unsigned int evaluate(unsigned int& num1, unsigned int& num2, const char& expression) {
    unsigned int result;
    switch (expression)
    {
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
    }
    return result;
}


int main() {
    std::string expression;
    unsigned int number = 0; 
    bool is_number = false;
    std::stack<unsigned int> stk;

    std::getline(std::cin, expression);

    for (const char &i : expression) {
        if (std::isdigit(i) != 0) {
            number *= 10;
            number += (i - '0');
            is_number = true;
        } else {
            if (i == ' ' && is_number) {
                stk.push(number);
                number = 0;
                is_number = false;
            } else if (i != ' ') {
                unsigned int num2 = stk.top();
                stk.pop();
                unsigned int num1 = stk.top();
                stk.pop();
                stk.push(evaluate(num1, num2, i));
                is_number = false;
            }
        }
    }

    std::cout << stk.top() << std::endl;
    stk.pop();
}