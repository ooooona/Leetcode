#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> ans;
		ans.resize(1, 1);
		int uglyMultiply2 = 0;
		int uglyMultiply3 = 0;
		int uglyMultiply5 = 0;
		while (ans.size() < n)
		{
			int curUglyNum = min3(ans[uglyMultiply2] * 2, ans[uglyMultiply3] * 3, ans[uglyMultiply5] * 5);
			ans.push_back(curUglyNum);
			while (ans[uglyMultiply2] * 2 <= curUglyNum)
			{
				uglyMultiply2++;
			}
			while (ans[uglyMultiply3] * 3 <= curUglyNum)
			{
				uglyMultiply3++;
			}
			while (ans[uglyMultiply5] * 5 <= curUglyNum)
			{
				uglyMultiply5++;
			}
		}
		return ans.back();
	}
private:
	int min3(int a, int b, int c)
	{
		a = a < c ? a : c;
		return a < b ? a : b;
	}
};

int main()
{
	Solution sol;
	cout << sol.nthUglyNumber(1) << endl;
	cout << sol.nthUglyNumber(10) << endl;
	system("pause");
	return 0;
}