#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Top K Elements in List
Neetcode medium
https://neetcode.io/problems/top-k-elements-in-list
time: 5 mins
*/

class Solution
{
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		// first build up a frequency map
		unordered_map<int, int> freq;
		for (int n : nums)
		{
			if (freq.find(n) == freq.end())
			{
				freq[n] = 1;
			}
			else
			{
				freq[n]++;
			}
		}

		// sort the frequency map by value, descending
		vector<pair<int, int>> freqVec;
		for (auto &p : freq)
		{
			freqVec.push_back(p);
		}

		sort(freqVec.begin(), freqVec.end(), [](pair<int, int> &a, pair<int, int> &b)
			 { return a.second > b.second; });

		// get the top k elements
		vector<int> res;
		for (int i = 0; i < k; i++)
		{
			res.push_back(freqVec[i].first);
		}
		return res;
	}
};
