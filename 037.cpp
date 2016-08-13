#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		this->initial(board);
		this->backTracking(board, 0, 0);
	}
private:
	bool backTracking(vector< vector<char> >& board, int row, int col)
	{
		if (row >= this->_rowNum)
		{
			return true;
		}
		if (col >= this->_colNum)
		{
			return this->backTracking(board, row + 1, 0);
		}
		if (board[row][col] != '.')
		{
			return this->backTracking(board, row, col + 1);
		}
		int b = (row / 3)*(this->_colNum / 3) + (col / 3);
		for (int num = 1; num <= 9; ++num)
		{
			if (rows[row][num] || cols[col][num] || blocks[b][num])
			{
				continue;
			}
			rows[row][num] = true;
			cols[col][num] = true;
			blocks[b][num] = true;
			if (this->backTracking(board, row, col + 1))
			{
				board[row][col] = char('0' + num);
				return true;
			}
			else
			{
				rows[row][num] = false;
				cols[col][num] = false;
				blocks[b][num] = false;
			}
		}
		return false;
	}
	void initial(const vector<vector<char>>& board)
	{
		this->_rowNum = board.size();
		this->_colNum = board[0].size();
		this->_blockNum = (this->_rowNum / 3)*(this->_colNum);

		for (int row = 0; row < this->_rowNum; ++row)
		{
			vector<int> tmp;
			tmp.resize(10, false);
			this->rows.push_back(tmp);
		}
		for (int col = 0; col < this->_colNum; ++col)
		{
			vector<int> tmp;
			tmp.resize(10, false);
			this->cols.push_back(tmp);
		}
		for (int b = 0; b < this->_blockNum; ++b)
		{
			vector<int> tmp;
			tmp.resize(10, false);
			this->blocks.push_back(tmp);
		}

		for (int row = 0; row < _rowNum; ++row)
		{
			for (int col = 0; col < _colNum; ++col)
			{
				int b = (row / 3)*(_colNum / 3) + (col / 3);
				if (board[row][col] == '.')
				{
					continue;
				}
				int num = int(board[row][col] - '0');
				rows[row][num] = true;
				cols[col][num] = true;
				blocks[b][num] = true;
			}
		}
	}
	
	int _rowNum;
	int _colNum;
	int _blockNum;
	vector< vector<int> > rows;
	vector< vector<int> > cols;
	vector< vector<int> > blocks;
};



int main()
{
	Solution sol;

	system("pause");
	return 0;
}