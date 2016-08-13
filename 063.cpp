#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector< vector<int> > dp;
		int m = obstacleGrid.size();
		if (m == 0)
		{
			return 0;
		}
		int n = obstacleGrid[0].size();

		for (int row = 0; row <= m; ++row)
		{
			vector<int> tmp;
			tmp.resize(n + 1, 0);
			dp.push_back(tmp);
		}

		dp[1][1] = 1;
		for (int row = 1; row <= m; ++row)
		{
			for (int col = 1; col <= n; ++col)
			{
				if (obstacleGrid[row - 1][col - 1] == 1)
				{
					dp[row][col] = 0;
				}
				else
				{
					dp[row][col] = this->max(dp[row - 1][col] + dp[row][col - 1], dp[row][col]);
				}
			}
		}
		return dp[m][n];
	}
private:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	return 0;
}