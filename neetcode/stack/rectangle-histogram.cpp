#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

/*
Largest Rectangle In Histogram
Neetcode hard
https://neetcode.io/problems/largest-rectangle-in-histogram
time:
notes:
*/

class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		// pair: index, height
		stack<pair<int, int>> s;
		int maxArea = 0;
		int start = 0;

		for (int i = 0; i < heights.size(); i++)
		{
			// by default the start is the current index
			int start = i;

			while (!s.empty() && s.top().second > heights[i])
			{
				pair<int, int> curRect = s.top();
				// i - curRect.first because the rectangle goes from
				// curRect.first to i - 1, and we add + 1 to get the width
				maxArea = max(maxArea, curRect.second * (i - curRect.first));

				// if previous indices were higher, we can start from there
				start = curRect.first;

				s.pop();
			}
			s.push({start, heights[i]});
		}

		while (!s.empty())
		{
			pair<int, int> curRect = s.top();
			maxArea = max(maxArea, curRect.second * (static_cast<int>(heights.size()) - curRect.first));
			s.pop();
		}

		return maxArea;
	}
};
