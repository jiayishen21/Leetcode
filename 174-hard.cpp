#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
174. Dungeon Game
leetcode hard
https://leetcode.com/problems/dungeon-game/description/
time:
notes: learned to first solve the problem recursively, then convert to dp
*/

class Solution
{
public:
	int calculateMinimumHP(vector<vector<int>> &dungeon)
	{
		// this question is kind of difficult
		// there can be paths that
		// 1. maximize health at certain points
		// 2. minimize encountering the biggest health drop
		// 3. offer something in between

		// O(n^3)

		int m = dungeon.size();
		int n = dungeon[0].size();

		// min hp needed before accessing cell i, j
		vector<vector<int>> dp(m, vector<int>(n, 0));

		// we need to end with at least 1 hp
		dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				// skip the last cell
				if (i == m - 1 && j == n - 1)
				{
					continue;
				}

				int right = (j == n - 1) ? INT_MAX : dp[i][j + 1];
				int down = (i == m - 1) ? INT_MAX : dp[i + 1][j];

				int minHp = min(right, down) - dungeon[i][j];
				dp[i][j] = max(1, minHp);
			}
		}

		return dp[0][0];
	}
};
