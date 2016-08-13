#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
///Method.02
	int findDuplicate(vector<int>& nums) {
		int lowPoint = 0;
		int fastPoint = nums[0];
		while (lowPoint != fastPoint)
		{
			lowPoint = nums[lowPoint];
			fastPoint = nums[nums[lowPoint]];
		}
	}
private:
/// Method.01 Binary Search
	int findDuplicate(vector<int>& nums) {
		int N = nums.size() - 1;
		int low = 1;
		int high = N;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			int lowerCnt = 0;
			for (int i = 0; i < nums.size(); ++i)
			{
				if (nums[i] <= mid)
				{
					lowerCnt++;
				}
			}
			if (lowerCnt > mid)
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		return low;
	}
};

int main()
{
	cout << ((7+6) >> 1) << endl;
	system("pause");
	return 0;
}