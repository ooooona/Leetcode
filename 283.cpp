#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int zeroNum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 0)
			{
				zeroNum++;
			}
		}
		int order = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != 0)
			{
				if (order != i)
				{
					nums[order] = nums[i];
				}
				order++;
			}
		}
		order = nums.size() - 1;
		while (zeroNum)
		{
			if (nums[order] != 0)
			{
				nums[order] = 0;
			}
			order--;
			zeroNum--;
		}
	}
};

int main()
{
	int data[] = { 1,2,3,4,5 };
	vector<int> nums;
	for (int i = 0; i < 5; ++i)
	{
		nums.push_back(data[i]);
	}
	Solution sol;
	sol.moveZeroes(nums);
	for (int i = 0; i < 5; ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
nums = [0, 1, 0, 3, 12]
*/