#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
32. Longest Valid Parentheses
Leetcode hard
https://leetcode.com/problems/longest-valid-parentheses/description/
time: 30 mins
notes: forgot to check for (()()) at first
*/

class Solution
{
public:
	bool coallesce(vector<pair<int, int>> &valids)
	{
		bool changed = false;
		int n = valids.size();
		for (int i = 0; i < n - 1; i++)
		{
			if (valids[i].second + 1 == valids[i + 1].first)
			{
				valids[i].second = valids[i + 1].second;
				valids.erase(valids.begin() + i + 1);
				changed = true;
				n--;
				i--;
			}
		}
		return changed;
	}

	int longestValidParentheses(string s)
	{
		// initial thoughts:
		// two valid substrings together are also valid
		// we can just mark down all the valid substrings and add together their length
		// challenge is to find how to deal with (()())

		int n = s.size();
		vector<pair<int, int>> valids;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] == '(' && s[i + 1] == ')')
			{
				valids.push_back({i, i + 1});
			}
		}

		bool changed = true;
		while (changed)
		{
			changed = coallesce(valids);
			// extend out valids by one to each side
			for (int i = 0; i < valids.size(); i++)
			{
				if (valids[i].first > 0 && valids[i].second < n - 1 && s[valids[i].first - 1] == '(' && s[valids[i].second + 1] == ')')
				{
					valids[i].first--;
					valids[i].second++;
					changed = true;
				}
			}
		}

		int longest = 0;
		for (auto &valid : valids)
		{
			longest = max(longest, valid.second - valid.first + 1);
		}
		return longest;
	}
};