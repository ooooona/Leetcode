#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct node
{
	double data;
	int leftNum, rightNum;
	int count;
	node* left;
	node* right;

	node(double _data_, int _ln_ = 0, int _rn_ = 0, int _c_ = 1, node* _left_ = NULL, node* _right_ = NULL)
		: data(_data_), leftNum(_ln_), rightNum(_rn_), count(_c_), left(_left_), right(_right_)
	{}
};

class MedianFinder {
public:

	MedianFinder()
	{
		this->root = NULL;
		this->totalNum = 0;
	}

	// Adds a number into the data structure.
	void addNum(int num) {
		this->totalNum++;
		this->insertTree(num, this->root);
	}

	// Returns the median of current data stream
	double findMedian() {
		if (this->totalNum == 0)
		{
			return 0;
		}
		int mid = (this->totalNum / 2) + 1;
		if (this->totalNum % 2)
		{
			return this->dfsTree(mid, this->root);
		}
		else
		{
			return (this->dfsTree(mid, this->root) + this->dfsTree(mid - 1, this->root)) / 2;
		}
	}

private:
	void insertTree(int num, node*& p)
	{
		if (p == NULL)
		{
			p = new node(num);
			return;
		}
		if (num < p->data)
		{
			p->leftNum++;
			this->insertTree(num, p->left);
		}
		else if (num > p->data)
		{
			p->rightNum++;
			this->insertTree(num, p->right);
		}
		else
		{
			p->count++;
		}
	}

	double dfsTree(int order, node* p)
	{
		if (p == NULL)
		{
			return 0; /// need to be redefined.
		}
		//cout << order << " " << p->data <<" "<<p->leftNum<<" & "<<p->rightNum<< " : " << this->totalNum << endl;

		if (order <= p->leftNum)
		{
			return this->dfsTree(order, p->left);
		}
		else if (order > (p->leftNum + p->count))
		{
			return this->dfsTree(order - p->leftNum - p->count, p->right);
		}
		else
		{
			return p->data;
		}
	}	
	
	node* root;
	int totalNum;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main()
{
	MedianFinder sol;
	sol.addNum(1);
	sol.addNum(2);
	cout << sol.findMedian() << endl;
	sol.addNum(3);
	cout << sol.findMedian() << endl;
	system("pause");
	return 0;
}

/*
add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
*/