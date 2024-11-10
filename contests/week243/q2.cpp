#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	int maxIncreasingSubarrays(vector<int> &nums)
	{
		// find the sequences of increasing numbers
		int maxSoFar = nums[0] - 1;
		int streak = 0;
		int prevStreak = 0;
		int maxTwoStreak = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= maxSoFar)
			{
				maxTwoStreak = max(maxTwoStreak, max(min(streak, prevStreak), streak / 2));
				prevStreak = streak;
				streak = 1;
				maxSoFar = nums[i];
			}
			else
			{
				streak++;
				maxSoFar = nums[i];
			}
		}
		maxTwoStreak = max(maxTwoStreak, max(min(streak, prevStreak), streak / 2));
		prevStreak = streak;
		streak = 0;
		maxSoFar = -2147483648;

		return maxTwoStreak;
	}
};
