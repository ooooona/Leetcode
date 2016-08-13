#include <stack>
#include <iostream>
using namespace std;

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		this->_stack1.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		this->changeInternalStack();
		this->_stack2.pop();
	}

	// Get the front element.
	int peek(void) {
		this->changeInternalStack();
		return this->_stack2.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		this->changeInternalStack();
		return this->_stack2.empty();
	}
private:
	stack<int> _stack1;
	stack<int> _stack2;

	void changeInternalStack()
	{
		if (this->_stack2.empty())
		{
			while (!this->_stack1.empty())
			{
				this->_stack2.push(this->_stack1.top());
				this->_stack1.pop();
			}
		}
	}
};

int main()
{
	system("pause");
	return 0;
}