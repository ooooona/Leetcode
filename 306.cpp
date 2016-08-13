#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int len1 = 1; len1 < num.length(); ++len1)
		{
			for(int len2 = 1; len1 + len2 < num.length(); ++len2)
			{
				string str1 = num.substr(0, len1);
				string str2 = num.substr(len1, len2);
				if (!isValid(str1) || !isValid(str2))
				{
					continue;
				}
				string pat = num.substr(len1 + len2);
				if(dfs(str1, str2, pat))
				{
					return true;
				}
			}
		}
		return false;
    }

    bool isValid(string str)
	{
		if(str.length() == 0 || (str.length()>1 && str[0] == '0'))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	string strADD(string str1, string str2)
	{
		std::vector<int> v1, v2, v3;
		int len1 = str1.length(), len2 = str2.length();
		for(int i = len1 - 1; i >= 0; --i)
		{
			v1.push_back(int(str1[i] - '0'));
		}
		for(int i = len2 - 1; i >= 0; --i)
		{
			v2.push_back(str2[i] - '0');
		}

		int mod = 0;
		for(int i = 0; i < len1 && i < len2; ++i)
		{
			int digital = (v1[i] + v2[i] + mod) % 10;
			mod = (v1[i] + v2[i] + mod) / 10;
			v3.push_back(digital);
		}
		for(int i = len1; i < len2; ++i)
		{
			int digital = (v2[i] + mod) % 10;
			mod = (v2[i] + mod) / 10;
			v3.push_back(digital);
		}
		for(int i = len2; i < len1; ++i)
		{
			int digital = (v1[i] + mod) % 10;
			mod = (v1[i] + mod) / 10;
			v3.push_back(digital);
		}
		if(mod)
		{
			v3.push_back(mod);
		}

		string ans = "";
		for(int i = v3.size() - 1; i >= 0; --i)
		{
			ans = ans + char(v3[i] + '0');
		}
		return ans;
	}

	bool dfs(string str1, string str2, string pat)
	{
		if(pat.length() == 0)
		{
			return true;
		}
		string str3 = strADD(str1, str2);
		if(str3.length() > pat.length())
		{
			return false;
		}
		if (pat.substr(0, str3.length()) != str3)
		{
			return false;
		}
		else
		{
			return dfs(str2, str3, pat.substr(str3.length()));
		}
	}
};

int main()
{
	Solution sol;
	string str;
	while(cin>>str)
	{
		cout<<sol.isAdditiveNumber(str)<<endl;
	}

	return 0;
}
/*
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
*/
