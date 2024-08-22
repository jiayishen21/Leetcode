#include <iostream>
#include <vector>
using namespace std;

/*
1457. Pseudo-Palindromic Paths in a Binary Tree
Leetcode medium
https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
time: 20 minutes
*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	int pseudoPalindromicPaths(TreeNode *root)
	{
		// 1 <= Node.val <= 9
		// up to 10^5 nodes
		// solution should be O(n)

		// i'll leave the first index 0 as 0 so that i don't have to shift values down by 1
		vector<int> frequencies(11, 0);
		return pseudoPalindromicHelper(root, frequencies);
	}

	int pseudoPalindromicHelper(TreeNode *cur, vector<int> &frequencies)
	{
		if (!cur)
		{
			return 0;
		}
		frequencies[cur->val]++;
		if (!(cur->left) && !(cur->right))
		{
			// if we hit the end, check if the path is pseudo-palindromic
			// by checking # of odd frequencies
			int odds = 0;
			for (int i = 1; i < 11; i++)
			{
				if (frequencies[i] % 2 == 1)
				{
					odds++;
				}
			}
			// reset frequencies to before this node
			frequencies[cur->val]--;
			if (odds <= 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		int left = pseudoPalindromicHelper(cur->left, frequencies);
		int right = pseudoPalindromicHelper(cur->right, frequencies);
		// reset frequencies to before this node
		frequencies[cur->val]--;
		return left + right;
	}
};