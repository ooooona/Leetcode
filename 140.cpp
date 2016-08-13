#include <unordered_set>
#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> ans;
		if (s == "")
		{
			return ans;
		}
		this->wordBreak(s, wordDict, "", ans);
		return ans;
	}
private:
	void wordBreak(string s, unordered_set<string>& wordDict, string str, vector<string>& ans)
	{
		if (s == "")
		{
			ans.push_back(str);
		}
		for (int i = 0; i < s.length(); ++i)
		{
			if (wordDict.find(s.substr(0, i + 1)) != wordDict.end())
			{
				this->wordBreak(s.substr(i + 1), wordDict, str + s.substr(0, i + 1), ans);
			}
		}
	}
};

int main()
{
	return 0;
}