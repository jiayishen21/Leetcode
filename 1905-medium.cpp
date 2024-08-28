#include <iostream>
#include <vector>
using namespace std;

/*
1905. Count Sub Islands
Leetcode medium
https://leetcode.com/problems/count-sub-islands/description/?envType=daily-question&envId=2024-08-28
time: 15 minutes
notes:
*/
class Solution
{
public:
	int m;
	int n;

	void findIsland(vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<pair<int, int>> &island, int i, int j)
	{
		if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
		{
			return;
		}
		if (grid[i][j] == 0)
		{
			return;
		}
		visited[i][j] = true;
		island.push_back({i, j});

		findIsland(grid, visited, island, i + 1, j);
		findIsland(grid, visited, island, i - 1, j);
		findIsland(grid, visited, island, i, j + 1);
		findIsland(grid, visited, island, i, j - 1);
	}

	int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
	{
		m = grid1.size();
		n = grid1[0].size();

		// my approach is to keep track of all points on islands in grid2
		// then i match each point to the corresponding point in grid1

		// i can find all points on an island by keeping track of the visited points

		// visited[i][j] denotes whether we visited coords i, j or not
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		// islands[i] represents the list of points on island i
		vector<vector<pair<int, int>>> islands;

		// find all islands in grid2
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid2[i][j] == 1 && !visited[i][j])
				{
					vector<pair<int, int>> island;
					findIsland(grid2, visited, island, i, j);
					islands.push_back(island);
				}
			}
		}

		int total = 0;
		for (int i = 0; i < islands.size(); i++)
		{
			bool flag = true;
			for (int j = 0; j < islands[i].size(); j++)
			{
				if (grid1[islands[i][j].first][islands[i][j].second] == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				total++;
			}
		}

		return total;
	}
};