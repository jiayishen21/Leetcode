#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

/*
Daily Temperatures
Neetcode medium
https://neetcode.io/problems/daily-temperatures
time:
notes:
*/

class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		vector<int> res(temperatures.size(), 0);
		// stack of <temperature, index>
		stack<pair<int, int>> s;

		for (int i = 0; i < temperatures.size(); i++)
		{
			if (s.empty())
			{
				s.push({temperatures[i], i});
			}
			else
			{
				while (!s.empty())
				{
					pair<int, int> cur = s.top();
					if (temperatures[i] > cur.first)
					{
						res[cur.second] = i - cur.second;
						s.pop();
					}
					else
					{
						break;
					}
				}
				s.push({temperatures[i], i});
			}
		}

		return res;
	}
};
