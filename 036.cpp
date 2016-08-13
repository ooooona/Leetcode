#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector< vector<int> > rows, cols, blocks;
		int rowNum = board.size();
		if (rowNum <= 0)
		{
			return false;
		}
		int colNum = board[0].size();
		int blockNum = (rowNum / 3)*(colNum / 3);

		for (int i = 0; i < rowNum; ++i)
		{
			vector<int> tmp;
			tmp.resize(10, false);
			rows.push_back(tmp);
		}
		for (int i = 0; i < colNum; ++i)
		{
			vector<int> tmp;
			tmp.resize(10, false);
			cols.push_back(tmp);
		}
		for (int i = 0; i < blockNum; ++i)
		{
			vector<int> tmp;
			tmp.resize(10, false);
			blocks.push_back(tmp);
		}

		for (int i = 0; i < rowNum; ++i)
		{
			for (int j = 0; j < colNum; ++j)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				int num = int(board[i][j] - '0');
				int b = (i / 3)*(colNum / 3) + (j / 3);
				if (blocks[b][num] || rows[i][num] || cols[j][num])
				{
					return false;
				}
				else
				{
					blocks[b][num] = true;
					rows[i][num] = true;
					cols[j][num] = true;
				}
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