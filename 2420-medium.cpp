#include <iostream>
#include <vector>
using namespace std;

/*
2420. Find All Good Indices
Leetcode medium
https://leetcode.com/problems/find-all-good-indices/
time: 50 minutes
notes:
i made WAYYYYY too many careless mistakes (forgetting to update code in multiple parts, etc.)
which caused me to waste a lot of time debugging and used multiple submissions.
*/

class Solution
{
public:
	vector<int> goodIndices(vector<int> &nums, int k)
	{
		int n = nums.size();
		vector<int> res;
		if (k >= n - k)
		{
			return res;
		}

		// immediate thoughts is to do 2 sliding windows
		int nonIncreaseCount = 1;
		int nonDecreaseCount = 1;
		// arrays to indicate for how long the non-increasing and non-decreasing sequences are at each index
		vector<int> nonIncrease(n, 0); // longest non-increasing chain up to this index from the left
		vector<int> nonDecrease(n, 0); // longest non-decreasing chain up to this index from the right
		for (int i = 1; i < n; i++)
		{
			if (nums[i] <= nums[i - 1])
			{
				nonIncrease[i] = nonIncreaseCount;
				nonIncreaseCount++;
			}
			else
			{
				nonIncrease[i] = nonIncreaseCount;
				nonIncreaseCount = 1;
			}

			if (nums[n - i - 1] <= nums[n - i])
			{
				nonDecrease[n - i - 1] = nonDecreaseCount;
				nonDecreaseCount++;
			}
			else
			{
				nonDecrease[n - i - 1] = nonDecreaseCount;
				nonDecreaseCount = 1;
			}
		}

		for (int i = k; i < n - k; i++)
		{
			if (nonIncrease[i] >= k && nonDecrease[i] >= k)
			{
				res.push_back(i);
			}
		}

		return res;
	}
};
