#include <iostream>
#include <stack>
#include <string>

struct Block {
    int value, localMax;
};


struct Stack {
    std::stack<Block> stk;

    void push(int n) {
    if (stk.empty()) {
        stk.push(Block{n, n});
    } else {
        if (stk.top().localMax > n) {
            stk.push(Block{n, stk.top().localMax});
        } else {
            stk.push(Block{n, n});        
        }
    }
}
    int max() {
        return stk.top().localMax;
    }
};


int main() {
    Stack stk;
    int cmd_cnt;
    int value;
    std::string cmd;
    std::cin >> cmd_cnt;
    for (int i = 0;i<cmd_cnt;i++) {
        std::cin >> cmd;
        if (cmd == "push") {
            std::cin >> value;
            stk.push(value);
        } else if (cmd == "pop") {
            stk.stk.pop();
        } else if (cmd == "max") {
            std::cout << stk.max() << std::endl;
        }
    }
}