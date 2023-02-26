#include <algorithm>


struct BagStruct {
  size_t capacity;
  size_t balance = 0;

  BagStruct(size_t cap) { capacity = cap; }
  void Mint(size_t number) {
    if (balance + number < capacity) {
      balance += number;
    } else {
      balance = capacity;
    }
  }

  [[nodiscard]] size_t Balance() const { return balance; }

  void Transfer(BagStruct& destination) {
    size_t delta = std::min(destination.capacity, balance + destination.Balance()) - destination.Balance();
    balance -= delta;
    destination.balance += delta;
  }
  void Transfer(BagStruct* destination) {
    size_t delta = std::min((*destination).capacity, balance + (*destination).Balance()) - (*destination).Balance();
    balance -= delta;
    (*destination).balance += delta;
  }
};
