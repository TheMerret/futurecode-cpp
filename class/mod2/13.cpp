#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr;
    int cmd_cnt;
    char cmd;
    int value;
    size_t ind;
    std::cin >> cmd_cnt;
    for (int i = 0; i < cmd_cnt; i++) {
        std::cin >> cmd;
        switch (cmd)
        {
        case 'p':
            std::cin >> value;
            arr.push_back(value);
            break;
        case 'i':
            std::cin >> ind >> value;
            arr.insert(arr.begin() + ind, value);
            break;
        case '?':
            std::cin >> ind;
            std::cout << arr[ind] << std::endl;
            break;
        }
    }
}