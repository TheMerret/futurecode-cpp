struct EasyStruct {
    int x = 1;
    int y = 2;
    bool f = false;

    bool Equal() {
        f = x == y;
        return f; 
    }
};