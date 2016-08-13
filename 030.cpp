#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		int wnum = words.size();
		if (s.length() == 0 || wnum == 0) return ans;
		int wlen = words[0].length();
		if (wlen*wnum > s.length()) return ans;

		map<char, vector<string> > wordict;
		map<string, int> wordnum;
		for (int i = 0; i < wnum; ++i)
		{
			char ch = words[i][0];
			map<char, vector<string> >::iterator iter1 = wordict.find(ch);
			if (iter1 == wordict.end())
			{
				vector<string> tmp;
				wordict.insert(make_pair(ch, tmp));
			}
			wordict[ch].push_back(words[i]);
			map<string, int>::iterator iter = wordnum.find(words[i]);
			if (iter == wordnum.end())
			{
				wordnum.insert(make_pair(words[i], 0));
			}
			wordnum[words[i]]++;
		}
		
		for (int i = 0; i <= (s.length() - wlen*wnum); ++i)
		{
			map<string, int> tmpWordNum;
			for (map<string, int>::iterator tmpIter = wordnum.begin(); tmpIter != wordnum.end(); ++tmpIter)
			{
				tmpWordNum.insert(make_pair((*tmpIter).first, (*tmpIter).second));
			}
			bool flag = true;
			int wcount = 0;
			while (wcount < wnum)
			{
				if (i + wcount*wlen >= s.length())
				{
					flag = false; break;
				}
				char ch = s[i + wcount*wlen];
				map<char, vector<string> >::iterator iter = wordict.find(ch);
				if (iter == wordict.end())
				{
					flag = false; break;
				}
				string ssubtr = s.substr(i + wcount*wlen, wlen);
				string word = "";
				for (int j = 0; j < (*iter).second.size(); ++j)
				{
					if ((*iter).second[j] == ssubtr)
					{
						word = ssubtr; break;
					}
				}
				if (word == "" || tmpWordNum[word] <= 0)
				{
					flag = false; break;
				}
				tmpWordNum[word] --;
				wcount++;
			}
			if (flag) ans.push_back(i);
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	//string s = "barfoothefoobarman";
	//vector<string> words;
	//words.push_back("foo"), words.push_back("bar");
	string s = "wordgoodgoodgoodbestword";
	vector<string> words;
	words.push_back("word"), words.push_back("good"), words.push_back("best"), words.push_back("good");
	vector<int> ans = sol.findSubstring(s, words);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] <<"~"<< endl;
	}
	system("pause");
	return 0;
}
/*
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].

"wordgoodgoodgoodbestword"
["word","good","best","good"]
*/