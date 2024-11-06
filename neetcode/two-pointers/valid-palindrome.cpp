#include <string>

using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		size_t i = 0;
		size_t j = s.length() - 1;

		while (i < j)
		{
			if (!isalpha(s[i]) && !isdigit(s[i]))
			{
				i++;
				continue;
			}
			if (!isalpha(s[j]) && !isdigit(s[j]))
			{
				j--;
				continue;
			}

			if (tolower(s[i]) != tolower(s[j]))
			{
				return false;
			}
			i++;
			j--;
		}

		return true;
	}
};
