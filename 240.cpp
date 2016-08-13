#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n == 0)
		{
			return false;
		}
		int m = matrix[0].size();

		int row = 0, col = m - 1;
		while (row < n && col >= 0)
		{
			if (target > matrix[row][col])
			{
				row++;
			}
			else if (target < matrix[row][col])
			{
				col--;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	system("pause");
	return 0;
}