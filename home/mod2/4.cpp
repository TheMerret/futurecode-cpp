struct ReferenceWrapper1 {
    int* ref;

    ReferenceWrapper1(int& value) {
        ref = &value;
    }

    [[nodiscard]] int& Get() const { return *ref; }
};
