#include <vector>

using namespace std;

class Solution
{
public:
	int minimumSubarrayLength(vector<int> &nums, int k)
	{
		const int originalK = k;
		// the answer is 1 if anything in nums >= k

		// let k = 10010011
		// kBits is the bit representation of k backwards
		vector<int> kBits;
		while (k)
		{
			kBits.push_back(k % 2);
			k /= 2;
		}
		int n = kBits.size();

		for (auto num : nums)
		{
			if (num >= originalK)
			{
				return 1;
			}
			for (int i = 0; i < n; i++)
			{
			}
		}
	}
};
