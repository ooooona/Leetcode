#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string ans = "";
		while (n)
		{
			--n;
			int cur = n % 26 ;
			ans = char(cur + 'A') + ans;
			n /= 26;
		}
		return ans;
	}
};