#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
874. Walking Robot Simulation
Leetcode medium
https://leetcode.com/problems/walking-robot-simulation/?envType=daily-question&envId=2024-09-04
time: 30 mins
notes:
*/

class Solution
{
public:
	int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
	{
		// observations:
		// the robot's furthest distance is always at the end of a move (not in the middle unless it hits an obstacle)

		// -3 * 10^4 <= x, y <= 3 * 10^4
		// these are some very large coords, we can't just do a 2D array for the obstacles
		// 0 <= obstacles.length <= 10^4, we can't just use it as an array

		// i will use 2 layered map to store the obstacles
		unordered_map<int, unordered_set<int>> obstaclesX;
		unordered_map<int, unordered_set<int>> obstaclesY;
		for (auto obstacle : obstacles)
		{
			obstaclesX[obstacle[0]].insert(obstacle[1]);
			obstaclesY[obstacle[1]].insert(obstacle[0]);
		}

		int x = 0;
		int y = 0;
		int moveX = 0;
		int moveY = 1;
		int temp;
		int maxDist = 0;

		for (auto command : commands)
		{
			// turn left
			if (command == -2)
			{
				temp = moveX;
				moveX = -moveY;
				moveY = temp;
			}
			// turn right
			else if (command == -1)
			{
				temp = moveX;
				moveX = moveY;
				moveY = -temp;
			}
			// if we are moving horizontally
			else if (moveX)
			{
				int newX = x + moveX * command;
				if (moveX > 0)
				{
					// we can skip checking for command + 1 because it doesnt matter if there's an obstacle there
					for (int i = 1; i < command + 1; i++)
					{
						if (obstaclesX.find(x + i) != obstaclesX.end() && obstaclesX[x + i].find(y) != obstaclesX[x + i].end())
						{
							newX = x + i - 1;
							break;
						}
					}
				}
				else
				{
					for (int i = 1; i < command + 1; i++)
					{
						if (obstaclesX.find(x - i) != obstaclesX.end() && obstaclesX[x - i].find(y) != obstaclesX[x - i].end())
						{
							newX = x - i + 1;
							break;
						}
					}
				}
				x = newX;
			}

			else
			{
				int newY = y + moveY * command;
				if (moveY > 0)
				{
					// we can skip checking for command + 1 because it doesnt matter if there's an obstacle there
					for (int i = 1; i < command + 1; i++)
					{
						if (obstaclesY.find(y + i) != obstaclesY.end() && obstaclesY[y + i].find(x) != obstaclesY[y + i].end())
						{
							newY = y + i - 1;
							break;
						}
					}
				}
				else
				{
					for (int i = 1; i < command + 1; i++)
					{
						if (obstaclesY.find(y - i) != obstaclesY.end() && obstaclesY[y - i].find(x) != obstaclesY[y - i].end())
						{
							newY = y - i + 1;
							break;
						}
					}
				}
				y = newY;
			}

			maxDist = max(maxDist, x * x + y * y);
		}

		return maxDist;
	}
};
