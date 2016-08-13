#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lowIndex = 0;
		int highIndex = nums.size() - 1;
		while (lowIndex < highIndex)
		{
			int midIndex = lowIndex + ((highIndex - lowIndex) >> 1);
			if (nums[midIndex] == target)
			{
				return midIndex;
			}
			if (nums[highIndex] <= nums[lowIndex])
			{
				if (nums[midIndex] >= nums[lowIndex])
				{
					if (target >= nums[lowIndex] && target < nums[midIndex])
					{
						highIndex = midIndex - 1;
					}
					else
					{
						lowIndex = midIndex + 1;
					}
				}
				else
				{
					if (target <= nums[highIndex] && target > nums[midIndex])
					{
						lowIndex = midIndex + 1;
					}
					else
					{
						highIndex = midIndex - 1;
					}
				}
			}
			else
			{
				if (nums[midIndex] > target)
				{
					highIndex = midIndex - 1;
				}
				else
				{
					lowIndex = midIndex + 1;
				}
			}
		}
		return target == nums[lowIndex] ? lowIndex : -1;
	}
};

int main()
{
	return 0;
}