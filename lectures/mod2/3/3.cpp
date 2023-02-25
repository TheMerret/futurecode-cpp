#include <iostream>


struct Summator {
private:
    int sum = 0;

public:
    void add(int n) {
        sum += n;
    }

    [[nodiscard]] int get() const { return sum; }
};


int main() {}
