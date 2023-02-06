#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (c < a) {
        std::swap(a, c);
    }
    if (b < a) {
        std::swap(a, b);
    }
    if (c < b) {
        std::swap(c, b);
    }
    std::cout << a << " " << b << " " << c;
}
