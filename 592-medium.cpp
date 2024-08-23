#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
592. Fraction Addition and Subtraction
Leetcode medium
https://leetcode.com/problems/fraction-addition-and-subtraction/description/?envType=daily-question&envId=2024-08-23
time: 25 minutes
*/

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

class Solution
{
public:
	string fractionAddition(string expression)
	{
		if (expression[0] != '-')
		{
			expression = "+" + expression + "+";
		}
		else
		{
			expression = expression + "+";
		}
		int n = expression.size();

		// my plan is to divide both sides by the gcd after each addition / subtraction
		int num = 0;
		int den = 1;
		int sign = 0;

		int curNum = 0;
		int curDen = 1;
		int tempGcd;

		string curStatus = "num";

		for (int i = 0; i < n; i++)
		{
			if (expression[i] == '+' || expression[i] == '-')
			{
				curNum *= den;
				num = num * curDen + sign * curNum;
				den *= curDen;

				sign = 1;
				tempGcd = max(gcd(abs(num), den), 1);
				// cout << "-------------" << endl;
				// cout << num << "/" << den << endl;
				num /= tempGcd;
				den /= tempGcd;

				// cout << num << "/" << den << endl;

				if (expression[i] == '+')
				{
					sign = 1;
				}
				else
				{
					sign = -1;
				}
				curStatus = "num";
				curNum = 0;
				curDen = 0;
			}
			else if (expression[i] == '/')
			{
				curStatus = "den";
				cout << "slash" << endl;
			}
			else if (curStatus == "num")
			{
				curNum = curNum * 10 + expression[i] - '0';
			}
			else if (curStatus == "den")
			{
				curDen = curDen * 10 + expression[i] - '0';
			}
		}

		return to_string(num) + "/" + to_string(den);
	}
};