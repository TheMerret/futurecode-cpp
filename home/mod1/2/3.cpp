#include <iostream>

int main()
{
    unsigned int a, k, c;
    std::cin >> a >> k >> c;
    switch (c) {
        case 1:
            std::cout << (~((1 << k) - 1) & a);
            break;
        case 2:
            std::cout << (1 << k ^ a);
            break;
        case 3:
            std::cout << (((1 << k) - 1) & a);
            break;
    }
    std::cout << std::endl;
}
