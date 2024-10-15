#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
String Encode and Decode
Neetcode medium
https://neetcode.io/problems/string-encode-and-decode
time:
*/

class Solution
{
public:
	// the idea is to encode it as strLength + " " + str
	// this avoids the hassle of converting the string to its ascii representation
	// why this works is because even if our strings were ["1 ", "2 ", "3 "], the encoded string would be "1 1 2 1 3 "
	// we would skip over the numbers that try to conflict with the string length since the
	// first thing we read is a length

	string encode(vector<string> &strs)
	{
		string res;
		for (string &s : strs)
		{
			res += to_string(s.size()) + " " + s;
		}
		return res;
	}

	vector<string> decode(string s)
	{
		int curIndex = 0;
		vector<string> res;
		while (curIndex < s.length())
		{
			int spaceIndex = curIndex;
			while (spaceIndex < s.size() && s[spaceIndex] != ' ')
			{
				spaceIndex++;
			}
			// we're done if we alrdy got all the strings
			if (spaceIndex == s.size())
			{
				break;
			}
			int stringLen = 0;
			for (int i = curIndex; i < spaceIndex; i++)
			{
				stringLen = stringLen * 10 + (s[i] - '0');
			}

			string curString = "";
			for (int i = 0; i < stringLen; i++)
			{
				curString += s[spaceIndex + 1 + i];
			}
			res.push_back(curString);
			curIndex = spaceIndex + 1 + stringLen;
		}
		return res;
	}
};
