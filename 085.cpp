#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size();
		if (n == 0)
		{
			return 0;
		}
		int m = matrix[0].size();

		vector< vector<int> > len;
		for (int row = 0; row < n; ++row)
		{
			vector<int> tmp;
			tmp.resize(m, 0);
			len.push_back(tmp);
		}

		for (int row = 0; row < n; ++row)
		{
			for (int col = 0; col < m; ++col)
			{
				if (row == 0)
				{
					len[row][col] = matrix[row][col] == '1' ? 1 : 0;
				}
				else
				{
					len[row][col] = matrix[row][col] == '1' ? len[row - 1][col] + 1 : 0;
				}
			}
		}
		int max = 0;
		for (int row = 0; row < n; ++row)
		{
			max = this->MAX(this->getMaxRectange(len[row]), max);
		}
		return max;
	}
private:
	int getMaxRectange(vector<int>& nums)
	{
		//for (int i = 0; i < nums.size(); ++i)
		//{
		//	cout << nums[i] << " ";
		//}
		//cout << endl;
		int max = 0;
		stack<rect> sta;
		for (int i = 0; i < nums.size(); ++i)
		{
			int width = 0;
			if (!sta.empty() && sta.top().height > nums[i])
			{
				while (!sta.empty() && sta.top().height > nums[i])
				{
					width += sta.top().width;
					max = this->MAX(max, sta.top().height*width);
					sta.pop();
				}
			}
			rect rec(nums[i], width + 1);
			sta.push(rec);
		}
		int width = 0;
		while (!sta.empty())
		{
			width += sta.top().width;
			max = this->MAX(max, sta.top().height*width);
			sta.pop();
		}
		return max;
	}
	int MAX(int a, int b)
	{
		return a > b ? a : b;
	}

	struct rect
	{
		int height;
		int width;
		rect(int _h, int _w):height(_h), width(_w){}
	};
};

int main()
{
	vector< vector<char> > matrix;
	vector<char> tmp;
	tmp.push_back('0'), tmp.push_back('1');
	matrix.push_back(tmp);
	Solution sol;
	cout << sol.maximalRectangle(matrix) << endl;
	system("pause");
	return 0;
}