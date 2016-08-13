#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		return num- 9 * int((num - 1) / 9);
	}
};

int main()
{
	Solution sol;
	cout << sol.addDigits(1853) << endl;
	cout << sol.addDigits(11) << endl;
	cout << sol.addDigits(17) << endl;
	system("pause");
	return 0;
}