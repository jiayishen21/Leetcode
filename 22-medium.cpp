#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
22. Generate Parentheses
leetcode medium
https://leetcode.com/problems/generate-parentheses/
time:
notes:
*/

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<vector<string>> dp(n + 1);
		dp[0] = {""};
		for (int i = 1; i < n + 1; i++)
		{
			// let j denote the size of first dyck path
			for (int j = 0; j < i; j++)
			{
				for (string &first : dp[j])
				{
					for (string &second : dp[i - j - 1])
					{
						dp[i].push_back("(" + first + ")" + second);
					}
				}
			}
		}
		return dp[n];
	}
};