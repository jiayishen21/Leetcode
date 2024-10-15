#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Longest Consecutive Sequence
Neetcode medium
https://neetcode.io/problems/longest-consecutive-sequence
time:
notes:
*/

class Solution
{
public:
	int longestConsecutive(vector<int> &nums)
	{
		if (nums.size() == 0)
		{
			return 0;
		}

		int longest = 0;
		// turn nums into sorted and remove duplicates
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());

		int prev = nums[0];
		int cur = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (prev + 1 == nums[i])
			{
				cur++;
				prev++;
			}
			else
			{
				longest = max(longest, cur);
				cur = 1;
				prev = nums[i];
			}
		}
		longest = max(longest, cur);
		return longest;
	}
};
