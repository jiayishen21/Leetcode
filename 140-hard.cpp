#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
140. Word Break II
leetcode hard
https://leetcode.com/problems/word-break-ii/description/
time:
notes:
*/

class Solution
{
public:
	vector<string> wordBreak(string s, vector<string> &wordDict)
	{
		// 1st step is to get an actual dict
		unordered_set<string> dict(wordDict.begin(), wordDict.end());

		// we know that the max length of a word is 10, so we can dp through and check the last 10 characters
		// we also know s is max length 20
		vector<vector<string>> dp(s.size());

		for (int i = 0; i < s.size(); i++)
		{
			// consider if took the last j characters as a word
			for (int j = 1; j < 11 && i - j + 1 >= 0; j++)
			{
				string word = s.substr(i + 1 - j, j);
				if (dict.find(word) != dict.end())
				{
					// if j letters is the entire string so far
					if (i + 1 == j)
					{
						dp[i].push_back(word);
					}
					else
					{
						for (string &sentence : dp[i - j])
						{
							dp[i].push_back(sentence + " " + word);
						}
					}
				}
			}
		}

		return dp[s.size() - 1];
	}
};
