template<typename T>
T* IncreaseSize(T*& buffer, size_t oldSize, size_t newSize) {
    T* new_arr = new T[newSize];
    for (size_t i = 0; i < oldSize; i++) {
        new_arr[i] = buffer[i];
    }

    delete[] buffer;
    buffer = new_arr;

    return new_arr;
}
