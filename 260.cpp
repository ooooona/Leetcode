#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int tmp = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			tmp ^= nums[i];
		}
		int index = this->findFirstBitOne(tmp);
		int data1 = 0, data2 = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (this->isBitOne(nums[i], index))
			{
				data1 ^= nums[i];
			}
			else
			{
				data2 ^= nums[i];
			}
		}

		vector<int> ans;
		ans.push_back(data1), ans.push_back(data2);
		return ans;
	}
private:
	int findFirstBitOne(int num)
	{
		int index = 0;
		while ((num & 1) == 0)
		{
			num >>= 1;
			index++;
		}
		return index;
	}
	bool isBitOne(int num, int index)
	{
		num = num >> index;
		return (num & 1);
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(0), nums.push_back(-1);
	Solution sol;
	vector<int> ans = sol.singleNumber(nums);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}