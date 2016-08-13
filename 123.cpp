#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int> dp1, dp2;
		int n = prices.size();
		if (n <= 1)
		{
			return 0;
		}
		
		dp1.resize(n, 0), dp2.resize(n, 0);
		int lowPrice = prices[0];
		int maxProfit = 0;
		for (int i = 1; i < n; ++i)
		{
			if (prices[i] < lowPrice)
			{
				lowPrice = prices[i];
			}
			maxProfit = maxProfit > (prices[i] - lowPrice) ? maxProfit : (prices[i] - lowPrice);
			dp1[i] = maxProfit;
		}

		int highPrice = prices[n - 1];
		maxProfit = 0;
		for (int i = n - 2; i >= 0; --i)
		{
			if (prices[i] > highPrice)
			{
				highPrice = prices[i];
			}
			maxProfit = maxProfit > (highPrice - prices[i]) ? maxProfit : (highPrice - prices[i]);
			dp2[i] = maxProfit;
		}

		maxProfit = 0;
		for (int i = 0; i < n; ++i)
		{
			maxProfit = maxProfit > (dp1[i] + dp2[i]) ? maxProfit : (dp1[i] + dp2[i]);
		}
		return maxProfit;
	}
};

int main()
{
	return 0;
}