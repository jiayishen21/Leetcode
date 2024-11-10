#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
	int binom(long long n, long long k)
	{
		const int M = 1e9 + 7;
		if (k == 0 || k == n)
		{
			return 1;
		}
		if (k == 1)
		{
			return n;
		}
		long long result = 1;
		for (int i = 0; i < k; i++)
		{
			result *= n - i;
			result /= i + 1;
			result %= M;
		}
		return result % M;
	}

public:
	int countKReducibleNumbers(string s, int k)
	{
		const int M = 1e9 + 7;
		vector<int> reductions = {0, 0};
		for (int i = 2; i <= s.size(); i++)
		{
			int numBits = 0;
			int iCopy = i;
			while (iCopy)
			{
				numBits += iCopy % 2;
				iCopy /= 2;
			}
			reductions.push_back(reductions[numBits] + 1);
		}

		// find number of binary numbers with specific bit count and also less than s
		vector<long long> numBits(s.size() + 1, 0);
		int sIndex = 0;
		int numOnes = 0;
		while (sIndex < s.size())
		{
			if (s[sIndex] == '0')
			{
				sIndex++;
				continue;
			}
			numOnes++;
			for (int i = 0; i <= s.size() - sIndex; i++)
			{
				numBits[numOnes + i] += binom(s.size() - 1 - sIndex, i);
				numBits[numOnes + i] %= M;
			}
			sIndex++;
		}

		// print reductions and numBits
		for (int i = 0; i < reductions.size(); i++)
		{
			cout << reductions[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < numBits.size(); i++)
		{
			cout << numBits[i] << " ";
		}

		long long result = 0;
		for (int i = 0; i < numBits.size(); i++)
		{
			if (reductions[i] < k)
			{
				result += numBits[i];
				result %= M;
			}
		}
		return result % M;
	}
};
