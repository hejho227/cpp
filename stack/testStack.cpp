#include "stack.h"
#include <iostream>

#define TIMES 20
#define BIGNUMBER 10000

using namespace std;

int main()
{
	Stack stack;

	for (int time = 0; time < TIMES; time++) {
		stack.push(8);
		stack.push(21);
		stack.push(12);
		stack.push(2);
	}
	for (int time = 0; time < TIMES; time++) {
		stack.pop();
	}
	stack.push(8);
	stack.push(21);
	stack.push(12);
	stack.push(2);
	stack.pop();
	stack.pop();
	stack.push(2);
	stack.pop();
	stack.pop();
}
