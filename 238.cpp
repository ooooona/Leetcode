#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans;
		ans.resize(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i)
		{
			ans[i] = ans[i - 1] * nums[i - 1];
		}
		int multy = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 0; --i)
		{
			ans[i] *= multy;
			multy *= nums[i];
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> nums;
	nums.push_back(1), nums.push_back(2), nums.push_back(3), nums.push_back(4);
	vector<int> ans = sol.productExceptSelf(nums);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
/*
[1,2,3,4], return [24,12,8,6].
*/