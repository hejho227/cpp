#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

#define SIZE 2

Stack::Stack() : ptrArr(NULL), hight(-1), done(false), allocated(0){
}

Stack::~Stack() {
    if (ptrArr != NULL){
        free(this->ptrArr);
    }
}


int* Stack::allocate(){
    allocated += SIZE;
    int* newPtr = (int*)realloc(ptrArr, (allocated * sizeof(int)) );
    if (newPtr == NULL){
        printf("allocation failed. exiting\n");
        free(ptrArr);
        exit(1);
    }
    return newPtr;
}


void Stack::push(int pushed) {
    if (hight == allocated - 1) {
        ptrArr = Stack::allocate();
    }
    hight++;    
    ptrArr[hight] = pushed;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Nothing to pop\n";
        exit(1);
    }
    int currChar = ptrArr[hight];
    ptrArr[hight] = 0;
    hight--;
    done = true;
    cout << "Popped: " << currChar << std::endl;
    return currChar;
}

bool Stack::isEmpty() const {
    return (hight < 0);
}


Stack::Stack(const Stack& stack2) : ptrArr(NULL), hight(stack2.hight), done(stack2.done), allocated(stack2.allocated) {
    if (stack2.ptrArr != NULL) {
        allocated -= SIZE;
        ptrArr = Stack::allocate();
        memcpy(ptrArr, stack2.ptrArr, allocated * sizeof(int));
    }
}


Stack& Stack::operator=(const Stack& stack2) {
    if (this == &stack2) {
        return *this;  
    }

    if (stack2.hight > allocated) {
        free(ptrArr);
        ptrArr = NULL;
        allocated -= SIZE;
        ptrArr = allocate();
        hight = stack2.hight;
    }

    for (int i = 0; i < hight; ++i) {
        ptrArr[i] = stack2.ptrArr[i];
    }

    return *this;
}
