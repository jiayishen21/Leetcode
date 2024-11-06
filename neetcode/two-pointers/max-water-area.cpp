#include <vector>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int> &heights)
	{
		// there's no point in moving the taller edge inwards because the area won't increase until the shorter edge is moved
		size_t i = 0;
		size_t j = heights.size() - 1;
		int maxArea = 0;
		while (i < j)
		{
			int area = (j - i) * min(heights[i], heights[j]);
			if (area > maxArea)
			{
				maxArea = area;
			}

			if (heights[i] < heights[j])
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		return maxArea;
	}
};
