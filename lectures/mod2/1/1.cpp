#include <iostream>
#include <string>

using namespace std;

struct my_struct {
    int a = 5;
    char b = 'a';

    my_struct(int a, char b) {
        (*this).a = a;
        this->b = b;
    }

    my_struct(int aa) {
        a = aa;
    }

    void print() {
        cout << a << " " << b << "\n";
    }
};



struct summator {
    int ans = 0;

    summator& add_1(int b) {
        ans += b;
        return *this;
    }

    summator* add_2(int b) {
        ans += b;
        return this;
    }

    summator add_3(int b) {
        ans += b;
        return *this;
    }

    int get() {
        return ans;
    }
};



struct test1 {
    test1() {
        cout << "Created test1\n";
    }
    ~test1() {
        cout << "Deleted test1\n";
    }
};

struct test2 {
    test1 a;

    test2() {
        cout << "Created test2\n";
    }
    ~test2() {
        cout << "Deleted test2\n";
    }
};



struct aboba {
    int a;
    char b; 
    long long c;
    string s;

    void print() {
        cout << a << " " << b << " " << c << " " << s << "\n";
    }
};

int main() {
    my_struct a1(6, 'b');
    a1.print();         // 6 b
    my_struct a2(6);
    a2.print();         // 6 a

    summator b1;
    b1.add_1(1).add_1(1).add_1(1);
    cout << b1.get() << "\n";   // 3

    summator* b2 = new summator;
    b2->add_2(1)->add_2(1)->add_2(1);
    cout << b2->get() << "\n";   // 3

    summator b3;
    b3.add_3(1).add_3(1).add_3(1);
    cout << b3.get() << "\n";   // 1

    test2 c;

    aboba d = {5, 'a', 1000000000000, "aviva"};
    d.print();
}