#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.length() == 0)
		{
			return 0;
		}
		stack<int> sta;
		int g_max = 0;
		int most_left = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(')
			{
				sta.push(i);
			}
			else
			{
				if (sta.empty())
				{
					most_left = i + 1;
				}
				else
				{
					//int cur_pos = sta.top();
					sta.pop();
					g_max = sta.empty() ? this->myMax(g_max, i - most_left + 1) : this->myMax(g_max, i - sta.top());
				}
			}
		}
		return g_max;
	}

	int myMax(int a, int b)
	{
		return a > b ? a : b;
	}
};

int main()
{
	Solution sol;
	cout << sol.longestValidParentheses("(())()(()((") << endl;
	system("pause");
	return 0;
}