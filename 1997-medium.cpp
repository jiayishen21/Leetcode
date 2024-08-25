#include <iostream>
#include <vector>
using namespace std;

/*
1997. First Day Where You Have Been in All the Rooms
Leetcode medium
https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/description/
time: 1 hour
notes: this was done on vacation, so probably not as fast or good as usual
i also didn't know exactly how c++ mod works, so now i know.
*/

class Solution
{
public:
	int firstDayBeenInAllRooms(vector<int> &nextVisit)
	{
		// 2 <= n <= 10^5
		// probably needs to be O(n) or better

		// initial thoughts:
		// we start at room 0,
		// each turn, we can at most move up to i + 1
		// hence, it's not possible to visit room n-1 without visiting all rooms before it an even number of times

		// i think we can use induction here
		// we want to show that
		// given that daysTaken[i] is the number of days taken to visit room i for the first time,
		// daysTaken[i] = daysTaken[i - 1] * 2 - daysTaken[nextVisit[i - 1]] + 2, for i > 0
		// base case:
		// it takes 1 day to visit room 0
		// it takes 3 days to visit room 1, shown by daysTaken[0] * 2 - daysTaken[nextVisit[0]] + 2 = 1 * 2 - 1 + 2 = 3
		// induction step:
		// let's say this holds up to i - 1. given i, we can see that we first need to reach i - 1 two times, then reach i.
		// the first time we reach i - 1, it takes daysTaken[i - 1] days. then we spend 1 day to reach nextVisit[i - 1].
		// to reach i - 1 again from scratch, we would need daysTaken[i - 1] days. but we already reached nextVisit[i - 1] once,
		// so we take those steps off the total, so we will reach i - 1 again from nextVisit[i - 1] in daysTaken[i - 1] - daysTaken[nextVisit[i - 1]] days.
		// once we reach there, we spend 1 day to reach i. hence, the total number of days taken to reach i is daysTaken[i - 1] * 2 - daysTaken[nextVisit[i - 1]] + 2.

		int n = nextVisit.size();
		vector<long> daysTaken(n, 0);
		daysTaken[0] = 1;
		const int MOD = 1000000007;
		for (int i = 1; i < n; i++)
		{
			// we can take the mod every turn instead of at the end because it's the same result
			daysTaken[i] = (daysTaken[i - 1] * 2 - daysTaken[nextVisit[i - 1]] + 2 + MOD) % MOD;
		}

		// sub 1 off since our first visit is on day 0

		// in case -1 results in overflow
		return (daysTaken[n - 1] - 1 + MOD) % MOD;
	}
};