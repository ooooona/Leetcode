#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int min = 999999;
		int sum = 0;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size()-2; ++i)
		{
			int tmp = this->get2Sum(nums, i + 1, nums.size() - 1, target - nums[i]);
			//cout << nums[i] << " " << tmp << endl;
			if (this->myABS(tmp + nums[i] - target) < min)
			{
				sum = tmp + nums[i];
				min = this->myABS(sum - target);
			}
			if (min == 0)
			{
				break;
			}
		}
		return sum;
	}
private:
	int get2Sum(vector<int>& nums, int head, int tail, int target)
	{
		int low = head;
		int high = tail;
		int min = 999999;
		int sum = 0;
		while (low < high)
		{
			if (this->myABS(nums[low] + nums[high] - target) < min)
			{
				sum = nums[low] + nums[high];
				min = this->myABS(sum - target);
			}
			if (nums[low] + nums[high] == target)
			{
				return sum;
			}
			else if (nums[low] + nums[high] < target)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
		return sum;
	}
	int myABS(int a)
	{
		return a < 0 ? -1 * a : a;
	}
	int myMin(int a, int b)
	{
		return a < b ? a : b;
	}
};

int main()
{
	Solution sol;
	vector<int> nums;
	nums.push_back(0); nums.push_back(1); nums.push_back(2);
	cout << sol.threeSumClosest(nums, 0) << endl;
	system("pause");
	return 0;
}