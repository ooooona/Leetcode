#include <iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int sum = 0;
		while (n >= 5)
		{
			sum += n / 5;
			n /= 5;
		}
		return sum;
	}
};

int main()
{
	return 0;
}