#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
15. 3Sum
leetcode medium
https://leetcode.com/problems/3sum/description/
time:
notes:
*/

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		unordered_map<int, int> frequencies;
		for (int i = 0; i < nums.size(); i++)
		{
			if (frequencies.find(nums[i]) == frequencies.end())
			{
				frequencies[nums[i]] = 1;
			}
			else
			{
				frequencies[nums[i]]++;
			}
		}

		vector<int> keys;
		for (const auto &[num, freq] : frequencies)
		{
			keys.push_back(num);
		}
		sort(keys.begin(), keys.end());

		vector<vector<int>> result;
		for (int i = 0; i < keys.size(); i++)
		{
			for (int j = i; j < keys.size(); j++)
			{
				int target = -keys[i] - keys[j];
				if (target < keys[j])
				{
					continue;
				}

				if (frequencies.find(target) == frequencies.end())
				{
					continue;
				}
				int curFreq = frequencies[keys[i]];
				int targetFreq = frequencies[target];
				if (keys[i] == target)
				{
					curFreq--;
					targetFreq--;
				}
				if (keys[j] == target)
				{
					targetFreq--;
				}
				if (keys[i] == keys[j])
				{
					curFreq--;
				}
				if (curFreq <= 0 || targetFreq <= 0)
				{
					continue;
				}
				result.push_back({keys[i], keys[j], target});
			}
		}
		return result;
	}
};
