#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector< vector<int> > ans;
		if (nums.size() >= 3)
		{
			sort(nums.begin(), nums.end());
			int i = 0;
			int prenum = nums[0];
			while (i < nums.size() - 2)
			{
				vector< vector< int> > tmp;
				tmp = this->get2Sum(nums, i + 1, nums.size() - 1, 0 - nums[i]);
				if (tmp.size())
				{
					for (int k = 0; k < tmp.size(); ++k)
					{
						tmp[k].push_back(nums[i]);
						sort(tmp[k].begin(), tmp[k].end());
						ans.push_back(tmp[k]);
					}
				}

				while (i < nums.size() && prenum == nums[i])
				{
					i++;
				}
				prenum = nums[i];
			}
		}
		return ans;
	}
private:
	vector< vector<int> > get2Sum(vector<int>& nums, int low, int high, int target)
	{
		vector< vector<int> > ans;
		int head = low;
		int tail = high;
		int prehead = nums[head];
		int pretail = nums[tail];
		while (head < tail)
		{
			if (nums[head] + nums[tail] == target)
			{
				vector<int> tmp;
				tmp.push_back(nums[head]), tmp.push_back(nums[tail]);
				while (head <= high && prehead == nums[head])
				{
					head++;
				}
				while (tail >= low && pretail == nums[tail])
				{
					tail--;
				}
				ans.push_back(tmp);
			}
			else if (nums[head] + nums[tail] < target)
			{
				while (head <= high && prehead == nums[head])
				{
					head++;
				}
			}
			else
			{
				while (tail >= low && pretail == nums[tail])
				{
					tail--;
				}
			}
			prehead = nums[head];
			pretail = nums[tail];
		}
		return ans;
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(-2), nums.push_back(0), nums.push_back(1), nums.push_back(1), nums.push_back(2);
	Solution sol;
	vector< vector<int> > ans = sol.threeSum(nums);
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
[-2,0,1,1,2]
*/