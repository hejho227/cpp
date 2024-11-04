#include <iostream>
#include "stack.h"

#define TIMES 20
#define BIGNUMBER 1000

using namespace std;

int main() {
    Stack stack;

    for (int time = 0; time < TIMES; time++){
        stack.push(8);
        stack.push(21);
        stack.push(12);
        stack.push(2);
    }
    stack.pop();
    stack.push(8);
    stack.push(21);
    stack.push(12);
    stack.push(2);
    Stack copyStack(stack);
    cout << "\ncopied stack to copyStack\n\n";
    stack.pop();
    copyStack.pop();
    stack.pop();
    copyStack.pop();
    stack.pop();
    copyStack.pop();

    Stack stack2 = stack;
    cout << "\ncopied stack to stack2\n\n";
    stack.pop();
    stack.pop();
    stack.push(2);
    stack.pop();
    cout << "\nnow stack2\n\n";
    stack2.pop();
    stack2.push(12);
    stack.push(75);
    stack.push(211);
    stack = stack2;
    cout << "\ncopied stack2 to stack\n\n";
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    cout<< "\nback to stack\n\n";
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.push(1);
    stack = stack;
    cout << "\ncopied stack to stack\n\n";
    stack.pop();
}
