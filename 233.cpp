#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0)
		{
			return 0;
		}
		long sum = 0;
		long cnt = 1;
		long num = 0;
		while (n)
		{
			if (n % 10 == 0)
			{
				sum += (n / 10) * cnt;
			}
			else if (n % 10 == 1)
			{
				sum += (n / 10) * cnt + num + 1;
			}
			else
			{
				sum += (n / 10 + 1) * cnt;
			}
			num = num + cnt * (n % 10);
			cnt *= 10;
			n /= 10;
		}
		return sum;
	}
};

int main()
{
	Solution sol;
	cout << sol.countDigitOne(0) << endl;
	cout << sol.countDigitOne(9) << endl;
	cout << sol.countDigitOne(1) << endl;
	cout << sol.countDigitOne(13) << endl;
	cout << sol.countDigitOne(23) << endl;

	system("pause");
	return 0;
} 