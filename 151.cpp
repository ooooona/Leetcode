#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int head = 0, tail = s.length() - 1;
		while (head <= tail && s[head] == ' ')
			head++;
		while (tail >= head && s[tail] == ' ')
			tail--;
		s = s.substr(head, tail - head + 1);
		int n = s.length();
		if (n <= 1) return;
		for (int i = 0; i < (n >> 1); ++i)
		{
			char ch = s[n - i - 1];
			s[n - i - 1] = s[i];
			s[i] = ch;
		}
		string ns = "";
		int start = 0;
		int end = start;
		for (++end; end < n; ++end)
		{
			if (s[end] == ' ')
			{
				int i = start;
				int j = end - 1;
				while (i < j)
				{
					char ch = s[j];
					s[j] = s[i]; s[i] = ch;
					++i, --j;
				}
				ns = ns + s.substr(start, end - start) + " ";
				start = end;
				while (s[start] == ' ')
					++start;
				end = start - 1;
			}
			else if (end == n - 1)
			{
				int i = start; 
				int j = end;
				while (i < j)
				{
					char ch = s[j];
					s[j] = s[i]; s[i] = ch;
					++i, --j;
				}
				ns = ns + s.substr(start, end - start + 1);
				start = end;
			}
			else
			{
				continue;
			}
		}
		s = ns;
	}
};

int main()
{
	Solution sol;
	string s = "  a    b ";
	sol.reverseWords(s);
	cout << s << endl;
	system("pause");
	return 0;
}