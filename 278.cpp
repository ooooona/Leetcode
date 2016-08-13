#include <iostream>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int low = 1;
		int high = n;
		while (low < high)
		{
			int mid = low + ((high - low) >> 1); 
			if (isBadVersion(mid))
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
	system("pause");
	return 0;
}