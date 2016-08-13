#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int index = 0;
		while (index < nums.size())
		{
			if (nums[index] != index + 1 && nums[index] > 0 && nums[index] <= nums.size() && nums[nums[index]-1] != nums[index])
			{
				this->swap(nums[nums[index] - 1], nums[index]);
			}
			else
			{
				++index;
			}
		}
		int ans = nums.size()+1;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] - 1 != i)
			{
				return ans = i + 1;
			}
		}
		return ans;
	}
private:
	void swap(int& a, int& b)
	{
		int c = a;
		a = b;
		b = c;
	}
};

int main()
{
	Solution sol;
	vector<int> nums;
	nums.push_back(1); nums.push_back(1); /*nums.push_back(-1); nums.push_back(1);*/
	cout << sol.firstMissingPositive(nums) << endl;
	system("pause");
	return 0;
}
/*
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
*/