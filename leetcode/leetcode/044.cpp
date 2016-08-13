#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.length() == 1 && isStar(p[0])) return true;
		if (s.length() == 0 && p.length() == 0) return true;
		if (s.length() == 0 || p.length() == 0) return false;
		vector< vector<bool> > dp;
		for (int i = 0; i <= p.length(); ++i)
		{
			vector<bool> tmp(s.length()+1, false);
			dp.push_back(tmp);
		}
		
		for (int index2 = 0; index2 < p.length(); ++index2)
		{
			char pchar = p[index2];
			if (this->isStar(pchar))
			{
				if (index2 == 0)
					for (int index1 = 0; index1 <= s.length(); ++index1) dp[index2][index1] = true;
				else
					for (int index1 = 0; index1 <= s.length(); ++index1)
					{
						if (dp[index2 - 1][index1])
						{
							for (int index3 = index1; index3 <= s.length(); ++index3) dp[index2][index3] = true;
						}
					}
			}
			else
			{
				if (index2 == 0)
					dp[index2][1] = (isQuestion(pchar) || pchar == s[0]) ? true : false;
				else
					for (int index1 = 0; index1 < s.length(); ++index1)
					{
						if (dp[index2 - 1][index1])
						{
							dp[index2][index1 + 1] = (isQuestion(pchar) || pchar == s[index1 + 1]) ? true : false;
						}
					}
			}
			//cout << "index2 = " << index2 << " : " << endl;
			//for (int i = 0; i < s.length() + 1; ++i)
			//{
			//	cout << dp[index2][i] << " ";
			//}
			//cout << endl;
		}
		return dp[p.length()-1][s.length()];
	}

	bool isStar(char ch)
	{
		return ch == '*';
	}
	bool isQuestion(char ch)
	{
		return ch == '?';
	}
};

int main()
{
	string s = "aa", p = "a";
	while (cin >> s >> p)
	{
		Solution sol;
		cout << sol.isMatch(s, p) << endl;
	}
	return 0;
}

/*
Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false

*/