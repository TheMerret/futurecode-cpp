#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T = int>
struct my_vector {
    vector <T> s;
    int size;

    my_vector(int size) : size(size) {
        s.resize(size);
    }

    T& at(int i) {
        return s[i];
    }

    const T& at(int i) const {
        return s[i];
    }

    int get_size() const {
        return size;
    }
};


template <typename T = int>
struct summator {
    T sum = 0;

    summator<T>& add(T n) {
        sum += n;
        return *this;
    }

    T get() {
        return sum;
    }

    summator(T n) : sum(n) {}
    summator() {}

    summator<T>& operator+=(T n) {      // Переопределение операторов внутри - значит первый операнд оператора есть та переменная, от которой вызываем.
        return add(n);
    }

    summator<T> operator+(T n) {        
        summator temp = *this;          // Создаём временную переменную, чтобы не затрагивать старую.
        temp += n;
        return temp;
    }


    operator int() {
        return sum;
    }
};

template <typename T = int>             // Переопределение операторов снаружи - значит первый операнд оператора есть первый аргумент функции этой.
summator<T> operator+(const summator<T>& first, const summator<T>& second) {
    summator<T> temp = *first;          // Создаём временную переменную, чтобы не затрагивать старую.
    temp += second.get();
    return temp;
}

template <typename T = int>
ostream& operator<<(ostream& out, summator<T>& s) {
    out << s.sum;
    return out;
}



int main() {
    my_vector<int> s(5);
    s.at(3) = 7;
    cout << s.at(3) << "\n";    // 7


    summator<int> s2(1);
    s2 += 2;
    s2 = s2 + 3;
    int kk = 4;

    auto k = s2 + kk;

    cout << k << "\n";      // 10
}
