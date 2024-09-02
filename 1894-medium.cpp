#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
1894. Find the Student that Will Replace the Chalk
Leetcode medium
https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/?envType=daily-question&envId=2024-09-02
time: 5 minutes
*/

class Solution
{
public:
	int chalkReplacer(vector<int> &chalk, int k)
	{
		// immediate thoughts: this is a really easy mod problem
		// only thing i'm worried about this int overflow, which is easy to address
		int sum = 0;

		// we do an initial loop to sum up the total chalk and also make sure total chalk doesn't overflow
		for (int i = 0; i < chalk.size(); i++)
		{
			if (k < chalk[i])
			{
				return i;
			}

			sum += chalk[i];
			k -= chalk[i];
		}

		k %= sum;
		for (int i = 0; i < chalk.size(); i++)
		{
			if (k < chalk[i])
			{
				return i;
			}
			k -= chalk[i];
		}
		return -1;
	}
};
