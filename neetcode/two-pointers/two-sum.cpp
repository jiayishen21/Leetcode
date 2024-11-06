#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		size_t i = 0;
		size_t j = numbers.size() - 1;
		vector<int> result;

		while (i < j)
		{
			if (numbers[i] + numbers[j] == target)
			{
				result.push_back(i + 1);
				result.push_back(j + 1);
				return result;
			}
			else if (numbers[i] + numbers[j] < target)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		return result;
	}
};
