#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
Car Fleet
Neetcode medium
https://neetcode.io/problems/car-fleet
time:
notes:
*/

class Solution
{
public:
	int carFleet(int target, vector<int> &position, vector<int> &speed)
	{
		// if p_i denotes initial position, if p_i < p_j, i will always stay behind j
		vector<pair<int, int>> cars;
		for (int i = 0; i < position.size(); i++)
		{
			cars.push_back({position[i], speed[i]});
		}
		sort(cars.begin(), cars.end(), greater<pair<int, int>>());

		double time = -1;
		int fleets = 0;
		for (auto car : cars)
		{
			// new fleet
			if (time * car.second + car.first < target)
			{
				time = (double)(target - car.first) / car.second;
				fleets++;
			}
		}

		return fleets;
	}
};
