#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
		map<char, int> hash1;
		map<string, int> hash2;

		vector<string> pattern2;
		int pre = 0, post = pre;
		for (; post != str.length(); )
		{
			if (str[post] == ' ')
			{
				if (pre != post)
				{
					pattern2.push_back(str.substr(pre, post - pre));
				}
				while (post != str.length() && str[post] == ' ')
				{
					post++;
				}
				pre = post;
			}
			else
			{
				post++;
			}
		}
		if (pre != post)
		{
			pattern2.push_back(str.substr(pre));
		}

		if (pattern.size() != pattern2.size())
		{
			return false;
		}
		for (int i = 0; i < pattern.size(); ++i)
		{
			map<char, int>::iterator hashIter1 = hash1.find(pattern[i]);
			map<string, int>::iterator hashIter2 = hash2.find(pattern2[i]);
			if ((hashIter1 != hash1.end() && hashIter2 == hash2.end()) || (hashIter1 == hash1.end() && hashIter2 != hash2.end()))
			{
				return false;
			}
			else if (hashIter1 == hash1.end() && hashIter2 == hash2.end())
			{
				hash1.insert(make_pair(pattern[i], i));
				hash2.insert(make_pair(pattern2[i], i));
				continue;
			}
			else
			{
				if (hash1[pattern[i]] == hash2[pattern2[i]])
				{
					hash1[pattern[i]] = i;
					hash2[pattern2[i]] = i;
				}
				else
				{
					return false;
				}
			}
		}
		return true;
    }
};

int main()
{
	Solution sol;
	
	cout << sol.wordPattern("abba", "dog cat cat dog") << endl;
	cout << sol.wordPattern("abba", "dog cat cat fish") << endl;
	cout << sol.wordPattern("aaaa", "dog cat cat dog") << endl;
	cout << sol.wordPattern("abba", "dog dog dog dog") << endl;
	cout << sol.wordPattern("", "") << endl;
	cout << sol.wordPattern("", "    ") << endl;
	system("pause");
	return 0;
}
/*
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
*/