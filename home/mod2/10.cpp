#include <deque>
#include <iostream>

struct FrontMiddleBackQueue {
    std::deque<int> front;
    std::deque<int> back;
    
    void push_front(int val) {
        front.push_front(val);
        balance();
    }
    
    void push_middle(int val) {
        front.push_back(val);
        balance();
    }
    
    void push_back(int val) {
        back.push_back(val);
        balance();
    }
    
    int pop_front() {
        int v;
        if (front.size() == 0) {
            if (back.size() == 0) {
                return -1;
            } else {
                v = back.front();
                back.pop_front();
            }
        } else {
            v = front.front();
            front.pop_front();
        }
        balance();
        return v;
    }
    
    void balance() {
        if (front.size() == back.size()) {
            return;
        }
        if (front.size() > back.size()) {
            front_to_back();
        }
        if (front.size() < back.size()) {
            back_to_front();
        }
    }
    
    void front_to_back() {
        back.push_front(front.back());
        front.pop_back();
    }
    
    void back_to_front() {
        front.push_back(back.front());
        back.pop_front();        
    }
};


int main() {
    FrontMiddleBackQueue queue;
    size_t cmd_cnt;
    std::cin >> cmd_cnt;
    char op;
    size_t index;
    for (int i = 0; i < cmd_cnt; i++) {
        std::cin >> op;
        switch (op)
        {
        case '+':
            std::cin >> index;
            queue.push_back(index);
            break;
        case '*':
            std::cin >> index;
            queue.push_middle(index);
            break;
        case '-':
            std::cout << queue.pop_front() << std::endl;
            break;
        }
    }
}