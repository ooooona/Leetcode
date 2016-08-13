#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		unsigned int divd = dividend, divs = divisor;
		if (dividend < 0)
		{
			divd = -divd;
		}
		if (divisor < 0)
		{
			divs = -divs;
		}
		unsigned int ans = 0;
		while (divs <= divd)
		{
			long long tmp = divs;
			int i;
			for (i = 1; tmp <= divd; ++i)
			{
				tmp <<= 1;
			}
			ans += (1 << (i - 2));
			divd -= (divs << (i - 2));
		}
		cout << ans << endl;
		return  (dividend > 0 ^ divisor > 0) ? -ans : (ans >= INT_MAX ? INT_MAX : ans);
	}
};

int main()
{
	Solution sol;
	cout << sol.divide(-10, 2) << endl;
	cout << sol.divide(-2, -2) << endl;
	cout << sol.divide(34, 3) << endl;
	system("pause");
	return 0;
}