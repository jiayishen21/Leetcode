#include <vector>;

using namespace std;

class Solution
{
public:
	bool hasIncreasingSubarrays(vector<int> &nums, int k)
	{
		for (int i = 0; i <= nums.size() - 2 * k; i++)
		{
			int maxSoFar = nums[i] - 1;
			bool failed = false;
			for (int j = 0; j < k; j++)
			{
				if (nums[i + j] > maxSoFar)
				{
					maxSoFar = nums[i + j];
				}
				else
				{
					failed = true;
					break;
				}
			}
			if (failed)
			{
				continue;
			}
			maxSoFar = nums[i + k] - 1;
			for (int j = 0; j < k; j++)
			{
				if (nums[i + k + j] > maxSoFar)
				{
					maxSoFar = nums[i + k + j];
				}
				else
				{
					failed = true;
					break;
				}
			}
			if (!failed)
			{
				return true;
			}
		}
		return false;
	}
};