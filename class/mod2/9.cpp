#include <vector>


template<typename T>
struct FlexArray {
    std::vector<T> arr;

    FlexArray() {};

    FlexArray(size_t size) {
        arr.resize(size);
    }

    const T& at(size_t index) const {
        return arr[index];
    }

    T& at(size_t index) {
        return arr[index];
    }

    [[nodiscard]] size_t Size() const { return arr.size(); }

    FlexArray<T>& operator+=(const FlexArray<T>& other) {
        size_t len = other.Size();
        for (size_t i = 0; i < len; i++) {
            arr.push_back(other.at(i));
        }
        return *this;
    }

    FlexArray<T>& operator*=(size_t n) {
        if (n > 1) {
            size_t len = Size();
            for (size_t i = 1;i < n;i++) {
                for (size_t j = 0;j < len;j++) {
                    arr.push_back(arr[j]);
                }
            }
        }
        return *this;
    }
};

template <typename T>
FlexArray<T> operator+(const FlexArray<T>& self, const FlexArray<T>& other) {
    FlexArray<T> temp = self;
    return temp += other;
}

template <typename T>
FlexArray<T> operator*(const FlexArray<T>& self, size_t n) {
    FlexArray<T> temp = self;
    return temp *= n;
}

template <typename T>
FlexArray<T> operator*(size_t n, const FlexArray<T>& other) {
    return other * n;
}
