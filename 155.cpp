#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
	void push(int x) {
		this->_dataStack.push(x);
		if (this->_minStack.empty())
		{
			this->_minStack.push(x);
		}
		else
		{
			int minNum = _minStack.top();
			this->_minStack.push(this->min(minNum, x));
		}
	}

	void pop() {
		this->_dataStack.pop();
		this->_minStack.pop();
	}

	int top() {
		return this->_dataStack.top();
	}

	int getMin() {
		return this->_minStack.top();
	}
private:
	stack<int> _dataStack;
	stack<int> _minStack;

	int min(int a, int b)
	{
		return a < b ? a : b;
	}
};

int main()
{
	return 0;
}