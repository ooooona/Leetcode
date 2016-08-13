#include <iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		int low = 0; 
		int high = x;
		while (low < high)
		{
			int mid = low + ((high - low) >> 1);
			if (mid*mid > x)
			{
				high = mid - 1;
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
	return 0;
}