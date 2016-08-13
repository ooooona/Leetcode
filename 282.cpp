#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	vector<string> addOperators(string num, int target) {
	}
};

int main()
{
	Solution sol;
	vector<string> ans = sol.addOperators("105", 5);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
	system("pause");
	return 0;
}

/*
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/