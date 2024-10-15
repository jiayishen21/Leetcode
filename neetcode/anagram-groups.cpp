#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
Anagram Groups
Neetcode medium
https://neetcode.io/problems/anagram-groups
time:
*/

bool isAnagram(unordered_map<char, int> &a, unordered_map<char, int> &b)
{
	if (a.size() != b.size())
	{
		return false;
	}

	for (auto &p : a)
	{
		if (b.find(p.first) == b.end() || b[p.first] != p.second)
		{
			return false;
		}
	}

	return true;
}

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		vector<pair<unordered_map<char, int>, vector<string>>> charFreqs;
		for (string &s : strs)
		{
			unordered_map<char, int> curFreq;
			for (char c : s)
			{
				curFreq[c]++;
			}

			bool found = false;
			for (auto &p : charFreqs)
			{
				if (isAnagram(p.first, curFreq))
				{
					p.second.push_back(s);
					found = true;
					break;
				}
			}
			if (!found)
			{
				charFreqs.push_back({curFreq, {s}});
			}
		}

		vector<vector<string>> result;
		for (auto &p : charFreqs)
		{
			result.push_back(p.second);
		}
		return result;
	}
};
