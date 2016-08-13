#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int num1 = 0, cnt1 = 0;
		int num2 = 0, cnt2 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == num1)
			{
				cnt1++;
			}
			else if (nums[i] == num2)
			{
				cnt2++;
			}
			else if (cnt1 == 0)
			{
				num1 = nums[i];
				cnt1 = 1;
			}
			else if (cnt2 == 0)
			{
				num2 = nums[i];
				cnt2 = 1;
			}
			else
			{
				cnt1--, cnt2--;
			}
		}
		//cout << num1 << " " << num2 << endl;
		cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == num1)
			{
				cnt1++;
			}
			if (nums[i] == num2)
			{
				cnt2++;
			}
		}

		vector<int> ans;
		if (cnt1 > nums.size() / 3)
		{
			ans.push_back(num1);
		}
		if (cnt2 > nums.size() / 3 && num1 != num2)
		{
			ans.push_back(num2);
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> nums;
	nums.push_back(1), nums.push_back(2);
	vector<int> ans = sol.majorityElement(nums);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}