#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> ans;
		ans.resize(ratings.size(), 1);

		for (int i = 1; i < ratings.size(); ++i)
		{
			if (ratings[i] > ratings[i - 1]) ans[i] = ans[i - 1] + 1;
		}
		for (int i = ratings.size() - 2; i >= 0; --i)
		{
			if (ratings[i] > ratings[i + 1] && ans[i] <= ans[i + 1]) ans[i] = ans[i + 1] + 1;
		}
		
		int sum = 0;
		for (int i = 0; i < ans.size(); ++i)
		{
			sum += ans[i];
		}
		return sum;
	}
};

int main()
{
	return 0;
}