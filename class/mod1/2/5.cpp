#include <iostream>

int main()
{
    unsigned int a, k, c;
    std::cin >> a >> k >> c;
    switch (c) {
        case 1:
            std::cout << (a >> k & 1);
            break;
        case 2:
            std::cout << (1 << k | a);
            break;
        case 3:
            std::cout << (~(1 << k) & a);
            break;
    }
    std::cout << std::endl;
}
