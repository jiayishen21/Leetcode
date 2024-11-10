#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Pair
{
	long long sum;
	long long freq;
};

class Solution
{
public:
	int sumOfGoodSubsequences(vector<int> &nums)
	{
		const int M = 1e9 + 7;
		// clean ass dp solution :)
		// map from num -> sum of all subsequences that end in num
		unordered_map<int, Pair> subseqSums;

		for (auto num : nums)
		{
			// check if the sum is even defined at num
			if (subseqSums.find(num) != subseqSums.end())
			{
				subseqSums[num].sum += num;
				subseqSums[num].freq++;
				subseqSums[num].freq %= M;
				subseqSums[num].sum %= M;
			}
			else
			{
				subseqSums[num] = {num, 1};
			}

			if (subseqSums.find(num - 1) != subseqSums.end())
			{
				subseqSums[num].freq += subseqSums[num - 1].freq;
				subseqSums[num].freq %= M;
				subseqSums[num].sum += subseqSums[num - 1].sum + subseqSums[num - 1].freq * num;
				subseqSums[num].sum %= M;
			}
			if (subseqSums.find(num + 1) != subseqSums.end())
			{
				subseqSums[num].freq += subseqSums[num + 1].freq;
				subseqSums[num].freq %= M;
				subseqSums[num].sum += subseqSums[num + 1].sum + subseqSums[num + 1].freq * num;
				subseqSums[num].sum %= M;
			}
		}

		long long result = 0;
		for (auto &it : subseqSums)
		{
			result += it.second.sum;
			result %= M;
		}
		int smallResult = result % M;
		return result;
	}
};
