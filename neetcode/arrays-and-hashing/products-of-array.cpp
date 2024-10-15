#include <iostream>
#include <vector>

using namespace std;

/*
Products of Array Discluding Self
Neetcode medium
https://neetcode.io/problems/products-of-array-discluding-self
time:
notes: i did not think to use prefix and suffix RAHHHHH
*/

class Solution
{
public:
	vector<int> productExceptSelf(vector<int> &nums)
	{
		// challenge, O(n) without division
		vector<int> prefix(nums.size());
		vector<int> suffix(nums.size());

		prefix[0] = 1;
		suffix[nums.size() - 1] = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			prefix[i] = prefix[i - 1] * nums[i - 1];
		}
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			suffix[i] = suffix[i + 1] * nums[i + 1];
		}

		vector<int> res(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			res[i] = prefix[i] * suffix[i];
		}
		return res;
	}
};
