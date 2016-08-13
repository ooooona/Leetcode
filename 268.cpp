#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int ans = 0;
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			ans = ans^i^nums[i];
		}
		return ans^n;
	}
};

int main()
{
	system("pause");
	return 0;
}