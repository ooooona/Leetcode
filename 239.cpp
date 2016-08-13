#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		priority_queue<int> Q;
		int cnt = k;
		for (int i = 0; i < nums.size(); ++i)
		{
			Q.push(nums[i]);
			if (cnt)
			{

			}
		}
	}
};

int main()
{

	system("pause");
	return 0;
}

/*
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
[3,3,5,5,6,7].
*/