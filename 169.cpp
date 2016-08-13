#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int num = 0, cnt = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (cnt == 0)
			{
				num = nums[i];
			}

			if (nums[i] == num)
			{
				cnt++;
			}
			else
			{
				cnt--;
			}
		}
		return num;
	}
};

int main()
{
	return 0;
}