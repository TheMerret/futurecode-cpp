struct ThisChecker {
    bool IsSame(const ThisChecker& other) {
        return this == &other;
    }
    [[nodiscard]] bool IsSame(const ThisChecker& other) const {
      return this == &other;
    }
};
