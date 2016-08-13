#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int lowIndex = 0;
		int highIndex = nums.size() - 1;
		while (lowIndex < highIndex)
		{
			int mid = lowIndex + ((highIndex - lowIndex) >> 1);
			if (nums[mid] == target)
			{
				return true;
			}
			
			if (nums[lowIndex] == nums[highIndex])
			{
				for (int i = lowIndex; i < highIndex; ++i)
				{
					if (nums[i] == target)
					{
						return true;
					}
				}
				return false;
			}
			else if (nums[lowIndex] < nums[highIndex])
			{
				if (nums[mid] < target)
				{
					lowIndex = mid + 1;
				}
				else
				{
					highIndex = mid - 1;
				}
			}
			else
			{
				if (nums[mid] >= nums[lowIndex])
				{
					if (target >= nums[lowIndex] && target <= nums[mid])
					{
						highIndex = mid - 1;
					}
					else
					{
						lowIndex = mid + 1;
					}
				}
				else
				{
					if (target <= nums[highIndex] && target >= nums[mid])
					{
						lowIndex = mid + 1;
					}
					else
					{
						highIndex = mid - 1;
					}
				}
			}
		}
		return target == nums[lowIndex] ? true : false;
	}
};

int main()
{
	return 0;
}