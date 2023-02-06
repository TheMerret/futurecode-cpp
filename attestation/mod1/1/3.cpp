#include <iostream>

int main() {
    int a, b;
    char op;
    int n;
    std::cin >> n;
    for (int i=0;i<n;i++) {
        std::cin >> a >> op >> b;
        switch (op) {
            case '+':
                std::cout << a + b;
                break;
            case '-':
                std::cout << a - b;
                break;
            case '*':
                std::cout << a * b;
                break;
            case '/':
                if (a % b == 0) {
                    std::cout << a / b;
                } else {
                    std::cout << "No";
                }
        }
        std::cout << std::endl;
    }
    std::cin >> a >> op >> b;
}
