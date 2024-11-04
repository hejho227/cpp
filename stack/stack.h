#pragma once

class Stack {
  private:
	int* ptrArr;
	int hight;
	int allocated;
	bool done;

  public:
	Stack();
	~Stack();
	void push(int pushed);
	int pop();
	bool isEmpty() const;
};
