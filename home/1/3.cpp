#include <iostream>

int main() {
    int k, n;
    std::cin >> k >> n;
    int ks = n / k;
    int os = n % k;
    int f = ks - os + k + 1;
    int b = ks + os;
    if (f < b) {
        std::cout << f;
    } else {
        std::cout << b;
    }
    return 0;
}