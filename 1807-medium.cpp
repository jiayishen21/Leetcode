#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
1807. evaluate the bracket pairs of a string
leetcode medium
https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/
time: 4 minutes
notes:
*/

class solution
{
public:
	string evaluate(string s, vector<vector<string>> &knowledge)
	{
		bool startbracket = false;
		string key = "";

		unordered_map<string, string> knowledgemap;
		for (auto k : knowledge)
		{
			knowledgemap[k[0]] = k[1];
		}

		string result = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				startbracket = true;
			}
			else if (s[i] == ')')
			{
				startbracket = false;
				if (knowledgemap.find(key) != knowledgemap.end())
				{
					result += knowledgemap[key];
				}
				else
				{
					result += "?";
				}
				key = "";
			}
			else
			{
				if (startbracket)
				{
					key += s[i];
				}
				else
				{
					result += s[i];
				}
			}
		}

		return result;
	}
};
