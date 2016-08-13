#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int inf = 999999;
class Solution {
public:
	int numSquares(int n) {
		return findLeastPerfectSquareNum(n);
	}
private:
	int min(int a, int b)
	{
		return a < b ? a : b;
	}
	int findLeastPerfectSquareNum(int n)
	{
		vector<int> dp;
		dp.resize(n + 1, inf);
		dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			if (i*i <= n)
			{
				dp[i*i] = 1;
			}
			for (int k = 1; k*k <= i; ++k)
			{
				dp[i] = min(dp[i], dp[i - k*k] + 1);
			}
		}
		return dp[n];
	}
};

int main()
{
	Solution sol;
	cout << sol.numSquares(12) << endl;
	cout << sol.numSquares(13) << endl;
	system("pause");
	return 0;
}