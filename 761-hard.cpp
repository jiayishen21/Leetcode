#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

/*
761. Special Binary String
Leetcode hard
https://leetcode.com/problems/special-binary-string/description/
time:
notes: had to use the hint. also read it entirely wrong. we can swap substrings of different lengths
*/

class Solution
{
public:
	string makeLargestSpecial(string s)
	{
		// The number of 0's is equal to the number of 1's.
		// Every prefix of the binary string has at least as many 1's as 0's.

		// initial thoughts:
		// s length is 50
		// there are WAYYY too many possible substrings to precompute whether each substring is special
		// disregarding the first condition, the prefix condition ensures that the binary string is going to be "large" for its length

		// hint:
		// Draw a line from(x, y) to(x + 1, y + 1) if we see a "1", else to(x + 1, y - 1).A special substring is just a line that starts
		// and ends at the same y - coordinate, and that is the lowest y - coordinate reached.Call a mountain a special substring with no
		// special prefixes - ie.only at the beginning and end is the lowest y - coordinate reached.If F is the answer function, and S has
		// mountain decomposition M1, M2, M3, ..., Mk, then the answer is : reverse_sorted(F(M1), F(M2), ..., F(Mk)).However, you'll also
		// need to deal with the case that S is a mountain, such as 11011000 -> 11100100.

		// TODO: draw out the mountain again next time i work on this

		int n = s.size();
		vector<int> heights(n + 1, 0);
		int height = 0;
		for (int i = 1; i < n; i++)
		{
			if (s[i] == '1')
			{
				height++;
			}
			else
			{
				height--;
			}
			heights[i] = height;
		}
	}
};