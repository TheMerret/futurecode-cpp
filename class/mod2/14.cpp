template<typename T>
class Vector {
    T* arr;
    size_t _size = 0;
    size_t capacity = 4;

public:
    Vector() {
        arr = new T[capacity];
    };

    Vector(size_t size) {
        while (capacity < size) {
            capacity <<= 1;
        }

        arr = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            arr[i] = T();
        }
        
        _size = size;
    }

    Vector(size_t size, const T& defaultValue) {
        while (capacity < size)
        {
            capacity <<= 1;
        }

        arr = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            arr[i] = defaultValue;
        }
        
        _size = size;
    }

    Vector(const Vector& other) {
        capacity = other.capacity;
        _size = other._size;

        arr = new T[capacity];
        for (size_t i = 0; i < _size; i++) {
            arr[i] = other.arr[i];
        }
    }

    Vector& operator=(Vector& other) {
        Resize(other.Size());
        _size = other._size;
        for (size_t i = 0; i < _size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    const Vector& operator=(const Vector& other) const {
        Resize(other.Size());
        _size = other._size;
        for (size_t i = 0; i < _size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    ~Vector() {
        delete[] arr;
    }

    const T& operator[](size_t index) const {
        return arr[index];
    }

    T& operator[](size_t index) {
        return arr[index];
    }

    void PushBack(const T& element) {
        _size++;
        if (_size > capacity) {
            Resize(_size);
        }
        arr[_size - 1] = element;
    }

    void PopBack() {
        if (_size) {
            _size--;
        }
    }

    void Insert(size_t atIndex, const T& element) {
        if (atIndex >= 0 && atIndex <= _size) {
            Resize(_size + 1);
            for (size_t i = _size;i > atIndex;i--) {
                arr[i] = arr[i - 1];
            }
            arr[atIndex] = element;
        }
    }

    void Erase(size_t atIndex) {
        if (atIndex >= 0 && atIndex < _size) {
            for (size_t i = atIndex; i < _size; i++) {
                arr[i] = arr[i + 1];
            }
            _size--;
        }
    }

    void Resize(size_t newSize) {
        if (newSize > capacity) {
            while (capacity < newSize) {
                capacity <<= 1;
            }

            T* new_arr = new T[capacity];
            for (size_t i = 0; i < _size; i++) {
                new_arr[i] = arr[i];
            }

            delete[] arr;

            arr = new_arr;
        }
        _size = newSize;
    }

    [[nodiscard]] size_t Size() const { return _size; }
};
