#include <iostream>

int main()
{
    double a, b;
    std::cin >> a >> b;
    double eps = 0.001;
    std::cout << (bool)(std::abs(a - b) <= eps) << std::endl;
    return 0;
}
