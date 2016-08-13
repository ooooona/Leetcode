#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector< vector<int> > ans;
		if (nums.size() == 0)
		{
			return ans;
		}

		vector<int> sol;
		vector<bool> visit;
		visit.resize(nums.size(), false);
		sort(nums.begin(), nums.end());
		this->getPermute(nums, visit, sol, ans);
		return ans;
	}
private:
	void getPermute(vector<int>& nums, vector<bool>& visit, vector<int>& sol, vector< vector<int> >& ans)
	{
		if (nums.size() == sol.size())
		{
			ans.push_back(sol);
			return;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (visit[i] == true)
			{
				continue;
			}
			if (i > 0 && visit[i - 1] == false && nums[i] == nums[i - 1])
			{
				continue;
			}
			visit[i] = true;
			sol.push_back(nums[i]);
			this->getPermute(nums, visit, sol, ans);
			visit[i] = false;
			sol.pop_back();
		}
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(1); nums.push_back(1); nums.push_back(0); nums.push_back(0); nums.push_back(1); nums.push_back(-1); nums.push_back(-1); nums.push_back(1); 
	Solution sol;
	vector< vector<int> > ans = sol.permuteUnique(nums);
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
[1,1,0,0,1,-1,-1,1]
*/