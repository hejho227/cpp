#include "stack.h"
#include <iostream>


using namespace std;

#define SIZE 2

Stack::Stack() : hight(-1), allocated(0), done(false)
{
	ptrArr = NULL;
}

Stack::~Stack()
{
	free(ptrArr);
}

void Stack::push(int pushed)
{
	if (hight == (allocated - 1)) {
		allocated += SIZE;
		int* newPtr = (int*)realloc(ptrArr, (allocated * sizeof(int)));
		if (newPtr == NULL) {
			cout << "allocation failed. exiting\n";
			free(ptrArr);
			exit(1);
		}
		ptrArr = newPtr;
	}
	hight++;
	ptrArr[hight] = pushed;
}

int Stack::pop()
{
	if (isEmpty()) {
		cout << "Nothing to pop\n";
		exit(0);
	}
	int currChar = ptrArr[hight];
	ptrArr[hight] = 0;
	hight--;
	done = true;
	cout << "Popped: " << currChar << std::endl;
	return currChar;
}

bool Stack::isEmpty() const
{
	return (hight < 0);
}
