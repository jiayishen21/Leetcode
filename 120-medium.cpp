#include <iostream>
#include <vector>

using namespace std;

/*
120. Triangle
leetcode medium
https://leetcode.com/problems/triangle/description/
time:
notes:
*/

class Solution
{
public:
	int minimumTotal(vector<vector<int>> &triangle)
	{
		// idea is to start at bottom and dp up
		vector<vector<int>> dp(triangle);
		// the last row is the same
		// start at second to last row
		for (int i = triangle.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j < triangle[i].size(); j++)
			{
				dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
			}
		}
		return dp[0][0];
	}
};
