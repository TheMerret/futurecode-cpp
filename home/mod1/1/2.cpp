#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::setprecision(5); // Делает 5 знаков после запятой для любого дробного числа
    std::cout << std::fixed;
    double a, b, c;
    std::cin >> a >> b >> c;
    double d = std::pow(b, 2) - 4 * a * c;
    double x1 = (-b + std::sqrt(d)) / (2 * a), x2 = (-b - std::sqrt(d)) / (2 * a);
    if (x1 > x2)
    {
        std::swap(x1, x2);
    }
    std::cout << x1 << std::endl << x2;
    return 0;
}
