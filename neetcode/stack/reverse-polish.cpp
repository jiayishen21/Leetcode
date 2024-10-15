#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
Evaluate Reverse Polish Notation
Neetcode medium
https://neetcode.io/problems/evaluate-reverse-polish-notation
time:
notes:
*/

class Solution
{
public:
	int evalRPN(vector<string> &tokens)
	{
		stack<int> s;

		for (auto &token : tokens)
		{
			if (token == "+" || token == "-" || token == "*" || token == "/")
			{
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();

				if (token == "+")
					s.push(a + b);
				else if (token == "-")
					s.push(a - b);
				else if (token == "*")
					s.push(a * b);
				else if (token == "/")
					s.push(a / b);
			}
			else
			{
				s.push(stoi(token));
			}
		}
		return s.top();
	}
};
