#include <iostream>
#include <vector>

using namespace std;

/*
Valid Sudoku
Neetcode medium
https://neetcode.io/problems/valid-sudoku
time:
notes:
*/

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		// we only need to check rows and cols once
		// then we just need to check the 3x3 boxes
		// we could use unordered_set, but size is 9, so it's a bit overkill

		for (int i = 0; i < 9; i++)
		{
			vector<bool> row(9, false);
			vector<bool> col(9, false);
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					if (row[board[i][j] - '1'])
					{
						return false;
					}
					row[board[i][j] - '1'] = true;
				}
				if (board[j][i] != '.')
				{
					if (col[board[j][i] - '1'])
					{
						return false;
					}
					col[board[j][i] - '1'] = true;
				}
			}
		}

		// now check the 3x3 boxes
		for (int i = 0; i < 9; i += 3)
		{
			for (int j = 0; j < 9; j += 3)
			{
				vector<bool> box(9, false);
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if (board[i + k][j + l] != '.')
						{
							if (box[board[i + k][j + l] - '1'])
							{
								return false;
							}
							box[board[i + k][j + l] - '1'] = true;
						}
					}
				}
			}
		}
		return true;
	}
};
