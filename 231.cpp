#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n < 1)
		{
			return false;
		}
		int cnt = 0;
		while (n)
		{
			if ((n & 1) == 1)
			{
				cnt++;
			}
			if (cnt > 1)
			{
				return false;
			}
			n >>= 1;
		}
		return true;
	}
	//bool isPowerOfTwo(int n) {
	//	if (n <= 1)
	//	{
	//		return false;
	//	}
	//	while (n % 2 == 0)
	//	{
	//		n /= 2;
	//	}
	//	return n == 1 ? true : false;
	//}
};

int main()
{
	return 0;
}