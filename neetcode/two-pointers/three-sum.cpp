#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		unordered_map<int, int> numCount;
		for (int num : nums)
		{
			numCount[num]++;
		}

		vector<vector<int>> result;

		unordered_map<int, unordered_set<int>> twoSum;

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				vector<int> triplet;
				triplet.push_back(nums[i]);
				triplet.push_back(nums[j]);
				triplet.push_back(-nums[i] - nums[j]);
				sort(triplet.begin(), triplet.end());

				// duplicate check
				if (
					twoSum.find(triplet[0]) != twoSum.end() &&
					twoSum[triplet[0]].find(triplet[1]) != twoSum[triplet[0]].end())
				{
					continue;
				}

				numCount[triplet[0]]--;
				numCount[triplet[1]]--;
				numCount[triplet[2]]--;

				if (
					numCount[triplet[0]] >= 0 &&
					numCount[triplet[1]] >= 0 &&
					numCount[triplet[2]] >= 0)
				{
					result.push_back(triplet);
					twoSum[triplet[0]].insert(triplet[1]);
				}

				numCount[triplet[0]]++;
				numCount[triplet[1]]++;
				numCount[triplet[2]]++;
			}
		}

		return result;
	}
};
