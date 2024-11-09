#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
	long long minEnd(int n, int x)
	{
		// step 1, put x into bit representation
		vector<int> xBits;
		int insertionsPerCycle = 1;
		while (x)
		{
			xBits.push_back(x % 2);
			if (x % 2 == 0)
			{
				insertionsPerCycle *= 2;
			}
			x /= 2;
		}

		// step 2, calculate the minimum insertion of powers of 2
		int pow2Insertions = (n - 1) / insertionsPerCycle;
		int pow2Remainder = (n - 1) % insertionsPerCycle;
		long long power2Insertion = pow(2, xBits.size()) * pow2Insertions;

		int remainderInsertion = 0;
		int remainderMultiplier = 1;
		for (size_t i = 0; i < xBits.size(); i++)
		{
			if (xBits[i] == 1)
			{
				remainderInsertion += remainderMultiplier;
			}
			else if (pow2Remainder > 0)
			{
				if (pow2Remainder % 2 == 1)
				{
					remainderInsertion += remainderMultiplier;
				}
				pow2Remainder /= 2;
			}
			remainderMultiplier *= 2;
		}

		return power2Insertion + remainderInsertion;
	}
};
