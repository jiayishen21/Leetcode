#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
2530. Maximal Score After Applying K Operations
leetcode medium
https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14
time:
notes: didn't know about priority queues, i tried implementing my own bst, but forgot about the possibility of
unbalanced trees, so i TLE'd. i should have used priority queues or heaps or avl trees.
*/

class Solution
{
public:
	long long maxKelements(vector<int> &nums, int k)
	{
		priority_queue<int> pq(nums.begin(), nums.end());
		long long score = 0;
		for (int i = 0; i < k; i++)
		{
			int maxVal = pq.top();
			score += maxVal;
			pq.pop();
			// ceil without conversion to double
			pq.push((maxVal + 2) / 3);
		}
		return score;
	}
};
