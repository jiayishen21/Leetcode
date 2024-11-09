#include <vector>

using namespace std;

class Solution
{
public:
	int trap(vector<int> &height)
	{
		if (height.empty())
		{
			return 0;
		}

		int j = 0;
		int area = 0;
		int curHeight = height[0];
		int toDelete = 0;
		for (size_t i = 1; i < height.size(); i++)
		{
			if (height[i] < curHeight)
			{
				toDelete += height[i];
			}
			else
			{
				area += (i - j - 1) * curHeight - toDelete;
				curHeight = height[i];
				j = i;
				toDelete = 0;
			}
		}

		for (size_t i = j + 1; i < height.size(); i++)
		{
		}

		return area;
	}
};
