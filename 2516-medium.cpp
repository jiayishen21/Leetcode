#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct ABC
{
	int a, b, c;
};

class Solution
{
public:
	int takeCharacters(string s, int k)
	{
		if (k == 0)
		{
			return 0;
		}
		int n = s.size();
		ABC frequencies{0, 0, 0};
		for (auto &c : s)
		{
			if (c == 'a')
			{
				frequencies.a++;
			}
			else if (c == 'b')
			{
				frequencies.b++;
			}
			else
			{
				frequencies.c++;
			}
		}
		if (frequencies.a < k || frequencies.b < k || frequencies.c < k)
		{
			return -1;
		}

		size_t left = 0;
		size_t right = n;
		frequencies = {0, 0, 0};
		while (frequencies.a < k || frequencies.b < k || frequencies.c < k)
		{
			right--;
			if (s[right] == 'a')
			{
				frequencies.a++;
			}
			else if (s[right] == 'b')
			{
				frequencies.b++;
			}
			else
			{
				frequencies.c++;
			}
		}
		int result = n - right + left;
		while (left < n - 1)
		{
			if (s[left] == 'a')
			{
				frequencies.a++;
			}
			else if (s[left] == 'b')
			{
				frequencies.b++;
			}
			else
			{
				frequencies.c++;
			}
			while (right < n)
			{
				if (s[right] == 'a')
				{
					if (frequencies.a == k)
					{
						break;
					}
					else
					{
						frequencies.a--;
					}
				}
				else if (s[right] == 'b')
				{
					if (frequencies.b == k)
					{
						break;
					}
					else
					{
						frequencies.b--;
					}
				}
				else
				{
					if (frequencies.c == k)
					{
						break;
					}
					else
					{
						frequencies.c--;
					}
				}
				right++;
			}

			// increment left before result since left is an index, but we want the length
			left++;
			result = min(result, (int(n - right + left)));
		}

		return result;
	}
};
