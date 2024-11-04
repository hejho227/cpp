#pragma once    

class Stack {
private:
    int* ptrArr;
    int hight;
    bool done;
    int allocated;

public:
    Stack();
    ~Stack();
    int* allocate();
    void push(int pushed);
    int pop();
    bool isEmpty() const;
    Stack(const Stack& stack2);
    Stack& operator=(const Stack& stack2);
};
