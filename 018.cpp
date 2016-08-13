#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector< vector<int> > ans;
		if (nums.size() < 4)
		{
			return ans;
		}
		sort(nums.begin(), nums.end());
		///the first loop
		for (int i = 0; i < nums.size() - 3; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			/// the second loop
			for (int j = i + 1; j < nums.size() - 2; ++j)
			{
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;

				int low = j + 1; 
				int high = nums.size() - 1;
				while (low < high)
				{
					int add = nums[low] + nums[high] + nums[i] + nums[j];
					if (add == target)
					{
						vector<int> tmp;
						tmp.push_back(nums[i]), tmp.push_back(nums[j]), tmp.push_back(nums[low]), tmp.push_back(nums[high]);
						ans.push_back(tmp);
						
						int k = low + 1;
						while (k < high && nums[k] == nums[low]) ++k;
						low = k;

						k = high - 1;
						while (k > low && nums[k] == nums[high]) --k;
						high = k;
					}
					else if (add < target)
					{
						low++;
					}
					else
					{
						high--;
					}
				}
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(0); nums.push_back(0); nums.push_back(0); nums.push_back(0); /*nums.push_back(-2); nums.push_back(2); */
	Solution sol;
	vector< vector<int> > ans = sol.fourSum(nums, 0);
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

/*
S = {1 0 -1 0 -2 2}, and target = 0.
A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/