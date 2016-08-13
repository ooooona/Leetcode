#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> hash1, hash2;
		hash1.resize(26, 0), hash2.resize(26, 0);

		for (int i = 0; i < s.length(); ++i)
		{
			hash1[int(s[i] - 'a')] ++;
		}
		for (int i = 0; i < t.length(); ++i)
		{
			hash2[int(t[i] - 'a')] ++;
		}

		for (int i = 0; i < hash1.size(); ++i)
		{
			if (hash1[i] != hash2[i])
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	system("pause");
	return 0;
}