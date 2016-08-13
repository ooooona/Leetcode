#include <iostream>
#include <vector>
#include<unordered_set>
#include <map>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int n = s.length();
		vector<bool> dp; 
		dp.resize(n + 1, false);
		dp[0] = true;
		for (int i = 1; i <= n; ++i)
		{
			if (dp[i - 1] == true)
			{
				for (int j = i; j <= n; ++j)
				{
					if (wordDict.find(s.substr(i - 1, (j - i + 1))) != wordDict.end())
					{
						dp[j] = true;
					}
				}
			}
		}
		return dp[n];
	}
};

int main()
{
	return 0;
}