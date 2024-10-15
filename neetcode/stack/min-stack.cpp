#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
Minimum Stack
Neetcode medium
https://neetcode.io/problems/minimum-stack
time:
notes:
*/

class MinStack
{
public:
	MinStack()
	{
		st = stack<int>();
		minSt = stack<int>();
	}

	void push(int val)
	{
		if (st.empty())
		{
			st.push(val);
			minSt.push(val);
		}
		else
		{
			st.push(val);
			minSt.push(min(val, minSt.top()));
		}
	}

	void pop()
	{
		st.pop();
		minSt.pop();
	}

	int top()
	{
		return st.top();
	}

	int getMin()
	{
		return minSt.top();
	}

private:
	stack<int> minSt;
	stack<int> st;
};
